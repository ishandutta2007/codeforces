#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
using ll = long long;

bool check(ll a, ll low, ll high) {
	return low <= a && a <= high;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	int tc;
	cin >> tc;
	for (int ti = 0; ti < tc; ++ti) {
		ll a, b, c, d;
		cin >> a >> b >> c >> d;
		ll x, y, x0, y0, x1, y1;
		cin >> x >> y >> x0 >> y0 >> x1 >> y1;

		bool fail = false;
		if ((x0 == x1 && (a != 0 || b != 0)) || (y0 == y1 && (c != 0 || d != 0))) fail = true;
		if (!check(x, x0, x1) || !check(y, y0, y1)) fail = true;
		if (!check(x - a + b, x0, x1) || !check(y - c + d, y0, y1)) fail = true;
		if (fail) cout << "NO\n";
		else cout << "YES\n";
	}
}