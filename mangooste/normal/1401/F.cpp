#include <bits/stdc++.h>
using namespace std;

struct fenwik {
	int n;
	vector<int> bit;

	fenwik(int n = 0) : n(n) {
		bit.resize(n + 1);
	}

	void increase(int pos) {
		for (pos++; pos <= n; pos += pos & -pos)
			bit[pos]++;
	}

	int get(int pos) {
		int sum = 0;
		for (pos++; pos; pos -= pos & -pos)
			sum += bit[pos];
		return sum;
	}
};

struct segmentTree {
	int p2, n;
	vector<int64_t> tree;
	fenwik mod;

	segmentTree(int k) : p2(k), n(1 << k) {
		tree.resize(2 * n);
		mod = fenwik(k);
	}

	void change(int pos, int64_t newVal) {
		change(0, 0, n, pos, newVal, 0);
	}

	void change(int v, int vl, int vr, int pos, int64_t newVal, int dep) {
		if (pos < vl || vr <= pos)
			return;
		if (vr - vl == 1) {
			tree[v] = newVal;
			return;
		}

		int vm = (vl + vr) / 2;
		bool rev = mod.get(dep) % 2;
		change(2 * v + 1 + rev, vl, vm, pos, newVal, dep + 1);
		change(2 * v + 2 - rev, vm, vr, pos, newVal, dep + 1);

		tree[v] = tree[2 * v + 1] + tree[2 * v + 2];
	}

	void reverse(int k) {
		mod.increase(p2 - k);
	}

	int64_t get(int L, int R) {
		return get(0, 0, n, L, R, 0);
	}

	int64_t get(int v, int vl, int vr, int L, int R, int dep) {
		if (R <= vl || vr <= L)
			return 0;
		if (L <= vl && vr <= R)
			return tree[v];

		int vm = (vl + vr) / 2;
		bool rev = mod.get(dep) % 2;
		return get(2 * v + 1 + rev, vl, vm, L, R, dep + 1) + get(2 * v + 2 - rev, vm, vr, L, R, dep + 1);
	}
};

signed main() {
	ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);

	int n, q; cin >> n >> q;
	segmentTree tree(n);
	for (int i = 0; i < (1 << n); i++) {
		int x; cin >> x;
		tree.change(i, x);
	}

	while (q--) {
		int tp; cin >> tp;
		if (tp == 4) {
			int L, R; cin >> L >> R, L--;
			cout << tree.get(L, R) << '\n';
		} else if (tp == 1) {
			int pos; int64_t newVal; cin >> pos >> newVal, pos--;
			tree.change(pos, newVal);
		} else {
			int k; cin >> k;
			tree.reverse(k);
			if (tp == 3)
				tree.reverse(k + 1);
		}

		// cout << "tree =";
		// for (int i = 0; i < (1 << n); i++)
		// 	cout << ' ' << tree.get(i, i + 1);
		// cout << endl;
	}
}