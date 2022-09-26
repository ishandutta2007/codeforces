#include <bits/stdc++.h>
using namespace std;

const int N = 1e6 + 5;

int n;
vector<int> adj[N];
int lev[N];
pair<int,int> res[N];
map<int,int> cnt[N];

void dfs(int u,int p) {
	cnt[u][lev[u]] = 1;
	res[u] = make_pair(1, -lev[u]);
	for (int v : adj[u]) if (v != p) {
		lev[v] = lev[u] + 1; dfs(v, u);
		if (cnt[u].size() < cnt[v].size()) {
			cnt[u].swap(cnt[v]);
			res[u] = res[v];
		}
		for (auto it : cnt[v]) {
			int tmp = cnt[u][it.first] += it.second;
			res[u] = max(res[u], make_pair(tmp, -it.first));
		}
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin >> n;
	for (int i = 2; i <= n; ++i) {
		int u, v; cin >> u >> v;
		adj[u].push_back(v), adj[v].push_back(u);
	}
	dfs(1, 1);
	for (int i = 1; i <= n; ++i) cout << -res[i].second - lev[i] << '\n';
}