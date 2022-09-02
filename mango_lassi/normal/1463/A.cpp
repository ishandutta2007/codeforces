#include <bits/stdc++.h>
using namespace std;
using ll = long long;

void solve() {
	ll a, b, c;
	cin >> a >> b >> c;

	ll k = (a + b + c) / 9;
	if (a >= k && b >= k && c >= k && (((a + b + c) % 9) == 0)) cout << "Yes\n";
	else cout << "No\n";
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	int t;
	cin >> t;
	for (int ti = 0; ti < t; ++ti) solve();
}