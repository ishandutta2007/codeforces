#include <iostream>
using namespace std;

int main() {
    int x;
    cin >> x;
    if(x == 0){
        cout << "O-|-OOOO" << endl;
    }
    while(x > 0){
        if(x%10 >= 5){
            cout << "-O|";
            x -= 5;
        } else {
            cout << "O-|";
        }
        if(x% 10 == 0){
            cout << "-OOOO" << endl;
        } else if(x%10 == 1){
            cout << "O-OOO" << endl;
        }else if(x%10 == 2){
            cout << "OO-OO" << endl;
        }else if(x%10 == 3){
            cout << "OOO-O" << endl;
        }else if(x%10 == 4){
            cout << "OOOO-" << endl;
        }
        x = x/10;
    }
    return 0;
}