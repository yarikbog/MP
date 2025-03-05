#include <vector>
#include <iostream>
#include <ctime>
//https://education.yandex.ru/handbook/cpp/article/vectors-and-strings
using namespace std;

string hpcheck(int hp) {
    if (hp <= 0) {
        return "Вы погибли!";
    }
    else return "Вы выжили!";
}

void inventorycheck(const vector<string>& items) {
    cout << "\nВаш текущий инвентарь:" << endl;
    for (size_t i = 0; i < items.size(); ++i) {
        cout << i + 1 << ". " << items[i] << endl;
    }
}

//void harcheck(const vector<int>& har) {
   // cout << "\nВаши текущие характеристики:" << endl;
    //for (const auto& hars : har) {
      //  cout << hars << endl;
    //}
//}

void harcheck1(int hp, int uron) {
    cout << "\nВаши текущие характеристики:" << endl;
    cout << "Здоровье:"<< hp;
    cout << "\nУрон:" << uron << endl;
} 
void combat(vector<string>& inventory, int& hp, int& uron) {
    int monster_hp = 15;
    bool combat_active = true;

    cout << "\nБой начался!" << endl;

    while (combat_active && hp > 0 && monster_hp > 0) {
        harcheck1(hp, uron);
        cout << "\nЗдоровье монстра: " << monster_hp << endl;

        cout << "\nВыберите действие:" << endl;
        cout << "1. Атака" << endl;
        cout << "2. Защита" << endl;
        cout << "3. Использовать зелье" << endl;

        int choice;
        cin >> choice;

        switch (choice) {
        case 1: {
            // Атака
            int damage = uron + (rand() % 3);
            monster_hp -= damage;
            cout << "Вы нанесли " << damage << " урона!" << endl;

            if (monster_hp > 0) {
                int counter = (rand() % 3) + 1;
                hp -= counter;
                cout << "Монстр ответил! Получено " << counter << " урона." << endl;
            }
            break;
        }
        case 2: {
            // Защита
            cout << "Вы принимаете оборонительную позицию." << endl;
            if (monster_hp > 0) {
                int counter = 1;
                hp -= counter;
                cout << "Монстр атаковал, но урон уменьшен! Получено " << counter << " урона." << endl;
            }
            break;
        }
        case 3: {
            // Использование зелья
            if (!inventory.empty()) {
                cout << "\nДоступные зелья:" << endl;
                for (size_t i = 0; i < inventory.size(); ++i) {
                    cout << i + 1 << ". " << inventory[i] << endl;
                }

                int potion_choice;
                cin >> potion_choice;

                if (potion_choice > 0 && potion_choice <= inventory.size()) {
                    if (inventory[potion_choice - 1] == "Зеленое зелье") {
                    cout << "\nВы использовали " << inventory[potion_choice - 1] << endl;
                    hp += 5;
                    inventory.erase(inventory.begin() + (potion_choice - 1));
                    cout << "Восстановлено 5 здоровья!" << endl;
                    }
                    else {
                        hp = hp - 3;
                    }
                    
                }
            }
            else {
                cout << "Карманы пусты!" << endl;
            }
            break;
        }
        default:
            cout << "Неверный выбор!" << endl;
        }

        if (monster_hp <= 0) {
            cout << "\nМонстр побежден!" << endl;
            combat_active = false;
        }
    }

    if (hp <= 0) {
        cout << "\n" << hpcheck(hp) << endl;
    }
}

