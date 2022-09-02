#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
using ll = long long;

void solve() {
	ll a, b, c, r;
	cin >> a >> b >> c >> r;
	if (b < a) swap(a, b);
	ll x = max(a, c - r);
	ll y = min(b, c + r);
	cout << (b-a) - max(0ll, y-x) << '\n';
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	int t;
	cin >> t;
	for (int ti = 0; ti < t; ++ti) solve();
}