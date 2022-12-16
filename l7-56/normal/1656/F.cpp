#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef double db;
typedef pair <ll, ll> pii;

const ll maxn = 2e5 + 10;
ll n,a[maxn];
#define w(i, j, t) (a[i] * a[j] + (t) * (a[i] + a[j]))
ll calc(ll x) {
	ll l = 2, r = n, ans = 0;
	while (l <= r) {
		pii res = min(make_pair(w(l - 1, l, x), l), make_pair(w(l - 1, r, x), r));
		res = min(res, min(make_pair(w(1, l, x), l), make_pair(w(1, r, x), r)));
		if (r < n) res = min(res, min(make_pair(w(n, l, x), l), make_pair(w(n, r, x), r)));
		ans += res.first;
		if (res.second == l) ++l;
		else --r;
	}
	return ans;
}

void work() {
	scanf("%lld", &n);
	for (ll i = 1; i <= n; ++i) scanf("%lld", &a[i]);
	sort(a + 1, a + n + 1);
	ll mn = 0, mx = 0;
	for (ll i = 1; i <= n; ++i) mn += a[i], mx += a[i];
	mn += (n - 2) * a[1], mx += (n - 2) * a[n];
	if (mn > 0 || mx < 0) return printf("INF\n"), void();
	ll l = -1e6, r = 1e6, mid, ans = LLONG_MIN;
	while (r - l >= 4) {
		mid = (l + r) / 2;
		ll res1 = calc(mid), res2 = calc(mid + 1);
		if (res1 < res2) l = mid;
		else r = mid + 1;
	}
	while (l <= r) ans = max(ans, calc(l++));
	printf("%lld\n", ans);
}

int main() {
	int t; scanf("%d", &t);
	while (t--) work();
	return 0;
}