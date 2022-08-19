#include <bits/stdc++.h>
using namespace std;
typedef long long LL;

const LL MOD = 998244353;
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
void init(){
    fact[0] = 1;
    invfact[0] = 1;
    LL inv2 = inv(2);
    for(LL i = 1; i < 110000; i++){
        fact[i] = (i*fact[i-1]) % MOD;
        invfact[i] = inv(fact[i]);
    }
}

int main(){
	init();
	LL n, m, k;
	cin >> n >> m >> k;
	LL ans = m;
	ans = (ans * ncr(n-1, k)) % MOD;
	ans = (ans * powmod(m-1, k)) % MOD;
	if(ans < 0) ans += MOD;
	cout << ans << '\n';
}