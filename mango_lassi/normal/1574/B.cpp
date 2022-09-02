#include <bits/stdc++.h>
using namespace std;
using ll = long long;

void solve() {
	ll a, b, c, m;
	cin >> a >> b >> c >> m;

	if (a < b) swap(a, b);
	if (a < c) swap(a, c);
	if (b < c) swap(b, c);
	
	ll must = max(0ll, (a - 1) - b - c);
	ll can = max(0ll, a - 1) + max(0ll, b - 1) + max(0ll, c - 1);
	
	if (must <= m && m <= can) cout << "YES\n";
	else cout << "NO\n";
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	int t;
	cin >> t;
	for (int ti = 0; ti < t; ++ti) solve();
}