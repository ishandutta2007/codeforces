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
		vector<int> a(n);
		for (auto &x : a)
			cin >> x;

		sort(a.rbegin(), a.rend());
		vector<char> used(n, 0);
		vector<int> b{a[0]};
		used[0] = 1;

		int g = b[0];
		for (int i = 0; i < n - 1; i++) {
			int mx = 0;
			for (int j = 0; j < n; j++)
				if (!used[j])
					mx = max(mx, __gcd(g, a[j]));

			for (int j = 0; j < n; j++)
				if (!used[j] && __gcd(g, a[j]) == mx) {
					used[j] = 1;
					b.push_back(a[j]);
					g = __gcd(g, a[j]);
					break;
				}
		}

		for (auto x : b)
			cout << x << ' ';
		cout << '\n';
	}
}