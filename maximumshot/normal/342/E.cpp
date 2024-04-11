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
#include <bitset>

using namespace std;

#define vec vector
#define ALL(x) (x).begin(), (x).end()
#define mp make_pair
#define mt make_tuple

typedef long double ld;
typedef long long ll;
typedef unsigned long long ull;
typedef pair< int, int > pii;

const int inf = 1000 * 1000 * 1000;
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

vec< int > clist, lvl, dp, lnk;

void go(int v, int par = -1) {
	dp[v] = 1;
	for(int to : g[v]) {
		if(to == par) continue;
		if(lvl[to] != -1) continue;
		go(to, v);
		dp[v] += dp[to];
	}
}

void find_center(int v, int size, int & center, int par = -1) {
	int mx = size - dp[v];
	for(int to : g[v]) {
		if(to == par) continue;
		if(lvl[to] != -1) continue;
		mx = max(mx, dp[to]);
		find_center(to, size, center, v);
	}
	if(mx <= size / 2) {
		if(center == -1) center = v;
	}
}

void show(int v, int par = -1) {
	cout << "dp[ " << v << " ] = " << dp[v] << "\n";
	for(int to : g[v]) {
		if(to == par) continue;
		if(lvl[to] != -1) continue;
		show(to, v);
	}
}

void build(int v = 1, int cid = 0, int last = -1) {
	int center = -1, sz;
	go(v);
	//cout << v << " last = " << last << ", lvl = " << cid << " : \n";
	//show(v);
	find_center(v, dp[v], center);
	//cout << "center = " << center << "\n\n";
	lnk[center] = last;
	lvl[center] = cid;
	for(int to : g[center]) {
		if(lvl[to] != -1) continue;
		build(to, cid + 1, center);	
	}
}

void build_centr_dec() {
	
	lvl.resize(n + 1, -1);
	dp.resize(n + 1);
	lnk.resize(n + 1);
	build();

}

const int LOG = 21;
vec< int > p[LOG], h;

void DFS(int v = 1, int par = -1, int H = 0) {
	h[v] = H;
	p[0][v] = par;
	for(int to : g[v]) {
		if(to != par) DFS(to, v, H + 1);
	}
}

void build_dist() {
	
	for(int i = 0;i < LOG;i++) p[i].resize(n + 1, -1);
	h.resize(n + 1);

	DFS();

	for(int i = 1;i < LOG;i++) {
		for(int j = 1;j <= n;j++) {
			int x = p[i - 1][j];
			if(x != -1) p[i][j] = p[i - 1][x];
		}
	}
}

int lca(int u, int v) {
	if(h[u] < h[v]) swap(u, v);
	for(int i = LOG - 1;i >= 0;i--) {
		int pu = p[i][u];
		if(pu == -1 || h[pu] < h[v]) continue;
		u = pu;
	}
	for(int i = LOG - 1;i >= 0;i--) {
		int pu, pv;
		pu = p[i][u];
		pv = p[i][v];
		if(pu == -1 || pv == -1 || pu == pv) continue;
		u = pu;
		v = pv;
	}
	if(u != v) u = p[0][u];
	return u;
}

int get_dist(int u, int v) {
	return h[u] + h[v] - 2 * h[lca(u, v)];
}

vec< int > ans;

void upd(int v) {
	for(int u = v;u != -1;u = lnk[u]) {
		ans[u] = min(ans[u], get_dist(u, v));
	}
}

int get(int v) {
	int res = inf;
	for(int u = v;u != -1;u = lnk[u]) {
		res = min(res, ans[u] + get_dist(u, v));
	}
	return res;
}

bool solve() {
	
	read();
	build_centr_dec();
	build_dist();

	ans.resize(n + 1, inf);

	upd(1);

	for(int ty, v;m;m--) {
		scanf("%d %d", &ty, &v);
		if(ty == 1) {
			upd(v);
		}else {
			printf("%d\n", get(v));
		}
	}

	return true;
}

int main() {

	//while(solve());
	solve();	
	
	return 0;
}