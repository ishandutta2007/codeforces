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
		int sum = accumulate(a.begin(), a.end(), 0);
		if (sum % n != 0) {
			cout << "-1\n";
			continue;
		}
		a.insert(a.begin(), 0);
		vector<array<int, 3>> ops;
		auto change = [&](int i, int j, int x) {
			ops.push_back({i, j, x});
			a[i] -= i * x;
			a[j] += i * x;
			assert(a[i] >= 0);
			assert(x >= 0);
		};
		for (int i = 2; i <= n; i++) {
			if (a[i] % i != 0)
				change(1, i, i - a[i] % i);
			if (a[i] != 0)
				change(i, 1, a[i] / i);
		}
		int need = sum / n;
		for (int i = 2; i <= n; i++)
			change(1, i, need);

		assert((int) ops.size() <= 3 * n);
		cout << (int) ops.size() << '\n';
		for (auto [i, j, x] : ops)
			cout << i << ' ' << j << ' ' << x << '\n';
	}
}