#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
using ll = long long;

void solve() {
	ll a, b, c;
	cin >> a >> b >> c;

	if (a < c) cout << 1 << ' ';
	else cout << -1 << ' ';

	if (a*b > c) cout << b << ' ';
	else cout << -1 << ' ';
	
	cout << '\n';
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	int t;
	cin >> t;
	for (int ti = 0; ti < t; ++ti) solve();
}