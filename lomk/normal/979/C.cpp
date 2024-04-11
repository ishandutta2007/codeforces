/*input
3 1 3
1 2
2 3
*/
#include <bits/stdc++.h>
using namespace std;
#define sp ' '
#define endl '\n'
#define fi first
#define se second
#define mp make_pair
#define int long long
#define N 300005
#define bit(x,y) ((x>>y)&1LL)
#define For(i,l,r) for(int i=l; i<r; i++)

int n, X, Y;
vector<vector<int> > a(N);
int child[N];
int par[N][22];
int depth[N];

void dfs(int u, int p) {
	child[u] = 1; par[u][0] = p;
	for (auto v : a[u]) {
		if (v == p) continue;
		depth[v] = depth[u] + 1;
		dfs(v, u);
		child[u] += child[v];
	}
}

int lca(int p, int q) {
	if (depth[p] < depth[q]) swap(p, q);
	for (signed i = 20; i >= 0; i--) {
		if (depth[par[p][i]] >= depth[q]) {
			p = par[p][i];
		}
	}
	if (p == q) return p;
	for (signed i = 20; i >= 0; i--) {
		if (par[p][i] != par[q][i]) {
			p = par[p][i];
			q = par[q][i];
		}
	}
	return par[p][0];
}

int nlca(int p, int q) {
	if (depth[p] < depth[q]) swap(p, q);
	for (signed i = 20; i >= 0; i--) {
		if (depth[par[p][i]] > depth[q]) {
			p = par[p][i];
		}
	}
	return p;
}

void makelca() {
	dfs(1, 1);
	for (int i = 1; i <= 20; i++) {
		for (int j = 1; j <= n; j++) {
			par[j][i] = par[par[j][i - 1]][i - 1];
		}
	}
}

signed main() {
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	cin >> n >> X >> Y;
	for (int i = 1; i <= n - 1; i++) {
		int u, v; cin >> u >> v;
		a[u].push_back(v);
		a[v].push_back(u);
	}
	makelca();
	if (lca(X, Y) == X) {
		cout << n*n - n - (n - child[nlca(X, Y)])*child[Y]  << endl;
	}
	else if (lca(X, Y) == Y) {
		cout << n*n - n - (n - child[nlca(X, Y)])*child[X]  << endl;
	}
	else {
		cout << n*n - n - child[X]*child[Y] << endl;
	}
}