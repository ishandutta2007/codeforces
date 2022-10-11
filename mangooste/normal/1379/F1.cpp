#include <bits/stdc++.h>

using namespace std;
using ll = long long;

signed main() {
	ios::sync_with_stdio(false);
	cin.tie(0), cout.tie(0);
	int n, m, q;
	cin >> n >> m >> q;
	vector<pair<int, int>> qes(q);
	for (auto &[x, y] : qes) {
		cin >> x >> y;
	}
	int L = 0, R = q + 1;
	while (R - L > 1) {
		int mid = (L + R) / 2;
		vector<pair<int, int>> t0, t1;
		for (int i = 0; i < mid; i++) {
			auto [x, y] = qes[i];
			if (x % 2) {
				t0.emplace_back((x - 1) / 2, (y - 1) / 2);
			} else {
				t1.emplace_back((x - 1) / 2, (y - 1) / 2);
			}
		}
		sort(t0.begin(), t0.end());
		vector<int> pref(t0.size() + 1, 1e9);
		for (int i = 0; i < t0.size(); i++) {
			pref[i + 1] = min(pref[i], t0[i].second);
		}
		bool ok = true;
		for (auto [x, y] : t1) {
			int pos = lower_bound(t0.begin(), t0.end(), pair<int, int>{x + 1, -1e9}) - t0.begin();
			ok &= (pref[pos] > y);
		}
		(ok ? L : R) = mid;
	}
	for (int i = 0; i < L; i++) {
		cout << "YES\n";
	}
	for (int i = L; i < q; i++) {
		cout << "NO\n";
	}
}