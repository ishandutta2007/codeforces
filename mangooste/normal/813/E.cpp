#include <bits/stdc++.h>

using namespace std;
using ll = long long;

struct segment_tree {
	int n;
	vector<vector<int>> tree;

	inline void build(vector<int> &a) {
		n = a.size();
		tree.resize(4 * n);
		build(0, 0, n, a);
	}

	void build(int v, int vl, int vr, vector<int> &a) {
		if (vr - vl == 1) {
			tree[v] = {a[vl]};
			return;
		}
		int vm = (vl + vr) / 2;
		build(2 * v + 1, vl, vm, a);
		build(2 * v + 2, vm, vr, a);
		tree[v].resize(vr - vl);
		merge(tree[2 * v + 1].begin(), tree[2 * v + 1].end(), tree[2 * v + 2].begin(), tree[2 * v + 2].end(), tree[v].begin());
	}

	inline int get(int L, int R, int val) {
		return get(0, 0, n, L, R, val);
	}

	int get(int v, int vl, int vr, int L, int R, int val) {
		if (R <= vl || vr <= L) {
			return 0;
		}
		if (L <= vl && vr <= R) {
			return lower_bound(tree[v].begin(), tree[v].end(), val) - tree[v].begin();
		}
		int vm = (vl + vr) / 2;
		return get(2 * v + 1, vl, vm, L, R, val) + get(2 * v + 2, vm, vr, L, R, val);
	}
};

const int MAXA = 100001;

signed main() {
	ios::sync_with_stdio(false);
	cin.tie(0), cout.tie(0);

	int n, k;
	cin >> n >> k;
	vector<vector<int>> where(MAXA);
	for (int i = 0; i < n; i++) {
		int x;
		cin >> x;
		where[x].push_back(i);
	}

	vector<int> left(n);
	for (int x = 0; x < MAXA; x++) {
		for (int i = 0; i < where[x].size(); i++) {
			left[where[x][i]] = (i < k ? -1 : where[x][i - k]);
		}
	}

	segment_tree tree;
	tree.build(left);

	int last = 0, q;
	cin >> q;
	while (q--) {
		int L, R;
		cin >> L >> R;
		L = (L + last) % n;
		R = (R + last) % n;
		if (L > R) {
			swap(L, R);
		}

		last = tree.get(L, R + 1, L);
		cout << last << '\n';
	}
}