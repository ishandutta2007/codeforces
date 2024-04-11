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
LL fact[110000];
LL invfact[110000];

LL ncr(LL n, LL r){
    if(r < 0 || n < 0) return 0;
    if(n < r) return 0;
    LL a = fact[n];
    a = (a * invfact[r]) % MOD;
    a = (a * invfact[n-r]) % MOD;
    return a;
}
LL inv2;
void init(){
    fact[0] = 1;
    invfact[0] = 1;
    inv2 = inv(2);
    for(LL i = 1; i < 110000; i++){
        fact[i] = (i*fact[i-1]) % MOD;
        invfact[i] = inv(fact[i]);
    }
}


LL dp[5100][5100];
int main(){
    init();
    LL n, k;
    cin >> n >> k;
    for(LL i = 0; i < 5100; i++){
        for(LL j = 0; j < 5100; j++){
            dp[i][j] = 0;
        }
    }
    dp[0][0] = 1;
    for(LL i = 0; i < k; i++){
        for(LL j = 0; j < 5100; j++){
            if(dp[i][j] == 0) continue;
            dp[i+1][j] += (dp[i][j] * j) % MOD;
            dp[i+1][j+1] += (((dp[i][j] * (n-j)) % MOD) * inv2) % MOD;
            dp[i+1][j] %= MOD;
            dp[i+1][j+1] %= MOD;
        }
    }
    LL ans = 0;
    for(LL j = 0; j < 5100; j++){
        ans += dp[k][j];
        ans %= MOD;
    }
    ans = (ans * powmod(2, n) ) % MOD;
    cout << ans << endl;
}