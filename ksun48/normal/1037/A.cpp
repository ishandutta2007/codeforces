#include <bits/stdc++.h>
using namespace std;
typedef long long LL;


int main(){
    LL n;
    cin >> n;
    for(LL i = 1; i <= 30; i++){
        if(n < (1LL << i)){
            cout << i << endl;
            return 0;
        }
    }
}