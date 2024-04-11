#include <bits/stdc++.h>

using namespace std;
using ll = long long;

struct segment_tree {
	int n;
	vector<int> tree, mod;

	segment_tree(int n = 0) : n(n) {
		tree.resize(4 * n);
		mod.resize(4 * n);
	}

	inline void push(int v, int vl, int vr) {
		tree[v] += mod[v];
		if (vr - vl > 1) {
			mod[2 * v + 1] += mod[v];
			mod[2 * v + 2] += mod[v];
		}
		mod[v] = 0;
	}

	inline void add(int L, int R, int delta) {
		add(0, 0, n, L, R, delta);
	}

	void add(int v, int vl, int vr, int L, int R, int delta) {
		push(v, vl, vr);
		if (R <= vl || vr <= L) {
			return;
		}
		if (L <= vl && vr <= R) {
			mod[v] += delta;
			return;
		}
		int vm = (vl + vr) / 2;
		add(2 * v + 1, vl, vm, L, R, delta);
		add(2 * v + 2, vm, vr, L, R, delta);
		push(2 * v + 1, vl, vm);
		push(2 * v + 2, vm, vr);
		tree[v] = max(tree[2 * v + 1], tree[2 * v + 2]);
	}

	inline int get(int L, int R) {
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
		return max(get(2 * v + 1, vl, vm, L, R), get(2 * v + 2, vm, vr, L, R));
	}
};

const int INF = 1e9;

signed main() {
	ios::sync_with_stdio(false);
	cin.tie(0), cout.tie(0);

	int n, k;
	cin >> n >> k;
	vector<int> a(n);
	for (int i = 0; i < n; i++) {
		cin >> a[i];
		a[i]--;
	}
	a.insert(a.begin(), 0);

	vector<segment_tree> trees(k + 1, segment_tree(n + 1));
	for (int i = 0; i <= k; i++) {
		trees[i].add(i == 0, n + 1, -INF);
	}
	vector<int> now(n, 0);
	for (int i = 1; i <= n; i++) {
		for (int j = 0; j < k; j++) {
			trees[j].add(now[a[i]], i, 1);
		}
		now[a[i]] = i;
		for (int j = 1; j <= k; j++) {
			int val = trees[j - 1].get(0, i);
			if (val > 0) {
				trees[j].add(i, i + 1, INF + val);
			}
		}
	}
	cout << trees[k].get(n, n + 1) << '\n';
}