#include <bits/stdc++.h>

using namespace std;

signed main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int t;
	cin >> t;
	while (t--) {
		int n, q;
		cin >> n >> q;
		assert(q == 0);
		long long ans = 0;
		int last = 0;
		for (int i = 0; i < n; i++) {
			int now;
			cin >> now;
			ans += max(0, now - last);
			last = now;
		}
		cout << ans << '\n';
	}	
}