#include <iostream>
using namespace std;
typedef long long ll;

ll gcd(ll a, ll b) {
	if (b == 0) return a;
	return gcd(b, a % b);
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	// Area is:
	ll n, m, k;
	cin >> n >> m >> k;

	ll prod = n * m;
	ll gd = gcd(prod, k);
	k /= gd;

	if (k > 2) {
		cout << "NO\n";
	} else {
		cout << "YES\n";

		ll rem = gcd(n, gd);
		if (k == 1) {
			if (rem >= 2) {
				n *= 2;
			} else {
				m *= 2;
			}
		}
		n /= rem;
		m /= gd / rem;
		cout << "0 0\n";
		cout << n << " 0\n";
		cout << n << ' ' << m << '\n';
	}
}