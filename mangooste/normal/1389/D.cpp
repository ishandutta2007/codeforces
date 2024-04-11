#include <bits/stdc++.h>

using namespace std;
using ll = long long;

signed main() {
	ios::sync_with_stdio(false);
	cin.tie(0), cout.tie(0);

	int t;
	cin >> t;
	while (t--) {
		ll n, k, l1, r1, l2, r2;
		cin >> n >> k >> l1 >> r1 >> l2 >> r2;

		if (l1 > l2) {
			swap(l1, l2);
			swap(r1, r2);
		}

		auto check = [&](ll steps) -> bool {
			ll need = k - max(0ll, min(r1, r2) - max(l1, l2)) * n;

			if (need <= 0) {
				return true;
			}

			ll to_one = max(0ll, l2 - r1);
			ll cnt_one = (r2 <= r1 ? r1 - r2 : r2 - max(l2, r1)) + l2 - l1;

			for (ll change = 1; change <= n && to_one * change < steps; change++) {
				ll steps_left = steps - to_one * change;
				ll now = min(steps_left, change * cnt_one);
				steps_left -= now;
				now += steps_left / 2;

				if (now >= need) {
					return true;
				}
			}

			return false;
		};

		ll L = -1, R = 1e18;
		while (R - L > 1) {
			ll mid = (L + R) / 2;
			(check(mid) ? R : L) = mid;
		}

		cout << R << '\n';
	}
}