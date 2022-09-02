#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <memory.h>
#include <math.h>
#include <assert.h>
#include <queue>
#include <map>
#include <set>
#include <string>
#include <algorithm>
#include <iostream>
#include <functional>
#include <unordered_map>
#include <unordered_set>
#include <list>
#include <bitset>

using namespace std;
typedef pair<int, int> pii;
typedef long long ll;
#define Fi first
#define Se second
#define pb(x) push_back(x)
#define szz(x) ((int)(x).size())
#define rep(i, n) for(int i=0;i<n;i++)
#define all(x) (x).begin(), (x).end()
typedef tuple<int, int, int> t3;
typedef pair<ll, ll> pll;
typedef long double ldouble;
typedef pair<double, double> pdd;

int n;
ll V[200020];
vector <int> E[200020];
ll C[200020][2];
const int MOD = 1e9 + 7;

void pdfs(int x, int fa){
	C[x][0]++;
	for(int e : E[x]) if(e != fa) {
		pdfs(e, x);
		rep(u, 2) C[x][u] += C[e][!u];
	}
}

ll ans;

void dfs(int x, int fa, pll t) {
	if(fa != -1) {
		ll pl = -t.Fi * C[x][1] + t.Se * C[x][0];
		pl %= MOD; if(pl < 0) pl += MOD;
		ll vl = (V[x] - V[fa] + MOD) % MOD;
		ans = (ans + vl * pl) % MOD;
	}
	ll cnt = t.Se;
	pll r = t; swap(r.Fi, r.Se);
	for(int e : E[x]) if(e != fa) {
		r.Fi += C[e][1];
		r.Se += C[e][0];
		cnt += C[e][1];
	}
	++cnt;
	ans = (ans + V[x] * cnt) % MOD;
	for(int e : E[x]) if(e != fa) {
		pll rr = pll(r.Fi - C[e][1] + 1, r.Se - C[e][0]);
		dfs(e, x, rr);
	}
}

void solve() {
	scanf("%d", &n);
	for(int i=1;i<=n;i++) { scanf("%lld", V+i); if(V[i] < 0) V[i] += MOD; }
	rep(i, n-1) {
		int x, y; scanf("%d%d", &x, &y);
		E[x].pb(y);
		E[y].pb(x);
	}
	pdfs(1, -1);
	dfs(1, -1, pll(0, 0));
	printf("%lld\n", ans);
}

int main(){
	int Tc = 1; // scanf("%d\n", &Tc);
	for(int tc=1;tc<=Tc;tc++){
		solve();
	}
	return 0;
}