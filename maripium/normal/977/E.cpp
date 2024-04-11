#include <bits/stdc++.h>
using namespace std;

const int N = 2e5 + 5;

int n, m;
int par[N], deg[N];
int edge[N], vertex[N];

int anc(int u) {
	return par[u] == u ? u : par[u] = anc(par[u]);
}

void join(int u,int v) {
	u = anc(u), v = anc(v);
	if (u == v) edge[u]++;
	else {
		par[v] = u;
		edge[u] += edge[v] + 1;
		vertex[u] += vertex[v];
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin >> n >> m;
	for (int i = 1;i <= n;++i) {
		par[i] = i, edge[i] = 0, vertex[i] = 1;
	}
	while(m--) {
		int u, v; cin >> u >> v;
		deg[u]++, deg[v]++;
		join(u, v);
	}
	int cnt = 0;
	vector<int> cpn[N];
	for (int i = 1;i <= n;++i) cpn[anc(i)].push_back(i); 
	for (int i = 1;i <= n;++i) {
		if (!cpn[i].size()) continue;
		bool ok = true;
		for (int j = 0;j < cpn[i].size();++j) if (deg[cpn[i][j]] != 2) {
			ok = false; break;
		}
		if (ok) cnt++;
	}
	cout << cnt;
}