#include <bits/stdc++.h>
using namespace std;
typedef long long int LL;
const int MAXN = 100005, MAXM = 200005;

int g[MAXN], nxt[MAXM], to[MAXM], edgeSize, n, m, q;
int f[MAXN], down[MAXN], up[MAXN], d[MAXN];
vector <int> suf; vector <LL> cnt[MAXN], cnti[MAXN];
map <int, map <int, double> > memo;

int find(int x){return f[x] < 0 ? x : (f[x] = find(f[x]));}
void dfs1(int x, int fa){
	down[x] = 0;
	if(to[g[x]] == fa) g[x] = nxt[g[x]];
	if(g[x]){
		dfs1(to[g[x]], x), down[x] = down[to[g[x]]] + 1;
		for(int p = g[x]; nxt[p]; p = nxt[p]){
			if(to[nxt[p]] == fa) nxt[p] = nxt[nxt[p]];
			if(nxt[p]){
				dfs1(to[nxt[p]], x);
				down[x] = max(down[x], down[to[nxt[p]]] + 1);
			}else break;
		}
	}
}
void dfs2(int x){
	++ cnt[find(x)][max(down[x], up[x])];
	d[find(x)] = max(d[find(x)], max(down[x], up[x]));
	int p, prf;
	for(p = g[x]; p; p = nxt[p])
		suf.push_back(down[to[p]]);
	reverse(suf.begin(), suf.end());
	for(p = 1; p < int(suf.size()); ++ p)
		suf[p] = max(suf[p], suf[p - 1]);
	for(p = g[x], prf = 0; p; p = nxt[p]){
		suf.pop_back();
		up[to[p]] = max(up[x], prf);
		if(!suf.empty()) up[to[p]] = max(up[to[p]], suf.back() + 1);
		++ up[to[p]];
		prf = max(prf, down[to[p]] + 1);
	}
	for(p = g[x]; p; p = nxt[p])
		dfs2(to[p]);
}
void addEdge(int u, int v){
	nxt[++ edgeSize] = g[u];
	to[g[u] = edgeSize] = v;
}
void merge(int u, int v){
	u = find(u), v = find(v);
	if(f[u] < f[v]) f[u] += f[v], f[v] = u;
	else f[v] += f[u], f[u] = v;
}
int main(){
	int i, j, k, u, v, D; double ans;
	memset(f, -1, sizeof(f));
	scanf("%d%d%d", &n, &m, &q);
	for(i = 1; i <= m; ++ i){
		scanf("%d%d", &u, &v);
		addEdge(u, v);
		addEdge(v, u);
		merge(u, v);
	}
	for(i = 1; i <= n; ++ i){
		if(find(i) != i) continue;
		cnt[i].resize(- f[i]);
		dfs1(i, 0), dfs2(i);
		for(j = 0; j < - f[i]; ++ j)
			cnti[i].push_back(cnt[i][j] * j);
		for(j = - f[i] - 2; j >= 0; -- j){
			cnti[i][j] += cnti[i][j + 1];
			cnt[i][j] += cnt[i][j + 1];
		} cnt[i].push_back(0LL), cnti[i].push_back(0LL);
	}
	for(i = 1; i <= q; ++ i){
		scanf("%d%d", &u, &v);
		if((u = find(u)) == (v = find(v))){
			printf("-1\n");
			continue;
		} if(f[u] < f[v] || (f[u] == f[v] && u > v)) swap(u, v);
		if(memo.count(u) && memo[u].count(v)){
			printf("%.10lf\n", memo[u][v]);
			continue;
		} D = max(d[u], d[v]);
		for(ans = j = 0; j < - f[u]; ++ j){
			k = D - j - 1;
			if(k >= - f[v]) ans += 1.0 * (cnt[u][j] - cnt[u][j + 1]) * (- f[v]) * D;
			else{
				ans += 1.0 * (cnti[u][j] - cnti[u][j + 1]) * cnt[v][max(k, 0)] + 1.0 * (cnt[u][j] - cnt[u][j + 1]) * cnti[v][max(k, 0)] + 1.0 * (cnt[u][j] - cnt[u][j + 1]) * cnt[v][max(k, 0)];
				if(k > 0) ans += 1.0 * (cnt[u][j] - cnt[u][j + 1]) * (- f[v] - cnt[v][k]) * D;
			}
		} ans = ans / (- f[u]) / (- f[v]);
		printf("%.10lf\n", memo[u][v] = ans);
	}
	return 0;
}