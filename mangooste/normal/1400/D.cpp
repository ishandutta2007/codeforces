#include <bits/stdc++.h>

using namespace std;
using ll = long long;

signed main() {
	ios::sync_with_stdio(false);
	cin.tie(0), cout.tie(0);

	int t;
	cin >> t;
	while (t--) {
		int n;
		cin >> n;
		vector<int> a(n);
		for (auto &x : a)
			cin >> x, x--;

		vector<vector<int>> left(n + 1, vector<int>(n, 0));
		for (int i = 0; i < n; i++) {
			left[i + 1] = left[i];
			left[i + 1][a[i]]++;
		}

		vector<vector<int>> right(n + 1, vector<int>(n, 0));
		for (int i = n - 1; i >= 0; i--) {
			right[i] = right[i + 1];
			right[i][a[i]]++;
		}

		ll ans = 0;
		for (int i = 1; i < n - 2; i++)
			for (int j = i + 1; j < n - 1; j++)
				ans += (ll) left[i][a[j]] * right[j + 1][a[i]];

		cout << ans << '\n';
	}
}