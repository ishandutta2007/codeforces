#include <bits/stdc++.h>

using namespace std;
using ll = long long;

struct segment_tree {
	int n;
	vector<pair<int, int>> tree;

	inline void build(vector<int> &vals) {
		n = vals.size();
		tree.resize(4 * n);
		build(0, 0, n, vals);
	}

	void build(int v, int vl, int vr, vector<int> &vals) {
		if (vr - vl == 1) {
			tree[v] = {vals[vl], vl};
			return;
		}
		int vm = (vl + vr) / 2;
		build(2 * v + 1, vl, vm, vals);
		build(2 * v + 2, vm, vr, vals);
		tree[v] = max(tree[2 * v + 1], tree[2 * v + 2]);
	}

	inline pair<int, int> get(int L, int R) {
		return get(0, 0, n, L, R);
	}

	pair<int, int> get(int v, int vl, int vr, int L, int R) {
		if (R <= vl || vr <= L) {
			return {-1, -1};
		}
		if (L <= vl && vr <= R) {
			return tree[v];
		}
		int vm = (vl + vr) / 2;
		return max(get(2 * v + 1, vl, vm, L, R), get(2 * v + 2, vm, vr, L, R));
	}
};

const int MAXN = 500004;
const int LOG = 21;

signed main() {
	ios::sync_with_stdio(false);
	cin.tie(0), cout.tie(0);

	int n, m;
	cin >> n >> m;
	vector<int> to(MAXN, -1);
	for (int i = 0; i < n; i++) {
		int L, R;
		cin >> L >> R;
		to[L] = max(to[L], R);
	}

	segment_tree tree;
	tree.build(to);

	vector<vector<int>> next(LOG, vector<int>(MAXN));
	for (int i = 0; i < MAXN; i++) {
		if (to[i] != -1) {
			auto [R, where] = tree.get(0, to[i] + 1);
			next[0][i] = (R == to[i] ? i : where);
		}
	}

	for (int level = 1; level < LOG; level++) {
		for (int i = 0; i < MAXN; i++) {
			next[level][i] = next[level - 1][next[level - 1][i]];
		}
	}

	while (m--) {
		int L, R;
		cin >> L >> R;

		int pos = tree.get(0, L + 1).second;

		int ans = 1;
		for (int level = LOG - 1; ~level; level--) {
			if (to[next[level][pos]] < R) {
				ans += (1 << level);
				pos = next[level][pos];
			}
		}
		if (to[pos] < R) {
			ans++;
			pos = next[0][pos];
		}

		cout << (to[pos] >= R ? ans : -1) << '\n';
	}
}