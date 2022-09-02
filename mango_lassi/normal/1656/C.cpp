#include <bits/stdc++.h>
using namespace std;
using ll = long long;

void solve() {
	int n;
	cin >> n;

	vector<ll> as(n);
	for (ll& a : as) cin >> a;
	sort(as.begin(), as.end());

	// If the array doesn't contain a 1, the answer is YES (starting from largest number, apply x = that number -> everything becomes 0)
	// Otherwise, we have to make everything into a 1. This is possible IFF we don't have y and y + 1 for some y.
	// To see this, note that after any operation, either one of them becomes 0, or their difference is still 1.

	bool has_one = 0;
	for (ll v : as) has_one |= (v == 1);

	if (has_one) {
		bool works = 1;
		for (int i = 1; i < n; ++i) works &= (as[i] != as[i-1] + 1);
		if (works) cout << "YES\n";
		else cout << "NO\n";
	} else {
		cout << "YES\n";
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	int t;
	cin >> t;
	for (int ti = 0; ti < t; ++ti) solve();
}