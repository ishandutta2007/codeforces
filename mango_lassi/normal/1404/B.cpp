#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
using ll = long long;

pair<int, int> furthest(int i, int p, const vector<vector<int>>& g) {
	pair<int, int> res = {0, i};
	for (auto t : g[i]) {
		if (t == p) continue;
		res = max(res, furthest(t, i, g));
	}
	++res.first;
	return res;
}

int dist(int i, int p, int tar, const vector<vector<int>>& g) {
	if (i == tar) return 0;
	for (auto t : g[i]) {
		if (t == p) continue;
		int sub = dist(t, i, tar, g);
		if (sub != -1) return sub + 1;
	}
	return -1;
}

bool solve() {
	int n, x, y, da, db;
	cin >> n >> x >> y >> da >> db;
	--x; --y;

	vector<vector<int>> g(n);
	for (int i = 0; i < n-1; ++i) {
		int a, b;
		cin >> a >> b;
		--a; --b;
		g[a].push_back(b);
		g[b].push_back(a);
	}

	// If the tree was a line:
	// 	B wins if
	//		1. da <= 2 * db
	//		2. 2*db + 1 >= n
	// Assume da <= 2*db. Then it is a winning strategy for B to always move one step towards A
	// If that doesn't hold, as long as there are two vertices at least 2*db + 2 apart from each other, A wins
	// Starting positions never matter


	int d = dist(x, -1, y, g);
	if (d <= da) return true;

	int va = furthest(0, -1, g).second;
	int diam = furthest(va, -1, g).first;
	if (diam <= 2*da + 1 || db <= 2*da) return true;
	else return false;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	int t;
	cin >> t;
	for (int ti = 0; ti < t; ++ti) {
		bool res = solve();
		if (! res) cout << "Bob\n";
		else cout << "Alice\n";
	}
}