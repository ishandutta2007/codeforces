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
		if (!mod[v]) return;
		tree[v] += mod[v];
		if (vr - vl > 1) {
			mod[2 * v + 1] += mod[v];
			mod[2 * v + 2] += mod[v];
		}
		mod[v] = 0;
	}

	inline void add(int L, int R, int del) {
		add(0, 0, n, L, R, del);
	}

	void add(int v, int vl, int vr, int L, int R, int del) {
		push(v, vl, vr);
		if (R <= vl || vr <= L) return;
		if (L <= vl && vr <= R) {
			mod[v] += del;
			return;
		}
		int vm = (vl + vr) / 2;
		add(2 * v + 1, vl, vm, L, R, del);
		add(2 * v + 2, vm, vr, L, R, del);
		push(2 * v + 1, vl, vm);
		push(2 * v + 2, vm, vr);
		tree[v] = min(tree[2 * v + 1], tree[2 * v + 2]);
	}

	inline int get(int L, int R) {
		return get(0, 0, n, L, R);
	}

	int get(int v, int vl, int vr, int L, int R) {
		push(v, vl, vr);
		if (R <= vl || vr <= L) return 1e9;
		if (L <= vl && vr <= R) return tree[v];
		int vm = (vl + vr) / 2;
		return min(get(2 * v + 1, vl, vm, L, R), get(2 * v + 2, vm, vr, L, R));
	}
};

signed main() {
	ios::sync_with_stdio(false);
	cin.tie(0), cout.tie(0);

	int n, k, m;
	cin >> n >> k >> m;
	k--;

	set<pair<int, int>> now;
	multiset<int, greater<int>> poses;
	segment_tree tree(2 * n);
	for (int i = 0; i < 2 * n; i++) {
		tree.add(i, i + 1, n - i);
	}

	while (m--) {
		int x, y;
		cin >> x >> y;
		x--, y--;
		int pos = y + abs(x - k);
		if (now.count({x, y})) {
			now.erase({x, y});
			poses.erase(poses.find(pos));
			tree.add(0, pos + 1, 1);
		} else {
			now.insert({x, y});
			poses.insert(pos);
			tree.add(0, pos + 1, -1);
		}
		cout << (poses.size() ? -min(0, tree.get(0, *poses.begin() + 1)) : 0) << '\n';
	}
}