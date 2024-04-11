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
		vector<int> a(n);
		for (auto &x : a)
			cin >> x;
		n++;
		a.insert(a.begin(), 0);
		vector<int> b(n, 0);
		for (int i = 1; i < n; i++)
			b[i] = max(0, a[i] - a[i - 1]);
		long long ans = accumulate(b.begin(), b.end(), 0ll);
		auto change = [&](int pos, int new_val) {
			if (pos != 0)
				ans -= b[pos];
			if (pos != n - 1)
				ans -= b[pos + 1];
			if (pos != 0)
				b[pos] = max(0, new_val - a[pos - 1]);
			if (pos != n - 1)
				b[pos + 1] = max(0, a[pos + 1] - new_val);
			if (pos != 0)
				ans += b[pos];
			if (pos != n - 1)
				ans += b[pos + 1];
			a[pos] = new_val;
		};

		cout << ans << '\n';
		while (q--) {
			int l, r;
			cin >> l >> r;
			int left = a[l];
			int right = a[r];
			change(l, right);
			change(r, left);
			cout << ans << '\n';
		}
	}	
}