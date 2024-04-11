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
typedef long long ll;
#define Fi first
#define Se second
#define pb(x) push_back(x)
#define sz(x) ((int)(x).size())
#define rep(i, n) for(int i=0;i<n;i++)
#define all(x) (x).begin(), (x).end()
typedef tuple<int, int, int> t3;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef long double ldouble;
typedef pair<double, double> pdd;

int n, m;
struct edge{
	edge(){}
	edge(int x, int y, int l, int c):x(x), y(y), l(l), c(c){}
	int x, y, l, c;
	bool operator<(const edge &rhs) const{
		return l < rhs.l;
	}
} E[200020];
int ans[200020];
int p[200020];
int Find(int x) { return p[x] == x ? x : p[x] = Find(p[x]); }

vector <t3> T[200020];	//des, l, idx

int dep[200020];
int up[200020][20];
int upl[200020][20];

void dfs1(int x, int fa) {
	for(t3 e : T[x]) {
		int u = get<0>(e);
		if(u == fa) continue;
		up[u][0] = x; upl[u][0] = get<1>(e);
		for(int i=1;i<20;i++) {
			up[u][i] = up[ up[u][i-1] ][i-1];
			upl[u][i] = max(upl[u][i-1], upl[ up[u][i-1] ][i-1]);
		}
		dep[u] = dep[x] + 1;
		dfs1(u, x);
		
	}
}

int lca(int x, int y) {
	if(dep[x] < dep[y]) swap(x, y);
	rep(i, 20) if(1<<i & (dep[x] - dep[y])) x = up[x][i];
	for(int i=19;i>=0;i--) if(up[x][i] != up[y][i]) x = up[x][i], y = up[y][i];
	return x == y ? x : up[x][0];
}

vector <int> VI[200020], VD[200020];

int get_max(int x, int y, int L) {
	int lc = lca(x, y);
	VI[x].pb(L);
	VI[y].pb(L);
	VD[lc].pb(L);
	VD[lc].pb(L);
	int res = -1e9;
	rep(i, 20) if(1<<i & (dep[x] - dep[lc])) res = max(res, upl[x][i]), x = up[x][i];
	rep(i, 20) if(1<<i & (dep[y] - dep[lc])) res = max(res, upl[y][i]), y = up[y][i];
	return res;
}

int is_t[200020];
multiset <int> S[200020]; int idx[200020];

void dfs2(int x, int fa, int ue) {
	for(t3 e : T[x]) {
		int u = get<0>(e);
		if(u == fa) continue;
		dfs2(u, x, get<2>(e));
		if(sz(S[idx[x]]) > sz(S[idx[u]])) {
			for(int e : S[idx[u]]) S[idx[x]].insert(e);
		}
		else {
			for(int e : S[idx[x]]) S[idx[u]].insert(e);
			idx[x] = idx[u];
		}
	}
	for(int e : VI[x]) {
		S[idx[x]].insert(e);
	}
	for(int e : VD[x]) {
		S[idx[x]].erase(S[idx[x]].find(e));
	}
	if(sz(S[idx[x]])) {
		ans[ue] = *S[idx[x]].begin() - 1;
	}
}

void solve(){
	scanf("%d%d", &n, &m);
	rep(i, m) {
		int x, y, z; scanf("%d%d%d", &x, &y, &z);
		E[i] = edge(x, y, z, i);
	}
	
	sort(E, E+m);
	for(int i=1;i<=n;i++) p[i] = i;
	rep(i, m) {
		int x = E[i].x, y = E[i].y;
		x = Find(x), y = Find(y);
		if(x != y) {
			p[x] = y;
			T[E[i].x].pb(t3(E[i].y, E[i].l, E[i].c));
			T[E[i].y].pb(t3(E[i].x, E[i].l, E[i].c));
			is_t[E[i].c] = 1;
		}
	}
	
	dfs1(1, -1);
	rep(i, m) {
		if(is_t[E[i].c] == 0) {
			int x = E[i].x, y = E[i].y;
			ans[E[i].c] = get_max(x, y, E[i].l) - 1;
		}
		else ans[E[i].c] = -1;
	}
	for(int i=1;i<=n;i++) idx[i] = i;
	dfs2(1, -1, -1);
	
	rep(i, m) printf("%d ", ans[i]); puts("");
}

int main(){
	int Tc = 1; // scanf("%d\n", &Tc);
	for(int tc=1;tc<=Tc;tc++){
		// printf("Case #%d: ", tc);
		solve();
	}
	return 0;
};