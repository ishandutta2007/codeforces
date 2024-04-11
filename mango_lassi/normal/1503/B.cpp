#include <bits/stdc++.h>
using namespace std;
using ll = long long;

void solve() {
	int n;
	cin >> n;

	// Always extend either c = 1, x+y even grid, or c = 2, x+y odd grid
	// Once one grid is full, we win no matter what!

	vector<pair<int, int>> pos_even, pos_odd;
	for (int y = 1; y <= n; ++y) {
		for (int x = 1; x <= n; ++x) {
			if ((x + y) & 1) pos_odd.emplace_back(y, x);
			else pos_even.emplace_back(y, x);
		}
	}

	for (int ind = 0; ind < n*n; ++ind) {
		int ban;
		cin >> ban;

		int pick_c = -1;
		int pick_p = -1;
		if (pos_even.empty() ) {
			pick_p = 1;
			pick_c = (ban == 3 ? 2 : 3);
		} else if (pos_odd.empty()) {
			pick_p = 0;
			pick_c = (ban == 1 ? 2 : 1);
		} else if (ban == 1) {
			pick_p = 1;
			pick_c = 3;
		} else {
			pick_p = 0;
			pick_c = 1;
		}

		pair<int, int> pos;
		if (pick_p == 0) {
			pos = pos_even.back();
			pos_even.pop_back();
		} else {
			pos = pos_odd.back();
			pos_odd.pop_back();
		}
		cout << pick_c << ' ' << pos.first << ' ' << pos.second << endl;
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	solve();
}