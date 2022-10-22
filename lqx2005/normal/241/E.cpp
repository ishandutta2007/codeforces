#include <bits/stdc++.h>
#define sz(a) int((a).size())
using namespace std;
typedef long long i64;
const int N = 1010, M = 1e4 + 10, oo = 0x3f3f3f3f;
int n, m;
int u[M], v[M], w[M], tot = 0;
int dis[N], vis[N];
int from[N], to[N];
vector<int> g[N], rg[N];
void dfs(int u) {
	from[u] = 1;
	for(int v : g[u]) if(!from[v]) dfs(v);
	return;
}

void DFS(int u) {
	to[u] = 1;
	for(int v : rg[u]) if(!to[v]) DFS(v);
	return;
}

int main() {
	scanf("%d%d", &n, &m);
	for(int i = 1, a, b; i <= m; i++) {
		scanf("%d%d", &a, &b);
		g[a].push_back(b);
		rg[b].push_back(a);
		tot++;
		u[tot] = a, v[tot] = b, w[tot] = 2;
		tot++;
		u[tot] = b, v[tot] = a, w[tot] = -1;
	}
	dfs(1);
	DFS(n);
	for(int i = 1; i <= n; i++) vis[i] = from[i] && to[i];
	memset(dis, 0x3f, sizeof(dis));
	dis[1] = 0;
	for(int i = 1; i <= n; i++) {
		for(int j = 1; j <= tot; j++) {
			if(!vis[u[j]] || !vis[v[j]]) continue;
			if(dis[v[j]] > dis[u[j]] + w[j]) {
				dis[v[j]] = dis[u[j]] + w[j];
			}
		}
	}
	for(int j = 1; j <= tot; j++) {
		if(!vis[u[j]] || !vis[v[j]]) continue;
		if(dis[v[j]] > dis[u[j]] + w[j]) {
			puts("No");
			return 0;
		}
	}
	puts("Yes");
	for(int i = 1; i <= tot; i += 2) {
		if(!vis[u[i]] || !vis[v[i]]) puts("1");
		else printf("%d\n", dis[v[i]] - dis[u[i]]);
	}
	return 0;
}