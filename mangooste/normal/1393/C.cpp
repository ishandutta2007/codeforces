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
		cin >> n;
		vector<int> cnt(n, 0);
		for (int i = 0; i < n; i++) {
			int x;
			cin >> x;
			cnt[x - 1]++;
		}
		int L = 0, R = n - 1;
		while (R - L > 1) {
			int mid = (L + R) / 2;
			bool ok = true;
			set<pair<int, int>, greater<pair<int, int>>> can;
			set<pair<int, pair<int, int>>> later;
			for (int i = 0; i < n; i++) {
				if (cnt[i]) can.emplace(cnt[i], i);
			}
			for (int i = 0; i < n; i++) {
				while (later.size() && later.begin()->first == i) {
					can.insert(later.begin()->second);
					later.erase(later.begin());
				}
				if (!can.size()) {
					ok = false;
					continue;
				}
				auto [num, val] = *can.begin();
				can.erase(can.begin());
				num--;
				if (num) later.insert({i + mid + 1, {num, val}});
			}
			(ok ? L : R) = mid;
		}
		cout << L << '\n';
	}
}