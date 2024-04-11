#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
LL n1, n2, k;

const LL MOD = 998244353;

vector<LL> r;
vector<LL> edges[4100];
vector<LL> dfs(LL v, LL p){
	vector<LL> sum(k+1, 0);
	for(LL w : edges[v]){
		if(w != p){
			vector<LL> g = dfs(w, v);
			for(int j = 0; j <= k; j++){
				sum[j] += g[j];
				sum[j] %= MOD;
			}
		}
	}
	vector<LL> numcycles(k+1, 0);
	numcycles[0] = 1;

	vector<LL> cnt(k+1, 0);
	cnt[0] = 1;
	for(LL j = 1; j <= k; j++){
		for(LL r = 0; r + 2 <= j; r++){
			numcycles[j] += numcycles[j-r-2] * sum[r];
			numcycles[j] %= MOD;
		}
		for(LL r = 0; r + 2 <= j; r++){
			if(r + 2 == j){
				cnt[j] += (r+2) * sum[r];
				cnt[j] %= MOD;
			} else {
				cnt[j] += cnt[j-r-2] * sum[r];
				cnt[j] %= MOD;
			}
		}
	}
	for(LL j = 0; j <= k; j++){
		r[j] += cnt[j];
		r[j] %= MOD;
	}
	return numcycles;
}
vector<LL> solve(LL n){
	r.clear();
	r.resize(k+1, 0);
	for(int i = 0; i < n; i++){
		edges[i].clear();
	}
	for(int i = 0; i < n-1; i++){
		LL a, b;
		cin >> a >> b;
		a--; b--;
		edges[a].push_back(b);
		edges[b].push_back(a);
	}
	dfs(0, -1);
	return r;
}

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
	cin >> n1 >> n2 >> k;
	vector<LL> ans1 = solve(n1);
	vector<LL> ans2 = solve(n2);
	LL ans = 0;
	for(LL f = 0; f <= k; f++){
		LL g = (ans1[f] * ans2[k-f]) % MOD;
		g = (g * ncr(k, f)) % MOD;
		ans = (ans + g) % MOD;
	}
	cout << ans << endl;
}