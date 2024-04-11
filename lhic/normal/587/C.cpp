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


typedef long long ll;
typedef long double ld;

using namespace std;


const int INF = 400000;
const int MAXN = 120000;
const int LOG = 20;

int rmq[MAXN * 4];
int up[LOG][MAXN];
int tin[MAXN];
int was[MAXN];
int tout[MAXN];
vector<int> eds[MAXN];

int p[MAXN];
int ggg[MAXN];
vector<int> vv;
vector<int> vv2;

int n, m, q;
int tm;
vector<int> gg[MAXN];
vector<int> go[MAXN];
int qq[MAXN];
int lc[MAXN];
vector<int> ans[MAXN];
int h[MAXN];

void dfs(int v) {
	tin[v] = tm++;
	was[v] = 1;
	for (int i = 0; i < (int)eds[v].size(); ++i) {
		int u = eds[v][i];
		if (!was[u])
			h[u] = h[v] + 1,p[u] = v, dfs(u);
	}
	tout[v] = tm++;
}

void initLca() {
	dfs(0);
	p[0] = 0;
	for (int i = 0; i < n; ++i)
		up[0][i] = p[i];
	for (int i = 1; i < LOG; ++i)
		for (int j = 0; j < n; ++j)
			up[i][j] = up[i - 1][up[i - 1][j]];
}

int is_p(int a, int b) {
	if (tin[a] <= tin[b] && tout[b] <= tout[a])
		return 1;
	else
		return 0;
}

int lca(int a, int b) {
	if (is_p(a, b))
		return a;
	if (is_p(b, a))
		return b;
	for (int i = LOG - 1; i >= 0; --i)
		if (!is_p(up[i][a], b))
			a = up[i][a];
	return p[a];
}

int get(int v, int tl, int tr, int l, int r) {
	if (r <= tl || tr <= l)
		return INF;
	if (l <= tl && tr <= r)
		return rmq[v];
	int m = (tl + tr) >> 1;
	return min(get(v * 2 + 1, tl, m, l, r), get(v * 2 + 2, m, tr, l, r));
}

void upd(int v, int tl, int tr, int x, int y) {
	if (tl + 1 == tr) {
		rmq[v] = y;
		return;
	}
	int m = (tl + tr) >> 1;
	if (x < m)
		upd(v * 2 + 1, tl, m, x, y);
	else
		upd(v * 2 + 2, m, tr, x, y);
	rmq[v] = min(rmq[v * 2 + 1], rmq[v * 2 + 2]);
}


void push(int v, int h) {
	upd(0, 0, m, (int)vv.size(), v);
	ggg[v] = vv.size();
	vv.push_back(h);
}

void pop() {
	vv.pop_back();
	upd(0, 0, m, (int)vv.size(), INF);
}

void get(int h, int q) {
	vv2.clear();
	int l = lower_bound(vv.begin(), vv.end(), h) - vv.begin();
	if (l == (int)vv.size())
		return;
	for (int i = 0; i < 10; ++i) {
		int x = get(0, 0, m, l, m);
		if (x == INF)
			break;
		ans[q].push_back(x);
		vv2.push_back(x);
		upd(0, 0, m, ggg[x], INF);
	}
	for (int i = 0; i < (int)vv2.size(); ++i)
		upd(0, 0, m, ggg[vv2[i]], vv2[i]);
}


void dfs2(int v) {
	was[v] = 1;
	for (int i = 0; i < (int)go[v].size(); ++i) {
		push(go[v][i], h[v]);
	}

	for (int i = 0; i < (int)gg[v].size(); ++i) {
		int q = gg[v][i];
		int x = lc[q];
		get(h[x], q);
	}

	for (int i = 0; i < (int)eds[v].size(); ++i) {
		int u = eds[v][i];
		if (!was[u])
			dfs2(u);
	}
	for (int i = 0; i < (int)go[v].size(); ++i)
		pop();
}

void build(int v, int tl, int tr) {
	rmq[v] = INF;
	if (tl + 1 == tr)
		return;
	int m = (tl + tr) >> 1;
	build(v * 2 + 1, tl, m);
	build(v * 2 + 2, m, tr);
}

int main() {
	scanf("%d%d%d", &n, &m, &q);
	for (int i = 0; i < n - 1; ++i) {
		int a, b;
		scanf("%d%d", &a, &b);
		--a;
		--b;
		eds[a].push_back(b);
		eds[b].push_back(a);
	}
	for (int i = 0; i < m; ++i) {
		int c;
		scanf("%d", &c);
		--c;
		go[c].push_back(i);
	}
	initLca();
	for (int i = 0; i < q; ++i) {
		int a, b, c;
		scanf("%d%d%d", &a, &b, &c);
		--a;
		--b;
		qq[i] = c;
		lc[i] = lca(a, b);
		gg[a].push_back(i);
		gg[b].push_back(i);
	}
	memset(was, 0, sizeof(was));
	build(0, 0, m);
	dfs2(0);
	for (int i = 0; i < q; ++i) {
		sort(ans[i].begin(), ans[i].end());
		ans[i].resize(unique(ans[i].begin(), ans[i].end()) - ans[i].begin());
		int k = min(qq[i], (int)ans[i].size());
		printf("%d ", k);
		for (int j = 0; j < k; ++j)
			printf("%d ", ans[i][j] + 1);
		printf("\n");
	}
	return 0;
}