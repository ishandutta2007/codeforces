#include <bits/stdc++.h>
#define i64 long long
#define db double
#define x first
#define y second
using namespace std;
const int N = 2e5 + 10;
int T, n, pa[N], deg[N], son[N], leaf[N];
vector<int> g[N];
queue<int> q;
void dfs(int u, int fa) {
	pa[u] = fa;
	for(int &v : g[u]) {
		if(v == fa) continue;
		dfs(v, u);
		son[u]++;
	}
	if(son[u] >= 1) deg[pa[u]]++;
	else leaf[u] = 1;
	return;
}

void solve() {
	cin >> n;
	for(int i = 1; i <= n; i++) leaf[i] = son[i] = deg[i] = 0, g[i].clear();
	for(int i = 1, u, v; i < n; i++) {
		cin >> u >> v;
		g[u].push_back(v);
		g[v].push_back(u);
	}
	dfs(1, 0);
	for(int i = 1; i <= n; i++) if(deg[i] == 0 && !leaf[i] && i > 1) q.push(i);
	int cnt = 0;
	while(!q.empty()) {
		int u = q.front();
		//~ cout << u << endl;
		q.pop();
		cnt++;
		son[pa[u]]--;
		deg[pa[u]]--;
		if(son[pa[u]] == 0) {
			leaf[pa[u]] = 1;
			deg[pa[pa[u]]]--;
			if(deg[pa[pa[u]]] == 0 && pa[pa[u]] > 1) {
				q.push(pa[pa[u]]);
			}
		} else {
			if(deg[pa[u]] == 0 && pa[u] > 1) {
				q.push(pa[u]);
			}
		}
	}
	int sum = 0;
	for(int i = 1; i <= n; i++) if(leaf[i]) sum++;
	cout << sum - cnt << endl;
	return;
}

int main() {
	cin >> T;
	for(; T--; ) {
		solve();
	}
	return 0;
}