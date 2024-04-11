#include <bits/stdc++.h>

using namespace std;
using ll = long long;

signed main() {
	ios::sync_with_stdio(false);
	cin.tie(0), cout.tie(0);

	int t;
	cin >> t;
	while (t--) {
		int n;
		string s;
		cin >> n >> s;
		vector<int> pref(n + 1, 0);
		for (int i = 0; i < n; i++) pref[i + 1] = pref[i] + s[i] - '0';
		ll ans = 0;
		map<int, int> cnt;
		for (int i = 0; i <= n; i++) cnt[pref[i] - i]++;
		for (auto [_, num] : cnt) ans += (ll) num * (num - 1) / 2;
		cout << ans << '\n';
	}
}