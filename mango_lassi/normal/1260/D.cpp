#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
using ll = long long;

int check(int n, vector<pair<int, int>> itvs) {
	sort(itvs.begin(), itvs.end());

	int res = n+1;
	int cb = -1;
	for (int j = 0; j < itvs.size(); ++j) {
		res += 2*max(0, itvs[j].second - max(cb, itvs[j].first));
		cb = max(cb, itvs[j].second);
	}
	return res;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	int m, n, k, t;
	cin >> m >> n >> k >> t;

	vector<int> as(m);
	for (int i = 0; i < m; ++i) cin >> as[i];
	sort(as.begin(), as.end());
	reverse(as.begin(), as.end());

	vector<pair<int, pair<int, int>>> traps(k);
	for (int i = 0; i < k; ++i) {
		cin >> traps[i].second.first >> traps[i].second.second >> traps[i].first;
		--traps[i].second.first;
	}

	int low = 0;
	int high = m;
	while(low != high) {
		int mid = (low + high + 1) >> 1;
		int a = as[mid-1];
		vector<pair<int, int>> itvs;
		for (auto pr : traps) {
			if (pr.first > a) itvs.push_back(pr.second);
		}
		if (check(n, itvs) <= t) low = mid;
		else high = mid - 1;
	}
	cout << low << '\n';
}