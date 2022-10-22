#include <bits/stdc++.h>
#define sz(a) int((a).size())
using namespace std;
const int N = 1e5 + 10;
int n, col[N];
vector<int> g[N];
void dfs(int u, int fa) {
	col[u] = col[fa] ^ 1;
	for(auto v : g[u]) if(v != fa) dfs(v, u);
}
void solve() {
	cin >> n;
	for(int i = 1; i <= n; i++) g[i].clear();
	for(int i = 1, u, v; i < n; i++) {
		cin >> u >> v;
		g[u].push_back(v), g[v].push_back(u);
	}
	dfs(1, 0);
	for(int i = 1; i <= n; i++) {
		if(col[i]) cout << sz(g[i]) <<" ";
		else cout << -sz(g[i]) <<" ";
	}
	cout << endl;
	return;
}
int main() {
	ios :: sync_with_stdio(0), cin.tie(0), cout.tie(0);
	int t;
	for(cin >> t; t--; ) solve();
	return 0;
}