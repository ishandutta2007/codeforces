#include <bits/stdc++.h>

using namespace std;

using ll = long long;

struct Data {
	ll mn, mx;
	ll pref, suf;
	ll ans;
	void modify(ll add) {
		mn += add;
		mx += add;
		pref -= add;
		suf -= add; 
	}
	friend Data operator + (const Data &l, const Data &r) {
		Data ans;
		ans.mn = min(l.mn, r.mn);
		ans.mx = max(l.mx, r.mx);
		ans.pref = max(l.mx - 2 * r.mn, max(l.pref, r.pref));
		ans.suf = max(-2 * l.mn + r.mx, max(l.suf, r.suf));
		ans.ans = max(max(l.ans, r.ans), max(l.mx + r.suf, l.pref + r.mx));
		return ans;
	}
};

const int N = 200100;

Data t[N << 2];
ll lz[N << 2];

void push(int v, int l, int r) {
	if (lz[v]) {
		t[v].modify(lz[v]);
		if (l < r) {
			lz[v << 1] += lz[v];
			lz[v << 1 | 1] += lz[v];
		}
		lz[v] = 0;
	}
}

void add(int v, int l, int r, int L, int R, ll w) {
	push(v, l, r);
	if (L > r || R < l) return;
	if (L <= l && r <= R) {
		lz[v] = w;
		push(v, l, r);
		return;
	}
	int md = (l + r) >> 1;
	add(v << 1, l, md, L, R, w);
	add(v << 1 | 1, md + 1, r, L, R, w);
	t[v] = t[v << 1] + t[v << 1 | 1];
}

int n, q;
ll maxw, w[N];
int to[N];
vector<pair<int, int>> g[N];
int tin[N], tout[N], tt;

void dfs(int u, int p) {
	tin[u] = ++tt;
	for (auto e : g[u]) {
		int v, id;
		tie(v, id) = e;
		if (v != p) {
			to[id] = v;
			dfs(v, u);
		}
	}
	tout[u] = ++tt;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin >> n >> q >> maxw;
	for (int i = 0; i < n - 1; ++i) {
		int u, v;
		cin >> u >> v >> w[i];
		g[u].emplace_back(v, i);
		g[v].emplace_back(u, i);
	}
	dfs(1, -1);
	for (int i = 0; i < n - 1; ++i) {
		int v = to[i];
		add(1, 1, 2 * n, tin[v], tout[v] - 1, w[i]);
	}
	ll last = 0;
	while (q--) {
		int id; ll nw;
		cin >> id >> nw;
		id = (id + last) % (n - 1);
		nw = (nw + last) % maxw;
		int v = to[id];
		add(1, 1, 2 * n, tin[v], tout[v] - 1, -w[id]);
		w[id] = nw;
		add(1, 1, 2 * n, tin[v], tout[v] - 1, w[id]);
		cout << (last = t[1].ans) << "\n";
	}
}