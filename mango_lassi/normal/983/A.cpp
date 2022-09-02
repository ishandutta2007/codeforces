#include <iostream>
using namespace std;
typedef long long ll;

ll gcd(ll a, ll b) {
	if (a < b) return gcd(b, a);
	if (b == 0) return a;
	return gcd(b, a % b);
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	int n;
	cin >> n;
	for (int i = 0; i < n; ++i) {
		ll p, q, b;
		cin >> p >> q >> b;
		ll v = q / gcd(p, q);
		while(v > 1) {
			b = gcd(v, b);
			if (b == 1) break;
			while(v % b == 0) v /= b;
		}
		if (v == 1) {
			cout << "Finite\n";
		} else {
			cout << "Infinite\n";
		}
	}
}