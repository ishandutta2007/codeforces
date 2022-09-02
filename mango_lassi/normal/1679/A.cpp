#include <bits/stdc++.h>
using namespace std;
using ll = long long;

void solve() {
	ll n;
	cin >> n;
	if ((n & 1) || (n < 4)) cout << -1 << '\n';
	else cout << (n + 5) / 6 << ' ' << (n / 4) << '\n';
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	int t;
	cin >> t;
	for (int ti = 0; ti < t; ++ti) solve();
}