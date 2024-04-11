#include <bits/stdc++.h>
using namespace std;
using ll = long long;

void solve() {
	int n;
	cin >> n;

	vector<ll> as(n);
	for (ll& a : as) cin >> a;

	// a, b
	// a, a + b
	// -b, a + b
	// -b, a
	// -b, a - b
	// -a, a - b
	// -a, -b

	// a, b
	// a + b, b
	// a + b, -a
	// -a + b, -a
	// -a + b, -b
	// -a, -b


	cout << 6 * (n / 2) << '\n';
	for (int i = 0; i < n; i += 2) {
		// a, b
		cout << "1 " << i+1 << ' ' << i+2 << '\n'; // a + b, b
		cout << "2 " << i+1 << ' ' << i+2 << '\n'; // a + b, -a
		cout << "1 " << i+1 << ' ' << i+2 << '\n'; // b, -a
		cout << "1 " << i+1 << ' ' << i+2 << '\n'; // -a + b, -a
		cout << "2 " << i+1 << ' ' << i+2 << '\n'; // -a + b, -b
		cout << "1 " << i+1 << ' ' << i+2 << '\n'; // -a, -b
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	int t;
	cin >> t;
	for (int ti = 0; ti < t; ++ti) solve();
}