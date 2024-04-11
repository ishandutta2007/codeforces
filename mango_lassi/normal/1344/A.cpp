#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
using ll = long long;

void solve() {
	int n;
	cin >> n;

	// f(x) = x + a[x % n]
	// -> Just take mod n of these, and see if there are any conflicts

	bool fail = 0;
	vector<bool> used(n, 0);
	for (int i = 0; i < n; ++i) {
		ll a;
		cin >> a;
		a += i;

		a %= n;
		if (a < 0) a += n;
		if (used[a % n]) fail = 1;
		else used[a % n] = 1;
	}
	if (fail) cout << "NO\n";
	else cout << "YES\n";
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	int t;
	cin >> t;
	for (int ti = 0; ti < t; ++ti) solve();
}