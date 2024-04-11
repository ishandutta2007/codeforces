#include <bits/stdc++.h>

using namespace std;
using ll = long long;

struct segment_tree {
	int n;
	vector<int> tree, mod;

	inline void resize(int n_) {
		n = n_;
		tree.resize(4 * n);
		mod.resize(4 * n);
	}

	inline void push(int v, int vl, int vr) {
		if (!mod[v]) {
			return;
		}
		tree[v] = vr - vl - tree[v];
		if (vr - vl > 1) {
			mod[2 * v + 1] ^= 1;
			mod[2 * v + 2] ^= 1;
		}
		mod[v] = 0;
	}

	void update(int L, int R) {
		update(0, 0, n, L, R);
	}

	void update(int v, int vl, int vr, int L, int R) {
		push(v, vl, vr);
		if (R <= vl || vr <= L) {
			return;
		}
		if (L <= vl && vr <= R) {
			mod[v] ^= 1;
			return;
		}
		int vm = (vl + vr) / 2;
		update(2 * v + 1, vl, vm, L, R);
		update(2 * v + 2, vm, vr, L, R);
		push(2 * v + 1, vl, vm);
		push(2 * v + 2, vm, vr);
		tree[v] = tree[2 * v + 1] + tree[2 * v + 2];
	}

	int get(int L, int R) {
		return get(0, 0, n, L, R);
	}

	int get(int v, int vl, int vr, int L, int R) {
		push(v, vl, vr);
		if (R <= vl || vr <= L) {
			return 0;
		}
		if (L <= vl && vr <= R) {
			return tree[v];
		}
		int vm = (vl + vr) / 2;
		return get(2 * v + 1, vl, vm, L, R) + get(2 * v + 2, vm, vr, L, R);
	}
};

const int LOG = 21;

vector<segment_tree> trees;

signed main() {
	ios::sync_with_stdio(false);
	cin.tie(0), cout.tie(0);
	int n;
	cin >> n;
	trees.resize(LOG);
	for (int i = 0; i < LOG; i++) {
		trees[i].resize(n);
	}
	for (int i = 0; i < n; i++) {
		int x;
		cin >> x;
		for (int j = 0; j < LOG; j++) {
			if ((x >> j) & 1) {
				trees[j].update(i, i + 1);
			}
		}
	}
	int q;
	cin >> q;
	while (q--) {
		int t, L, R;
		cin >> t >> L >> R;
		L--;
		if (t == 1) {
			ll res = 0;
			for (int i = 0; i < LOG; i++) {
				res += (ll)(1 << i) * trees[i].get(L, R);
			}
			cout << res << '\n';
		} else {
			int x;
			cin >> x;
			for (int i = 0; i < LOG; i++) {
				if ((x >> i) & 1) {
					trees[i].update(L, R);
				}
			}
		}
	}
}