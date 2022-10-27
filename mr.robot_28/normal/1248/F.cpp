#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int MOD = 1000000007, N = 1e6 + 5;
int vis[N], cnt = 0;
vector<int> g[N], rg[N], order, scc[N];
 
void add_edge(int u, int v) {
	g[u].push_back(v);
	rg[v].push_back(u);
}
 
void dfs(int u) {
	if (vis[u]) return;
	vis[u] = 1;
	for (int v : g[u]) dfs(v);
	order.push_back(u);
}
 
void rdfs(int u) {
	if (vis[u] == 2) return;
	vis[u] = 2;
	scc[cnt].push_back(u);
	for (int v : rg[u]) rdfs(v);
}
 
int main() {
	ios::sync_with_stdio(0); cin.tie(0);
	int t;
	cin >> t;
	while(t--) {
		int n, m;
		cin >> n >> m;
		for (int i = 0; i < m; i++) {
			int u, v;
			cin >> u >> v;
			u--, v--;
			// if (u == v) continue;
			add_edge(u, v);
		}
		for (int i = 0; i < n; i++) {
			if (vis[i]) continue;
			dfs(i);
		}
		reverse(order.begin(), order.end());
		cnt = 0;
		for (int v : order) {
			if (vis[v] == 2) continue;
			rdfs(v);
			cnt++;
		}
		if (cnt <= 1) cout << "No\n";
		else {
			cout << "Yes\n";
			cout << scc[cnt-1].size() << " " << n - scc[cnt-1].size() << "\n";
			for (int v : scc[cnt-1]) cout << v+1 << " ";
			cout << "\n";
			for (int i = 0; i < cnt - 1; i++) {
				for (int v : scc[i]) cout << v+1 << " ";
			}
			cout << "\n";
		}
		order.clear();
		for (int i = 0; i < n; i++) {
			vis[i] = 0;
			scc[i].clear();
			g[i].clear();
			rg[i].clear();
		}
	}
	return 0;
}