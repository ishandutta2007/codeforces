#include <bits/stdc++.h>

using namespace std;

template<class T>
string to_string(T v);

string to_string(string s) {
	return "\"" + s + "\"";
}

string to_string(bool b) {
	return b ? "true" : "false";
}

template<class A, class B>
string to_string(pair<A, B> p) {
	return "(" + to_string(p.first) + ", " + to_string(p.second) + ")";
}

template<class T>
string to_string(T v) {
	string s = "{";
	bool first = true;
	for (auto x : v) {
		if (!first)
			s += ", ";
		first = false;
		s += to_string(x);
	}
	return s + "}";
}

void debug_out() { cerr << endl; }
template<class Head, class... Tail>
void debug_out(Head head, Tail... tail) {
	cerr << ' ' << to_string(head);
	debug_out(tail...);
}

#ifdef LOCAL
#define debug(...) cerr << '[' << #__VA_ARGS__ << "]:", debug_out(__VA_ARGS__)
#else
#define debug(...)
#endif

const int INF = (int) 1e9;

struct Segment_tree {
	struct Node {
		int mn;
		int cnt;

		Node(int mn = INF, int cnt = 0) : mn(mn), cnt(cnt) {}

		Node operator + (Node n) {
			Node res;
			res.mn = min(mn, n.mn);
			res.cnt = 0;
			if (mn == res.mn)
				res.cnt += cnt;
			if (n.mn == res.mn)
				res.cnt += n.cnt;
			assert(res.mn >= 0);
			return res;
		}
	};

	int n;
	vector<Node> tree;
	vector<int> mod;

	Segment_tree(int n = 1, int all_values = INF) : n(n) {
		tree.resize(4 * n);
		mod.resize(4 * n);
		build(0, 0, n, all_values);
	}

	void build(int v, int vl, int vr, int all_values) {
		tree[v] = Node(all_values, vr - vl);
		if (vr - vl == 1)
			return;
		int vm = (vl + vr) / 2;
		build(2 * v + 1, vl, vm, all_values);
		build(2 * v + 2, vm, vr, all_values);
	}

	void push(int v, int vl, int vr) {
		if (mod[v] == 0)
			return;
		tree[v].mn += mod[v];
		if (vr - vl > 1) {
			mod[2 * v + 1] += mod[v];
			mod[2 * v + 2] += mod[v];
		}
		mod[v] = 0;
	}

	void add(int L, int R, int del) {
		add(0, 0, n, L, R, del);
	}

	void add(int v, int vl, int vr, int L, int R, int del) {
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
		tree[v] = tree[2 * v + 1] + tree[2 * v + 2];
	}

	int get() {
		push(0, 0, n);
		return tree[0].mn == 0 ? tree[0].cnt : 0;
	}
};

signed main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr), cout.tie(nullptr);

	int n;
	cin >> n;
	vector<vector<int>> poses(n);
	vector<int> a(n);
	for (int i = 0; i < n; i++) {
		cin >> a[i];
		a[i]--;
		poses[a[i]].push_back(i);
	}
	vector<int> now(n, INF);
	Segment_tree tree(n, 0);

	auto update = [&](int pos, bool delete_mod) {
		int val = now[pos];
		assert(val >= pos);
		tree.add(pos, val, (delete_mod ? -1 : 1));
	};

	auto change = [&](int pos, int new_val) {
		update(pos, true);
		now[pos] = new_val;
		update(pos, false);
	};

	for (int i = 0; i < n; i++)
		update(i, false);
	for (int i = 0; i < n; i++)
		if ((int) poses[i].size() > 2) {
			array<int, 3> p{poses[i][0], poses[i][1], poses[i][2]};
			change(p[0], p[2]);
			change(p[1], p[1]);
			change(p[2], p[2]);
		}

	// debug(now);
	long long ans = 0;
	vector<int> current_pos(n, 0);
	for (int start = 0; start < n; start++) {
		ans += tree.get();
		int cur_pos = current_pos[a[start]];
		if ((int) poses[a[start]].size() - current_pos[a[start]] <= 3) {
			change(poses[a[start]][cur_pos], poses[a[start]][cur_pos]);
			for (int i = cur_pos + 1; i < (int) poses[a[start]].size(); i++)
				change(poses[a[start]][i], INF);
		} else {
			change(poses[a[start]][cur_pos], poses[a[start]][cur_pos]);
			change(poses[a[start]][cur_pos + 1], poses[a[start]][cur_pos + 3]);
			change(poses[a[start]][cur_pos + 3], poses[a[start]][cur_pos + 3]);
		}
		current_pos[a[start]]++;
		// debug(now);
	}
	cout << ans - (long long) n * (n - 1) / 2 << '\n';
}