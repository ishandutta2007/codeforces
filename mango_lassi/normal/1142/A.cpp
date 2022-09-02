#include <iostream>
#include <vector>
using namespace std;
using ll = long long;
const ll MOD = 1e9 + 7;

ll gcd(ll a, ll b) {
	if (b == 0) return a;
	return gcd(b, a % b);
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	ll n, k;
	cin >> n >> k;

	ll a, b;
	cin >> a >> b;

	ll mins = 1e18;
	ll maxs = 0;
	for (ll s : {a, k-a}) {
		for (ll t : {b, k-b}) {
			for (ll l = t - s; l < n*k; l += k) {
				if (l < 0) continue;
				ll v = n*k / gcd(l, n*k);
				mins = min(mins, v);
				maxs = max(maxs, v);
			}
		}
	}
	cout << mins << ' ' << maxs << '\n';
}