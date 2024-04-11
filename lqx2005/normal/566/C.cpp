#include <bits/stdc++.h>
#define PI pair<int, int>
#define db double
using namespace std;
const int N = 2e5 + 10;
const db eps = 1e-12;
int n, w[N], used[N], siz[N], son[N];
vector<PI> g[N];
db f[N];
int id = -1;
db ans = 1.0 / 0.0;

void dfs(int u, int fa, int sz, int &c) {
	siz[u] = 1;
	son[u] = 0;
	for(PI &e : g[u]) {
		int v, w;
		tie(v, w) = e;
		if(v == fa || used[v]) continue;
		dfs(v, u, sz, c);
		siz[u] += siz[v];
		son[u] = max(son[u], siz[v]);
	}
	son[u] = max(son[u], sz - siz[u]);
	if(c == -1 || son[c] > son[u]) c = u;
	return;
}

db DFS(int u, int fa, db dep) {
	db res = 0;
	for(PI &e : g[u]) {
		int v, w;
		tie(v, w) = e;
		if(v == fa) continue;
		res += DFS(v, u, dep + w);
	}
	res += sqrt(dep) * w[u];
	return res;
}

db Dfs(int u, int fa, db dep) {
	db res = 0;
	for(PI &e : g[u]) {
		int v, w;
		tie(v, w) = e;
		if(v == fa) continue;
		res += Dfs(v, u, dep + w);
	}
	res += pow(dep, 1.5) * w[u];
	return res;
}

void divide(int u, int sz) {
	int c = -1;
	dfs(u, 0, sz, c);
	u = c;
	dfs(u, 0, sz, c);
	db sum = 0;
	for(PI &e : g[u]) {
		int v, w;
		tie(v, w) = e;
		if(used[v]) continue;
		f[v] = DFS(v, u, w);
		sum += f[v];
	}
	db now = Dfs(u, 0, 0);
	if(ans > now) {
		ans = now;
		id = u;
	}
	used[u] = 1;
	for(PI &e : g[u]) {
		int v, w;
		tie(v, w) = e;
		if(used[v]) continue;
		if(f[v] * 2 > sum + eps) {
			divide(v, siz[v]);
		}
	}
	return;
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);
	cin >> n;
	for(int i = 1; i <= n; i++) cin >> w[i];
	for(int i = 1, u, v, w; i < n; i++) {
		cin >> u >> v >> w;
		g[u].emplace_back(v, w);
		g[v].emplace_back(u, w);
	}
	divide(1, n);
	cout.precision(20), cout << fixed;
	cout << id <<" "<< ans << endl;
	return 0;
}