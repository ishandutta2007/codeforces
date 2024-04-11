#include <bits/stdc++.h>

typedef long long ll;
typedef long long llong;
typedef long double ld;
typedef unsigned long long ull;

using namespace std;

/*
ll pw(ll a, ll b) {
	ll ans = 1; while (b) {
		while (!(b & 1)) b >>= 1, a = (a * a) % MOD;
		ans = (ans * a) % MOD, --b;
	} return ans;
}
*/

int n;
ll a[220000];
multiset<ll> ss;

ll get(multiset<ll> ss) {
	ll ans = 0;
	while (ss.size() >= 3) {
		ll x = *ss.begin();
		ll y = *next(ss.begin());
		ll z = *next(next(ss.begin()));
		ans += x + y + z;
		for (int i = 0; i < 3; ++i)
			ss.erase(ss.begin());
		ss.insert(x + y + z);
	}
	if (ss.size() == 2) {
		ans += *ss.begin() + *ss.rbegin();
	}
	return ans;
}

int main() {
	scanf("%d", &n);
	for (int i = 0; i < n; ++i)
		scanf("%lld", a + i);
	for (int i = 0; i < n; ++i)
		ss.insert(a[i]);
	ll ans = get(ss);
	ss.insert(0);
	ans = min(ans, get(ss));
	ss.insert(0);
	ans = min(ans, get(ss));
	cout << ans << "\n";
	return 0;
}