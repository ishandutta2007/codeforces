#include <cstdio>
#include <iostream>
#include <cmath>
using namespace std;
const int N = 100005, L = 18;
int n, Q, dfn[N], Max[N][L], fa[N][L], dep[N], Lca[N][L], Min[N][L], Log[N];
int head[N], numE = 0, cnt = 0;
struct E{
	int next, v;
}e[N];
void add(int u, int v) {
	e[++numE] = (E) { head[u], v };
	head[u] = numE;
}
void dfs(int u) {
	dfn[u] = ++cnt;
	for (int i = 1; i < L && fa[u][i - 1]; i++)
		fa[u][i] = fa[fa[u][i - 1]][i - 1];
	for (int i = head[u]; i; i = e[i].next) {
		int v = e[i].v;
		if(v == fa[u][0]) continue;
		dep[v] = dep[u] + 1;
		fa[v][0] = u;
		dfs(v);
	}
}
int inline lca(int x, int y) {
	if(dep[x] < dep[y]) swap(x, y);
	for (int i = L - 1; ~i; i--)
		if(dep[x] - (1 << i) >= dep[y]) x = fa[x][i];
	if(x == y) return x;
	for (int i = L - 1; ~i; i--)
		if(fa[x][i] != fa[y][i]) x = fa[x][i], y = fa[y][i];
	return fa[x][0];
}
void inline ST_prework() {
	for (int i = 1; i <= n; i++) 
		Log[i] = log2(i), Max[i][0] = Min[i][0] = i, Lca[i][0] = i;

	for (int j = 1; j <= Log[n]; j++) {
		for (int i = 1; i + (1 << j) - 1 <= n; i++) {
			if(dfn[Max[i][j - 1]] > dfn[Max[i + (1 << (j - 1))][j - 1]]) {
				Max[i][j] = Max[i][j - 1];
			} else Max[i][j] = Max[i + (1 << (j - 1))][j - 1];
			
			
			if(dfn[Min[i][j - 1]] < dfn[Min[i + (1 << (j - 1))][j - 1]]) {
				Min[i][j] = Min[i][j - 1];
			} else Min[i][j] = Min[i + (1 << (j - 1))][j - 1];
			
			Lca[i][j] = lca(Lca[i][j - 1], Lca[i + (1 << (j - 1))][j - 1]);
		}
	} 
}
int inline getMax(int l, int r) {
	int k = Log[r - l + 1];
	int a = Max[l][k], b = Max[r - (1 << k) + 1][k];
	return dfn[a] > dfn[b] ? a : b;
} 
int inline getMin(int l, int r) {
	int k = Log[r - l + 1];
	int a = Min[l][k], b = Min[r - (1 << k) + 1][k];
	return dfn[a] < dfn[b] ? a : b;
} 
int inline getLca(int l, int r) {
	if(l > r) return 1;
	int k = Log[r - l + 1];
	int a = Lca[l][k], b = Lca[r - (1 << k) + 1][k];
	return lca(a, b);
} 
int inline ask(int l, int r, int x) {
	if(x == r) return getLca(l, x - 1);
	else if(x == l) return getLca(x + 1, r);
	return lca(getLca(l, x - 1), getLca(x + 1, r));
} 
int main(){
	scanf("%d%d", &n, &Q);
	for (int i = 2, p; i <= n; i++) {
		scanf("%d", &p);
		add(p, i);
	} 
	dfs(1);
	ST_prework(); 
	while(Q--) {
		int l, r; scanf("%d%d", &l, &r);
		int A = getMin(l, r), B = getMax(l, r);
		
		int Va = ask(l, r, A); 
		
		int Vb = ask(l, r, B);
		if(dep[Va] < dep[Vb]) {
			Va = Vb, A = B;
		}
		printf("%d %d\n", A, dep[Va]);
	}
	return 0;
}