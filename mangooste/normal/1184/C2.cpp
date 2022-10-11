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

	void push(int v, int vl, int vr) {
		if (!mod[v])
			return;
		tree[v] += mod[v];
		if (vr - vl > 1) {
			mod[2 * v + 1] += mod[v];
			mod[2 * v + 2] += mod[v];
		}
		mod[v] = 0;
	}

	int get() {
		push(0, 0, n);
		return tree[0];
	}

	void add(int L, int R, int del) {
		add(0, 0, n, L, R, del);
	}

	void add(int v, int vl, int vr, int L, int R, int del) {
		push(v, vl, vr);
		if (R <= vl || vr <= L)
			return;
		if (L <= vl && vr <= R) {
			mod[v] += del;
			return;
		}
		int vm = (vl + vr) / 2;
		add(2 * v + 1, vl, vm, L, R, del);
		add(2 * v + 2, vm, vr, L, R, del);

		push(2 * v + 1, vl, vm);
		push(2 * v + 2, vm, vr);
		tree[v] = max(tree[2 * v + 1], tree[2 * v + 2]);
	}
};

struct event {
	int x, type, ly, ry;
};

signed main() {
	ios::sync_with_stdio(false);
	cin.tie(0), cout.tie(0);

	int n, r;
	cin >> n >> r;
	vector<int> xs(n), ys(n);
	for (int i = 0; i < n; i++) {
		int x, y;
		cin >> x >> y;
		xs[i] = x - y;
		ys[i] = x + y;
	}

	int mn_y = *min_element(ys.begin(), ys.end());
	for (int i = 0; i < n; i++)
		ys[i] -= mn_y - r;

	// cout << r << '\n';
	// for (int i = 0; i < n; i++)
	// 	cout << '(' << xs[i] << ' ' << ys[i] << ")\n";

	vector<event> evs;
	for (int i = 0; i < n; i++) {
		evs.push_back({xs[i] - r, 0, ys[i] - r, ys[i] + r});
		evs.push_back({xs[i] + r, 1, ys[i] - r, ys[i] + r});
	}

	sort(evs.begin(), evs.end(), [](event &a, event &b) {
		return pair<int, int>{a.x, a.type} < pair<int, int>{b.x, b.type};
	});

	segment_tree tree(*max_element(ys.begin(), ys.end()) + 1 + r);
	int ans = 1;
	for (auto ev : evs) {
		tree.add(ev.ly, ev.ry + 1, 1 - 2 * ev.type);
		ans = max(ans, tree.get());
	}
	cout << ans << '\n';
}