#include <bits/stdc++.h>

using namespace std;
using ll = long long;

signed main() {
	ios::sync_with_stdio(false);
	cin.tie(0), cout.tie(0);

	int n, d, m;
	cin >> n >> d >> m;
	array<vector<int>, 2> types;
	for (int i = 0; i < n; i++) {
		int x;
		cin >> x;
		types[x > m].push_back(x);
	}
	for (int i = 0; i < 2; i++) sort(types[i].rbegin(), types[i].rend());
	array<vector<ll>, 2> pref;
	for (int i = 0; i < 2; i++) {
		pref[i].push_back(0);
		for (int j = 0; j < types[i].size(); j++) pref[i].push_back(pref[i].back() + types[i][j]);
	}
	ll ans = 0;
	for (int i = 0; i < pref[0].size(); i++) {
		ll loc = 0;
		loc += pref[0][i];
		int cnt = min(1 * types[1].size(), (types[1].size() + types[0].size() - i + d) / (d + 1));
		loc += pref[1][cnt];
//		cout << "i = " << i << " loc = " << loc << '\n';
		ans = max(ans, loc);
	}
	cout << ans << '\n';
}