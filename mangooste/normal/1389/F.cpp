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
			return -1;
		}
		if (L <= vl && vr <= R) {
			return tree[v];
		}

		int vm = (vl + vr) / 2;
		return max(get(2 * v + 1, vl, vm, L, R), get(2 * v + 2, vm, vr, L, R));
	}
};

signed main() {
	ios::sync_with_stdio(false);
	cin.tie(0), cout.tie(0);

	int n;
	cin >> n;
	vector<int> L(n), R(n), t(n);
	for (int i = 0; i < n; i++) {
		cin >> L[i] >> R[i] >> t[i];
		t[i]--;
	}

	vector<int> vals;
	for (int i = 0; i < n; i++) {
		vals.push_back(L[i]);
		vals.push_back(R[i]);
	}

	sort(vals.begin(), vals.end());
	vals.resize(unique(vals.begin(), vals.end()) - vals.begin());

	for (int i = 0; i < n; i++) {
		L[i] = lower_bound(vals.begin(), vals.end(), L[i]) - vals.begin() + 1;
		R[i] = lower_bound(vals.begin(), vals.end(), R[i]) - vals.begin() + 1;
	}

	array<vector<vector<int>>, 2> events;
	events[0] = events[1] = vector<vector<int>>(2 * n + 1);

	for (int i = 0; i < n; i++) {
		events[t[i]][R[i]].push_back(L[i]);
	}

	array<segment_tree, 2> dp;
	dp[0] = dp[1] = segment_tree(2 * n + 1);

	int ans = 0;
	for (int i = 1; i <= 2 * n; i++) {
		for (int t = 0; t < 2; t++) {
			for (auto L_add : events[t][i]) {
				dp[t ^ 1].add(0, L_add, 1);
			}
		}

		for (int t = 0; t < 2; t++) {
			int val = dp[t ^ 1].get(0, i);
			ans = max(ans, val);
			dp[t].add(i, i + 1, val);
		}
	}

	cout << ans << '\n';
}