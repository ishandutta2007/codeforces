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

const int MAXN = 210000;

int n, m, q;

ll rmq[MAXN * 4];
ll dd[MAXN * 4];
ll a[MAXN];
ll b[MAXN];
ll ad[MAXN];

vector<pair<int, ll> > go[MAXN];

multiset<ll> ss;

void add(int v, int tl, int tr, int l, int r, ll d) {
	if (r <= tl || tr <= l)
		return;
	if (l <= tl && tr <= r) {
		rmq[v] += d;
		dd[v] += d;
		return;
	}
	int m = (tl + tr) >> 1;
	add(v * 2 + 1, tl, m, l, r, d);
	add(v * 2 + 2, m, tr, l, r, d);
	rmq[v] = min(rmq[v * 2 + 1], rmq[v * 2 + 2]) + dd[v];
}

int main() {
	scanf("%d%d%d", &n, &m, &q);
	for (int i = 0; i < n - 1; ++i)
		scanf("%lld%lld", a + i, b + i);
	for (int i = 0; i < m; ++i) {
		int x, y;
		ll c;
		scanf("%d%d%lld", &x, &y, &c);
		--x, --y;
		go[x].push_back(make_pair(y, c));
	}
	for (int i = 0; i < n - 1; ++i)
		add(0, 0, n, i + 1, i + 2, b[i]);
	for (int i = 0; i < n; ++i) {
		for (auto e: go[i])
			add(0, 0, n, 0, e.first + 1, e.second);
		ad[i] = rmq[0];
		ss.insert(ad[i] + a[i]);
	}
	cout << *ss.begin() << "\n";
	for (int i = 0; i < q; ++i) {
		int x, y;
		scanf("%d%d", &x, &y);
		--x;
		ss.erase(ss.find(ad[x] + a[x]));
		a[x] = y;
		ss.insert(ad[x] + a[x]);
		cout << *ss.begin() << "\n";
	}
	return 0;
}