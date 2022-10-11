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
		vector<int> a(n);
		for (auto &x : a)
			cin >> x;
		long long sum = accumulate(a.begin(), a.end(), 0ll);
		long long ans = 0;
		long long now = 0;
		for (int i = 0; i < n; i++) {
			now += a[i];
			ans = max(ans, sum - now);
		}
		cout << ans << '\n';
	}
}