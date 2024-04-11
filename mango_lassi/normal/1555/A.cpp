#include <bits/stdc++.h>
using namespace std;
using ll = long long;

void solve() {
	ll n;
	cin >> n;

	if (n & 1) ++n;
	if (n <= 6) n = 6;
	cout << n / 2 * 5 << '\n';
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	int t;
	cin >> t;
	for (int ti = 0; ti < t; ++ti) solve();
}