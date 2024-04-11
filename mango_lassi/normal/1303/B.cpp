#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
using ll = long long;
const ll INF = 4 * (ll)1e18;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	int t;
	cin >> t;
	for (int ti = 0; ti < t; ++ti) {
		ll n, a, b;
		cin >> n >> a >> b;

		ll low = 0;
		ll high = INF;
		while(low != high) {
			ll mid = (low + high) >> 1;
			ll k = mid / (a+b);
			ll x = k * a + min(a, mid - k * (a+b));
			ll y = min(k * b + max(0ll, mid - k * (a+b) - a), n/2);
			if (x+y >= n) high = mid;
			else low = mid + 1;
		}
		cout << low << '\n';
	}
}