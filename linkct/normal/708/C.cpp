#include <cstdio>
#include <vector>
using namespace std;
const int MAXN = 800005;

int n, g[MAXN], nxt[MAXN << 1], to[MAXN << 1], size[MAXN];
int mxv[MAXN], edgeSize, maxadj[MAXN], ans[MAXN];
vector <int> mx[MAXN], pf[MAXN], sf[MAXN], son[MAXN];

void addEdge(int u, int v){
	nxt[++ edgeSize] = g[u];
	to[g[u] = edgeSize] = v;
}
void dfs1(int x, int f){
	size[x] = 1; son[x].push_back(0);
	for(int p = g[x]; p; p = nxt[p])
		if(to[p] != f){
			son[x].push_back(to[p]);
			dfs1(to[p], x);
			size[x] += size[to[p]];
			if(size[to[p]] > maxadj[x])
				maxadj[x] = size[to[p]];
		}
	son[x].push_back(0);
	if(n - size[x] > maxadj[x])
		maxadj[x] = n - size[x];
}
void dfs2(int x){
	int i;
	if(size[x] <= n / 2) mxv[x] = size[x];
	mx[x].resize(son[x].size());
	pf[x].resize(son[x].size());
	sf[x].resize(son[x].size());
	for(i = 1; i < int(son[x].size()) - 1; ++ i){
		dfs2(son[x][i]);
		mx[x][i] = mxv[son[x][i]];
		if(mx[x][i] > mxv[x]) mxv[x] = mx[x][i];
	}
	for(i = 1; i < int(son[x].size()) - 1; ++ i)
		pf[x][i] = max(pf[x][i - 1], mx[x][i]);
	for(i = int(son[x].size()) - 2; i; -- i)
		sf[x][i] = max(sf[x][i + 1], mx[x][i]);
}
/*
12
1 2
1 3
2 4
2 5
2 6
5 7
7 8
7 9
3 10
10 11
10 12
*/
void dfs3(int x, int upmx){
	int i;
	for(i = 1; i < int(son[x].size()) - 1; ++ i){
		if(n - size[son[x][i]] <= n / 2)
			dfs3(son[x][i], max(max(upmx, n - size[son[x][i]]), max(pf[x][i - 1], sf[x][i + 1])));
		else dfs3(son[x][i], max(upmx, max(pf[x][i - 1], sf[x][i + 1])));
	}
	if(maxadj[x] <= n / 2) ans[x] = 1;
	else if(n - size[x] <= n / 2){
		for(i = 1; i < int(son[x].size()) - 1; ++ i)
			if(size[son[x][i]] > n / 2){
				ans[x] = int(mxv[son[x][i]] >= size[son[x][i]] - n / 2);
				break;
			}
	}else ans[x] = int(upmx >= (n + 1) / 2 - size[x]);
}
int main(){
	int i, u, v;
	scanf("%d", &n);
	for(i = 1; i < n; ++ i){
		scanf("%d%d", &u, &v);
		addEdge(u, v), addEdge(v, u);
	} dfs1(1, -1);
	dfs2(1);
	dfs3(1, 0);
	for(i = 1; i <= n; ++ i)
		printf("%d ", ans[i]);
	return 0;
}