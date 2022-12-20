#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const ll maxn = 2010, maxx = 2e5 + 10, mod = 1e9 + 7;
ll qpow(ll a, ll p) {
	ll ans = 1;
	while (p) {
		if (p & 1) ans = ans * a % mod;
		a = a * a % mod, p >>= 1;
	}
	return ans;
}
ll h,w,n,fact[maxx],inv[maxx],f[maxn];
ll c(ll n, ll m) {
	if (n < 0 || m < 0 || n < m) return 0;
	return fact[n] * inv[m] % mod * inv[n - m] % mod;
}

struct node {
	ll x,y;
	friend bool operator < (node a, node b) {
		if (a.x == b.x) return a.y < b.y;
		return a.x < b.x;
	}
}a[maxn];

int main() {
	scanf("%lld%lld%lld", &h, &w, &n);
	fact[0] = inv[0] = 1;
	for (ll i = 1; i <= h + w; ++i) fact[i] = fact[i - 1] * i % mod, inv[i] = qpow(fact[i], mod - 2);
	for (ll i = 1; i <= n; ++i) scanf("%lld%lld", &a[i].x, &a[i].y);
	a[++n] = {h, w};
	sort(a + 1, a + n + 1);
	for (ll i = 1; i <= n; ++i) {
		f[i] = c( a[i].x + a[i].y - 2, a[i].x - 1);
		for (ll j = 0; j < i; ++j)
			f[i] = (f[i] - f[j] * c(a[i].x - a[j].x + a[i].y - a[j].y, a[i].x - a[j].x) % mod + mod) % mod;
	}
	printf("%lld\n", f[n]);
	return 0;
}