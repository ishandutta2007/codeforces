#include <iostream>
using namespace std;

int main() {
    int n;
    cin >> n;
    int a = 0;
    int b = 0;
    for(int i =0 ; i < n; i++){
        int k;
        cin >> k;
        if(k == 25){
            a++;
        } else if(k == 50){
            if(a > 0){
                a--; b++;
            } else {
                cout << "NO\n";
                return 0;
            }
        } else {
            if(a > 0 && b > 0){
                a--;
                b--;
            } else if(a > 2){
                a -= 3;
            } else {
                                cout << "NO\n";
                                return 0;
            }
        }
    }
    cout << "YES\n";
    return 0;
}