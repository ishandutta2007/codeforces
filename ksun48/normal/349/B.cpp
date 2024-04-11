#include <iostream>
using namespace std;

int main() {
    int v;
    cin >> v;
    int a[10];
    int yes = 0;
    int mins = 1000000;
    for(int i = 1; i <= 9; i++){
        cin >> a[i];
        mins = min(mins, a[i]);
        if(a[i] <= v){
            yes = 1;
        }
    }
    if(yes == 0){
        cout << -1 << endl;
        return 0;
    }
    int maxk = v/mins;
    v %= mins;
    for(int i = 0; i < maxk; i++){
        for(int j = 9; j >= 0; j--){
            if(v >= a[j]-mins){
                v -= (a[j]-mins);
                cout << j;
                break;
            }
        }
    }
    cout << endl;
    return 0;
}