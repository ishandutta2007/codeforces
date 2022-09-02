#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
using ll = long long;

void solve() {
	ll n, r;
	cin >> n >> r;

	if (n == 1) cout << 1 << '\n';
	else {
		ll res = (r >= n);
		r = min(r, n-1);
		res += r * (r+1) / 2;
		cout << res << '\n';
	} 
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	int t;
	cin >> t;
	for (int ti = 0; ti < t; ++ti) solve();
}