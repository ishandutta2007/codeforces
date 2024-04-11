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
LL fact[1100000];
LL invfact[1100000];
LL pow3[1100000];
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
    pow3[0] = 1;
    for(LL i = 1; i < 1100000; i++){
        fact[i] = (i*fact[i-1]) % MOD;
        invfact[i] = inv(fact[i]);
        pow3[i] = (pow3[i-1] * 3) % MOD;
    }
}

int main(){
	cin.sync_with_stdio(0); cin.tie(0);
	init();
	LL n;
	cin >> n;
	LL ans = 0;
	for(LL k = 1; k <= n; k++){
		LL r = ncr(n,k);
		if(k % 2) r = -r;
		LL g = (pow3[k] - 3) * powmod(3, n*(n-k));
		g %= MOD;
		g += 3 * powmod(pow3[n-k]-1, n);
		g %= MOD;
		ans += (r * g) % MOD;
		ans %= MOD;
	}
	ans += powmod(pow3[n]-3, n);
	ans = powmod(3, n*n) - ans;
	ans %= MOD;
	if(ans < 0) ans += MOD;
	cout << ans << '\n';
}