#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
using ll = long long;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	int n, m;
	cin >> n >> m;

	if (n > m) cout << 0 << '\n';
	else {
		vector<ll> vals(n);
		for (ll& v : vals) cin >> v;

		ll res = 1;
		for (int i = 0; i < n; ++i) {
			for (int j = 0; j < i; ++j) {
				res = (res * abs(vals[i] - vals[j])) % m;
			}
		}
		cout << res << '\n';
	}
}