#include <bits/stdc++.h>
using namespace std;

const int N = 1e5 + 5;
const int inf = 2e9;

int n, q;
vector<int> g[N];
int le[N], ri[N];
int child[N], root[N], par[N];
int tot = 0;

void dfs(int u) {
	child[u] = 1;
	for (int v : g[u]) {
		par[v] = u, dfs(v);
		child[u] += child[v];
	}
}

void hld(int u, bool ok) {
	if (ok) root[u] = u;
	else root[u] = root[par[u]];
	le[u] = ++tot;
	int bigChild = 0;
	for (int v : g[u]) {
		if (child[v] > child[bigChild]) bigChild = v;
	}
	if (bigChild) hld(bigChild, 0);
	for (int v : g[u]) if (v != bigChild) {
		hld(v, 1);
	}
	ri[u] = tot;
}

struct node {
	int sum, mx;
	node(int sum = -inf, int mx = -inf) : sum(sum), mx(mx) {}
};

node merge(node L, node R) {
	if (L.sum == -inf) return R;
	if (R.sum == -inf) return L;
	node ret;
	ret.sum = L.sum + R.sum;
	ret.mx = max(R.mx, L.mx + R.sum);
	return ret;
}

node t[N << 2];
bool lz[N << 2];

void build(int v,int l,int r) {
	if (l == r) {
		t[v] = node(-1, -1);
		return;
	}
	int mid = l + r >> 1;
	build(v << 1, l, mid);
	build(v << 1 | 1, mid + 1, r);
	t[v] = merge(t[v << 1], t[v << 1 | 1]);
}

void push(int v,int l,int r) {
	if (!lz[v]) return;
	t[v] = node(-(r - l + 1), -1);
	if (l < r) {
		lz[v << 1] = 1;
		lz[v << 1 | 1] = 1;
	}
	lz[v] = 0;
}

void upd(int v,int l,int r,int L,int R) {
	push(v, l, r);
	if (L > r || R < l) return;
	if (L <= l && R >= r) {
		lz[v] = 1; push(v, l, r);
		return;
	}
	int mid = l + r >> 1;
	upd(v << 1, l, mid, L, R);
	upd(v << 1 | 1, mid + 1, r, L, R);
	t[v] = merge(t[v << 1], t[v << 1 | 1]);
}

void upd_pos(int v,int l,int r,int pos,int val) {
	push(v, l, r);
	if (pos > r || pos < l) return;
	if (l == r) {
		t[v].sum += val, t[v].mx += val;
		return;
	} 
	int mid = l + r >> 1;
	upd_pos(v << 1, l, mid, pos, val);
	upd_pos(v << 1 | 1, mid + 1, r, pos, val);
	t[v] = merge(t[v << 1], t[v << 1 | 1]);
}

node get(int v,int l,int r,int L,int R) {
	push(v, l, r);
	if (L > r || R < l) return node();
	if (L <= l && R >= r) return t[v];
	int mid = l + r >> 1;
	return merge(get(v << 1, l, mid, L, R), get(v << 1 | 1, mid + 1, r, L, R));
} 

node get(int v) {
	node ret = node();
	while (root[v] != 1) {
		ret = merge(get(1, 1, n, le[root[v]], le[v]), ret);
		v = par[root[v]];
	}
	ret = merge(get(1, 1, n, 1, le[v]), ret);
	return ret;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin >> n >> q;
	for (int i = 2; i <= n; ++i) {
		int p; cin >> p;
		g[p].push_back(i);
	}
	dfs(1), hld(1, 1);
	build(1, 1, n);
	while (q--) {
		int t, v; cin >> t >> v;
		if (t == 1) {
			upd_pos(1, 1, n, le[v], 1);
		}
		else if (t == 2) {
			upd(1, 1, n, le[v], ri[v]);
			node cur = get(v);
			if (cur.mx >= 0) upd_pos(1, 1, n, le[v], -cur.mx - 1); 
		}
		else {
			node cur = get(v);
			cout << (cur.mx < 0 ? "white" : "black") << '\n';
 		}
	}
}