#include <bits/stdc++.h>
using namespace std;
using ll = long long;

void solve() {
	ll n;
 	cin >> n;

	ll x = 1;
	while(2*x*x < n) ++x;

	ll y = 1;
	while(4*y*y < n) ++y;

	if (2*x*x == n || 4*y*y == n) {
		cout << "YES\n";
	} else {
		cout << "NO\n";
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	int t;
	cin >> t;
	for (int ti = 0; ti < t; ++ti) solve();
}