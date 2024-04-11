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
#include <map>
#include <queue>

using namespace std;

#define vec vector
#define ALL(x) (x).begin(), (x).end()
#define mp make_pair
#define mt make_tuple

#define info(x) cerr << #x << " = " << x << endl

typedef long double ld;
typedef long long ll;
typedef unsigned long long ull;
typedef pair< int, int > pii;

const int inf = 1000000000;
const ll inf64 = 1ll * inf * inf;
const double pi = acos(-1.0);

int n, m;
vec< vec< int > > g;

void read() {
	scanf("%d %d", &n, &m);
	g.resize(n + 1);
	for(int u, v, i = 0;i < n - 1;i++) {
		scanf("%d %d", &u, &v);
		g[u].push_back(v);
		g[v].push_back(u);
	}
}

const int LOG = 21;
vec< int > p[LOG], h, c;
vec< ll > s, spa, cpa;

void dfs(int v, int par = -1, int H = 0) {
	p[0][v] = par;
	h[v] = H;
	c[v] = 1;
	for(auto to : g[v]) {
		if(to == par) continue;
		dfs(to, v, H + 1);
		c[v] += c[to];
		s[v] += c[to] + s[to];
	}
}

void go(int v, int par = -1, ll cp = 0, ll sp = 0) {
	cpa[v] = cp;
	spa[v] = sp;
	for(auto to : g[v]) {
		if(to == par) continue;
		go(to, v, c[v] - c[to] + cp, s[v] - s[to] - c[to] + sp + cp);
	}
}

void precalc() {
	for(int i = 0;i < LOG;i++) {
		p[i].resize(n + 1, -1);
	}

	h.resize(n + 1);
	c.resize(n + 1);
	s.resize(n + 1);
	spa.resize(n + 1);
	cpa.resize(n + 1);

	dfs(1);
	go(1);

	for(int i = 1;i < LOG;i++) {
		for(int j = 1;j <= n;j++) {
			int x = p[i - 1][j];
			if(x != -1) p[i][j] = p[i - 1][x];
		}
	} 
}

int lca(int x, int y) {
	if(h[x] < h[y]) swap(x, y);
	for(int i = LOG - 1;i >= 0;i--) {
		int px = p[i][x];
		if(px == -1 || h[px] < h[y]) continue;
		x = px;
	}
	for(int i = LOG - 1;i >= 0;i--) {
		int px = p[i][x];
		int py = p[i][y];
		if(px == -1 || py == -1 || px == py) continue;
		x = px;
		y = py;
	}
	if(x != y) x = p[0][x];
	return x;
}

int get(int u, int v) {
	for(int i = LOG - 1;i >= 0;i--) {
		int pv = p[i][v];
		if(pv == -1 || h[pv] < h[u] + 1) continue;
		v = pv;
	}
	return v;
}

bool solve() {

	read();
	precalc();

	cout.precision(10);
	cout << fixed;

	for(int u, v, q;m;m--) {
		scanf("%d %d", &u, &v);	
		if(h[u] > h[v]) swap(u, v);
		q = lca(u, v);
		ll c1, c2, s1, s2, d;
		d = h[u] - h[q] + h[v] - h[q];
		if(u != q) {
			c1 = c[u];
			c2 = c[v];
			s1 = s[u];
			s2 = s[v];
		}else {
			c1 = c[u] - c[get(u, v)] + cpa[u];
			c2 = c[v];
			s1 = s[u] - s[get(u, v)] - c[get(u, v)] + cpa[u] + spa[u];
			s2 = s[v];
		}

		/*info(d);
		info(c1);
		info(c2);
		info(s1);
		info(s2);*/

		printf("%.10lf\n", double(s1 * c2 + s2 * c1 + d * c1 * c2 + c1 * c2) / double(c1 * c2));
	}

	return true;
}

int main() {

	//while(solve());
	solve();
	
	return 0;
}