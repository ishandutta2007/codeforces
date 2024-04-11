#ifndef LOCAL
#pragma GCC optimize "-O3"
#endif
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

int n, k;
int main() {
	cin >> n >> k;
	int ans = k;
	for (int i = 0; i < n; ++i) {
		int x;
		cin >> x;
		if (k % x == 0)
			ans = min(ans, k / x);
	}
	cout << ans << "\n";
	return 0;
}