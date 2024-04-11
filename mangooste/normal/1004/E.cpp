#include <bits/stdc++.h>

using namespace std;

const int INF = 2e9;

int n, k;
vector<vector<pair<int, int>>> g;
vector<int> dep;
vector<int> max_dep;
vector<int> dp;
bool local_can;

void dfs_calc(int v, int pr) {
	max_dep[v] = dep[v];
	for (auto [u, w] : g[v])
		if (u != pr) {
			dep[u] = dep[v] + w;
			dfs_calc(u, v);
			max_dep[v] = max(max_dep[v], max_dep[u]);
		}
}

void dfs_solve(int v, int pr, int max_up, int val) {
	array<pair<int, int>, 2> maxes;
	maxes[0] = {max_up, -1};
	maxes[1] = {0, v};
	for (auto [u, w] : g[v])
		if (u != pr) {
			pair<int, int> now{max_dep[u] - dep[v], u};
			for (int i = 0; i < 2; i++)
				if (maxes[i] < now)
					swap(now, maxes[i]);
		}

	for (auto [u, w] : g[v])
		if (u != pr) {
			int i = maxes[0].second == u;
			dfs_solve(u, v, maxes[i].first + w, val);
		}
    
	vector<int> need;
	for (auto [u, w] : g[v])
		if (u != pr && max_dep[u] - dep[v] > val)
			need.push_back(u);

	if ((int) need.size() >= 3)
		dp[v] = INF;
	else if ((int) need.size() == 0) {
		dp[v] = 0;
		local_can |= max_up <= val;
	} else {
		long long sum = 1;
		for (auto u : need)
			sum += max(1, dp[u]);
		if (sum <= k)
			local_can |= max_up <= val;
		if ((int) need.size() == 2)
			dp[v] = INF;
		else
			dp[v] = max(1, dp[need[0]]) + 1;
	}
}

inline bool check(int val) {
	dep = vector<int>(n, 0);
	dp = vector<int>(n, 0);
	max_dep = vector<int>(n, 0);
	local_can = false;
	dfs_calc(0, 0);
	dfs_solve(0, 0, 0, val);
	return local_can;
}

signed main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	cin >> n >> k;
	g.resize(n);
	for (int i = 1; i < n; i++) {
		int v, u, w;
		cin >> v >> u >> w;
		v--, u--;
		g[v].emplace_back(u, w);
		g[u].emplace_back(v, w);
	}
	int l = -1, r = INF;
	while (r - l > 1) {
		int mid = (l + r) / 2;
		if (check(mid))
			r = mid;
		else
			l = mid;
	}
	cout << r << '\n';
}