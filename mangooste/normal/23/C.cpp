#include <bits/stdc++.h>
using namespace std;

signed main() {
	ios::sync_with_stdio(false);
	cin.tie(0), cout.tie(0);

	int t;
	cin >> t;
	while (t--) {
		int n;
		cin >> n;
		vector<array<int64_t, 3>> a(2 * n - 1);
		for (int i = 0; i < 2 * n - 1; i++) {
			cin >> a[i][0] >> a[i][1];
			a[i][2] = i + 1;
		}

		sort(a.rbegin(), a.rend());
		vector<int> res{a[0][2]};
		for (int i = 1; i + 1 < 2 * n - 1; i += 2)
			res.push_back(a[i][1] > a[i + 1][1] ? a[i][2] : a[i + 1][2]);

		cout << "YES\n";
		for (auto x : res)
			cout << x << ' ';
		cout << '\n';
	}
}