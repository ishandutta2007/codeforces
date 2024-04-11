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
int p[120];
int was[120];

int main() {
	cin >> n;
	for (int i = 0; i < n; ++i)
		cin >> p[i], --p[i];
	ll ans = 1;
	for (int i = 0; i < n; ++i) {
		if (was[i])
			continue;
		int x = i;
		int cnt = 0;
		while (!was[x]) {
			++cnt;
			was[x] = 1;
			x = p[x];
		}
		if (x != i) {
			cout << -1 << "\n";
			return 0;
		}
		if (cnt % 2 == 0)
			cnt /= 2;
		ll g = __gcd(ans, (ll)cnt);
		ans = (ans * cnt) / g;
	}
	cout << ans << "\n";
	return 0;
}