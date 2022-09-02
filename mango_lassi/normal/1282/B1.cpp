#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
using ll = long long;

void solve() {
	int n, k;
	ll p;
	cin >> n >> p >> k;

	vector<ll> as(n);
	for (int i = 0; i < n; ++i) cin >> as[i];
	sort(as.begin(), as.end());

	// Number of goods we buy on their own
	int res = 0;
	for (int j = 0; j < k; ++j) {
		int off = j;
		ll tmp = p;
		for (int i = j+k-1; i < n; i += k) {
			tmp -= as[i];
			if (tmp >= 0) off += k;
			else break;
		}
		res = max(res, off);

		p -= as[j];
		if (p < 0) break;
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