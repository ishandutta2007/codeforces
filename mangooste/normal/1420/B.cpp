#include <bits/stdc++.h>

using namespace std;

signed main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int t;
	cin >> t;
	while (t--) {
		int n;
		cin >> n;
		vector<int> cnt(32, 0);
		for (int i = 0; i < n; i++) {
			int x;
			cin >> x;
			int bit = 31 - __builtin_clz(x);
			cnt[bit]++;
		}
		long long ans = 0;
		for (auto x : cnt)
			ans += (long long) x * (x - 1) / 2;
		cout << ans << '\n';
	}	
}