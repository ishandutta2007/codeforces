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
		vector<int> cnt(101, 0);
		for (int i = 0; i < n; i++) {
			int x;
			cin >> x;
			cnt[x]++;
		}
		int def = 0;
		while (cnt[def] > 1)
			def++;
		int ans = def;
		while (cnt[def] > 0)
			def++;
		ans += def;
		cout << ans << '\n';
	}
}