#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
using ll = long long;

void solve() {
	int n;
	cin >> n;
	vector<pair<int, pair<int, int>>> vals(n);
	for (int i = 0; i < n; ++i) {
		cin >> vals[i].first;
		vals[i].second = {i, i};
	}
	sort(vals.begin(), vals.end());

	vector<pair<int, pair<int, int>>> act;
	for (int i = 0; i < n; ++i) {
		if (act.empty() || act.back().first != vals[i].first) {
			act.push_back(vals[i]);
		} else {
			act.back().second.second = vals[i].second.second;
		}
	}
	int m = act.size();

	int res = m;
	int cur = 0;
	for (int i = 0; i < m; ++i) {
		if (i == 0 || act[i-1].second.second < act[i].second.first) ++cur;
		else cur = 1;
		res = min(res, m - cur);
	}
	cout << res << '\n';
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	int q;
	cin >> q;
	for (int qi = 0; qi < q; ++qi) solve();

}