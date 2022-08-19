#include <iostream>
#include <string>
using namespace std;

int main() {
    string a, b;
    cin >> a >> b;
    int n = a.size();
    int game = 0;
    for(int i = 0; i < n; i+= 2){
        if(a[i] == b[i]){
        } else if(a[i] == '8' && b[i] == '['){
            game++;
        } else if(a[i] == '[' && b[i] == '('){
            game++;
        } else if(a[i] == '(' && b[i] == '8'){
            game++;
        } else {
            game--;
        }
    }
    if(game > 0){
        cout << "TEAM 1 WINS" << endl;
    } else if(game < 0){
        cout << "TEAM 2 WINS" << endl;
    } else {
        cout << "TIE" << endl;
    }
    return 0;
}