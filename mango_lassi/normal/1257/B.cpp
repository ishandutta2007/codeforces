#include <iostream>
#include <vector>
using namespace std;
using ll = long long;

void solve() {
	ll x, y;
	cin >> x >> y;
	if (x >= 4) cout << "YES\n";
	else if (x >= 2 && y < 4) cout << "YES\n";
	else if (y == 1) cout << "YES\n";
	else cout << "NO\n";
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	int t;
	cin >> t;
	for (int ti = 0; ti < t; ++ti) solve();
}