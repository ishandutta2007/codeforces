#include <bits/stdc++.h>

using namespace std;
using ll = long long;

signed main() {
	ios::sync_with_stdio(false);
	cin.tie(0), cout.tie(0);

	int n;
	cin >> n;
	vector<vector<ll>> a(n, vector<ll>(n, 0));
	vector<vector<ll>> suf(n, vector<ll>(n, 0));

	for (int j = n - 2; j >= 0; j--)
		for (int i = 1; i < n; i++) {
			a[i][j]++;
			for (int k = i - 1; k < n - 1; k++)
				a[i][j] += a[k][j + 1];
			for (int k = j + 1; k < n; k++)
				a[i][j] += a[n - 1][k];
			a[i][j] -= suf[i][j + 1];

			assert(a[i][j] <= 10'000'000'000'000'000ll);
			suf[i][j] = suf[i][j + 1] + a[i][j];
		}

	for (auto xs : a) {
		for (auto x : xs)
			cout << x << ' ';
		cout << '\n';
	}
	cout << flush;

	int q;
	cin >> q;
	while (q--) {
		ll sum;
		cin >> sum;

		vector<pair<int, int>> order;
		for (int x = 0, y = 0; y < n; y++) {
			order.emplace_back(x, y);
			sum -= a[x][y];
			while (x < n - 1 && suf[x + 1][y] <= sum) {
				sum -= a[++x][y];
				order.emplace_back(x, y);
			}
		}

		for (auto [x, y] : order)
			cout << x + 1 << ' ' << y + 1 << '\n';
		cout << flush;
	}
}