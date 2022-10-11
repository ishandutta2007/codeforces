#include <bits/stdc++.h>

using namespace std;

signed main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int t;
	cin >> t;
	while (t--) {
		long long x;
		cin >> x;
		int ans = 0;
		for (long long i = 1; i * (i + 1) / 2 <= x; i = i * 2 + 1) {
			x -= i * (i + 1) / 2;
			ans++;
		}
		cout << ans << '\n';
	}
}