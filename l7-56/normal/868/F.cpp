#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const ll maxn = 1e5 + 10, inf = 3e18;
ll n,k,a[maxn],cnt[maxn],w,f[maxn],g[maxn];
void add(ll val) { w += (cnt[val]++); }
void del(ll val) { w -= (--cnt[val]); }

void solve(ll l, ll r, ll L, ll R) {
	if (l > r) return;
	ll mid = (l + r) >> 1, pos = L;
	// printf("[%lld, %lld] [%lld, %lld] %lld\n", l, r, L, R, w);
	for (ll i = l; i <= mid; ++i) add(a[i]);
	for (ll i = L; i <= R && i < mid; ++i) {
		del(a[i]);
		// printf("[%lld, %lld] %lld\n", i + 1, mid, w);
		if (f[mid] > g[i] + w)
			f[mid] = g[i] + w, pos = i;
	}
	for (ll i = L; i <= R && i < mid; ++i) add(a[i]);
	for (ll i = l; i <= mid; ++i) del(a[i]);
	// printf("%lld : %lld\n", mid, f[mid]);
	solve(l, mid - 1, L, pos);
	for (ll i = l; i <= mid; ++i) add(a[i]);
	for (ll i = L; i < pos; ++i) del(a[i]);
	solve(mid + 1, r, pos, R);
	for (ll i = L; i < pos; ++i) add(a[i]);
	for (ll i = l; i <= mid; ++i) del(a[i]);
}

int main() {
	scanf("%lld%lld", &n, &k);
	for (ll i = 1; i <= n; ++i) scanf("%lld", &a[i]);
	memset(f, 0x3f, sizeof f);
	memset(g, 0x3f, sizeof g);
	g[0] = 0;
	while (k--) {
		add(a[0]);
		solve(1, n, 0, n);
		del(a[0]);
		for (ll i = 1; i <= n; ++i)
			g[i] = f[i], f[i] = inf;
	}
	printf("%lld\n", g[n]);
	return 0;
}