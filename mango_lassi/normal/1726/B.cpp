#include <bits/stdc++.h>
using namespace std;
using ll = long long;

void solve() {
	int n;
	ll m;
	cin >> n >> m;

	if (m < n) {
		cout << "No\n";
	} else if (n & 1) {
		cout << "Yes\n";
		for (int i = 0; i < n-1; ++i) cout << 1 << ' ';
		cout << m-(n-1) << '\n';
	} else if (! (m & 1)) {
		cout << "Yes\n";
		for (int i = 0; i < n - 2; i += 2) cout << 1 << ' ' << 1 << ' ';
		
		m -= n-2;
		cout << m/2 << ' ' << m/2 << '\n';
	} else {
		cout << "No\n";
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	int t;
	cin >> t;
	for (int ti = 0; ti < t; ++ti) solve();
}