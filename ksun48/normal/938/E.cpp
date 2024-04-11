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


int main(){
    cin.sync_with_stdio(0); cin.tie(0);
    init();
    LL n;
    cin >> n;
    LL a[n];
    for(LL i = 0; i < n; i++) cin >> a[i];
    sort(a, a+n);
    LL s = 0;
    LL ans = 0;
    for(LL t = 0; t < n; t++){
        while(a[s] < a[t]) s++;
        ans += ( (inv(n-s)) % MOD ) * a[t];
        ans %= MOD;
    }
    ans -= a[n-1];
    ans %= MOD;
    while(ans < 0) ans += MOD;
    ans = (ans * fact[n]) % MOD;
    cout << ans << endl;


}