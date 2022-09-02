#include <iostream>
#include <vector>
using namespace std;
typedef long long ll;
const ll MOD = 1e9 + 7;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	ll x, y, z;
	ll a, b, c;
	cin >> x >> y >> z;
	cin >> a >> b >> c;

	bool fail = false;
	if (x > a) fail = true;
	else {
		a -= x;
	}

	if (y > a + b) fail = true;
	else {
		ll cou = min(y, a);
		a -= cou;
		y -= cou;
		b -= y;
	}

	if (z > a+b+c) fail = true;
	
	if (fail) {
		cout << "NO\n";
	} else {
		cout << "YES\n";
	}
}