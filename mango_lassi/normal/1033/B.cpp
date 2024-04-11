#include <iostream>
using namespace std;
typedef long long ll;
const ll MOD = 1e9 + 7;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	int t;
	cin >> t;
	for (int j = 0; j < t; ++j) {
		ll b, a;
		cin >> a >> b;
		// a^2 - b^2 = (a - b)(a + b)
		// prime iff b = (a-1) and 2a + 1 is prime
		if (b == a-1) {
			ll t = a + b;
			bool pr = true;
			for (ll i = 2; i * i <= t; ++i) {
				if (t % i == 0) pr = false;
			}
			if (pr) {
				cout << "YES\n";
				continue;
			}
		}
		cout << "NO\n";
	}
}