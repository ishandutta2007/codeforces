#include <bits/stdc++.h>

using namespace std;
using ll = long long;

const ll INF = 1e18;

signed main() {
	ios::sync_with_stdio(false);
	cin.tie(0), cout.tie(0);

	int t;
	cin >> t;
	while (t--) {
		ll m, d, w;
		cin >> m >> d >> w;
		ll R = min(d, m);

		if (d == 1) {
			cout << R * (R - 1) / 2 << '\n';
			continue;
		}

		ll g = __gcd(d - 1, w);
		w /= g;

		ll ans = 0;

		ll cnt = R / w;
		ans += (cnt - 1) * cnt / 2 * w;
		ans += (R - cnt * w) * cnt;

		cout << ans << '\n';
	}
}