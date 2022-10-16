#include <cstdio>
#include <iostream>
using namespace std;
const int N = 300005;
int n, c[N], f[N], K;
int head[N], numE = 0;
struct E{
	int next, v;
}e[N];
void inline add(int u, int v) {
	e[++numE] = (E) { head[u], v };
	head[u] = numE;
} 
void dfs(int u, int fa) {
	if(!head[u]) {
		K++, f[u] = 1;
		return;
	}
	if(c[u]) f[u] = 2e9;
	for (int i = head[u]; i; i = e[i].next) {
		int v = e[i].v;
		if(v == fa) continue;
		dfs(v, u);
		if(c[u]) f[u] = min(f[u], f[v]);
		else f[u] += f[v];		
	}
}
int main() {
	scanf("%d", &n);
	for (int i = 1; i <= n; i++) scanf("%d", c + i);
	for (int i = 2, p; i <= n; i++) {
		scanf("%d", &p);
		add(p, i);
	}
	
	dfs(1, 0);
	printf("%d\n", K + 1 - f[1]);
	
	return 0;
}