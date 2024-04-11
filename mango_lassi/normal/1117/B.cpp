#include <iostream>
#include <vector>
using namespace std;
using ll = long long;
const ll MOD = 1e9 + 7;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	int n;
	ll m, k;
	cin >> n >> m >> k;

	ll mx1 = -1;
	ll mx2 = -1;
	for (int i = 0; i < n; ++i) {
		ll v;
		cin >> v;
		if (v > mx1) {
			mx2 = mx1;
			mx1 = v;
		} else if (v > mx2) mx2 = v;
	}
	ll res = (m/(k+1)) * (mx1 *k + mx2) + (m % (k+1)) * mx1;
	cout << res << '\n';
}