#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
using ll = long long;

void solve() {
	int n;
	ll k;
	cin >> n >> k;

	int cou = 0;
	vector<int> vals(n, 0);
	for (int i = 0; i < n; ++i) {
		ll v;
		cin >> v;

		if (v >= k) vals[i] = 1;
		if (v == k) ++cou;
	}

	// If true, can fill with largers
	bool can = (n == 1);
	for (int i = 0; i < n; ++i) {
		if (vals[i] != 1) continue;
		if (i+1 < n && vals[i+1] == 1) can = 1;
		if (i+2 < n && vals[i+2] == 1) can = 1;
	}
	if (can && cou > 0) cout << "YES\n";
	else cout << "NO\n";
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	int t;
	cin >> t;
	for (int ti = 0; ti < t; ++ti) solve();
}