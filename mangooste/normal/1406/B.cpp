#include <bits/stdc++.h>

using namespace std;

signed main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr), cout.tie(nullptr);

	int t;
	cin >> t;
	while (t--) {
		int n;
		cin >> n;
		array<vector<int>, 2> all;
		bool any_zeroes = false;
		for (int i = 0; i < n; i++) {
			int x;
			cin >> x;
			if (x == 0) {
				any_zeroes = true;
				continue;
			}
			all[x > 0].push_back(abs(x));
		}
		for (int i = 0; i < 2; i++)
			sort(all[i].rbegin(), all[i].rend());

		long long ans = -1e18;
		for (int cnt = 0; cnt <= 5 && cnt <= (int) all[0].size(); cnt++) {
			if (5 - cnt > (int) all[1].size()) {
				continue;
			}
			long long p = 1;
			for (int i = 0; i < cnt; i++)
				p *= -all[0][i];
			for (int i = 0; i < 5 - cnt; i++)
				p *= all[1][i];
			ans = max(ans, p);
		}
		reverse(all[0].begin(), all[0].end());
		for (int cnt = 0; cnt <= 5 && cnt <= (int) all[0].size(); cnt++) {
			if (5 - cnt > (int) all[1].size()) {
				continue;
			}
			long long p = 1;
			for (int i = 0; i < cnt; i++)
				p *= -all[0][i];
			for (int i = 0; i < 5 - cnt; i++)
				p *= all[1][i];
			ans = max(ans, p);
		}
		if (any_zeroes)
			ans = max(ans, 0ll);
		cout << ans << '\n';
	}
}