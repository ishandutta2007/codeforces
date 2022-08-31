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

int main() {
	int n;
	ll x;
	scanf("%d%lld", &n, &x);
	for (int i = 0; i < n; ++i) {
		ll y;
		scanf("%lld", &y);
		x -= y;
	}
	x -= n - 1;
	if (x == 0)
		cout << "YES\n";
	else
		cout << "NO\n";
	return 0;
}