#include <bits/stdc++.h>

using namespace std;
using ll = long long;

struct fenwik {
	int n;
	vector<ll> bit;

	inline void resize(int n_) {
		n = n_;
		bit.resize(n + 1);
	}

	inline ll get(int pos) {
		ll res = 0;
		for (pos++; pos > 0; pos -= pos & -pos) {
			res += bit[pos];
		}
		return res;
	}

	inline void add(int L, int R, ll del) {
		add(L, del);
		add(R, -del);
	}

	inline void add(int pos, ll del) {
		for (pos++; pos <= n; pos += pos & -pos) {
			bit[pos] += del;
		}
	}
};

fenwik bit;
vector<vector<int>> g;
vector<vector<pair<int, ll>>>queries;
vector<ll> ans;

void dfs(int v, int pr, int dep) {
	for (auto [d, x] : queries[v]) {
		bit.add(dep, dep + d + 1, x);
	}

	ans[v] = bit.get(dep);

	for (auto u : g[v]) {
		if (u != pr) {
			dfs(u, v, dep + 1);
		}
	}

	for (auto [d, x] : queries[v]) {
		bit.add(dep, dep + d + 1, -x);
	}
}

signed main() {
	ios::sync_with_stdio(false);
	cin.tie(0), cout.tie(0);

	int n;
	cin >> n;
	g.resize(n);
	for (int i = 1; i < n; i++) {
		int v, u;
		cin >> v >> u;
		v--, u--;
		g[v].push_back(u);
		g[u].push_back(v);
	}

	int q;
	cin >> q;
	queries.resize(n);
	while (q--) {
		int v, d;
		ll x;
		cin >> v >> d >> x;
		v--;
		queries[v].emplace_back(d, x);
	}

	bit.resize(n);
	ans.resize(n);

	dfs(0, 0, 0);

	for (auto el : ans) {
		cout << el << ' ';
	}
}