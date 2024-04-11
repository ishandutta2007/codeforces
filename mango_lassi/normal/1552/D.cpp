#include <bits/stdc++.h>
using namespace std;
using ll = long long;

void solve() {
	int n;
	cin >> n;

	vector<ll> as(n);
	for (ll& a : as) {
		cin >> a;
		a = abs(a);
	}
	sort(as.begin(), as.end());

	if (as[0] == 0) {
		cout << "YES\n";
		return;
	}

	// Possible IFF some two distinct subsets have same sum
	int res1 = -1, res2 = -1;
	for (int mask = 1; mask < (1 << n); ++mask) {
		ll sum = 0;
		for (int j = 0; j < n; ++j) {
			if (mask & (1 << j)) sum += as[j];
		}

		int rev = ((1 << n) - 1) ^ mask;
		for (int mask2 = rev; mask2 > 0; mask2 = ((mask2 - 1) & rev)) {
			ll sum2 = 0;
			for (int j = 0; j < n; ++j) {
				if (mask2 & (1 << j)) sum2 += as[j];
			}
			if (sum2 == sum) {
				cout << "YES\n";
				return;
			}
		}
	}
	cout << "NO\n";
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	int t;
	cin >> t;
	for (int ti = 0; ti < t; ++ti) {
		solve();
	}

}