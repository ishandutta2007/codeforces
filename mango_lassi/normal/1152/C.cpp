#include <iostream>
#include <vector>
using namespace std;
using ll = long long;
const ll INF = 2 * (ll)1e18;

ll gcd(ll a, ll b) {
	if (b == 0) return a;
	return gcd(b, a % b);
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	ll a, b;
	cin >> a >> b;
	
	// LCA(a+k, b+k) = LCA(x, x + k)
	// With the bound x >= a.

	if (b < a) swap(a, b);
	ll k = b - a;

	ll x = a;
	ll pen = INF;

	for (ll td = 1; td*td <= k; ++td) {
		if (k % td != 0) continue;
		for (ll d : {td, k / td}) {
			ll ox = ((a + d-1) / d) * d;
			ll of = (ox * (ox+k)) / gcd(ox, ox+k);
			if (of < pen) {
				x = ox;
				pen = of;
			}
		}
	}
	cout << x-a << '\n';
}