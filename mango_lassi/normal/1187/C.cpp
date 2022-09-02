#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	int n, m;
	cin >> n >> m;
	vector<pair<int, pair<int, int>>> evs(m);
	for (int i = 0; i < m; ++i) {
		int t, a, b;
		cin >> t >> a >> b;
		--a; --b;
		evs[i] = {a, {t, b}};
	}
	sort(evs.begin(), evs.end());

	int j = 0;
	int last_sorted = -1;
	int first_not_sorted = n;
	bool fail = false;
	vector<int> res(n);
	for (int i = 0; i < n; ++i) {
		if (i > 0) {
			if (last_sorted >= i) {
				res[i] = res[i-1] + 1;
				if (first_not_sorted <= i) fail = true;
			} else {
				res[i] = res[i-1] - 1;
				first_not_sorted = n;
			}
		} else {
			res[0] = n;
		}
		while(j < m && evs[j].first == i) {
			int t = evs[j].second.first;
			int b = evs[j].second.second;
			if (t == 1) last_sorted = max(last_sorted, b);
			if (t == 0) first_not_sorted = min(first_not_sorted, b);
			++j;
		}
	}
	if (fail) cout << "NO\n";
	else {
		cout << "YES\n";
		for (auto it : res) cout << it << ' '; cout << '\n';
	}
}