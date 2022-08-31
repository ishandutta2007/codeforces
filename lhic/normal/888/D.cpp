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

ll n;

ll get(int k) {
	if (k == 1)
		return 0;
	if (k == 2) {
		return n * (n - 1) / 2;
	}
	if (k == 3) {
		return n * (n - 1) * (n - 2) / 6 * 2;
	}
	if (k == 4) {
		return n * (n - 1) * (n - 2) * (n - 3) / 24 * (6 + 3);
	}
	return 0;
}

int main() {
	int k;
	cin >> n >> k;
	ll ans = 1;
	for (int i = 1; i <= k; ++i)
		ans += get(i);
	cout << ans << "\n";
	return 0;
}