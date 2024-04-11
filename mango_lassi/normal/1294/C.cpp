#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
using ll = long long;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	int tc;
	cin >> tc;
	for (int ti = 0; ti < tc; ++ti) {
		ll n;
		cin >> n;

		vector<ll> res;
		for (ll x = 2; res.size() < 2 && x*x <= n; ++x) {
			if (n % x == 0) {
				res.push_back(x);
				n /= x;
			}
		}
		if (res.size() < 2 || n <= res.back()) cout << "NO\n";
		else cout << "YES\n" << res[0] << ' ' << res[1] << ' ' << n << '\n';
	}
}