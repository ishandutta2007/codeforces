#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef double db;

const ll maxn = 1e5 + 10;
ll n,a[maxn];
void work() {
	scanf("%lld", &n);
	for (ll i = 1; i <= n; ++i) scanf("%lld", &a[i]);
	ll ans = 0, cntl = 0, cntr = 0;
	bool flag = 0;
	for (ll i = 2; i < n; ++i) {
		ans += (a[i] + 1) / 2;
		if (a[i] / 2 > 0 && cntl) flag = 1;
		cntl += (a[i] & 1);
	}
	if (!cntl) flag = 1;
	for (ll i = n - 1; i >= 2; --i) {
		if (a[i] / 2 > 0 && cntr) flag = 1;
		cntr += (a[i] & 1);
	}
	if (!flag) return printf("-1\n"), void();
	printf("%lld\n", ans);
}

int main() {
	ll t;
	scanf("%lld", &t);
	while (t--) work();
	return 0;
}