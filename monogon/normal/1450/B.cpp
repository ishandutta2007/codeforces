#include <bits/stdc++.h>

using namespace std;

int main() {
	ios_base::sync_with_stdio(0), cin.tie(0);
	int t;
	cin >> t;
	while (t--) {
		int n, k;
		cin >> n >> k;
		vector<pair<int, int>> a(n);
		for (auto &i : a)
			cin >> i.first >> i.second;
		int ans = -1;
		for (int i = 0; i < n; ++i) {
			int mx = 0;
			for (int j = 0; j < n; ++j) {
				mx = max(mx, abs(a[i].first - a[j].first) + abs(a[i].second - a[j].second));
			}
			if (mx <= k) ans = 1;
		}
		cout << ans << "\n";
	}
}