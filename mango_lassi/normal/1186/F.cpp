#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

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

	int n, m;
	cin >> n >> m;

	vector<vector<int>> conns(n+1);
	for (int j = 0; j < m; ++j) {
		int a, b;
		cin >> a >> b;
		--a; --b;
		conns[a].push_back(b);
		conns[b].push_back(a);
	}
	for (int i = 0; i < n; ++i) {
		if (conns[i].size() & 1) {
			conns[i].push_back(n);
			conns[n].push_back(i);
		}
	}
	EulerTour et(conns);
	vector<pair<int, int>> res;
	for (int i = 0; i < n; ++i) {
		vector<int> tour = et.getTour(i);
		tour.push_back(n);

		int a = 0;
		for (int b = 0; b < tour.size(); ++b) {
			if (tour[b] == n) {
				for (int j = a; j+1 < b; j += 2) {
					res.emplace_back(tour[j], tour[j+1]);
				}
				if ((b-a >= 2) && ((b-a) & 1)) res.emplace_back(tour[b-2], tour[b-1]);
				a = b+1;
			}
		}
	}
	cout << res.size() << '\n';
	for (auto pr : res) cout << pr.first+1 << ' ' << pr.second+1 << '\n';
}