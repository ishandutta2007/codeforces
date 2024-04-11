#include <bits/stdc++.h>

using namespace std;

signed main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int t;
	cin >> t;
	while (t--) {
		int n, x;
		cin >> n >> x;
		vector<int> a(n);
		for (auto &x : a)
			cin >> x;
		sort(a.begin(), a.end());
		if (a[0] == a.back() && a[0] == x) {
			cout << "0\n";
			continue;
		}
		long long sum = accumulate(a.begin(), a.end(), 0ll);
		bool any_x = (upper_bound(a.begin(), a.end(), x) != lower_bound(a.begin(), a.end(), x));
		if (any_x || sum == (long long) x * n)
			cout << "1\n";
		else
			cout << "2\n";
	}
}