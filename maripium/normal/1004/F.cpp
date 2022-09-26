#include <bits/stdc++.h>
using namespace std;

const int N = 1e5 + 5;

int n, m, x;
int a[N];

struct node {
	int l, r;
	vector<pair<int,int>> prf, suf;
	// first : pos
	// second : val
	int sum;
	long long val; // result
	node() {
		l = r = 0; // empty case
	}
};

node merge(node a, node b) {
	if (a.l == 0) return b;
	if (b.l == 0) return a;
	node res;
	res.l = a.l, res.r = b.r;
	res.sum = a.sum | b.sum;
	res.val = a.val + b.val;
	res.prf = a.prf;
	for (auto p : b.prf) {
		int x = p.first;
		if ((a.sum | x) != res.prf.back().first) {
			res.prf.push_back({a.sum | x, p.second});
		}
	}
	res.suf = b.suf;
	for (auto p : a.suf) {
		int x = p.first;
		if ((b.sum | x) != res.suf.back().first) {
			res.suf.push_back({b.sum | x, p.second});
		}
	}
	
	int j = 0;
	for (int i = b.prf.size() - 1; i >= 0; --i) {
		while (j < a.suf.size() && ((b.prf[i].first | a.suf[j].first) < x)) j++;
		if (j < a.suf.size()) {
			int u = (i < b.prf.size() - 1 ? b.prf[i + 1].second : (b.r + 1)) - b.prf[i].second;
			int v = a.suf[j].second - a.l + 1;
			res.val += 1ll * u * v;
		}
	}
	return res;
}

node t[N << 2];

void build(int v,int l,int r) {
	if (l == r) {
		t[v].l = t[v].r = l;
		t[v].prf.push_back({a[l], l});
		t[v].suf.push_back({a[l], l});
		t[v].sum = a[l];
		t[v].val = a[l] >= x;
		return;
	}
	int mid = l + r >> 1;
	build(v << 1, l, mid);
	build(v << 1 | 1, mid + 1, r);
	t[v] = merge(t[v << 1], t[v << 1 | 1]);
}

void upd(int v,int l,int r,int pos,int val) {
	if (l > pos || r < pos)  return;
	if (l == r) {
		t[v].prf[0].first = val;
		t[v].suf[0].first = val;
		t[v].sum = val;
		t[v].val = val >= x;
		return;
	}
	int mid = l + r >> 1;
	upd(v << 1, l, mid, pos, val);
	upd(v << 1 | 1, mid + 1, r, pos, val);
	t[v] = merge(t[v << 1], t[v << 1 | 1]);
}

node get(int v,int l,int r,int L,int R) {
	if (L > r || R < l) return node();
	if (L <= l && R >= r) return t[v];
	int mid = l + r >> 1;
	return merge(get(v << 1, l, mid, L, R), get(v << 1 | 1, mid + 1, r, L, R));
}

int main() {
	ios_base::sync_with_stdio(false);
	cin >> n >> m >> x;
	for (int i = 1; i <= n; ++i) {
		cin >> a[i];
	}
	build(1, 1, n);
	while (m--) {
		int op; cin >> op;
		if (op == 1) {
			int pos, val; cin >> pos >> val;
			upd(1, 1, n, pos, val);
		}
		else {
			int l, r; cin >> l >> r;
			cout << get(1, 1, n, l, r).val << '\n';
		}
	}
}