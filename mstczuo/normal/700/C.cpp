# include <iostream>
# include <cstdio>
# include <cstring>
# include <vector>
using namespace std;

int n, m, s, t;

typedef pair<int,int> pii;

const int maxn = 1002;

struct Edge {
	int x, y, s, w;
} edge[30000 + 10];

int forb = -1;
int cnt = 0;

int low[maxn], dfn[maxn], vis[maxn], par[maxn], vis1[maxn];
vector<int> g[maxn], route;

void tarjan(int u,int eid) {
	low[u] = dfn[u] = ++cnt;
	vis[u] += 1;
	for(int e: g[u]) if(e != eid && e != forb) {
		int v = edge[e].s - u;
		if(vis[v] == 0) par[v] = e, tarjan(v, e), low[u] = min(low[u], low[v]);
		else if(vis[v] == 1) low[u] = min(low[u], dfn[v]);
	}
}

int ans = ~0u>>1, ans1, ans2;
#define update_ans(w,x,y) if(w < ans) { ans = w; ans1 = x; ans2 = y; }

int getInt() {
	char c;
	while(!isdigit(c = getchar()));
	int ret = c - '0';
	while(isdigit(c = getchar())) 
		ret = ret * 10 + (c - '0');
	return ret;
}

int main() {
	n = getInt(), m = getInt(), s = getInt(), t = getInt();
	for(int i = 0; i < m; ++i) {
		int x = getInt(), y = getInt(), w = getInt();
		edge[i].x = x;
		edge[i].y = y;
		edge[i].w = w;
		edge[i].s = x + y;
		g[x].push_back(i);
		g[y].push_back(i);
	}
	memset(vis, 0, sizeof(vis));
	tarjan(s, -1);
	if (!vis[t]) update_ans(0, 0, 0); 
	if (vis[t]) {
		for(int u = t; u != s; u = edge[par[u]].s - u) {
			if(low[u] == dfn[u]) {
				update_ans(edge[par[u]].w, par[u] + 1, 0);
			} else {
				route.push_back(par[u]);
			}
		}
		memcpy(vis1, vis, sizeof(vis));
		for(auto forb: route) {
			::forb = forb;
			memset(vis, 0, sizeof(vis));
			tarjan(s, -1);
			if(vis[t]) {
				for(int u = t; u != s; u = edge[par[u]].s - u) {
					if(low[u] == dfn[u]) {
						update_ans(edge[par[u]].w + edge[forb].w, forb + 1, par[u] + 1);
					}
				}
			}
		}
	}
	if(ans == ~0u>>1) {
		cout << -1 << endl;
	} else if(ans1 == 0) {
		cout << ans << endl;
		cout << 0 << endl;
	} else if(ans2 == 0) {
		cout << ans << endl;
		cout << 1 << endl;
		cout << ans1 << endl;
	} else {
		cout << ans << endl;
		cout << 2 << endl;
		cout << ans1 << ' ' << ans2 << endl;
	}
}