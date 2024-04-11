#include <bits/stdc++.h>
using namespace std;
using ll = long long;

void solve() {
	ll a, b, c;
	cin >> a >> b >> c;

	ll z = c;
	ll y = z + b;
	ll x = y + a;
	cout << x << ' ' << y << ' ' << z << '\n';
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	int t;
	cin >> t;
	for (int ti = 0; ti < t; ++ti) solve();
}