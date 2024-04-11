#include <bits/stdc++.h>
#define pi pair<int, int>
#define x first
#define y second
#define i64 long long
#define mid ((l + r) >> 1)
#define lc (p + 1)
#define rc (p + ((mid - l + 1) << 1))
using namespace std;
const int N = 5e5 + 10;
const i64 oo = 0x3f3f3f3f3f3f3f3f;
struct scan {
	int l, r, id;
};
int n, Q, cost[N];
int L[N], R[N], dfc = 0;
vector<int> g[N];
vector<scan> q[N];
i64 dep[N], tag[N << 1], mn[N << 1], ans[N];

void upd(int p, int l, int r) {
	mn[p] = min(mn[lc], mn[rc]);
	return;
}

void pushd(int p, int l, int r) {
	if(!tag[p]) return;
	tag[lc] += tag[p], tag[rc] += tag[p];
	mn[lc] += tag[p], mn[rc] += tag[p];
	tag[p] = 0;
	return;
}

void change(int p, int l, int r, int L, int R, i64 v) {
	if(L > R) return;
	if(L <= l && r <= R) {
		mn[p] += v, tag[p] += v;
		return;
	}
	pushd(p, l, r);
	if(L <= mid) change(lc, l, mid, L, R, v);
	if(R > mid) change(rc, mid + 1, r, L, R, v);
	upd(p, l, r);
	return;
}
i64 query(int p, int l, int r, int L, int R) {
	if(L <= l && r <= R) {
		return mn[p];
	}
	pushd(p, l, r);
	i64 res = oo;
	if(L <= mid) res = min(res, query(lc, l, mid, L, R));
	if(R > mid) res = min(res, query(rc, mid + 1, r, L, R));
	return res;
}

void dfs(int u, int fa) {
	sort(g[u].begin(), g[u].end());
	L[u] = ++dfc;
	for(int &v : g[u]) dfs(v, u);
	R[u] = dfc;
	change(1, 1, n, L[u], R[u], cost[u]);
	if(!g[u].empty()) change(1, 1, n, L[u], L[u], oo);
	return;
}

void Dfs(int u, int fa) {
	change(1, 1, n, 1, n, cost[u]);
	change(1, 1, n, L[u], R[u], - 2 * cost[u]);
	for(scan &a : q[u]) {
		ans[a.id] = query(1, 1, n, a.l, a.r);
	}
	for(int &v : g[u]) Dfs(v, u);
	change(1, 1, n, 1, n, - cost[u]);
	change(1, 1, n, L[u], R[u], 2 * cost[u]);
	return;
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);
	cin >> n >> Q;
	for(int i = 2, fa; i <= n; i++) {
		cin >> fa >> cost[i];
		g[fa].push_back(i);
	}
	dfs(1, 0);
	for(int i = 1; i <= Q; i++) {
		int u, l, r;
		cin >> u >> l >> r;
		q[u].push_back(scan{l, r, i});
	}
	Dfs(1, 0);
	for(int i = 1; i <= Q; i++) cout << ans[i] << endl;
	return 0;
}