int main() {
    
    system("chcp 1251>nul");

    string weapon = "Кинжал разбойника";
    int uron = 3;
    int hp = 10;
    vector<int> haracter = {hp, uron};

        vector<int> kubik = {0,1,2};
        srand(time(0));

            int randomnomer = rand() % kubik.size();
            int randomchislo = kubik[randomnomer];
            cout << "Случайное число:" << randomchislo << endl;

        vector<string> effects{ "Яда","Огоня","Заморозки"};
        vector<int> damage{ 5,10,7 }; 

        cout << "Ваш персонаж очнулся от страшной боли. Не помня произошедшего, он испытал эффект " << effects[randomchislo]; cout << endl;
        cout << "Ему нанесено " << damage[randomchislo]; cout << " урона!" << endl;
        vector<string> posl{ "Ваши кишки вывернуты наружу","Ваша кожа обуглена, а кости хрустят","Ваши органы заледенели насквозь" };
        cout << posl[randomchislo] << endl;

        hp = hp - damage[randomchislo];

        cout << hpcheck(hp) << endl;

        if (hp <= 0) {
            return 0;
        } 

        cout << "Теперь перед Вами стоит нелёгкий выбор" << endl;
        string chose;

        vector<string> spels{ "Зеленое зелье","Красное зелье" };
        cout << "Персонаж обнаруживает на своём поясе два зелья. Красное и зеленое. Но выбор за Вами. Какую бутыль желаете опусташить?" << endl;
        
        //harcheck(haracter);

        harcheck1(hp, uron);

        inventorycheck(spels);

        std::cin >> chose;

        if (chose == "красную" || chose == "Красную" || chose == "красное" || chose == "Красное") {
            cout << "Вы испробовали зелье греха. Ваше ментальное здоровье в упадке!";
            hp = hp - 3;
            spels.pop_back();
            if (hp <= 0) {
                cout << hpcheck(hp) << endl;
                if (hp <= 0) {
                    return 0;
                }
            }
        }
        else if (chose == "зеленую" || chose == "Зеленую" || chose == "зеленое" || chose == "Зеленое") {
            cout << "Вы испробовали зелье жизни. Ваше здоровье восстановлено!" << endl;
            spels.erase(spels.begin());
            hp = hp + 5; // Восстановление здоровья
        }
        harcheck1(hp, uron);
        string ring;
        cout << "Выбор сделан. Элексир медленно растекается по телу. Вы чувствуюте это. Солнце слепит Вас. Пора идти дальше" << endl;
        
        cout << "Озираясь по сторонам, Вы вглядваетесь в Лес. Он отвечает Вам взаимностью. Хруст. Вы падаете. Нога зацепилась за корень. Подняв веки, Вы замечаете на земле два кольца. Топаз прямоугольной формы и круглый сапфир на них намекают о неестесвенном происхождении. Что-то подсказывает, что судьба не даст взять два. Какой камень предпочтете?" << endl;

        std::cin >> ring;

        if (ring == "Топаз" || ring == "топаз") {
            spels.push_back("Кольцо с топазом");
            cout << "Вы надели кольцо с топазом. Ваши кости затрещали, сухожилия загорелись и глаза полезли наружу. Тяжело было подняться на ноги, когда скелет стал жилеобразным. Ваша сила явно увеличалась за счет живучести." << endl;
            hp = hp - 3;
            uron = uron + 5;
            cout << hpcheck(hp) << endl;
            if (hp <= 0) {
                return 0;
            }
            inventorycheck(spels);
            harcheck1(hp, uron);
        }
        if (ring == "Сапфир" || ring == "сапфир") {
            spels.push_back("Кольцо с сапфиром");
            cout << "Вы надели кольцо с сапфиром. Раны затянулись, синяка от падения как-будто бы и не было, дуновение ветра подняло Вас на ноги и предало сил." << endl;
            hp = hp + 3;
            uron = uron + 1;
            cout << hpcheck(hp) << endl;
            if (hp <= 0) {
                return 0;
            }
            inventorycheck(spels);
            harcheck1(hp, uron);
        }
        // древесный паук-хранитель дает эффект отравления на оружие
        // птица-феникс зачарует оружие на огонь 
        // мелодия леса

        if (randomchislo == 0) {
            cout << "Впитав новую силу, Вы наконец возвращаетесь в Лес. Перед собой в корнях дерева Вы замечаете большую нору. Через мгновение из неё показывается восмиглазая голова древесного паука-хранителя. " << endl;

            cout << "Он всеми глазами въедается в кольцо на Вашем пальце. Очевидно, предстоит битва." << endl;
            combat(spels, hp, uron);

            if (hp > 0) {
                cout << "\nВытащим меч из внутренностей паука, Вы замечаете, как яд объел лезвее. Обжигающая кислота обвалакивала оружие.";
                weapon.insert(6, "обугленный древеной кислотой ");
                uron += 4;
                cout << "\nТеперь вы обладаете: " << weapon;
                harcheck1(hp, uron);
            }
        }
        else if (randomchislo == 1 || randomchislo == 2) {
            cout << "Впитав новую силу, Вы наконец возвращаетесь в Лес. Перед собой на ветвях дерева Вы замечаете полыхающую огнем птицу. Она вся покртыка пламенем, зажигая вокруг себя листья и сучки деревьев. Вы застыли от изумления. Феникс грозен и изящен. " << endl;

            cout << "Она глазами въедается в кольцо на Вашем пальце. Очевидно, предстоит битва." << endl;
            combat(spels, hp, uron);

            if (hp > 0) {
                cout << "\n Нанеся последний удар, феникс издает кипятящий кровь вой и потухшем факелом падает на землю. Вас клинок, разрезав его тело, закалился яростным пламенем жар-птици.";
                weapon.insert(6, "яростного пламени феникса ");
                uron += 4;
                cout << "\nТеперь вы обладаете: " << weapon;
                harcheck1(hp, uron);
            }
        }

    return 0;
}
