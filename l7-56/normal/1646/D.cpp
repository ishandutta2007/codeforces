#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef double db;
typedef pair <int, int> pii;

const int maxn = 2e5 + 10;
int n,deg[maxn],col[maxn],w[maxn],sum;
pii f[maxn][2];
struct Edge {
	int v, nxt;
}e[maxn << 1];
int h[maxn], cnt_e;
void add(int x, int y) { e[++cnt_e] = {y, h[x]}, h[x] = cnt_e, deg[x]++; }
#define plu(p, q) (make_pair(p.first + q.first, p.second + q.second))
void dfs1(int u, int pre) {
	f[u][0] = {0, -1}, f[u][1] = {1, -deg[u]};
	for (int j = h[u]; j; j = e[j].nxt) {
		int v = e[j].v;
		if (v == pre) continue;
		dfs1(v, u);
		f[u][0] = plu(f[u][0], max(f[v][0], f[v][1]));
		f[u][1] = plu(f[u][1], f[v][0]);
	}
}

void dfs2(int u, int pre) {
	if (!col[pre] && f[u][1] > f[u][0]) col[u] = 1;
	w[u] = col[u] ? deg[u] : 1; sum += w[u];
	for (int j = h[u]; j; j = e[j].nxt) {
		int v = e[j].v;
		if (v == pre) continue;
		dfs2(v, u);
	}
}

int main() {
	scanf("%d", &n);
	for (int i = 1; i < n; ++i) {
		int x, y; scanf("%d%d", &x, &y);
		add(x, y), add(y, x);
	}
	if (n == 2) return printf("2 2\n1 1\n"), 0;
	dfs1(1, 0), dfs2(1, 0);
	printf("%d %d\n", f[1][col[1]].first, -f[1][col[1]].second);
	for (int i = 1; i <= n; ++i) printf("%d%c", w[i], " \n"[i == n]);
	return 0;
}