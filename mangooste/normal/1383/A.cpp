#include <bits/stdc++.h>

using namespace std;
using ll = long long;

const int N = 20;

signed main() {
	ios::sync_with_stdio(false);
	cin.tie(0), cout.tie(0);

	int t;
	cin >> t;
	while (t--) {
		int n;
		string a, b;
		cin >> n >> a >> b;

		bool ok = true;

		vector<vector<int>> want(20);
		for (int i = 0; i < n; i++) {
			if (a[i] > b[i]) {
				ok = false;
				break;
			}
			want[a[i] - 'a'].push_back(b[i] - 'a');
		}

		if (!ok) {
			cout << "-1\n";
			continue;
		}

		int ans = 0;

		for (int i = 0; i < 20; i++) {
			sort(want[i].rbegin(), want[i].rend());
			while (want[i].size() && want[i].back() == i) {
				want[i].pop_back();
			}
			reverse(want[i].begin(), want[i].end());

			if (!want[i].size()) {
				continue;
			}

			ans++;
			int mn = want[i][0];
			while (want[i].size()) {
				want[mn].push_back(want[i].back());
				want[i].pop_back();
			}
		}

		cout << ans << '\n';
	}
}