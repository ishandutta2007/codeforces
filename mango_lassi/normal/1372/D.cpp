#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
using ll = long long;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	int n;
	cin >> n;

	// Delete (n-1)/2, but no two adjacent ones
	// -> Select two adjacent ones to keep

	vector<ll> as(n);
	for (ll& a : as) cin >> a;

	ll sum = 0;
	vector<ll> pref = as;
	vector<ll> suff = as;
	for (int i = 0; i < n; ++i) {
		sum += as[i];
		int r = n-1-i;
		if (i >= 2) {
			pref[i] = pref[i-2] + as[i];
			suff[r] = suff[r+2] + as[r];
		}
	}

	ll res = 0;
	for (int i = 0; i < n; ++i) {
		ll off = sum;
		if (i > 0) off -= pref[i-1];
		if (i+2 < n) off -= suff[i+2];
		res = max(res, off);
	}
	cout << res << '\n';
}