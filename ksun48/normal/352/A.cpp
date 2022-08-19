#include <iostream>
using namespace std;

int main() {
    int n;
    cin >> n;
    int a = 0, b = 0;
    int k;
    for(int i = 0; i < n; i++){
        cin >> k;
        if(k == 0) a++;
        if(k == 5) b++;
    }
    if(a == 0){
        cout << -1 << endl;
    } else if(b<9){
        cout << 0 << endl;
    } else {
        for(int i = 0; i < b/9; i++){
            cout << "555555555";
        }
        for(int i = 0; i < a; i++){
            cout << 0;
        }
        cout << endl;
    }
    return 0;
}