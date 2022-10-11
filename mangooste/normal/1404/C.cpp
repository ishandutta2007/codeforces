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

template<class T>
struct Fenwick {
	int n;
	vector<T> bit;

	Fenwick(int n = 0) : n(n), bit(vector<T>(n + 1, 0)) {}

	T get(int pos) {
		T sum = 0;
		for (; pos; pos -= pos & -pos)
			sum += bit[pos];
		return sum;
	}

	T get(int L, int R) {
		return get(R) - get(L);
	}

	void update(int pos, T add) {
		for (pos++; pos <= n; pos += pos & -pos)
			bit[pos] += add;
	}
};

struct Segment_tree {
	int n;
	vector<vector<int>> tree;

	Segment_tree(vector<int> a = {1}) : n((int) a.size()) {
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

	int get(int L, int R, int at_least) {
		return get(0, 0, n, L, R, at_least);
	}

	int get(int v, int vl, int vr, int L, int R, int at_least) {
		if (R <= vl || vr <= L)
			return 0;
		if (L <= vl && vr <= R)
			return int(tree[v].end() - lower_bound(tree[v].begin(), tree[v].end(), at_least));
		int vm = (vl + vr) / 2;
		return get(2 * v + 1, vl, vm, L, R, at_least) + get(2 * v + 2, vm, vr, L, R, at_least);
	}
};

signed main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr), cout.tie(nullptr);

	int n, q;
	cin >> n >> q;
	vector<int> a(n);
	for (int i = 0; i < n; i++) {
		cin >> a[i], a[i]--;
		a[i] = i - a[i];
	}
	debug(a);
	Fenwick<int> bit(n);
	vector<int> max_l(n, -1);
	for (int i = 0; i < n; i++) {
		int lb = -1, rb = i + 1;
		while (rb - lb > 1) {
			int mid = (lb + rb) / 2;
			if (bit.get(mid, i + 1) >= a[i])
				lb = mid;
			else
				rb = mid;
		}
		if (a[i] < 0)
		    lb = -1;
		if (lb != -1)
			bit.update(lb, 1);
		max_l[i] = lb;
	}
	debug(max_l);
	Segment_tree tree(max_l);
	while (q--) {
		int pref, suf;
		cin >> pref >> suf;
		cout << tree.get(pref, n - suf, pref) << '\n';
	}
}