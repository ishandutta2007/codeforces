#include <iostream>
#include <cstdio>

using namespace std;

const int N = 200005;

int n, a[N], f[N], g[N];

int head[N], numE = 0;
struct E{
	int next, v;
} e[N << 1];
void add(int u, int v) {
	e[++numE] = (E) { head[u], v };
	head[u] = numE;
}

void dfs(int u, int last) {
	f[u] = a[u] ? 1 : -1;
	for (int i = head[u]; i; i = e[i].next) {
		int v = e[i].v;
		if (v == last) continue;
		dfs(v, u);
		f[u] = max(f[u], f[u] + f[v]); 
	}
}

void dfs2(int u, int last) {
	for (int i = head[u]; i; i = e[i].next) {
		int v = e[i].v;
		if (v == last) continue;
		g[v] = max(g[v], g[u] + f[u] - max(0, f[v]));
		dfs2(v, u);
	}
}

int main() {
	scanf("%d", &n);
	for (int i = 1; i <= n; i++) scanf("%d", a + i);
	for (int i = 1, u, v; i < n; i++) {
		scanf("%d%d", &u, &v);
		add(u, v); add(v, u);
	}
	dfs(1, 0);
	dfs2(1, 0);
	for (int i = 1; i <= n; i++)
		printf("%d ", f[i] + g[i]);
	return 0;
}