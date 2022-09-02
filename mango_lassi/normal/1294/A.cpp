#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
using ll = long long;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	int tc;
	cin >> tc;
	for (int ti = 0; ti < tc; ++ti) {
		ll a, b, c, n;
		cin >> a >> b >> c >> n;
		ll mx = max(a, max(b, c));

		n -= mx - a;
		a += mx - a;

		n -= mx - b;
		b += mx - b;
		
		n -= mx - c;
		c += mx - c;

		if (n >= 0 && n % 3 == 0) cout << "YES\n";
		else cout << "NO\n";
	}
}