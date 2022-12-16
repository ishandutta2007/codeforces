#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef double db;

const int maxn = 1e5 + 10;
int n,w[maxn],deg[maxn];
struct Edge {
	int v, nxt;
}e[maxn << 1];
int h[maxn], cnt_e;
void add(int x, int y) { e[++cnt_e] = {y, h[x]}, h[x] = cnt_e; }

void dfs(int u, int pre, int col) {
	w[u] = deg[u] * col;
	for (int j = h[u]; j; j = e[j].nxt) {
		int v = e[j].v;
		if (v == pre) continue;
		dfs(v, u, -col);
	}
}

void work() {
	scanf("%d", &n);
	cnt_e = 0;
	for (int i = 1; i <= n; ++i) h[i] = deg[i] = 0;
	for (int i = 1; i < n; ++i) {
		int x, y; scanf("%d%d", &x, &y);
		add(x, y), add(y, x), deg[x]++, deg[y]++;
	}
	dfs(1, 0, 1);
	for (int i = 1; i <= n; ++i) printf("%d%c", w[i], " \n"[i == n]);
}

int main() {
	int t; scanf("%d", &t);
	while (t--) work();
	return 0;
}