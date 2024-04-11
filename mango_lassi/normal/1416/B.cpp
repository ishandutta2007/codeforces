#include <bits/stdc++.h>
using namespace std;
using ll = long long;

void solve() {
	// If possible, we can pile everything at zero
	// Then it is trivial to get all to equal, if the sum is divisible by n

	// 1. Pick largest pile that we can move out of. Move from it as much as possible to 1
	// 2. For all piles but 1, in any order: move in enough to make the amount in the pile (indexed k) a multiple of k
	//	Then, move all that back to 1
	// 3. Move everything out evenly

	int n;
	cin >> n;

	int j = 0;
	vector<int> as(n);
	for (int i = 0; i < n; ++i) {
		cin >> as[i];
		if (as[i] >= i+1) j = i;
	}

	vector<pair<int, pair<int, int>>> ops;
	if (j > 0) {
		int x = as[j] / (j+1);
		as[j] -= x * (j+1);
		as[0] += x * (j+1);
		ops.push_back({x, {j+1, 1}});
	}

	vector<pair<int, int>> needs;
	for (int i = 1; i < n; ++i) {
		needs.push_back({max(0, i+1 - as[i]), i});
	}
	sort(needs.begin(), needs.end());

	bool fail = 0;
	for (auto pr : needs) {
		if (as[0] >= pr.first) {
			j = pr.second;
			int need = ((j + 1) - (as[j] % (j+1))) % (j+1);
			if (need > 0) {
				ops.push_back({need, {1, j+1}});
				as[j] += need;
				as[0] -= need;
			}
			int x = as[j] / (j+1);
			ops.push_back({x, {j+1, 1}});
			as[0] += as[j];
			as[j] = 0;
		} else {
			fail = 1;
		}
	}

	fail |= ((as[0] % n) != 0);
	if (fail) {
		cout << -1 << '\n';
		return;
	}

	int tar = as[0] / n;
	for (int i = 1; i < n; ++i) {
		ops.push_back({tar, {1, i+1}});
	}

	cout << ops.size() << '\n';
	for (auto pr : ops) {
		cout << pr.second.first << ' ' << pr.second.second << ' ' << pr.first << '\n';
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	int t;
	cin >> t;
	for (int ti = 0; ti < t; ++ti) solve();


	
}