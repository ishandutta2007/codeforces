#include <bits/stdc++.h>

using namespace std;
using ll = long long;

signed main() {
	ios::sync_with_stdio(false);
	cin.tie(0), cout.tie(0);

	int t;
	cin >> t;
	while (t--) {
		string s;
		cin >> s;
		int n = s.size();
		for (auto &el : s) {
			el -= '0';
		}

		int ans = n;

		for (int i = 0; i < 10; i++) {
			int cnt = count(s.begin(), s.end(), i);
			cnt -= 1 - cnt % 2;
			ans = min(ans, n - cnt);
		}

		for (int fir = 0; fir < 10; fir++) {
			for (int sec = 0; sec < 10; sec++) {
				int cnt = 0, now = 0;
				for (int i = 0; i < n; i++) {
					if (!now && s[i] == fir || now && s[i] == sec) {
						cnt++;
						now ^= 1;
					}
				}
				cnt -= now;
				ans = min(ans, n - cnt);
			}
		}

		cout << ans << '\n';
	}
}