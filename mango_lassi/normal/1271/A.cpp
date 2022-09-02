#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
using ll = long long;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	ll a, b, c, d, e, f;
	cin >> a >> b >> c >> d >> e >> f;

	ll x = a;
	ll y = min(b, c);

	if (e > f) {
		x = min(x, d);
		d -= x;
		y = min(y, d);
		d -= y;
	} else {
		y = min(y, d);
		d -= y;
		x = min(x, d);
		d -= x;
	}
	cout << x*e + y*f << '\n';
}