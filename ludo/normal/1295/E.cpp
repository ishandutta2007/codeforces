#include<bits/stdc++.h>
using namespace std;
using ll = long long;

struct Node {
	ll mn, lazy;

	Node() : mn(LLONG_MAX), lazy(0) {}

	inline void merge(Node a, Node b) {
		// assert(lazy == 0);
		mn = min(a.mn, b.mn);
	}

	inline void propagate(Node &a, Node &b) {
		if (a.mn != LLONG_MAX) {
			a.mn += lazy;
			a.lazy += lazy;
		}
		if (b.mn != LLONG_MAX) {
			b.mn += lazy;
			b.lazy += lazy;
		}

		lazy = 0;
	}
};

constexpr int maxn = 1 << 20;

Node T[2*maxn];

void rupdate(int idx, int l, int r, int a, int b, int v) {
	if (r <= a || l >= b) return; // outside interval

	if (a <= l && r <= b) {
		// this interval completely contains it.
		assert(T[idx].mn != LLONG_MAX);
		T[idx].lazy += v;
		T[idx].mn += v;
		return;
	} else {
		assert(idx < maxn);
		// work recursively
		int m = (l+r) / 2;
		Node &lc = T[2*idx], &rc = T[2*idx+1];
		if (T[idx].lazy != 0) T[idx].propagate(lc, rc);
		rupdate(2*idx,   l, m, a, b, v);
		rupdate(2*idx+1, m, r, a, b, v);
		T[idx].merge(lc, rc);
	}
}

void range_update(int a, int b, int v) {
	if (a < b) {
		// add v to interval [a,b).
		rupdate(1, 0, maxn, a, b, v);
	}
}

int main() {
	int n;
	scanf("%d", &n);

	vector<int> p(n), a(n);
	for (int &x : p) scanf("%d", &x);
	for (int &x : a) scanf("%d", &x);

	// build tree
	vector<int> pf(n+1, 0);
	for (int i=0; i<n; i++) pf[p[i]] = a[i];
	ll s = 0;
	for (int i=0; i<=n; i++) {
		s += pf[i];
		T[maxn + i].mn = s;
	}

	for (int i=maxn; --i; )
		T[i].merge(T[2*i], T[2*i+1]);

	ll ans = LLONG_MAX;
	for (int i=0; i < n-1; i++) {
		range_update(p[i], n+1, -a[i]);
		range_update(0, p[i], a[i]);
		ans = min(ans, T[1].mn);
		// if (ans == T[1].mn) cerr << i << ": " << T[1].mn << endl;
	}

	printf("%lld\n", ans);
	return 0;
}