#include <bits/stdc++.h>

using namespace std;
using ll = long long;

struct segment_tree {
	struct node {
		int sum, x, left, right;

		node(ll sum = 0, int x = 0, int left = -1, int right = -1)
			: sum(sum), x(x), left(left), right(right) {}
	};

	int n;
	vector<node> nodes;

	segment_tree(int n = 0) : n(n) {
		nodes.reserve(1e7);
		nodes.push_back(node());
	}

	inline void add_childrens(int v, int vl, int vr) {
		ll vm = (vl + vr) / 2;
		if (nodes[v].left == -1) {
			nodes[v].left = nodes.size();
			nodes.push_back(node());
		}
		if (nodes[v].right == -1) {
			nodes[v].right = nodes.size();
			nodes.push_back(node());
		}
	}

	inline void push(int v, int vl, int vr) {
		int vm = (vl + vr) / 2;
		if (nodes[v].sum == vr - vl && nodes[v].left != -1) {
			nodes[nodes[v].left].sum = vm - vl;
			nodes[nodes[v].right].sum = vr - vm;
			nodes[nodes[v].left].x = nodes[nodes[v].right].x = 0;
		}
		if (nodes[v].sum == 0 && nodes[v].left != -1) {
			nodes[nodes[v].left].sum = nodes[nodes[v].right].sum = 0;
			nodes[nodes[v].left].x = nodes[nodes[v].right].x = 0;
		}
		if (nodes[v].x) {
			nodes[v].sum = vr - vl - nodes[v].sum;
			if (nodes[v].left != -1) {
				nodes[nodes[v].left].x ^= 1;
				nodes[nodes[v].right].x ^= 1;
			}
		}
		nodes[v].x = 0;
	}

	inline void relax(int v, int vl, int vr) {
		int vm = (vl + vr) / 2;
		push(nodes[v].left, vl, vm);
		push(nodes[v].right, vm, vr);
		nodes[v].sum = nodes[nodes[v].left].sum + nodes[nodes[v].right].sum;
	}

	inline void update1(int L, int R, int type) {
		update1(0, 0, n, L, R, type);
	}

	void update1(int v, int vl, int vr, int L, int R, bool type) {
		if (R <= vl || vr <= L) {
			return;
		}
		if (L <= vl && vr <= R) {
			nodes[v].x = 0;
			nodes[v].sum = (type ? vr - vl : 0);
			return;
		}
		add_childrens(v, vl, vr);
		push(v, vl, vr);
		ll vm = (vl + vr) / 2;
		update1(nodes[v].left, vl, vm, L, R, type);
		update1(nodes[v].right, vm, vr, L, R, type);
		relax(v, vl, vr);
	}

	inline void update2(int L, int R) {
		update2(0, 0, n, L, R);
	}

	inline void update2(int v, int vl, int vr, int L, int R) {
		if (R <= vl || vr <= L) {
			return;
		}
		if (L <= vl && vr <= R) {
			nodes[v].x ^= 1;
			return;
		}
		add_childrens(v, vl, vr);
		push(v, vl, vr);
		int vm = (vl + vr) / 2;
		update2(nodes[v].left, vl, vm, L, R);
		update2(nodes[v].right, vm, vr, L, R);
		relax(v, vl, vr);
	}

	inline int get() {
		return get(0, 0, n);
	}

	int get(int v, int vl, int vr) {
		if ((nodes[v].x ? vr - vl - nodes[v].sum : nodes[v].sum) == vr - vl) {
			return -1;
		}
		if (vr - vl == 1) {
			return vl;
		}
		add_childrens(v, vl, vr);
		push(v, vl, vr);
		int vm = (vl + vr) / 2;
		int res = get(nodes[v].left, vl, vm);
		if (res == -1) {
			res = get(nodes[v].right, vm, vr);
		}
		return res;
	}
};

signed main() {
	ios::sync_with_stdio(false);
	cin.tie(0), cout.tie(0);

	int n;
	cin >> n;
	vector<array<ll, 3>> queries(n);
	vector<ll> mb = {1};
	for (auto &el : queries) {
		cin >> el[0] >> el[1] >> el[2];
		mb.push_back(el[1]);
		mb.push_back(el[2]);
		mb.push_back(el[2] + 1);
	}
	sort(mb.begin(), mb.end());
	mb.resize(unique(mb.begin(), mb.end()) - mb.begin());
	segment_tree tree(mb.size());
	for (auto el : queries) {
		ll t = el[0], L = el[1], R = el[2];
		int wl = lower_bound(mb.begin(), mb.end(), L) - mb.begin();
		int wr = lower_bound(mb.begin(), mb.end(), R) - mb.begin();
		if (t == 3) {
			tree.update2(wl, wr + 1);
		} else {
			tree.update1(wl, wr + 1, t == 1);
		}
		cout << mb[tree.get()] << '\n';
	}
}