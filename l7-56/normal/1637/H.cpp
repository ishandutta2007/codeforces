#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef double db;

const ll maxn = 5e5 + 10;
ll n, p[maxn], c[maxn];
struct BIT {
	ll c[maxn];
	void init() { for (ll i = 1; i <= n; ++i) c[i] = 0; }
	void add(ll x, ll val) { for (; x <= n; x += x & (-x)) c[x] += val; }
	ll ask(ll x) {
		ll res = 0;
		for (; x > 0; x &= x - 1) res += c[x];
		return res;
	}
	ll ask(ll l, ll r) {
		if (l > r) return 0;
		return ask(r) - ask(l - 1);
	}
}T;

void work() {
	scanf("%lld", &n);
	T.init();
	ll ans = 0;
	for (ll i = 1; i <= n; ++i) {
		scanf("%lld", &p[i]), c[i] = i - 2 * p[i] + 1;
		T.add(p[i], 1), ans += T.ask(p[i] + 1, n);
	}
	sort(c + 1, c + n + 1, greater <ll> ());
	printf("%lld ", ans);
	ll sum = 0;
	for (ll k = 1; k <= n; ++k) {
		sum += c[k];
		printf("%lld%c", ans - sum - k * (k - 1) / 2, " \n"[k == n]);
	}
}

int main() {
	ll t;
	scanf("%lld", &t);
	while (t--) work();
	return 0;
}