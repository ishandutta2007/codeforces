#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const int INF = (int)1e9 + 7;


void solve() {
	int n, m;
	cin >> n >> m;

	vector<pair<int, int>> as(n), bs(m);
	for (auto& pr : as) cin >> pr.first >> pr.second;
	for (auto& pr : bs) cin >> pr.first >> pr.second;

	vector<pair<int, int>> reqs;
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < m; ++j) {
			int dx = bs[j].first - as[i].first;
			int dy = bs[j].second - as[i].second;
			if (dx >= 0 && dy >= 0) reqs.push_back({dx, dy});
		}
	}

	// Remove useless requirements
	sort(reqs.begin(), reqs.end());
	reverse(reqs.begin(), reqs.end());

	vector<pair<int, int>> tmp;
	swap(tmp, reqs);
	for (auto pr : tmp) {
		if (reqs.empty() || (reqs.back().second < pr.second)) reqs.push_back(pr);
	}

	int dx = -1, dy = -1;
	int res = INF;
	for (int i = 0; i <= reqs.size(); ++i) {
		// We must beat this one's dx and previous one's dy
		dx = (i < reqs.size() ? reqs[i].first : -1);
		res = min(res, dx + dy + 2);
		dy = (i < reqs.size() ? reqs[i].second : -1);
	}
	cout << res << '\n';
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	solve();
}