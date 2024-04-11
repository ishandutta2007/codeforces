#include <bits/stdc++.h>
using namespace std;
using ll = long long;

void solve() {
	int n, m;
	cin >> n >> m;
	int mx = (m + 1) / 2;

	vector<int> apps(n), picks(m);
	vector<vector<int>> days(m);
	for (int i = 0; i < m; ++i) {
		int k;
		cin >> k;
		days[i].resize(k);
		for (int& j : days[i]) {
			cin >> j;
			--j;
		}
		picks[i] = days[i][0];
		++apps[picks[i]];
	}

	pair<int, int> worst = {0, -1};
	for (int i = 0; i < n; ++i) {
		worst = max(worst, {apps[i] - mx, i});
	}
	for (int i = 0; i < m && worst.first > 0; ++i) {
		if (picks[i] == worst.second && days[i].size() > 1) {
			picks[i] = days[i][1];
			--worst.first;
		}
	}

	if (worst.first <= 0) {
		cout << "YES\n";
		for (auto i : picks) cout << i+1 << ' '; cout << '\n';
	} else {
		cout << "NO\n";
	}

	
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	int t;
	cin >> t;
	for (int ti = 0; ti < t; ++ti) solve();
}