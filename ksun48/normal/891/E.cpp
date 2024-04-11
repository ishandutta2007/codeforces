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
    for(LL i = 1; i < 11000; i++){
        fact[i] = (i*fact[i-1]) % MOD;
        invfact[i] = inv(fact[i]);
    }
}

int main(){
    init();
    LL n, k;
    cin >> n >> k;
    LL a[n];
    for(LL i = 0; i < n; i++){
        cin >> a[i];
        a[i] = -a[i];
    }
    vector<LL> symsums(n+1, 0);
    symsums[0] = 1;

    LL ans = 0;

    for(LL i = 0; i < n; i++){
        vector<LL> newsums(n+1,0);
        for(int j = 0; j < n; j++){
            newsums[j+1] += symsums[j];
            newsums[j] += (symsums[j] * a[i]) % MOD;
            newsums[j+1] %= MOD;
            newsums[j] %= MOD;
        }
        symsums = newsums;
    }
    reverse(symsums.begin(), symsums.end());

    LL st = 1;
    for(LL a = 0; a < n; a++){
        if(a+1 > k) break;

        LL cur = a+1;
        cur *= symsums[n-1-a];
        cur %= MOD;
        cur *= inv(powmod(n,a));
        cur %= MOD;
        cur *= fact[a];
        cur %= MOD;

        st = (st * (k-a)) % MOD;
        st = (st * inv(a+1)) % MOD;

        ans += (cur * st) % MOD;
        ans %= MOD;
    }

    ans *= inv(n);
    if(n % 2 == 0) ans *= -1;
    ans %= MOD;
    while(ans < 0) ans += MOD;
    cout << ans << endl;

}