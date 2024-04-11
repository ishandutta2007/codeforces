#include <bits/stdc++.h>

using namespace std;
using ll = long long;

struct DSU {
	int n, ans;
	vector<int> par, col, change, def;
	vector<vector<int>> els;
	vector<array<int, 2>> val;

	DSU(int n = 0) : n(n), ans(0) {
		par.resize(n);
		iota(par.begin(), par.end(), 0);
		els.resize(n);
		for (int i = 0; i < n; i++) {
			els[i] = {i};
		}
		val.resize(n, {1, 0});
		col.resize(n);
		change.resize(n);
		def.resize(n);
	}

	int get_par(int v) {
		return par[v] == v ? v : par[v] = get_par(par[v]);
	}

	inline int get_val(int root) {
		return def[root] ? val[root][!change[root]] : min(val[root][0], val[root][1]);
	}

	inline void change_col(int v, int new_col) {
		int vv = get_par(v);
		ans -= get_val(vv);
		if (col[v] ^ change[vv] != new_col) {
			change[vv] = 1;
		}
		def[vv] = 1;
		ans += get_val(vv);
	}

	inline int get_size(int root) {
		return val[root][0] + val[root][1];
	}

	inline void unite(int v, int u, int type) {
		int vv = get_par(v);
		int uu = get_par(u);
		if (vv == uu) {
			return;
		}
		if (get_size(vv) < get_size(uu)) {
			swap(u, v);
			swap(uu, vv);
		}

		ans -= get_val(vv);
		ans -= get_val(uu);
		int v_col = col[v] ^ change[vv];
		int u_col = col[u] ^ change[uu];
		if ((v_col != u_col) ^ type) {
			if (def[uu]) {
				change[vv] ^= 1;
			} else {
				change[uu] ^= 1;
			}
		}
		def[vv] |= def[uu];

		while (els[uu].size()) {
			int el = els[uu].back();
			els[uu].pop_back();
			col[el] ^= change[uu] ^ change[vv];
			els[vv].push_back(el);
			val[vv][col[el]]++;
		}
		par[uu] = vv;
		ans += get_val(vv);
	}
};

signed main() {
	ios::sync_with_stdio(false);
	cin.tie(0), cout.tie(0);

	int n, k;
	string s;
	cin >> n >> k >> s;
	vector<vector<int>> where(n);
	for (int i = 0; i < k; i++) {
		int m;
		cin >> m;
		for (int j = 0; j < m; j++) {
			int pos;
			cin >> pos;
			where[pos - 1].push_back(i);
		}
	}

	DSU dsu(k);
	for (int i = 0; i < n; i++) {
		if (where[i].size() == 1) {
			dsu.change_col(where[i][0], s[i] == '0');
		} else if (where[i].size() == 2) {
			dsu.unite(where[i][0], where[i][1], s[i] == '0');
		}
		cout << dsu.ans << '\n';
	}
}