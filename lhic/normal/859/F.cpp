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
const ll INF = 1e16;

int n;
ll c;
ll a[MAXN];
ll b[MAXN];
ll sm[MAXN];
ll ans[MAXN];
ll dd[MAXN * 4];
ll rmq[MAXN * 4];

void add(int v, int tl, int tr, int l, int r, ll d) {
	if (r <= tl || tr <= l)
		return;
	if (l <= tl && tr <= r) {
		dd[v] += d;
		rmq[v] += d;
		return;
	}
	int m = (tl + tr) >> 1;
	add(v * 2 + 1, tl, m, l, r, d);
	add(v * 2 + 2, m, tr, l, r, d);
	rmq[v] = min(rmq[v * 2 + 1], rmq[v * 2 + 2]) + dd[v];
}

ll get(int v, int tl, int tr, int l, int r) {
	if (r <= tl || tr <= l)
		return INF;
	if (l <= tl && tr <= r)
		return rmq[v];
	int m = (tl + tr) >> 1;
	return min(get(v * 2 + 1, tl, m, l, r), get(v * 2 + 2, m, tr, l, r)) + dd[v];
}

int main() {
	scanf("%d%lld", &n, &c);
	scanf("%lld", a + 0);
	for (int i = 1; i < n; ++i) {
		scanf("%lld%lld", b + i, a + i);
	}
	for (int i = 0; i < n; ++i)
		a[i] = min(a[i], c), b[i] = min(b[i], c);
	sm[0] = 0;
	sm[1] = a[0];
	for (int i = 1; i < n; ++i) {
		ll lb = a[i] - 1;
		ll rb = a[i] + b[i];
		add(0, 0, n, 0, i + 1, -a[i]);
		add(0, 0, n, 0, i, -b[i]);
		while (rb - lb > 1) {
			ll mid = (lb + rb) >> 1;
			ll sn = sm[i] + mid;
			int x = upper_bound(sm, sm + i + 1, sn - c) - sm;
			if (get(0, 0, n, x, i + 1) + mid >= 0)
				rb = mid;
			else
				lb = mid;
		}
		add(0, 0, n, 0, i + 1, rb);
		sm[i + 1] = sm[i] + rb;
	}
	cout << sm[n] << "\n";
	return 0;
}