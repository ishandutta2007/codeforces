#include <iostream>
#include <vector>
using namespace std;
typedef long long ll;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	ll res = 0;

	ll n, m;
	cin >> n >> m;
	for (ll x = 1; x <= m; ++x) {
		for (ll y = 1; y <= m; ++y) {
			ll sqr = x*x + y*y;
			ll x_cou = (n+m-x) / m;
			ll y_cou = (n+m-y) / m;
			if (sqr % m == 0) {
				res += x_cou * y_cou;
			}
		}
	}
	cout << res << '\n';
}