#include <bits/stdc++.h>

using namespace std;

signed main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr), cout.tie(nullptr);

	int t;
	cin >> t;
	while (t--) {
		string s;
		cin >> s;
		int x;
		cin >> x;
		int n = (int) s.size();
		string ans(n, '1');
		for (int i = 0; i < n; i++)
			if (s[i] == '0') {
				if (i >= x)
					ans[i - x] = '0';
				if (i + x < n)
					ans[i + x] = '0';
			}

		bool can = true;
		for (int i = 0; i < n; i++) {
			auto get = [&](int pos) {
				if (pos < 0 || pos >= n)
					return 0;
				return ans[pos] - '0';
			};
			char now = '0' + (get(i - x) || get(i + x));
			can &= (s[i] == now);
		}
		if (can)
			cout << ans << '\n';
		else
			cout << -1 << '\n';
	}
}