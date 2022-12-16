#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef double db;

const ll maxn = 2e5 + 10;
ll n,a[maxn],b[maxn];
void work() {
	scanf("%lld", &n);
	for (ll i = 1; i <= n; ++i) scanf("%lld", &a[i]);
	for (ll i = 1; i <= n; ++i) scanf("%lld", &b[i]);
	ll val1 = abs(a[1] - b[1]), val2 = abs(a[n] - b[1]), val3 = abs(b[1] - a[1]), val4 = abs(b[n] - a[1]);
	for (ll i = 2; i <= n; ++i) {
		val1 = min(val1, abs(a[1] - b[i]));
		val2 = min(val2, abs(a[n] - b[i]));
		val3 = min(val3, abs(b[1] - a[i]));
		val4 = min(val4, abs(b[n] - a[i]));
	}
	ll ans = val1 + val2 + val3 + val4;
	ans = min(ans, min(val1 + val3, abs(a[1] - b[1])) + min(val2 + val4, abs(a[n] - b[n])));
	ans = min(ans, min(val1 + val4, abs(a[1] - b[n])) + min(val2 + val3, abs(a[n] - b[1])));
	printf("%lld\n", ans);
}

int main() {
	ll t; scanf("%lld", &t);
	while (t--) work();
	return 0;
}