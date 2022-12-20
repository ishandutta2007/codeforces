#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef double db;

const ll maxn = 2010;
ll n,k,a[maxn],l[maxn],r[maxn],f[maxn];

int main() {
	scanf("%lld%lld", &n, &k);
	for (ll i = 1; i <= n; ++i) scanf("%lld%lld%lld", &l[i], &r[i], &a[i]);
	for (ll i = n; i >= 1; --i) {
		ll need = a[i] + (r[i] == l[i + 1]) * f[i + 1];
		if ((r[i] - l[i] + 1) * k < need) return printf("-1\n"), 0;
		f[i] = max(0ll, need - (r[i] - l[i]) * k);
	}
	ll ans = 0, rst = k;
	for (ll i = 1; i <= n; ++i) {
		if (rst < f[i]) ans += rst, rst = k;
		ans += a[i];
		rst = ((rst - a[i]) % k + k) % k;
	}
	printf("%lld\n", ans);
	return 0;
}