#include <bits/stdc++.h>
typedef long long ll;
using namespace std;

const int maxn = 30, mod = 1e9 + 7;
ll n,m,a[maxn],ans,inv[maxn];

ll qpow(ll a, ll p) {
	a %= mod;
	ll res = 1;
	while (p) {
		if (p & 1) res = res * a % mod;
		a = a * a % mod, p >>= 1;
	}
	return res;
}

ll c(ll n, ll m) {
	if (n < 0 || m < 0 || m > n) return 0;
	if (n == 0 || m == 0) return 1;
	ll ret = c(n / mod, m / mod);
	n %= mod, m %= mod;
	for (ll i = n; i > n - m; --i) ret = (ret * i) % mod;
	ret = ret * inv[m] % mod;
	return ret;
}

int main() {
	scanf("%lld%lld", &n, &m);
	inv[0] = 1;
	for (int i = 1; i <= n; ++i) scanf("%lld", &a[i]), inv[i] = inv[i - 1] * qpow(i, mod - 2) % mod;
	for (int s = 0; s < (1 << n); ++s) {
		ll sum = n + m, cnt = 0;
		for (int i = 1; i <= n; ++i)
			if (s & (1 << (i - 1))) cnt++, sum -= a[i];
		ans = (ans + ((cnt & 1) ? -1 : 1) * c(sum - cnt - 1, n - 1) + mod) % mod;
	}
	printf("%lld\n", ans);
	return 0;
}