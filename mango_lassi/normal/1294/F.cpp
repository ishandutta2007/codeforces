#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
using ll = long long;

const int N = 2 * (int)1e5;
vector<int> conns[N];
pair<int, int> dp[N][3];

void off(pair<int, int> x, int i) {
	for (int j = 0; j < 3; ++j) {
		if (dp[i][j] < x) swap(dp[i][j], x);
	}
}
pair<int, int> add(pair<int, int> x) {
	return {x.first + 1, x.second};
}

void dfs(int i = 0, int p = -1) {
	off({0, i}, i);
	for (auto t : conns[i]) {
		if (t == p) continue;
		dfs(t, i);
		off(add(dp[t][0]), i);
	}
}
vector<int> solve(int i = 0, int p = -1) {
	vector<int> res(4, 0);
	for (int j = 0; j < 3; ++j) {
		res[0] += dp[i][j].first;
		res[j+1] = dp[i][j].second;
	}
	for (auto t : conns[i]) {
		if (t == p) continue;
		if (add(dp[t][0]) == dp[i][0]) off(add(dp[i][1]), t);
		else off(add(dp[i][0]), t);
		res = max(res, solve(t, i));
	}
	return res;
}


int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	int n;
	cin >> n;
	for (int i = 0; i < n-1; ++i) {
		int a, b;
		cin >> a >> b;
		--a; --b;
		conns[a].push_back(b);
		conns[b].push_back(a);
	}
	dfs();

	auto res = solve();
	cout << res[0] << '\n';
	cout << res[1] + 1 << ' ' << res[2] + 1 << ' ' << res[3] + 1 << '\n';
}