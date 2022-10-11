#include <bits/stdc++.h>

using namespace std;
using ll = long long;

int get(int L, int R, vector<int> &a) {
	int La = lower_bound(a.begin(), a.end(), L) - a.begin();
	int Ra = upper_bound(a.begin(), a.end(), R) - a.begin();

	if (Ra == La) {
		return 0;
	}

	int mx = max(a[La] - L, R - a[Ra - 1]);
	for (int i = La + 1; i < Ra; i++) {
		mx = max(mx, a[i] - a[i - 1]);
	}

	return R - L - mx;
}

signed main() {
	ios::sync_with_stdio(false);
	cin.tie(0), cout.tie(0);

	int n;
	cin >> n;
	array<vector<int>, 3> all;
	for (int i = 0; i < n; i++) {
		int x;
		char t;
		cin >> x >> t;
		all[t == 'P' ? 0 : (t == 'R' ? 1 : 2)].push_back(x);
	}

	for (int i = 0; i < 3; i++) {
		sort(all[i].begin(), all[i].end());
	}

	ll ans = 0;

	if (!all[0].size()) {
		for (int i = 1; i < 3; i++) {
			if (all[i].size()) {
				ans += all[i].back() - all[i][0];
			}
		}
		cout << ans;
		return 0;
	}

	for (int i = 1; i < 3; i++) {
		if (!all[i].size()) {
			continue;
		}

		ans += max(0, all[i].back() - all[0].back());
		ans += max(0, all[0][0] - all[i][0]);

		while (all[i].size() && all[i].back() >= all[0].back()) {
			all[i].pop_back();
		}
		reverse(all[i].begin(), all[i].end());
		while (all[i].size() && all[i].back() <= all[0][0]) {
			all[i].pop_back();
		}
		reverse(all[i].begin(), all[i].end());

		vector<int> new_all;
		for (auto el : all[i]) {
			int cnt = upper_bound(all[0].begin(), all[0].end(), el) - lower_bound(all[0].begin(), all[0].end(), el);
			if (!cnt) {
				new_all.push_back(el);
			}
		}

		all[i] = new_all;
	}

	for (int i = 1; i < all[0].size(); i++) {
		int maybe = get(all[0][i - 1], all[0][i], all[1]) + get(all[0][i - 1], all[0][i], all[2]);
		ans += min(maybe, all[0][i] - all[0][i - 1]) + all[0][i] - all[0][i - 1];
	}

	cout << ans;
}