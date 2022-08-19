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
    for(LL i = 1; i < 1100000; i++){
        fact[i] = (i*fact[i-1]) % MOD;
        invfact[i] = inv(fact[i]);
    }
}

LL b[1100000];
LL pb[1100000];

int main(){
    init();
    LL n, k;
    cin >> n >> k;
    b[0] = 1;
    pb[0] = 0;
    pb[1] = 1;
    for(LL i = 1; i <= n; i++){
        LL c = max(i-k,0LL);
        b[i] = (pb[i] - pb[c]) * inv(i);
        b[i] %= MOD;
        while(b[i] < 0) b[i] += MOD;
        pb[i+1] = (b[i] + pb[i]) % MOD;
        //cout << (b[i]*fact[i]) % MOD << endl;
    }
    LL ans = 0;
    for(LL i = 0; i <= n-1; i++){
        LL g = b[i]*fact[n-1];
        g %= MOD;
        //cout << g << endl;
        ans += g;
        ans %= MOD;
    }
    ans = fact[n] - ans;
    ans %= MOD;
    while(ans < 0) ans += MOD;
    cout << ans << endl;

}