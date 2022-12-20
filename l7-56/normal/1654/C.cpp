#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef double db;

const ll maxn = 2e5 + 10;
ll n,a[maxn];
void work() {
	multiset <ll> s;
	scanf("%lld", &n);
	ll sum = 0;
	for (ll i = 1; i <= n; ++i) scanf("%lld", &a[i]), sum += a[i];
	s.insert(sum);
	sort(a + 1, a + n + 1, greater <ll> ());
	for (ll i = 1; i <= n; ++i) {
		ll x = *--s.end();
		while (x > a[i] && (ll) s.size() <= n) {
			s.erase(--s.end());
			s.insert(x / 2), s.insert(x - x / 2);
			x = *--s.end();
		}
		if ((ll) s.size() > n) return printf("NO\n"), void();
		if (*--s.end() == a[i]) s.erase(--s.end());
		else return printf("NO\n"), void();
	}
	printf("YES\n");
}

int main() {
	ll t; scanf("%lld", &t);
	while (t--) work();
	return 0;
}