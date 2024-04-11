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

int main() {
	int n, x, l, r;
	cin >> n >> x >> l >> r;
	int ans = 100000;

	{
		int cur = x;
		int sum = 0;
		if (l > 1)
			sum += abs(l - cur), cur = l, ++sum;
		if (r < n)
			sum += abs(r - cur), cur = r, ++sum;
		ans = min(ans, sum);
	}
	{
		int cur = x;
		int sum = 0;
		if (r < n)
			sum += abs(r - cur), cur = r, ++sum;
		if (l > 1)
			sum += abs(l - cur), cur = l, ++sum;
		ans = min(ans, sum);
	}
	cout << ans << "\n";
	return 0;
}