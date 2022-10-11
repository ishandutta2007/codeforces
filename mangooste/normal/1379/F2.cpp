#include <bits/stdc++.h>

using namespace std;
using ll = long long;

struct segment_tree {
	struct node {
		bool ok;
		int mx, mn;

		node(bool ok = true, int mx = -1e9, int mn = 1e9) : ok(ok), mx(mx), mn(mn) {}

		node operator + (node n) {
			return node(ok && n.ok && mn > n.mx, max(mx, n.mx), min(mn, n.mn));
		}
	};

	int n;
	vector<node> tree;

	inline void resize(int n_) {
		n = n_;
		tree.resize(4 * n, node());
	}

	inline void update(int pos, pair<int, int> val) {
		update(0, 0, n, pos, val);
	}

	void update(int v, int vl, int vr, int pos, pair<int, int> val) {
		if (pos < vl || vr <= pos) {
			return;
		}
		if (vr - vl == 1) {
			tree[v].mx = val.second;
			tree[v].mn = val.first;
			tree[v].ok = (val.second < val.first);
			return;
		}
		int vm = (vl + vr) / 2;
		update(2 * v + 1, vl, vm, pos, val);
		update(2 * v + 2, vm, vr, pos, val);
		tree[v] = tree[2 * v + 1] + tree[2 * v + 2];
	}

	inline bool ok() {
		return tree[0].ok;
	}
};

signed main() {
	ios::sync_with_stdio(false);
	cin.tie(0), cout.tie(0);
	int n, m, q;
	cin >> n >> m >> q;
	segment_tree tree;
	tree.resize(n);
	array<vector<set<int>>, 2> all = {vector<set<int>>(n), vector<set<int>>(n)};
	while (q--) {
		int x, y;
		cin >> x >> y;
		int xx = (x - 1) / 2, yy = (y - 1) / 2;
		if (all[x % 2][xx].find(yy) == all[x % 2][xx].end()) {
			all[x % 2][xx].insert(yy);
		} else {
			all[x % 2][xx].erase(yy);
		}
		tree.update(xx, {all[1][xx].size() ? *all[1][xx].begin() : 1e9, all[0][xx].size() ? *all[0][xx].rbegin() : -1e9});
		cout << (tree.ok() ? "YES\n" : "NO\n");
	}
}