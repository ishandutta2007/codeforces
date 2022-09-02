#include <iostream>
#include <vector>
using namespace std;
using ll = long long;
const ll MOD = 1e9 + 7;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	int n;
	cin >> n;

	// Count number of intervals where this is contained but the one before it isn't.

	ll res = 0;
	vector<int> as(n);
	for (int i = 0; i < n; ++i) {
		ll v;
		cin >> v;
		as[i] = v;

		ll pv = (i > 0 ? as[i-1] : 0);
		ll low = (pv <= as[i] ? pv + 1 : 1);
		ll high = (pv >= as[i] ? pv - 1 : n);
		ll add = (high - v + 1) * (v - low + 1);
		res += add;
	}
	cout << res << '\n';
}