#include <bits/stdc++.h>
using namespace std;
using ll = long long;

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
using ll = long long;

class EulerTour {
	private:
		vector<vector<int>> g;
		vector<int> ei;
		bool d;

		void recTour(int i, vector<int>& que) {
			while(ei[i] < g[i].size()) {
				int t = g[i][ei[i]];
				++ei[i];
				if ((!d) && (ei[t] >= g[t].size() || g[t][ei[t]] > i)) continue;
				recTour(t, que);
			}
			que.push_back(i);
		}
	public:
		EulerTour(const vector<vector<int>>& conns, bool dir = false) : g(conns), ei(conns.size(), 0), d(dir) {
			for (int i = 0; i < g.size(); ++i) sort(g[i].begin(), g[i].end());
		}

		vector<int> getTour(int i = 0) {
			vector<int> res;
			recTour(i, res);
			return res;
		}
};

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	int n, k;
	cin >> n >> k;

	vector<vector<int>> g(k);
	for (int i = 0; i < k; ++i) {
		g[i].resize(k);
		for (int j = 0; j < k; ++j) g[i][j] = j;
	}

	EulerTour tmp(g, 1);
	vector<int> tour = tmp.getTour();

	string base;
	for (int j = 0; j + 1 < tour.size(); ++j) base.push_back('a' + tour[j]);

	string res(n, '_');
	for (int j = 0; j < n; ++j) res[j] = base[j % (int)base.size()];
	cout << res << '\n';
}