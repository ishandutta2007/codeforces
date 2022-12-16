#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef double db;
typedef pair <ll, ll> pll;

const ll maxn = 5010;
ll n,x,s[maxn],mx[maxn];
set <pll> S;
void work() {
	scanf("%lld%lld", &n, &x);
	for (ll i = 1; i <= n; ++i) scanf("%lld", &s[i]), s[i] += s[i - 1];
	for (ll len = 1; len <= n; ++len) {
		mx[len] = s[len];
		for (ll l = 2, r = len + 1; r <= n; ++l, ++r)
			mx[len] = max(mx[len], s[r] - s[l - 1]);
		S.insert(make_pair(mx[len], len));
	}
	ll ans = 0;
	printf("%lld ", max(ans, (*--S.end()).first));
	for (ll k = 1; k <= n; ++k) {
		S.erase(make_pair(mx[k], k)), ans = max(ans, mx[k] + k * x);
		ll res = ans;
		if (k < n) res = max(res, (*--S.end()).first + k * x);
		printf("%lld%c", res, " \n"[k == n]);
	}
}

int main() {
	ll t; scanf("%lld", &t);
	while (t--) work();
	return 0;
}