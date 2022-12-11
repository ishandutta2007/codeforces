#include <bits/stdc++.h>
using namespace std;
const long long MOD = 998244353;

long long n,ans,tmp=1;
int main()
{
    cin >> n;
    for(int i=n; i>=2; i--){
        tmp *= i;
        tmp %= MOD;
        ans -= tmp;
        ans %= MOD;
    }
    ans += n*tmp;
    ans %= MOD;
    cout << ans;
}