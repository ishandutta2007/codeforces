#include <bits/stdc++.h>
#define x first
#define y second
#define mp make_pair
#define sz(a) int((a).size())
#define pii pair<int, int>
using namespace std;
typedef double db;
typedef long long i64;
typedef unsigned u32;
const int N = 4e5 + 10;
struct Edge {
	int to, nxt, vis;
}e[N << 1];
int head[N], tot = 1;
int n, m, fa[N], deg[N], cnte[N];
int stk[N], top = 0;
int ansa[N], ansb[N], atot = 0;
vector<int> g[N];
void addedge(int u, int v) {e[++tot] = Edge{v, head[u], 0}, head[u] = tot; }
int find(int x) {return fa[x] == x ? x : fa[x] = find(fa[x]); }
int merge(int x, int y) {
	x = find(x), y = find(y);
	if(x == y) return 0;
	return fa[x] = y, cnte[y] += cnte[x], cnte[x] = 0, 1;
}

void dfs(int u) {
	for(int &i = head[u]; i; i = e[i].nxt) {
		if(e[i].vis) continue;
		int v = e[i].to;
		e[i].vis = e[i ^ 1].vis = 1;
		dfs(v);
	}
	stk[++top] = u;
	return;
}

int main() {
	scanf("%d%d", &n, &m);
	for(int i = 1; i <= n; i++) fa[i] = i;
	for(int i = 1; i <= m; i++) {
		int u, v;
		scanf("%d%d", &u, &v);
		deg[u]++, deg[v]++;
		addedge(u, v), addedge(v, u);
		merge(u, v);
		cnte[find(u)]++;
	}
	for(int i = 1; i <= n; i++) if(deg[i] & 1) g[find(i)].push_back(i);
	int pre = -1;
	for(int i = 1; i <= n; i++) {
		if(find(i) == i) {
			if(g[i].empty()) continue;
			if((cnte[i] + sz(g[i]) / 2) & 1) {
				if(pre != -1) {
					int u = g[pre].back();
					g[pre].pop_back();
					int v = g[pre].back();
					g[pre].pop_back();
					int w = g[i].back();
					g[i].pop_back();
					int k = g[i].back();
					g[i].pop_back();
					cnte[pre]++, cnte[i]++;
					addedge(u, w), addedge(w, u);
					addedge(v, k), addedge(k, v);
					merge(i, pre);
					pre = -1;
				} else {
					pre = i;
				}
			}
		}
	}
	for(int i = 1; i <= n; i++) {
		for(int j = 1; j < sz(g[i]); j += 2) {
			addedge(g[i][j - 1], g[i][j]);
			addedge(g[i][j], g[i][j - 1]);
			cnte[find(g[i][j])]++;
		}
		g[i].clear();
	}
	for(int i = 1; i <= n; i++) if(cnte[find(i)] & 1) cnte[find(i)]++, addedge(i, i);
	for(int i = 1; i <= n; i++) {
		if(find(i) == i) {
			top = 0;
			dfs(i);
			for(int j = 2; j <= top; j++) {
				if(j & 1) ansa[++atot] = stk[j - 1], ansb[atot] = stk[j];
				else ansa[++atot] = stk[j], ansb[atot] = stk[j - 1];
			}
		}
	}
	printf("%d\n", atot);
	for(int i = 1; i <= atot; i++) printf("%d %d\n", ansa[i], ansb[i]);
	return 0;
}