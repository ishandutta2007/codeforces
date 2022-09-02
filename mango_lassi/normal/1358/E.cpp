#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
using ll = long long;
const ll INF = 1e18;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	int n;
	cin >> n;
	int h = (n+1)/2;
	int h2 = n-h;

	vector<ll> as(h);
	for (ll& v : as) cin >> v;

	ll x;
	cin >> x;

	if (x >= 0) {
		// Optimal to pick k = n
		ll sum = h2 * x;
		for (auto v : as) sum += v;
		if (sum > 0) cout << n << '\n';
		else cout << -1 << '\n';
	} else {
		// If k <= h2, we can just double k, thus WLOG k >= h
		// Get maximum k for every position. Some prefix [0, t] must have maximum >= n-t

		for (int i = h-2; i >= 0; --i) as[i] += as[i+1];

		bool fail = 1;
		int max_k = n;
		for (int i = 0; i < h; ++i) {
			if (as[i] <= 0) break;
			else {
				int xs = min((ll)h2, (as[i] - 1) / -x);
				max_k = min(max_k, (h-i) + xs);
				if (max_k >= n-i) {
					cout << max_k << '\n';
					fail = 0;
					break;
				}
			}

		}
		if (fail) cout << -1 << '\n';
	}
	
}