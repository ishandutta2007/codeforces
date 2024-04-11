#include <iostream>
#include <vector>
#include <algorithm>
#include <time.h>
#include <set>
#include <string>
#include <tuple>
#include <fstream>
#include <stdio.h>
#include <cstring>

using namespace std;

#define vec vector
#define ALL(x) (x).begin(), (x).end()
#define mp make_pair
#define mt make_tuple

typedef long double ld;
typedef long long ll;
typedef unsigned long long ull;
typedef pair< int, int > pii;

const int inf = 1000000000;
const ll inf64 = 1ll * inf * inf;
const double pi = acos(-1.0);

struct Dsu {
	int n;
	vec< int > par, size;
	
	Dsu() {
		n = 0;
		par.clear();
		size.clear();
	}

	Dsu(int _n) : n(_n) {
		par.resize(n);
		size.resize(n);
		for(int i = 0;i < n;i++) {
			par[i] = i;
			size[i] = 1;
		}
	}

	int find(int x) {
		return (x == par[x]?x : par[x] = find(par[x]));
	}

	void merge(int u, int v) {
		int pu = find(u);
		int pv = find(v);
		if(pu == pv) return;
		if(size[pu] == size[pv]) {
			par[pv] = pu;
			size[pu]++;
		}else {
			if(size[pu] < size[pv]) swap(pu, pv);
			par[pv] = pu;
		}
	}
};

// Graph

int n, m;
ll S = 0;
vec< tuple< int, int, int, int > > edge; 
// {w, u, v, id}

// MST
vec< vec< int > > g;

const int LOG = 21;
vec< int > p[LOG], mx[LOG], h;

int get_to(int x, int id) {
	int u, v;
	tie(ignore, u, v, ignore) = edge[id];
	return (u == x?v : u);
}

int get_weight(int id) {
	int w;
	tie(w, ignore, ignore, ignore) = edge[id];
	return w;
}

void precalc_dfs(int v, int par = -1) {
	for(auto id : g[v]) {
		int to = get_to(v, id);
		if(to == par) continue;
		h[to] = h[v] + 1;
		p[0][to] = v;
		mx[0][to] = get_weight(id);
		precalc_dfs(to, v);
	}
}

void precalc() {
	for(int i = 0;i < LOG;i++)
		p[i].resize(n, -1), 
		mx[i].resize(n, -inf);
	h.resize(n);
	precalc_dfs(0);
	for(int i = 1;i < LOG;i++) {
		for(int j = 0;j < n;j++) {
			int x = p[i - 1][j];
			if(x != -1) { 
				p[i][j] = p[i - 1][x];
				mx[i][j] = max(mx[i - 1][j], mx[i - 1][x]);
			}else mx[i][j] = max(mx[i][j], mx[i - 1][j]);
		}
	}
}

int lca(int u, int v) {
	if(h[u] < h[v]) swap(u, v);
	for(int i = LOG - 1;i >= 0;i--) {
		if(p[i][u] == -1 || h[p[i][u]] < h[v]) continue;
		u = p[i][u];
	}
	for(int i = LOG - 1;i >= 0;i--) {
		if(p[i][u] == -1 || p[i][v] == -1 || p[i][u] == p[i][v]) continue;
		u = p[i][u];
		v = p[i][v];
	}
	if(u != v) u = p[0][u];
	return u;
}

int ask(int s, int f) {
	int ans = -inf;
	for(int i = LOG - 1;i >= 0;i--) {
		if(p[i][s] == -1 || h[p[i][s]] < h[f]) continue;
		ans = max(ans, mx[i][s]);
		s = p[i][s];
	}
	return ans;
}

bool solve() {
	
	cin >> n >> m;

	for(int u, v, w, i = 0;i < m;i++) {
		cin >> u >> v >> w;
		u--, v--;
		edge.push_back(mt(w, u, v, i));
	}

	sort(ALL(edge));
	g.resize(n);

	Dsu dsu(n);

	for(int i = 0;i < m;i++) {
		int u, v, w, id;
		tie(w, u, v, id) = edge[i];
		if(dsu.find(u) != dsu.find(v)) {
			dsu.merge(u, v);
			g[u].push_back(i);
			g[v].push_back(i);
			S += w;
		}
	}
	
	precalc();

	vec< ll > answer(m);

	for(auto it : edge) {
		int w, u, v, id, z, tmp;
		tie(w, u, v, id) = it;
		z = lca(u, v);
		tmp = max(ask(u, z), ask(v, z));
		answer[id] = S - tmp + w;
	}
	
	for(auto i : answer) cout << i << "\n";

	return true;
}

int main() {

	//while(solve());
	solve();
	
	return 0;
}