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
#define sz(x) ((int)(x).size())
#define rep(i, n) for(int i=0;i<n;i++)
#define all(x) (x).begin(), (x).end()
typedef tuple<int, int, int> t3;
typedef pair<ll, ll> pll;
typedef long double ldouble;
typedef pair<double, double> pdd;

int N, M;
int par[200010];

namespace dtree{
	const int MAXN = 200010;
	vector <int> E[MAXN];
	vector <int> RE[MAXN], rdom[MAXN];
	
	int S[MAXN], RS[MAXN], cs;
	int par[MAXN], val[MAXN];
	int sdom[MAXN], rp[MAXN];
	int dom[MAXN];
	
	int Find(int x, int c = 0) {
		if(par[x] == x) return c ? -1 : x;
		int p = Find(par[x], 1);
		if(p == -1) return c ? par[x] : val[x];
		if(sdom[val[x]] > sdom[val[par[x]]]) val[x] = val[par[x]];
		par[x] = p;
		return c ? p : val[x];
	}
	
	void Union(int x, int y) {
		par[x] = y;
	}
	
	void dfs(int x) {
		RS[ S[x] = ++cs ] = x;
		par[cs] = sdom[cs] = val[cs] = cs;
		for(int e : E[x]) {
			if(S[e] == 0) dfs(e), rp[S[e]] = S[x];
			RE[S[e]].pb(S[x]);
		}
	}
	
	int Do(int s, int *up) {
		dfs(s);
		for(int i=cs;i;i--) {
			for(int e : RE[i]) sdom[i] = min(sdom[i], sdom[Find(e)]);
			if(i > 1) rdom[sdom[i]].pb(i);
			for(int e : rdom[i]) {
				int p = Find(e);
				if(sdom[p] == i) dom[e] = i;
				else dom[e] = p;
			}
			if(i > 1) Union(i, rp[i]);
		}
		for(int i=2;i<=cs;i++) if(sdom[i] != dom[i]) dom[i] = dom[dom[i]];
		for(int i=2;i<=cs;i++) {
			up[RS[i]] = RS[dom[i]];
		}
		return cs;
	}
	
	void addE(int x, int y) {
		E[x].pb(y);
	}
}

int down[200010];
vector <int> E[200010];
vector <pii> TE[200020];
ll ans;
void dfs(int x) {
	down[x] = 1;
	for(int e : E[x]) {
		dfs(e);
		down[x] += down[e];
	}
}

void solve(){
	int n, m, s;
	scanf("%d%d%d", &n, &m, &s);
	rep(i, m) {
		int x, y, z; scanf("%d%d%d", &x, &y, &z);
		TE[x].pb(pii(z, y));
		TE[y].pb(pii(z, x));
	}
	priority_queue <pll, vector<pll>, greater<pll> > pq;
	ll dis[200020];
	for(int i=1;i<=n;i++) dis[i] = 1e18;
	dis[s] = 0; pq.push(pll(0, s));
	while(!pq.empty()) {
		pll t = pq.top(); pq.pop();
		if(dis[t.Se] != t.Fi) continue;
		for(pii e : TE[t.Se]) {
			if(t.Fi + e.Fi < dis[e.Se]) {
				dis[e.Se] = t.Fi + e.Fi;
				pq.push(pll(dis[e.Se], e.Se));
			}
		}
	}
	for(int i=1;i<=n;i++) for(pii e : TE[i]) {
		if(dis[i] + e.Fi == dis[e.Se]) dtree::addE(i, e.Se);
	}
	dtree::Do(s, par);
	for(int i=1;i<=n;i++) if(i != s) E[par[i]].pb(i);
	dfs(s);
	int ans = 0;
	for(int i=1;i<=n;i++) if(i != s) ans = max(ans, down[i]);
	printf("%d\n", ans);
}

int main(){
	int Tc = 1; //scanf("%d", &Tc);
	for(int tc=1;tc<=Tc;tc++){
		//printf("Case #%d\n", tc);
		solve();
	}
	return 0;
};