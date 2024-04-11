#ifndef LOCAL
#pragma GCC optimize "-O3"
#endif
#include <bits/stdc++.h>

typedef long long ll;
typedef long long llong;
typedef long double ld;
typedef unsigned long long ull;

using namespace std;

/*
ll pw(ll a, ll b) {
	ll ans = 1; while (b) {
		while (!(b & 1)) b >>= 1, a = (a * a) % MOD;
		ans = (ans * a) % MOD, --b;
	} return ans;
}
*/

const int MAXN = 1020000;
int n, q;

int dd[MAXN * 4];
int rmq[MAXN * 4];

vector<int> vv;

void build(int v, int tl, int tr) {
	if (tl + 1 == tr) {
		dd[v] = 0;
		rmq[v] = vv[tl + 1] - vv[tl];
		return;
	}
	int m = (tl + tr) >> 1;
	dd[v] = 0;
	build(v * 2 + 1, tl, m);
	build(v * 2 + 2, m, tr);
	rmq[v] = vv[tr] - vv[tl];
}

void push(int v, int tl, int tr) {
	if (!dd[v])
		return;
	int m = (tl + tr) >> 1;
	if (dd[v] == 1) {
		dd[v * 2 + 1] = 1;
		rmq[v * 2 + 1] = 0;
		dd[v * 2 + 2] = 1;
		rmq[v * 2 + 2] = 0;
		dd[v] = 0;
	}
	else {
		dd[v * 2 + 1] = 2;
		rmq[v * 2 + 1] = vv[m] - vv[tl];
		dd[v * 2 + 2] = 2;
		rmq[v * 2 + 2] = vv[tr] - vv[m];
		dd[v] = 0;
	}
}

void st(int v, int tl, int tr, int l, int r, int k) {
	if (r <= tl || tr <= l)
		return;
	if (l <= tl && tr <= r) {
		dd[v] = k;
		if (k == 1)
			rmq[v] = 0;
		else
			rmq[v] = vv[tr] - vv[tl];
		return;
	}
	push(v, tl, tr);
	int m = (tl + tr) >> 1;
	st(v * 2 + 1, tl, m, l, r, k);
	st(v * 2 + 2, m, tr, l, r, k);
	rmq[v] = rmq[v * 2 + 1] + rmq[v * 2 + 2];
}

int lb[MAXN];
int rb[MAXN];
int k[MAXN];

int main() {
	scanf("%d%d", &n, &q);
	for (int i = 0; i < q; ++i) {
		scanf("%d%d%d", lb + i, rb + i, k + i);
		vv.push_back(lb[i]);
		vv.push_back(rb[i] + 1);
	}
	vv.push_back(1);
	vv.push_back(n + 1);
	sort(vv.begin(), vv.end());
	vv.resize(unique(vv.begin(), vv.end()) - vv.begin());
	int sz = vv.size() - 1;
	build(0, 0, sz);
	for (int i = 0; i < q; ++i) {
		lb[i] = lower_bound(vv.begin(), vv.end(), lb[i]) - vv.begin();
		rb[i] = lower_bound(vv.begin(), vv.end(), rb[i] + 1) - vv.begin();
		st(0, 0, sz, lb[i], rb[i], k[i]);
		printf("%d\n", rmq[0]);
	}
	return 0;
}