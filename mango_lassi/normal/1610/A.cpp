#include <bits/stdc++.h>
using namespace std;
using ll = long long;

void solve() {
	ll n, m;
	cin >> n >> m;
	if (n == 1 && m == 1) {
		cout << 0 << '\n';
	} else if (n == 1 || m == 1) {
		cout << 1 << '\n';
	} else {
		// Bottom left and top left corner
		cout << 2 << '\n';
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	int t;
	cin >> t;
	for (int ti = 0; ti < t; ++ti) solve();
}