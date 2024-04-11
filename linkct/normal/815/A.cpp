#include <bits/stdc++.h>
using namespace std;
const int MAXN = 105;

int n, m, f[MAXN][MAXN], g[MAXN][MAXN];

void print(const char str[], int p, int v){
	while(v --) printf("%s %d\n", str, p);
}
int main(){
	int i, j, k, sum, ans = -1, mn, ansp;
	bool ok;
	scanf("%d%d", &n, &m);
	for(i = 1; i <= n; ++ i)
		for(j = 1; j <= m; ++ j)
			scanf("%d", &f[i][j]);
	for(i = 2, mn = f[1][1]; i <= m; ++ i)
		mn = min(mn, f[1][i]);
	for(i = 0; i <= mn; ++ i){
		memcpy(g, f, sizeof(g));
		ok = true;
		for(j = 1, sum = i; j <= m; ++ j)
			g[1][j] -= i, sum += g[1][j];
		for(j = 2; j <= n; ++ j){
			for(k = 1; k <= m; ++ k){
				g[j][k] -= g[1][k];
				if(k > 1 && g[j][k] != g[j][k - 1])
					ok = false;
			} sum += g[j][1];
			if(g[j][1] < 0) ok = false;
		} if(ok && (ans == -1 || ans > sum)) ans = sum, ansp = i;
	} printf("%d\n", ans);
	if(ans == -1) return 0;
	i = ansp;
	print("row", 1, ansp);
	memcpy(g, f, sizeof(g));
	for(j = 1, sum = i; j <= m; ++ j){
		g[1][j] -= i, sum += g[1][j];
		print("col", j, g[1][j]);
	}
	for(j = 2; j <= n; ++ j){
		for(k = 1; k <= m; ++ k)
			g[j][k] -= g[1][k];
		sum += g[j][1];
		print("row", j, g[j][1]);
	} return 0;
}