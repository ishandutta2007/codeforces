#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int dfs(int i, int p, vector<int>& dep, vector<int>& res0, vector<int>& res1, const vector<vector<pair<int, int>>>& g) {
	int ans = dep[i];
	vector<int> cand;
	bool down = 0;
	for (auto pr : g[i]) {
		int t = pr.first;
		if (t == p) continue;

		if (dep[t] != 0) {
			if (dep[t] < dep[i]) {
				ans = min(ans, dep[t]);
				res0.push_back(pr.second);
			} else {
				down = 1;
			}
		} else {
			dep[t] = dep[i] + 1;
			int sub = dfs(t, i, dep, res0, res1, g);
			if (sub == dep[i]) res1.push_back(pr.second);
			else if (sub < dep[i]) {
				cand.push_back(pr.second);
			}
			ans = min(ans, sub);
		}
	}
	if (down) {
		for (int i : cand) res1.push_back(i);
	}
	return ans;
}

void solve() {
	int n, m;
	cin >> n >> m;

	// Lower bound: 2n - m
	// Upper bound: n - 1 (graph is connected)

	// If we can find any three edges that don't form a triangle, such that removing them leaves the graph connected, answer is 2n - m
	// Otherwise, answer is 2n - m + 1
	// Look at DFS tree. All of the three additional edges have to go up in the tree

	// x - x - x - x - x - x - x
	// y - - - - - y
	//             z - - - - - z
	// k - - - - - - - - - - - k

	vector<pair<int, int>> ed(m);
	vector<vector<pair<int, int>>> g(n);
	for (int i = 0; i < m; ++i) {
		int a, b;
		cin >> a >> b;
		--a; --b;

		ed[i] = {a, b};
		g[a].emplace_back(b, i);
		g[b].emplace_back(a, i);
	}

	vector<int> dep(n, 0), res0, res1;
	dep[0] = 1;
	dfs(0, -1, dep, res0, res1, g);

	if (m < n+2) {
		string res(m, '0');
		for (int i : res0) res[i] = '1';
		cout << res << '\n';
	} else {
		vector<int> nodes;
		for (int i : res0) {
			nodes.push_back(ed[i].first);
			nodes.push_back(ed[i].second);
		}
		sort(nodes.begin(), nodes.end());
		nodes.erase(unique(nodes.begin(), nodes.end()), nodes.end());
		
		if (nodes.size() > 3) {
			string res(m, '0');
			for (int i : res0) res[i] = '1';
			cout << res << '\n';
		} else {
			for (int& i : nodes) i = dep[i];
			sort(nodes.begin(), nodes.end());

			/*
			cerr << "Here!\n";
			for (int i : res0) cerr << i << ' '; cerr << '\n';
			for (int i : res1) cerr << i << ' '; cerr << '\n';
			*/

			string res(m, '0');
			for (int i : res1) res[i] = '1';
			for (int i : res0) {
				int x = dep[ed[i].first];
				int y = dep[ed[i].second];
				if (x > y) swap(x, y);
				if (x == nodes[0] && y == nodes[2]) res[i] = '1';
			}
			cout << res << '\n';
		}
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	int t;
	cin >> t;
	for (int ti = 0; ti < t; ++ti) solve();
}