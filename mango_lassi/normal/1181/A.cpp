#include <iostream>
#include <vector>
using namespace std;
using ll = long long;
const ll MOD = 1e9 + 7;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	ll x, y, z;
	cin >> x >> y >> z;
	ll c = (x+y) / z;
	x %= z;
	y %= z;
	if (x+y >= z) {
		cout << c << ' ' << min(z-x, z-y) << '\n';
	} else {
		cout << c << ' ' << 0 << '\n';
	}
}