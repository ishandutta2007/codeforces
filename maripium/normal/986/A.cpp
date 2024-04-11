#include <bits/stdc++.h>
#define int long long
#define pb push_back
using namespace std;

const int N = 1e5 + 5;
int n, m, k, s;
int a[N];
vector<int> G[N];
int F[N][105];
void bfs(int x) {
	queue<int> q;
	for (int i = 1;i <= n;++i) if (a[i] == x) F[i][x] = 0, q.push(i);
	static bool mark[N] = {false};
	while (!q.empty()) {
		int u = q.front(); q.pop();
		for (int i = 0;i < G[u].size();++i) {
			int v = G[u][i];
			if (F[v][x] > F[u][x] + 1) {
				F[v][x] = F[u][x] + 1;
				q.push(v);
			}
		}
	}
}
signed main() {
	ios_base::sync_with_stdio(false);
	cin >> n >> m >> k >> s;
	for (int i = 1;i <= n;++i) cin >> a[i];
	for (int i = 0;i < m;++i) {
		int u, v; cin >> u >> v;
		G[u].pb(v), G[v].pb(u);
	}
	memset(F, 69, sizeof F);
	for (int i = 1;i <= k;++i) bfs(i);
	for (int i = 1;i <= n;++i) {
		int res = 0;
		sort(F[i] + 1, F[i] + 1 + k);
		for (int j = 1;j <= s;++j) res += F[i][j];
		cout << res << ' ';
	}
}