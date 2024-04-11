#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
using ll = long long;

const ll INF = (ll)1e9 + 7;


void solve() {
	int n;
	cin >> n;

	// Everything after maximum should be made equal to it
	// -> There exists an optimal solution where every operation only acts on supports of the same height

	ll res = 0;
	ll cur = 0, cur_max = 0;
	for (int i = 0; i < n; ++i) {
		ll a;
		cin >> a;
		if (a > cur) {
			ll t = min(a, cur_max);
			res += t - cur;
		}
		cur = a;
		cur_max = max(cur_max, a);
	}
	res += cur_max - cur;
	cout << res << '\n';
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	int t;
	cin >> t;
	for (int ti = 0; ti < t; ++ti) solve();
}