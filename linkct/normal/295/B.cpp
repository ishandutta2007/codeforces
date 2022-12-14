#include <cstdio>
const int MAXN = 505;
typedef long long int ll;

int g[MAXN][MAXN], n, p[MAXN];
ll sum, ans[MAXN];
bool vis[MAXN];

int main(){
	int i, j, k;
	scanf("%d", &n);
	for(i = 1; i <= n; ++ i)
		for(j = 1; j <= n; ++ j)
			scanf("%d", &g[i][j]);
	for(i = 1; i <= n; ++ i) scanf("%d", &p[i]);
	for(k = n; k; -- k){
		vis[p[k]] = true;
		sum = 0;
		for(i = 1; i <= n; ++ i)
			for(j = 1; j <= n; ++ j)
				if(g[i][j] > g[i][p[k]] + g[p[k]][j])
					g[i][j] = g[i][p[k]] + g[p[k]][j];
		for(i = 1; i <= n; ++ i)
			for(j = 1; j <= n; ++ j)
				if(vis[i] && vis[j]) sum += g[i][j];
		ans[k] = sum;
	}
	for(i = 1; i <= n; ++ i) printf("%I64d ", ans[i]);
	return 0;
}