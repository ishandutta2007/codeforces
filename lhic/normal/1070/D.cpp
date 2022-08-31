#ifndef BZ
#pragma GCC optimize "-O3"
#endif
#include <bits/stdc++.h>

using ll = long long;
using ld = long double;
using ull = uint64_t;

using namespace std;

const int MX = 200 * 1000 + 7;

ll a[MX], have = 0;

int main() {
	ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	cout.setf(ios::fixed), cout.precision(20);
	int n, k;
	cin >> n >> k;
	for (int i = 0; i < n; i++) {
		cin >> a[i];
	}
	ll ans = 0;
	for (int i = 0; i < n; i++) {
		ll now = (a[i] + have) / k;
		now = max(now, (have + k - 1) / k);
		ans += now;
		now *= k;
		ll more = now - have;
		a[i] -= more;
		have = 0;
		if (a[i] > 0) {
			have = a[i];
		}
	}
	ans += (have + k - 1) / k;

	cout << ans << "\n";
	return 0;
}