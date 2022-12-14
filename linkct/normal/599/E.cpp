#include <cstdio>
typedef long long int LL;
const int MAXN = 15, MAXQ = 105;

struct LCA{
	int u, v, f;
}lca[MAXQ];
int n, m, q, adj[MAXN];
LL f[(1 << 13) + 10][MAXN];

int main(){
	int i, j, k, cur, id, nrt, u, v, sta;
	scanf("%d%d%d", &n, &m, &q);
	for(i = 1; i <= m; ++ i){
		scanf("%d%d", &u, &v);
		-- u, -- v;
		adj[u] |= 1 << v;
		adj[v] |= 1 << u;
	}
	for(i = 1; i <= q; ++ i){
		scanf("%d%d%d", &lca[i].u, &lca[i].v, &lca[i].f);
		-- lca[i].u, -- lca[i].v, -- lca[i].f;
	}
	for(i = 1; i < (1 << n); ++ i)
		for(j = 0; j < n; ++ j){
			if((~i) & (1 << j)) continue;
			sta = i ^ (1 << j);
			if(!sta){
				f[i][j] = 1;
				continue;
			} id = sta & -sta;
			for(cur = sta; cur; cur = sta & (cur - 1)){
				if((~cur) & id) continue;
				for(k = 1; k <= q; ++ k)
					if((cur & (1 << lca[k].f)) && (((~cur) & (1 << lca[k].u)) || ((~cur) & (1 << lca[k].v)))) break;
					else if(((~cur) & (1 << lca[k].f)) && (cur & (1 << lca[k].u)) && (cur & (1 << lca[k].v))) break;
				if(k <= q) continue;
				for(nrt = 0; nrt < n; ++ nrt){
					if((~cur) & (1 << nrt)) continue;
					if((adj[nrt] & (cur | (1 << j))) != adj[nrt]) continue;
					f[i][j] += f[i ^ cur][j] * f[cur][nrt];
				}
			}
		}
	printf("%I64d\n", f[(1 << n) - 1][0]);
	return 0;
}