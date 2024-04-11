#include <iostream>
#include <vector>
using namespace std;
using ll = long long;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	int n;
	cin >> n;
	vector<ll> as(n);
	for (int i = 0; i < n; ++i) {
		cin >> as[i];
	}

	vector<ll> prefs(n);
	prefs[0] = as[0];
	for (int i = 1; i < n; ++i) prefs[i] = as[i] + prefs[i-1];

	// What about case where all three have same length?

	ll res = 0;
	ll rems = 0;
	for (int i = n-1; i >= 0; --i) {
		// Count how much we can borrow
		ll mb = (i == 0 ? 0 : prefs[i-1]) - rems;
		if (mb < 0) {
			as[i] += mb;
			rems += mb;
			mb = 0;
		}

		// Take 3 if odd
		if (as[i] % 2 == 1 && as[i] >= 3) {
			++res;
			as[i] -= 3;
		}

		// Take k times 2
		ll k = min(mb, as[i] / 2);
		res += k;
		rems += k;
		mb -= k;
		as[i] -= 2 * k;

		// Take k times 3
		k = as[i] / 3;
		res += k;
		as[i] -= 3 * k;

		// Remove possible last element
		rems -= min(rems, as[i]);
	}
	cout << res << '\n';
}