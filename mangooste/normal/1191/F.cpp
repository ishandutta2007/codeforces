#include <bits/stdc++.h>

using namespace std;

struct Segment_tree {
	int n;
	vector<int> tree;

	Segment_tree(int n = 0) : n(n) {
		tree.resize(4 * n);
	}

	inline void insert(int x) {
		insert(0, 0, n, x);
	}

	void insert(int v, int vl, int vr, int x) {
		if (x < vl || vr <= x)
			return;
		if (vr - vl == 1) {
			tree[v] = 1;
			return;
		}
		int vm = (vl + vr) / 2;
		insert(2 * v + 1, vl, vm, x);
		insert(2 * v + 2, vm, vr, x);
		tree[v] = tree[2 * v + 1] + tree[2 * v + 2];
	}

	inline int get_sum(int L, int R) {
		return get_sum(0, 0, n, L, R);
	}

	int get_sum(int v, int vl, int vr, int L, int R) {
		if (R <= vl || vr <= L)
			return 0;
		if (L <= vl && vr <= R)
			return tree[v];
		int vm = (vl + vr) / 2;
		return get_sum(2 * v + 1, vl, vm, L, R) + get_sum(2 * v + 2, vm, vr, L, R);
	}
};

inline void compress(vector<int> &a) {
	vector<int> vals = a;
	sort(vals.begin(), vals.end());
	vals.resize(unique(vals.begin(), vals.end()) - vals.begin());
	for (auto &x : a)
		x = (int) (lower_bound(vals.begin(), vals.end(), x) - vals.begin());
	assert(*max_element(a.begin(), a.end()) < (int) a.size());
}

signed main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int n;
	cin >> n;
	vector<int> x(n);
	vector<int> y(n);
	for (int i = 0; i < n; i++)
		cin >> x[i] >> y[i];
	compress(x);
	compress(y);
	vector<vector<int>> same_y(n);
	for (int i = 0; i < n; i++)
		same_y[y[i]].push_back(x[i]);
	for (auto &xs : same_y)
		sort(xs.begin(), xs.end());

	Segment_tree tree(n);
	long long ans = 0;
	for (int y = n - 1; y >= 0; y--) {
		vector<int> now = same_y[y];
		for (int i = 0; i < (int) now.size(); i++) {
			int y = now[i];
			tree.insert(y);
			int right = tree.get_sum(y, i == (int) now.size() - 1 ? n : now[i + 1]);
			int left = tree.get_sum(0, y + 1);
			ans += (long long) right * left;
		}
	}
	cout << ans << '\n';
}