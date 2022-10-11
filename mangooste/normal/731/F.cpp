#include <bits/stdc++.h>

using namespace std;
using ll = long long;

signed main() {
	ios::sync_with_stdio(false);
	cin.tie(0), cout.tie(0);
	int n;
	cin >> n;
	vector<int> a(n);
	for (auto &el : a) {
		cin >> el;
	}
	sort(a.begin(), a.end());
	int m = a.back() + 1;
	vector<int> cnt(m + 1, 0);
	for (auto &el : a) {
		cnt[el]++;
	}
	vector<int> pref(m, 0);
	for (int i = 1; i < m; i++) {
		pref[i] = pref[i - 1] + cnt[i];
	}
	ll ans = 0;
	for (int i = 0; i < n; i++) {
		if (i && a[i] == a[i - 1]) {
			continue;
		}
		ll res = 0;
		for (int j = a[i]; j < m; j += a[i]) {
			res += 1ll * (pref[min(m - 1, j + a[i] - 1)] - pref[j - 1]) * j;
		}
		ans = max(ans, res);
	}
	cout << ans;
}