#include<bits/stdc++.h>
using namespace std;

const int N = 300000 + 10;

struct Edge {
	int u, v, next;
}G[N << 1];

long long ans = 0;
int fa[N], d[N], head[N], size[N];
int n, x, y;
int tot = 0;

inline void addedge(int u, int v) {
	G[++tot] = (Edge) {u, v, head[u]}, head[u] = tot;
	G[++tot] = (Edge) {v, u, head[v]}, head[v] = tot;
}
void dfs(int u) {
	size[u] = 1;
	for(int i = head[u]; i; i = G[i].next) {
		int v = G[i].v;
		if(v == fa[u]) continue;
		fa[v] = u, d[v] = d[u] + 1;
		dfs(v);
		size[u] += size[v];
	}
}

int main() {
	scanf("%d %d %d", &n, &x, &y);
	for(int i = 1; i < n; i++) {
		int a, b;
		scanf("%d %d", &a, &b);
		addedge(a, b);
	}
	dfs(x);
	int tmp = y;
	while(fa[tmp] != x) {
		tmp = fa[tmp];
	}
	long long ltree = size[x] - size[tmp];
	long long rtree = size[y];
	long long mtree = n - ltree - rtree;
	ans = (rtree + mtree) * (long long)(n - 1) + ltree * (ltree + mtree - 1);
	printf("%lld", ans);
	return 0;
}