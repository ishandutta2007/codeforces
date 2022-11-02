# include <iostream>
# include <vector>
# include <cstdio>

using namespace std;

const int maxn = 400010;
vector<int> g[maxn];
int sz[maxn], psz[maxn];
int fsz[maxn], fpsz[maxn];
int son[maxn];
char ans[maxn];
int n;

void dfs2(int u,int fa) {
	fsz[u] = n - sz[u];
	if(fsz[u] * 2 <= n) 
		fpsz[u] = max(fpsz[u], fsz[u]);
	if(~fa)
		fpsz[u] = max(fpsz[u], fpsz[fa]);
	if((son[u] == -1 || (sz[son[u]] - psz[son[u]]) * 2 <= n) && (fsz[u] * 2 <= n || (fsz[u] - fpsz[u]) * 2 <= n))
		ans[u] = '1';
	for(auto v: g[u]) if(v != fa) dfs2(v, u);
}

void dfs(int u,int fa) {
	sz[u] = 1;
	int i1 = 0, i2 = 0;
	son[u] = -1;
	for(auto v: g[u]) if(v != fa) {
		dfs(v, u);
		if(sz[v] * 2 > n) son[u] = v;
		sz[u] += sz[v];
		psz[u] = max(psz[u], psz[v]);
		if(i1 == 0 || psz[v] >= psz[i1]) i2 = i1, i1 = v;
		else if(i2 == 0 || psz[v] >= psz[i2]) i2 = v;
	}
	for(auto v: g[u]) if(v != fa) {
		if(v != i1) {
			fpsz[v] = max(fpsz[v], psz[i1]);
		} else {
			fpsz[v] = max(fpsz[v], psz[i2]);
		}
	}
	if(sz[u] * 2 <= n)
		psz[u] = sz[u];
}

int main() {
	scanf("%d", &n);
	for(int i = 1; i < n; ++i) {
		int u, v; scanf("%d%d", &u, &v);
		g[u].push_back(v);
		g[v].push_back(u);
	}
	for(int i = 1; i <= n; ++i) ans[i] = '0';
	dfs(1, -1);
	dfs2(1, -1);
	for(int i = 1; i <= n; ++i) putchar(ans[i]), putchar(' ');
	puts("");
	return 0;
}