#include <bits/stdc++.h>

using namespace std;

set<int> unvisited;
vector<unordered_set<int>> adj;
int comp;

void dfs(int s){
	unvisited.erase(s);
	int i = 0;
	while (true){
		auto it = unvisited.upper_bound(i);
		if (it == unvisited.end()) break;

		i = *it;
		if (adj[s].count(i)) continue;
		if (s == 1) comp++;
		dfs(i);
	}
}

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	int n, m, k;
	cin >> n >> m >> k;

	adj = vector<unordered_set<int>>(n + 1);

	int neig = n - 1;

	for (int i = 0; i < m; ++i){
		int u, v; cin >> u >> v;

		if (min(u, v) == 1) neig--;

		adj[u].insert(v);
		adj[v].insert(u);
	}

	for (int i = 1; i <= n; ++i)
		unvisited.insert(i);

	dfs(1);

	if (!unvisited.empty() || neig < k || comp > k) cout << "im";
	cout << "possible" << endl;


	return 0;
}