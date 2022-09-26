#include <bits/stdc++.h>
using namespace std;

const int N = 200005;

int n, q;
vector<int> g[N];
int par[18][N], lev[N];
int le[N], ri[N], tot;
int cnt[N << 3], len[N << 3];
map<pair<int,int>, bool> ed;

void dfs(int u) {
	le[u] = ++tot;
	for (int i = 1; i <= 17; ++i) par[i][u] = par[i - 1][par[i - 1][u]];
	for (int v : g[u]) if (v != par[0][u]) {
		lev[v] = lev[u] + 1; par[0][v] = u; dfs(v);
	}
	ri[u] = tot;
}

void upd(int v,int l,int r,int L,int R,int val) {
	if (L > r || R < l) return;
	if (L <= l && R >= r) {
		cnt[v] += val;
		if (val == 1) len[v] = r - l + 1;
		else if (cnt[v] == 0) len[v] = len[v << 1] + len[v << 1 | 1];
		return;
	}
	int mid = l + r >> 1;
	upd(v << 1, l, mid, L, R, val);
	upd(v << 1 | 1, mid + 1, r, L, R, val);
	if (cnt[v] == 0) len[v] = len[v << 1] + len[v << 1 | 1];
}

int jump(int u,int dif) {
	int v = u;
	for (int i = 17; i >= 0; --i) if (dif & (1 << i)) {
		v = par[i][v];
	}
	return v;
}

void go(int u,int v,int val) {
	if (lev[u] > lev[v]) swap(u, v);
	if (le[u] > ri[v] || ri[u] < le[v]) {
		if (le[u] > le[v]) swap(u, v);
		upd(1, 1, n, 1, le[u] - 1, val);
		upd(1, 1, n, ri[u] + 1, le[v] - 1, val);
		upd(1, 1, n, ri[v] + 1, n, val);
	}
	else {
		int x = jump(v, lev[v] - lev[u] - 1);
		upd(1, 1, n, le[x], le[v] - 1, val);
		upd(1, 1, n, ri[v] + 1, ri[x], val);
	}
}

int main() {
	scanf("%d %d", &n, &q);
	for (int i = 2; i <= n; ++i) {
		int u, v; scanf("%d %d", &u, &v);
		g[u].push_back(v), g[v].push_back(u);
	}
	par[0][1] = 1; dfs(1);
	while (q--) {
		int u, v; scanf("%d %d", &u, &v);
		if (u > v) swap(u, v);
		if (ed[{u, v}]) {
			ed[{u, v}] = false; go(u, v, -1);
		}
		else {
			ed[{u, v}] = true; go(u, v, 1);
		}
		printf("%d\n", n - len[1]);
	}
}