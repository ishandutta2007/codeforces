#include <bits/stdc++.h>
using namespace std;
typedef long long LL;

#define MOD 1000000007
LL powmod(LL a, LL n){
    if(n == 0) return 1;
    if(n % 2) return (a*powmod(a,n-1)) % MOD;
    LL c = powmod(a, n/2);
    return (c*c) % MOD;
}
LL inv(LL a){
    return powmod(a, MOD-2);
}
LL fact[1100000];
LL invfact[1100000];

LL ncr(LL n, LL r){
    if(r < 0 || n < 0) return 0;
    if(n < r) return 0;
    LL a = fact[n];
    a = (a * invfact[r]) % MOD;
    a = (a * invfact[n-r]) % MOD;
    return a;
}
void init(){
    fact[0] = 1;
    invfact[0] = 1;
    LL inv2 = inv(2);
    for(LL i = 1; i < 110000; i++){
        fact[i] = (i*fact[i-1]) % MOD;
        invfact[i] = inv(fact[i]);
    }
}
LL dp[1100];
int main(){
    init();

    int n, m;
    cin >> m >> n;
    string g[n];
    for(int i = 0; i < n; i++) cin >> g[i];

    for(int i = 0; i < n; i++){
        if(g[i][0] == '1'){
            for(int j = 0; j < m; j++){
                g[i][j] = '0' + '1' - g[i][j];
            }
        }
    }
    map<LL,int> f;
    for(int j = 1; j < m; j++){
        LL c = 0;
        for(int i = 0; i < n; i++){
            c *= 2;
            c += g[i][j] - '0';
        }
        f[c]++;
    }

    for(int i = 0; i <= 1000; i++) dp[i] = 0;

    dp[0] = 1;
    dp[1] = 1;
    for(int i = 2; i <= 1000; i++){
        for(int k = 0; k < i; k++){
            dp[i] += dp[k] * ncr(i-1, k);
            dp[i] %= MOD;
        }
    }
    LL ans = 1;
    for(map<LL,int>::iterator it = f.begin(); it != f.end(); it++){
        if(it->first > 0){
            ans = (ans * dp[it->second]) % MOD;
        }
    }
    LL ans0 = 0;
    LL num = f[0];
    for(int i = 0; i <= num; i++){
        ans0 += ncr(num,i) * dp[num-i];
        ans0 %= MOD;
    }
    ans = (ans * ans0) % MOD;
    cout << ans << endl;
}