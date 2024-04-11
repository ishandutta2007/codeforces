#include <bits/stdc++.h>
using namespace std;
using ll = long long;

void solve() {
	ll n;
	cin >> n;

	ll k = n / 2020;
	ll r = n % 2020;
	if (r <= k) cout << "YES\n";
	else cout << "NO\n";
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	int t;
	cin >> t;
	for (int ti = 0; ti < t; ++ti) solve();
}