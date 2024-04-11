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
	cin >> n;
	int ans = 2 * n + 2;
	for (int i = 1; i <= n; ++i) {
		int j = (n + i - 1) / i;
		ans = min(ans, 2 * (i + j));
	}
	cout << ans << "\n";
	return 0;
}