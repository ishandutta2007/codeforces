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

vector<vector<int> > edges;
LL ans = 0;
LL pfree(LL v, LL p){
	LL prob = 1;
	for(LL a : edges[v]){
		if(a == p) continue;
		LL ans = (pfree(a, v) * inv2) % MOD;
		prob = (prob * (1-ans)) % MOD;
	}
	ans += 2*(1-prob);
	ans %= MOD;
	return prob;
}
int main(){
	cin.sync_with_stdio(0); cin.tie(0);
	int n;
	cin >> n;
	edges.resize(n);
	for(int i = 0; i < n-1; i++){
		int u, v;
		cin >> u >> v;
		u--; v--;
		edges[u].push_back(v);
		edges[v].push_back(u);
	}
	init();
	pfree(0 ,-1);
	ans = (ans * powmod(2, n-1)) % MOD;
	if(ans < 0) ans += MOD;
	cout << ans << '\n';
}