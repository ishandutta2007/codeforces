#include <cstdio>
#include <iostream>
using namespace std;
typedef long long LL;
const int N = 200005;
int n, sz[N], dep[N];
int head[N], numE = 0;
LL ans = 0;
struct E{
	int next, v;
}e[N << 1];
void inline add(int u, int v) {
	e[++numE] = (E) { head[u], v };
	head[u] = numE;
}
void dfs(int u, int last) {
	sz[u] = 1;
	for (int i = head[u]; i; i = e[i].next) {
		int v = e[i].v;
		if(v == last) continue;
		dep[v] = dep[u] + 1;
		dfs(v, u);
		sz[u] += sz[v];
	}
}
int main(){
	scanf("%d", &n);
	for(int i = 1, u, v; i < n; i++) {
		scanf("%d%d", &u, &v);
		add(u, v); add(v, u);
	}
	dfs(1, 0);
	int cnt = 0;
	for(int i = 1; i <= n; i++)
		ans += (LL)sz[i] * (n - sz[i]), cnt += dep[i] & 1;
	ans += (LL)cnt * (n - cnt);
	printf("%lld\n", ans >> 1);
	return 0;
}