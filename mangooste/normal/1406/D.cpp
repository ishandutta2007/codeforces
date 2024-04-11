#include <bits/stdc++.h>

using namespace std;

const long long INF = 1e18;

signed main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr), cout.tie(nullptr);

	int n;
	cin >> n;
	vector<long long> a(n);
	for (auto &x : a)
		cin >> x;
	vector<long long> b(n);
	for (int i = 1; i < n; i++)
		b[i] = a[i] - a[i - 1];
	long long sum = 0;
	auto add = [&](int pos) {
		if (pos < 1 || pos >= n)
			return 0ll;
		return max(0ll, b[pos]);
	};
	for (int i = 1; i < n; i++)
		sum += add(i);

	auto solve = [&]() {
		auto check = [&](long long val) {
			return a[0] - val + sum <= val;
		};
		long long lb = -INF;
		long long rb = INF;
		while (rb - lb > 1) {
			long long mid = (lb + rb) / 2;
			if (check(mid))
				rb = mid;
			else
				lb = mid;
		}
		cout << rb << '\n';
	};

	solve();
	int q;
	cin >> q;
	while (q--) {
		int L, R;
		long long del;
		cin >> L >> R >> del;
		L--;

		sum -= add(L);
		sum -= add(R);
		b[L] += del;
		if (R != n)
			b[R] -= del;
		sum += add(L);
		sum += add(R);
		a[L] += del;

		solve();
	}
}