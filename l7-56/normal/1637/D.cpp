#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef double db;

const ll maxn = 110, maxa = 40010, P = 20005;
ll n,a[maxn],b[maxn],f[maxa],g[maxa];
void work() {
	scanf("%lld", &n);
	ll ans = 0, sum = 0;
	for (ll i = 1; i <= n; ++i) scanf("%lld", &a[i]), ans += (n - 2) * a[i] * a[i], sum += a[i];
	for (ll i = 1; i <= n; ++i) scanf("%lld", &b[i]), ans += (n - 2) * b[i] * b[i], sum += b[i];
	memset(f, 0, sizeof f);
	f[P] = 1;
	for (ll i = 1; i <= n; ++i) {
		ll val = a[i] - b[i];
		for (ll j = P - 20000; j <= P + 20000; ++j) {
			g[j] = 0;
			if (j - val >= P - 20000) g[j] |= f[j - val];
			if (j + val <= P + 20000) g[j] |= f[j + val];
		}
		for (ll j = P - 20000; j <= P + 20000; ++j) f[j] = g[j];
	}
	ll dlt = 0;
	while (!f[P - dlt] && !f[P + dlt]) ++dlt;
	ll sa = (sum + dlt) / 2, sb = (sum - dlt) / 2;
	ans += sa * sa + sb * sb;
	printf("%lld\n", ans);
}

int main() {
	ll t;
	scanf("%lld", &t);
	while (t--) work();
	return 0;
}