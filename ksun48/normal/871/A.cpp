#include <bits/stdc++.h>
using namespace std;
typedef long long LL;

int main(){
    int q;
    cin >> q;
    for(int i = 0; i < q; i++){
        int n;
        cin >> n;
        if(n % 4 == 0){
            cout << n/4 << endl;
            continue;
        }
        if(n % 4 == 2 && n >= 6){
            cout << n/4 << endl;
            continue;
        }
        if(n <= 8){
            cout << -1 << endl;
            continue;
        }
        if(n % 4 == 1){
            cout << n/4 - 1 << endl;
            continue;
        }
        if(n <= 11){
            cout << -1 << endl;
            continue;
        }
        if(n % 4 == 3){
            cout << n/4 - 1 << endl;
            continue;
        }
    }
}