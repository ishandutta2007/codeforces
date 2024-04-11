#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

struct vertex {
	int ans, open, close;
	vertex(int ans = 0, int open = 0, int close = 0) : ans(ans), open(open), close(close) {}
};

vertex operator + (vertex a, vertex b) {
	int add = min(a.open, b.close);
	return vertex(a.ans + b.ans + add, a.open + b.open - add, a.close + b.close - add);
}

string s;
int n;
vector <vertex> tree;

void build(int v, int l, int r) {
	if (r - l == 1) {
		if (s[l] == '(')
			tree[v] = vertex(0, 1, 0);
		else
			tree[v] = vertex(0, 0, 1);
		return;
	}
	int m = (l + r) / 2;
	build(2 * v, l, m);
	build(2 * v + 1, m, r);
	tree[v] = tree[2 * v] + tree[2 * v + 1];
}

vertex get(int v, int l, int r, int tl, int tr) {
	if (tr <= l || r <= tl)
		return vertex();
	if (tl <= l && r <= tr)
		return tree[v];
	int m = (l + r) / 2;
	return get(2 * v, l, m, tl, tr) + get(2 * v + 1, m, r, tl, tr);
}

signed main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin >> s;
	n = (int)s.size();
	tree.resize(4 * n);
	build(1, 0, n);
	int m;
	cin >> m;
	while (m--) {
		int l, r;
		cin >> l >> r;
		cout << get(1, 0, n, l - 1, r).ans * 2 << '\n';
	}
	return 0;
}