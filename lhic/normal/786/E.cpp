#include <iostream>
#include <fstream>
#include <set>
#include <map>
#include <string>
#include <vector>
#include <bitset>
#include <algorithm>
#include <cstring>
#include <cstdlib>
#include <cmath>
#include <cassert>
#include <queue>

#define mp make_pair
#define pb push_back


typedef long long ll;
typedef long double ld;

using namespace std;

const int MAXN = 21000;
const int LOG = 15;
const int MAXXXX = 2 * LOG * MAXN;
int n, m;
vector<pair<int, int> > eds[MAXN];
int was[MAXXXX];
int tin[MAXN];
int tout[MAXN];
int h[MAXN];
int up[LOG][MAXN];
int upv[LOG][MAXN];
int tm;
int cc;
int dd[MAXXXX];
int pp[MAXXXX];
struct edge {
	int a, b, c, f;
};

vector<int> edd[MAXXXX];
vector<edge> ed;
int s, t;

void add_edge(int a, int b, int c) {
	edge x;
	x.a = a, x.b = b, x.c = c, x.f = 0;
	edd[a].push_back(ed.size());
	ed.push_back(x);
	swap(x.a, x.b);
	x.c = 0;
	edd[b].push_back(ed.size());
	ed.push_back(x);
}

int is_p(int a, int b) {
	return (tin[a] <= tin[b] && tin[b] < tout[a]);
}

int lca(int a, int b) {
	if (is_p(a, b))
		return a;
	if (is_p(b, a))
		return b;
	for (int i = LOG - 1; i >= 0; --i) {
		if (!is_p(up[i][a], b))
			a = up[i][a];
	}
	return up[0][a];
}

void dfs0(int v, int hh) {
	h[v] = hh;
	tin[v] = tm++;
	was[v] = 1;
	for (auto e: eds[v]) {
		int u = e.first;
		if (was[u])
			continue;
		up[0][u] = v;
		upv[0][u] = e.second;
		dfs0(u, hh + 1);
	}
	tout[v] = tm;
}


void build() {
	dfs0(0, 0);
	cc = n - 1;
	for (int i = 1; i < LOG; ++i) {
		for (int v = 0; v < n; ++v) {
			if ((1 << i) <= h[v]) {
				up[i][v] = up[i - 1][up[i - 1][v]];
				upv[i][v] = cc++;
				add_edge(upv[i][v], upv[i - 1][v], (1 << (i - 1)) + 1);
				add_edge(upv[i][v], upv[i - 1][up[i - 1][v]], (1 << (i - 1)) + 1);
			}
		}
	}
}

void add(int a, int b, int nm) {
	int k = 0;
	int l = h[a] - h[b];
	if (l == 0)
		return;
	while ((1 << (k + 1)) <= l)
		++k;
	int lst = l - (1 << k);
	add_edge(nm, upv[k][a], 1);
	if (lst == 0)
		return;
	for (int i = LOG - 1; i >= 0; --i)
		if ((1 << i) <= lst)
			lst -= (1 << i), a = up[i][a];
	add_edge(nm, upv[k][a], 1);
}


void dfs1(int v) {
	was[v] = 1;
	for (int e: edd[v]) {
		if (ed[e].c == ed[e].f || was[ed[e].b])
			continue;
		dfs1(ed[e].b);
	}
}

int dfsd(int v, int fl) {
	int ans = 0;
	if (v == t)
		return fl;
	if (dd[v] >= dd[t])
		return 0;
	for (; pp[v] < edd[v].size(); ++pp[v]) {
		int e = edd[v][pp[v]];
		int u = ed[e].b;
		int go = ed[e].c - ed[e].f;
		if (dd[u] != dd[v] + 1)
			continue;
		go = dfsd(u, min(fl, go));
		fl -= go;
		ans += go;
		ed[e].f += go;
		ed[e ^ 1].f -= go;
		if (fl == 0)
			return ans;
	}
	return ans;
}

const int INF = 1e8;
queue<int> qu;

int dinic() {
	fill(dd, dd + t + 1, INF);
	qu.push(s);
	dd[s] = 0;
	while (!qu.empty()) {
		int x = qu.front();
		qu.pop();
		for (int e: edd[x]) {
			if (ed[e].f == ed[e].c || dd[ed[e].b] <= dd[x] + 1)
				continue;
			dd[ed[e].b] = dd[x] + 1;
			qu.push(ed[e].b);
		}
	}
	if (dd[t] == INF)
		return 0;
	memset(pp, 0, sizeof(pp[0]) * (t + 1));
	return dfsd(s, INF);
}

int flow() {
	int ans = 0;
	while (true) {
		int x = dinic();
		if (x == 0)
			break;
		ans += x;
	}
	return ans;
}

int main() {
	scanf("%d%d", &n, &m);
	for (int i = 0; i < n - 1; ++i) {
		int a, b;
		scanf("%d%d", &a, &b);
		--a, --b;
		eds[a].push_back(make_pair(b, i));
		eds[b].push_back(make_pair(a, i));
	}
	build();
	for (int i = 0; i < m; ++i) {
		int x, y;
		scanf("%d%d", &x, &y);
		--x, --y;
		int l = lca(x, y);
		add(x, l, i + cc);
		add(y, l, i + cc);
	}
	s = cc + m;
	t = cc + m + 1;
	for (int i = 0; i < n - 1; ++i)
		add_edge(i, t, 1);
	for (int i = 0; i < m; ++i)
		add_edge(s, i + cc, 1);
	int x = flow();
	cout << x << "\n";
	memset(was, 0, sizeof(was));
	dfs1(s);
	vector<int> vv;
	for (int i = 0; i < m; ++i)
		if (!was[cc + i])
			vv.push_back(i);
	cout << vv.size() << " ";
	for (int i: vv)
		cout << i + 1 << " ";
	cout << "\n";
	vv.clear();
	for (int i = 0; i < n - 1; ++i)
		if (was[i])
			vv.push_back(i);
	cout << vv.size() << " ";
	for (int i: vv)
		cout << i + 1 << " ";
	cout << "\n";
	return 0;
}