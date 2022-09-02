#include <iostream>
#include <vector>
using namespace std;
using ll = long long;
const ll INF = 1e18;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	ll n, p;
	cin >> n >> p;

	ll res = INF;
	for (ll c = 0;; ++c) {
		// Repeated summands allowed!
		ll t = n - p*c;
		if (t < 0) break;

		int cou = __builtin_popcountll(t);;
		if (cou <= c && c <= t) {
			res = c;
			break;
		}
	}
	if (res >= INF) cout << -1 << '\n';
	else cout << res << '\n';
}