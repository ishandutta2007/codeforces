#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
using ll = long long;

void solve() {
	int n;
	cin >> n;

	vector<int> vals(n);
	for (int& v : vals) cin >> v;

	// If <= n/2 ones, delete all ones
	// If > n/2 ones, delete all zeroes and ones such that an even amount remains

	int cou = 0;
	for (auto& v : vals) cou += v;

	if (2*cou <= n) {
		cout << n/2 << '\n';
		for (int i = 0; i < n/2; ++i) cout << '0' << ' '; cout << '\n';
	} else {
		int m = n/2;
		if (m & 1) ++m;

		cout << m << '\n';
		for (int i = 0; i < m; ++i) cout << '1' << ' '; cout << '\n';
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	int t;
	cin >> t;
	for (int ti = 0; ti < t; ++ti) solve();
}