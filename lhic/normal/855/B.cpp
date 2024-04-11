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
ll p, q, r;
const ll INF = 5e18;

int main() {
	cin >> n >> p >> q >> r;
	ll c0 = 0;
	ll c1 = -INF;
	ll c2 = -INF;
	ll c3 = -INF;
	for (int i = 0; i < n; ++i) {
		ll x;
		scanf("%lld", &x);
		c1 = max(c1, c0 + p * x);
		c2 = max(c2, c1 + q * x);
		c3 = max(c3, c2 + r * x);
	}
	cout << c3 << "\n";
	return 0;
}