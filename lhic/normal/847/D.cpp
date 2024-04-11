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

int n;
ll T;
ll a[220000];
ll t[220000];
vector<ll> rmq[220000 * 4];

void build(int v, int tl, int tr) {
	if (tl + 1 == tr) {
		rmq[v].push_back(a[tl]);
		return;
	}
	int m = (tl + tr) >> 1;
	build(v * 2 + 1, tl, m);
	build(v * 2 + 2, m, tr);
	merge(rmq[v * 2 + 1].begin(), rmq[v * 2 + 1].end(), rmq[v * 2 + 2].begin(), rmq[v * 2 + 2].end(), back_inserter(rmq[v]));
}

int get(int v, int tl, int tr, int l, int r, ll x) {
	if (r <= tl || tr <= l)
		return 0;
	if (l <= tl && tr <= r) {
		return lower_bound(rmq[v].begin(), rmq[v].end(), x) - rmq[v].begin();
	}
	int m = (tl + tr) >> 1;
	return get(v * 2 + 1, tl, m, l, r, x) + get(v * 2 + 2, m, tr, l, r, x);
}

int main() {
	scanf("%d%lld", &n, &T);
	--T;
	for (int i = 0; i < n; ++i)
		scanf("%lld", t + i), --t[i], a[i] = t[i] - i;
	build(0, 0, n);
	int ans = 0;
	for (int i = 0; i < n; ++i) {
		int go = min((ll)n, min(T, T - a[i]));
		if (go > 0)
			ans = max(ans, get(0, 0, n, 0, go, a[i] + 1));
	}
	cout << ans << "\n";
	return 0;
}