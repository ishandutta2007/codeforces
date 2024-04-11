#include <bits/stdc++.h>

const int mod = 1e9 + 7;
const int inv2 = (mod + 1) / 2;
using ll = long long;
int inv(int x) { return x == 1 ? 1 : (ll) ( mod - mod / x ) * inv(mod % x) % mod; }

int n,C[2005][2005],x,y,dis[305][305],size[305][305],F[305][305];
std::vector<int>E[2005];

void dfs(int u,int f,int a) {
	size[a][u] = 1;
	dis[a][u] = dis[a][f] + 1;
	for (int v:E[u]) {
		if (v == f) continue;
		dfs(v,u,a);
		size[a][u] += size[a][v];
	}
}

int calc(int x,int y) {
	if (x == 0) return 1;
	if (y == 0) return 0;
	if (F[x][y] != -1) return F[x][y];
	F[x][y] = (ll) inv2 * (calc(x - 1,y) + calc(x,y - 1)) % mod;
	return F[x][y];
}

int main() {
	std::memset(F,-1,sizeof(F));
	scanf("%d",&n);
	for (int i = 0; i <= 1000; ++ i) {
		C[i][0] = 1;
		for (int j = 1; j <= i; ++ j) C[i][j] = (C[i-1][j] + C[i-1][j-1]) % mod;
	} 
	for (int i = 1; i < n; ++ i) {
		scanf("%d%d",&x,&y);
		E[x].push_back(y);
		E[y].push_back(x);
	} for (int i = 1; i <= n; ++ i) 
		dfs(i,0,i);
//	printf("-> %d\n",dis[5][3]);
	int ans = 0;
	int invn = inv(n);
	for (int i = 1; i <= n; ++ i)
	for (int j = 1; j < i; ++ j) {
		// visit i before j
		ans = (ans + (ll) inv(n) * size[j][i] % mod) % mod;
	//	printf("visit %d before %d = %d\n",i,j,size[j][i]);
		// between i and j
		for (int k = 1; k <= n; ++ k) {
			if (dis[i][k] == dis[i][j] + dis[j][k] - 1) continue;
			if (dis[j][k] == dis[j][i] + dis[i][k] - 1) continue;
			int d = dis[i][k] - dis[j][k];
			// x - y = d, x + y = dis[i][j] + 1-> 
			
			int x = (d + dis[i][j] + 1) / 2;
			int y = dis[i][j] + 1 - x;
		//	printf("x + y = %d, x - y = %d\n",dis[i][j] + 1,dis[i][k] - dis[j][k]);
		//	printf("%d -> [%d %d] = %d %d\n",k,i,j,x - 1,y - 1);
			ans = (ans + (ll) invn * calc(x - 1,y - 1) % mod) % mod;
		}
	} printf("%d",ans);
	return 0;
}