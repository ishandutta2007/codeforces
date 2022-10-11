#include <bits/stdc++.h>

using namespace std;
using ll = long long;

signed main() {
	ios::sync_with_stdio(false);
	cin.tie(0), cout.tie(0);

	int n;
	cin >> n;
	map<ll, vector<int>> mapa;
	for (int i = 0; i < n; i++) {
		int x;
		cin >> x;
		mapa[x].push_back(i);
	}

	vector<pair<int, ll>> ans;
	while (!mapa.empty()) {
		auto [val, els] = *mapa.begin();
		sort(els.begin(), els.end());

		if (els.size() % 2) {
			ans.emplace_back(els.back(), val);
			els.pop_back();
		}

		for (int i = 0; i < els.size(); i += 2) {
			mapa[2 * val].push_back(els[i + 1]);
		}

		mapa.erase(mapa.begin());
	}

	sort(ans.begin(), ans.end());

	cout << ans.size() << '\n';
	for (auto &[pos, val] : ans) {
		cout << val << ' ';
	}
}