#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
using ll = long long;

void solve() {
	int n;
	ll x;
	cin >> n >> x;

	ll mx = 0;
	bool ex = 0;
	for (int i = 0; i < n; ++i) {
		ll a;
		cin >> a;
		if (a == x) ex = 1;
		mx = max(mx, a);
	}
	
	if (ex) cout << 1 << '\n';
	else cout << max(2ll, (x + mx-1) / mx) << '\n';
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	int t;
	cin >> t;
	for (int ti = 0; ti < t; ++ti) {
		solve();
	}
}