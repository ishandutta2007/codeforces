#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef double db;
typedef pair <ll, ll> pii;

const ll maxn = 2e5 + 10;
map <ll, ll> cnt;
ll n,x,a[maxn];
void work() {
	cnt.clear();
	scanf("%lld%lld", &n, &x);
	ll ans = 0;
	for (ll i = 1; i <= n; ++i) scanf("%lld", &a[i]), cnt[a[i]]++;
	for (pii p : cnt) {
		auto it = cnt.find(p.first * x);
		if (it != cnt.end()) {
			ll val = min(it -> second, p.second);
			p.second -= val, it -> second -= val;
		}
		ans += p.second;
	}
	printf("%lld\n", ans);
}

int main() {
	ll t; scanf("%lld", &t);
	while (t--) work();
	return 0;
}