#include <bits/stdc++.h>
using namespace std;
using ll = long long;

void solve() {
	int n;
	cin >> n;
	vector<int> as(n);
	for (int& a : as) cin >> a;

	int res = max(n-2, 0);
	for (int i0 = 0; i0 < n; ++i0) {
		for (int j0 = i0 + 1; j0 < n; ++j0) {
			int cou = 0;
			for (int i = 0; i < n; ++i) {
				ll num = (i - i0) * (as[j0] - as[i0]);
				ll div = j0 - i0;
				if ((as[i] - as[i0]) * div == num) ++cou;
			}
			res = min(res, n - cou);
		}
	}
	cout << res << '\n';
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	int t;
	cin >> t;
	for (int ti = 0; ti < t; ++ti) solve();
}