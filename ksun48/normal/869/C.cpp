#include <bits/stdc++.h>
using namespace std;
typedef long long LL;

#define MOD 998244353
#define MAXN 25000

LL powmod(LL a, LL n){
	if(n == 0) return 1;
	if(n % 2) return (a*powmod(a,n-1)) % MOD;
	LL c = powmod(a, n/2);
	return (c*c) % MOD;
}
LL inv(LL a){
	return powmod(a, MOD-2);
}
LL fact[MAXN];
LL invfact[MAXN];
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
	for(LL i = 1; i < MAXN; i++){
		fact[i] = (i*fact[i-1]) % MOD;
		invfact[i] = inv(fact[i]);
	}	
}

LL solve(LL a, LL b){
	LL ans = 0;
	for(int i = 0; i <= a && i <= b; i++){
		LL cur = ncr(a,i) * ncr(b,i);
		cur %= MOD;
		cur = (cur * fact[i]) % MOD;
		ans = (ans + cur) % MOD;
	}
	return ans % MOD;
}
int main(){
	init();
	LL a, b, c;
	cin >> a >> b >> c;
	LL ans = 1;
	ans = (ans * solve(a,b)) % MOD;
	ans = (ans * solve(a,c)) % MOD;
	ans = (ans * solve(b,c)) % MOD;
	cout << ans << endl;
}