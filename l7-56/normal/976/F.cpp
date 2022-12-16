#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef double db;

const int maxn = 1e6 + 10, inf = 1e9;
int n1,n2,m,s,t,deg[maxn];
struct Edge {
	int v, w, nxt, id;
} e[maxn];
int h[maxn], cnt_e = 1;
void add(int x, int y, int z, int i) {
	e[++cnt_e] = {y, z, h[x], i}, h[x] = cnt_e;
	e[++cnt_e] = {x, 0, h[y], i}, h[y] = cnt_e;
}

int dep[maxn],now[maxn];
bool bfs() {
	memset(dep, 0, sizeof dep);
	queue <int> q;
	q.push(s), dep[s] = 1, now[s] = h[s];
	while (!q.empty()) {
		int u = q.front(); q.pop();
		for (int j = h[u]; j; j = e[j].nxt) {
			int v = e[j].v;
			if (dep[v] || !e[j].w) continue;
			q.push(v), dep[v] = dep[u] + 1, now[v] = h[v];
			if (v == t) return 1;
		}
	}
	return 0;
}

int dfs(int u, int in) {
	if (u == t) return in;
	int rst = in;
	for (int &j = now[u]; j && rst; j = e[j].nxt) {
		int v = e[j].v;
		if (dep[v] != dep[u] + 1 || !e[j].w) continue;
		int out = dfs(v, min(rst, e[j].w));
		e[j].w -= out, e[j ^ 1].w += out, rst -= out;
		if (!out) dep[v] = 0;
	}
	return in - rst;
}

vector <int> ans[maxn];

int main() {
	scanf("%d%d%d", &n1, &n2, &m), s = n1 + n2 + 1, t = s + 1;
	for (int i = 1; i <= m; ++i) {
		int x, y;
		scanf("%d%d", &x, &y);
		add(x, y + n1, 1, i);
		deg[x]++, deg[y + n1]++;
	}
	int mndeg = inf;
	for (int i = 1; i <= n1 + n2; ++i) mndeg = min(mndeg, deg[i]);
	for (int i = 1; i <= n1; ++i) add(s, i, deg[i] - mndeg, -1);
	for (int i = 1; i <= n2; ++i) add(i + n1, t, deg[i + n1] - mndeg, -1);
	for (int k = mndeg; k >= 0; --k) {
		while (bfs()) for (int flow; (flow = dfs(s, inf)) > 0; );
		for (int i = 1; i <= n1; ++i)
			for (int j = h[i]; j; j = e[j].nxt)
				if (e[j].w && e[j].id != -1) ans[k].push_back(e[j].id);
		sort(ans[k].begin(), ans[k].end());
		for (int j = h[s]; j; j = e[j].nxt) e[j].w++;
		for (int j = h[t]; j; j = e[j].nxt) e[j ^ 1].w++;
	}
	for (int k = 0; k <= mndeg; ++k) {
		printf("%d ", (int) ans[k].size());
		for (int i : ans[k]) printf("%d ", i);
		printf("\n");
	}
	return 0;
}
//