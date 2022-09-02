#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
using namespace std;
using ll = long long;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	// Answer is sum of ai's minus sum of used milestones
	// When is a milestone useless?

	// If k milestones reward resource i, we'll always take at least ai - k of that resource, so take
	// that amount. But this is enough!

	int n;
	cin >> n;

	ll res = 0;
	vector<ll> as(n), ks(n, 0);
	for (int i = 0; i < n; ++i) {
		cin >> as[i];
		res += as[i];
	}
	map<pair<int, ll>, int> mp;

	int q;
	cin >> q;
	for (int qi = 0; qi < q; ++qi) {
		int s, u;
		ll t;
		cin >> s >> t >> u;
		--s; --u;
		pair<int, ll> pr = {s, t};

		// Remove old
		auto it = mp.find(pr);
		if (it != mp.end()) {
			int v = it->second;
			res -= max(0ll, as[v] - ks[v]);
			--ks[v];
			res += max(0ll, as[v] - ks[v]);
			mp.erase(it);
		}

		// Add new
		if (u != -1) {
			res -= max(0ll, as[u] - ks[u]);
			++ks[u];
			res += max(0ll, as[u] - ks[u]);
			mp[pr] = u;
		}

		cout << res << '\n';
	}
	
}