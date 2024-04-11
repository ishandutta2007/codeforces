#include <bits/stdc++.h>

using namespace std;
using ll = long long;

signed main() {
	ios::sync_with_stdio(false);
	cin.tie(0), cout.tie(0);
	int t;
	cin >> t;
	while (t--) {
		int n, m;
		cin >> n >> m;
		vector<int> a(m), b(m);
		for (int i = 0; i < m; i++) {
			cin >> a[i] >> b[i];
		}
		vector<int> inds(m);
		iota(inds.begin(), inds.end(), 0);
		sort(inds.begin(), inds.end(), [&](int &i, int &j) {
			return b[i] < b[j] || b[i] == b[j] && a[i] < a[j];
		});
		set<pair<int, int>> st;
		ll sum = 0, ans = 0;
		for (int i = 0; i < m; i++) {
			while ((st.size() && st.begin()->first <= b[inds[i]]) || st.size() > n - 1) {
				sum -= st.begin()->first;
				st.erase(st.begin());
			}
			ll res = 0;
			res += a[inds[i]];
			res += sum;
			res += (ll)b[inds[i]] * (n - 1 - st.size());
			ans = max(ans, res);
			st.insert({a[inds[i]], inds[i]});
			sum += a[inds[i]];
		}
		cout << ans << '\n';
	}
}