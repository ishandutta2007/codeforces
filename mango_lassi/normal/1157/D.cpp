#include <iostream>
#include <vector>
using namespace std;
using ll = long long;

ll inc(ll a, ll b) {
	return a*b + (b * (b-1) / 2);
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	ll n, k;
	cin >> n >> k;

	// Always possible if the count is large enough!
	vector<ll> res(k);

	ll pa = 0;
	for (ll i = 0; i < k; ++i) {
		ll b = k - i;

		ll low = pa + 1;
		ll high = (i == 0 ? (ll)1e9 : 2 * pa);
		while(low != high) {
			ll mid = (low + high + 1) >> 1;
			if (inc(mid, b) <= n) {
				low = mid;
			} else {
				high = mid - 1;
			}
		}
		pa = low;
		res[i] = low;
		n -= pa;
	}
	if (n == 0) {
		cout << "YES\n";
		for (auto v : res) cout << v << ' '; cout << '\n';
	} else {
		cout << "NO\n";
	}
}