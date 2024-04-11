#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
typedef long long ll;

const ll INF = 1e18;
const int N = 3000;
const int M = 3000;
vector<int> votes[M];
int n, m;

ll test(int mo) {
	vector<int> costs;
	vector<int> oths;
	for (int i = 1; i < m; ++i) {
		int s = votes[i].size();
		int dif = max(s - mo, 0);
		for (int j = 0; j < dif; ++j) costs.push_back(votes[i][j]);
		for (int j = dif; j < s; ++j) oths.push_back(votes[i][j]);
	}
	sort(oths.begin(), oths.end());
	
	int base = votes[0].size() + costs.size();
	ll res = 0;
	for (int i = 0; i < costs.size(); ++i) res += costs[i];
	for (int j = 0; j < min((int)oths.size(), mo - base + 1); ++j) res += oths[j];
	return res;
}

int main() {
	cin >> n >> m;
	for (int i = 0; i < n; ++i) {
		int p, c;
		cin >> p >> c;
		--p;
		votes[p].push_back(c);
	}
	for (int i = 0; i < m; ++i) sort(votes[i].begin(), votes[i].end());

	ll res = INF;
	for (int i = 0; i <= n; ++i) {
		ll sub = test(i);
		if (sub != -1) res = min(res, sub);
	}
	cout << res << '\n';
}