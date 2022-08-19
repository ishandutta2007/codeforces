#include <iostream>
#include <cstring>
#include <string>
typedef long long LL;
using namespace std;
LL MOD = 1000000007;
int main() {
    char str[200];
    cin >> str;
    int len = strlen(str);
    LL cur = 1;
    LL ans = 0;
    for(int i = 0; i < len; i++){
        if(str[i] == '1'){
            LL num = 1;
            for(int j = i+1; j < len; j++){
               num = (num*4) % MOD;
            }
            ans = (ans+cur*num) % MOD;
        }
        cur *= 2;
        cur %= MOD;
    }
cout << ans << endl;
    return 0;
}