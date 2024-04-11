#include <iostream>
#include <vector>
using namespace std;
using ll = long long;
const ll INF = 4 * (ll)1e18;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	int n;
	cin >> n;

	vector<int> locs;
	for (int i = 0; i < n; ++i) {
		int ai;
		cin >> ai;
		if (ai == 1) locs.push_back(i);
	}
	int m = locs.size();

	vector<ll> suff(m+1, 0), pref(m+1, 0);
	for (int j = 0; j < m; ++j) {
		pref[j+1] = pref[j] + locs[j];
		suff[m-1-j] = suff[m-j] + (n-1 - locs[m-1-j]);
	}

	// If we want to stack boxes a1 ... ak, how much time does it take?
	// equal of sum of distances to median
	
	ll res = INF;
	for (ll d = 2; d <= locs.size(); ++d) {
		if (locs.size() % d != 0) continue;

		ll off = 0;
		for (int i = 0; i < locs.size(); i += d) {
			int j = i + d - 1;
			int m = (i + j) >> 1;
			ll add = 0;
			add += (suff[i] - suff[m]) - (ll)(n-1 - locs[m]) * (m-i);
			add += (pref[j+1] - pref[m+1]) - (ll)locs[m] * (j-m);
			off += add;
		}
		res = min(res, off);
	}
	if (res < INF) cout << res << '\n';
	else cout << -1 << '\n';
}