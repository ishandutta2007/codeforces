#include <bits/stdc++.h>
using namespace std;
typedef long long LL;

vector<vector<int> > edges;
const LL MOD = 998244353;
struct dp {
	int a, b, c;
};
dp solve(int v, int p){
	vector<LL> matched;
	vector<LL> unmatched;
	vector<LL> unused;
	for(int a : edges[v]){
		if(a == p) continue;
		dp x = solve(a, v);
		matched.push_back(x.a);
		unmatched.push_back(x.b);
		unused.push_back(x.c);
	}
	int k = matched.size();
	dp x;
	x.a = 1;
	x.b = 0;
	x.c = 1;
	if(k == 0) return x;
	for(int i = 0; i < k; i++){
		x.a = (x.a * (unmatched[i] + unused[i])) % MOD;
	}
	for(int i = 0; i < k; i++){
		x.c = (x.c * (unused[i])) % MOD;
	}
	vector<LL> left_prod(k);
	vector<LL> right_prod(k);
	left_prod[0] = 1;
	right_prod[k-1] = 1;
	for(int i = 1; i < k; i++){
		left_prod[i] = (left_prod[i-1] * (unmatched[i-1] + unused[i-1])) % MOD;
	}
	for(int i = k-2; i >= 0; i--){
		right_prod[i] = (right_prod[i+1] * (unmatched[i+1] + unused[i+1])) % MOD;
	}
	for(int i = 0; i < k; i++){
		LL z = left_prod[i] * right_prod[i];
		z %= MOD;
		z = (z * matched[i]) % MOD;
		x.b = (x.b + z) % MOD;
	}
	x.c = (x.c + x.b) % MOD;
	return x;
}

int main(){
	int n;
	cin >> n;
	edges.resize(n);
	for(int i = 0; i < n-1; i++){
		int a, b;
		cin >> a >> b;
		a--; b--; 
		edges[a].push_back(b);
		edges[b].push_back(a);
	}
	LL ans = solve(0, -1).c;
	ans %= MOD;
	if(ans < 0) ans += MOD;
	cout << ans << '\n';
}