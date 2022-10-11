#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

vector <vector <int>> G;
vector <int> used;

pair <int, int> dfs(int v) {
	used[v] = 1;
	pair <int, int> ans = { v, v };
	for (auto u : G[v]) {
		if (!used[u]) {
			auto tmp = dfs(u);
			ans.first = min(ans.first, tmp.first);
			ans.second = max(ans.second, tmp.second);
		}
	}
	return ans;
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int n, m;
	cin >> n >> m;
	G.resize(n);
	for (int i = 0; i < m; i++) {
		int u, v;
		cin >> u >> v, u--, v--;
		G[u].emplace_back(v);
		G[v].emplace_back(u);
	}
	int cnt = 0;
	vector <pair <int, int>> segments;
	used.resize(n, 0);
	for (int i = 0; i < n; i++) {
		if (!used[i]) {
			cnt++;
			segments.emplace_back(dfs(i));
		}
	}
	int cnt_per = 0, max_r = -1;
	sort(segments.begin(), segments.end());
	for (int i = 0; i < segments.size(); i++) {
		if (segments[i].first >= max_r) {
			cnt_per++;
			max_r = segments[i].second;
		}
		else {
			max_r = max(max_r, segments[i].second);
		}
	}
	cout << cnt - cnt_per;
}