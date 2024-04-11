#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
using ll = long long;

void addEdge(int a, int b, vector<vector<int>>& g) {
	g[a].push_back(b);
	g[b].push_back(a);
}

pair<int, int> dfsBC(int i, vector<int>& dep, vector<vector<int>>& ans, const vector<vector<int>>& g) {
	pair<int, int> res = {-1, g.size()};
	for (auto t : g[i]) {
		if (dep[t] == -1) {
			dep[t] = dep[i] + 1;
			auto off = dfsBC(t, dep, ans, g);
			if (off.first == -1) addEdge(i, t, ans);
			else {
				if (off.second < dep[i]) {
					if (res.first != -1) addEdge(res.first, off.first, ans);
					if (off.second < res.second) res = off;
				} else addEdge(i, off.first, ans);
			}
		} else if (dep[t] < dep[i] - 1) {
			if (res.first != -1) res.second = min(res.second, dep[t]);
			else {
				res = {ans.size(), dep[t]};
				ans.emplace_back();
			}
		}
	}
	if (res.first != -1) addEdge(i, res.first, ans);
	return res;
}

// Given connected undirected graph, returns a tree s.t. x is on the path
// between y and z in the tree iff x is on every path between y and z in the input graph.
// A vertex is a cut vertex iff it has degree >= 2 in the tree.
// The tree has size <= |E| + 1. Complexity O(|E|)
vector<vector<int>> blockCut(const vector<vector<int>>& g) {
	vector<vector<int>> res(g.size());
	vector<int> dep(g.size(), -1);
	dep[0] = 0;
	dfsBC(0, dep, res, g);
	return res;
}

int calc(int i, int p, int b, int n, const vector<vector<int>>& g) {
	int res = (i < n);
	if (i == b) return -1;
	for (auto t : g[i]) {
		if (t == p) continue;
		int sub = calc(t, i, b, n, g);
		if (sub == -1) return -1;
		res += sub;
	}
	return res;
}

void solve() {
	int n, m, a, b;
	cin >> n >> m >> a >> b;
	--a; --b;

	vector<vector<int>> g(n);
	for (int i = 0; i < m; ++i) {
		int x, y;
		cin >> x >> y;
		--x; --y;
		g[x].push_back(y);
		g[y].push_back(x);
	}
	g = blockCut(g);

	ll le = 0;
	ll ri = 0;
	for (auto t : g[a]) {
		int sub = calc(t, a, b, n, g);
		if (sub != -1) le += sub;
	}
	for (auto t : g[b]) {
		int sub = calc(t, b, a, n, g);
		if (sub != -1) ri += sub;
	}
	cout << le * ri << '\n';
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	int t;
	cin >> t;
	for (int ti = 0; ti < t; ++ti) solve();
}