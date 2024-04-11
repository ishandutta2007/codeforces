#include <bits/stdc++.h>
using namespace std;
using ll = long long;

// \sum_{i = 0}^{n-1} \sum_{j = i+1}^{n-1} (a[i] + a[j])^2
// = \sum_{i = 0}^{n-1} \sum_{j = i+1}^{n-1} a[i]^2 + a[j]^2 + 2a[i]a[j]
// = (\sum_{i = 0}^{n-1} (n-3) a[i]^2) + 2 \sum_{i = 0}^{n-1} a[i] * (\sum_{j = 0}^{n-1} a[j])
// = (\sum_{i = 0}^{n-1} (n-3) a[i]^2) + 2 (\sum_{j = 0}^{n-1} a[j])^2
// -> Only care about sum, and must make it as close to TOTAL/2 as possible

void solve() {
	int n;
	cin >> n;

	vector<int> as(n), bs(n);
	for (int& a : as) cin >> a;
	for (int& b : bs) cin >> b;
	int m = 100 * n;

	ll res = 0, total = 0;
	vector<bool> can(m + 1, 0);
	can[0] = 1;
	for (int i = 0; i < n; ++i) {
		total += as[i] + bs[i];
		res += as[i] * as[i] * (n-2);
		res += bs[i] * bs[i] * (n-2);
		for (int j = m; j >= 0; --j) {
			can[j] = ((j >= as[i] && can[j - as[i]]) || (j >= bs[i] && can[j - bs[i]]));
		}
	}

	for (int j = total / 2; j >= 0; --j) {
		if (can[j]) {
			res += j*j + (total-j)*(total-j);
			break;
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