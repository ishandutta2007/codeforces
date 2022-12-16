#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef double db;

const int maxn = 210, maxm = 4010, inf = 1e9;
int n,m;
namespace Flow {
	struct Edge {
		int v,w,rw,nxt;
	}e[maxm];
	int h[maxn], cnt_e = 1, s, t;
	void add(int x, int y, int z) {
		e[++cnt_e] = {y, z, z, h[x]}, h[x] = cnt_e;
		e[++cnt_e] = {x, 0, 0, h[y]}, h[y] = cnt_e;
	}
	void init() {
		for (int i = 1; i <= cnt_e; ++i) e[i].w = e[i].rw;
	}
	int dep[maxn], now[maxn];
	bool bfs(int s, int t) {
		memset(dep, 0, sizeof dep);
		queue <int> q;
		dep[s] = 1, now[s] = h[s], q.push(s);
		while (!q.empty()) {
			int u = q.front(); q.pop();
			for (int j = h[u]; j; j = e[j].nxt) {
				int v = e[j].v, w = e[j].w;
				if (!w || dep[v]) continue;
				dep[v] = dep[u] + 1, now[v] = h[v], q.push(v);
				if (v == t) return 1;
			}
		}
		return 0;
	}
	int dfs(int t, int u, int in) {
		if (u == t) return in;
		int rst = in;
		for (int &j = now[u]; j && rst; j = e[j].nxt) {
			int v = e[j].v, w = e[j].w;
			if (dep[v] != dep[u] + 1 || !w) continue;
			int out = dfs(t, v, min(w, rst));
			if (!out) dep[v] = 0;
			rst -= out, e[j].w -= out, e[j ^ 1].w += out;
		}
		return in - rst;
	}
	int dinic(int s, int t) {
		// printf("%d -> %d\n", s, t);
		init();
		int maxflow = 0;
		for (int flow = 0; bfs(s, t); )
			while ((flow = dfs(t, s, inf)) > 0) maxflow += flow;
		// printf("%d\n", maxflow);
		return maxflow;
	}
}

queue <int> q[maxn];
int ans, fa[maxn], tot;
int get(int x) { return x == fa[x] ? x : fa[x] = get(fa[x]); }
void merge(int x, int y) {
	x = get(x), y = get(y);
	fa[y] = x;
	while (!q[y].empty()) q[x].push(q[y].front()), q[y].pop();
}
struct node {
	int u, v, w;
	bool operator < (node &x) const { return w > x.w; }
}a[maxn];

namespace Tree {
	int id[maxn],il[maxn],ir[maxn];
	void build(int l, int r) {
		if (r <= l) return;
		// printf("[%d, %d]\n", l, r);
		// for (int i = l; i <= r; ++i) printf("%d%c", id[i], " \n"[i == r]);
		int w = Flow :: dinic(id[l], id[r]);
		a[++tot] = {id[l], id[r], w};
		ans += w;
		Flow :: bfs(id[l], id[r]);
		int totl = 0, totr = 0;
		for (int i = l; i <= r; ++i)
			if (Flow :: dep[id[i]]) il[++totl] = id[i];
			else ir[++totr] = id[i];
		for (int i = 1; i <= totl; ++i) id[l + i - 1] = il[i];
		for (int i = 1; i <= totr; ++i) id[l + totl + i - 1] = ir[i];
		build(l, l + totl - 1), build(l + totl, r);
	}
	void init() {
		for (int i = 1; i <= n; ++i) id[i] = i;
		build(1, n);
	}
}

int main() {
	scanf("%d%d", &n, &m);
	for (int i = 1; i <= m; ++i) {
		int x, y, z; scanf("%d%d%d", &x, &y, &z);
		Flow :: add(x, y, z), Flow :: add(y, x, z);
	}
	Tree :: init();
	printf("%d\n", ans);
	for (int i = 1; i <= n; ++i) fa[i] = i, q[i].push(i);
	sort(a + 1, a + tot + 1);
	for (int i = 1; i <= tot; ++i) merge(a[i].u, a[i].v);
	int f = get(1);
	while (!q[f].empty()) printf("%d ", q[f].front()), q[f].pop();
	printf("\n");
	return 0;
}