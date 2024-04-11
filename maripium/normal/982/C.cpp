#include <bits/stdc++.h>
using namespace std;

const int N = 1e5 + 5;

int n;
vector<int> G[N];
int sz[N];
int res= -1;
void dfs(int u,int p) {
	sz[u] = 1;
	for (int i = 0;i < G[u].size();++i) {
		int v = G[u][i];
		if (v == p) continue;
		dfs(v, u);
		sz[u] += sz[v];
	}
	res += (sz[u] % 2 == 0);
}

int main() {
	ios_base::sync_with_stdio(false);
	cin >> n;
	if (n % 2) return cout << -1,0;
	for (int i = 1;i < n;++i) {
		int u, v; cin >> u >> v;
		G[u].push_back(v), G[v].push_back(u);
	}
	dfs(1, 1);
	cout << res;
}