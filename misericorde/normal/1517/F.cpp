#include <bits/stdc++.h>

int n,u,v,f[305][2][305],g[305][305],size[305],ans;
std::vector<int>ch[305];
using ll = long long;
const int mod = 998244353;

int dec(int x) { return x >= mod ? x - mod : x; }

void dfs(int u,int fa,int k) {
	std::memset(f[u],0,sizeof(f[u]));
	f[u][1][k] = 1;
	f[u][0][0] = 1;
	size[u] = 1;
	for (int v:ch[u]) {
		int lim1,lim2;
		if (v == fa) continue;
		dfs(v,u,k);
		std::memcpy(g,f[u],sizeof(g));
		std::memset(f[u],0,sizeof(f[u]));
		for (int c1 = 0; c1 <= 1; ++ c1) {
			if (c1 == 0) lim1 = size[u];
			else lim1 = k;
			for (int i = 0; i <= lim1; ++ i) {
				if (!g[c1][i]) continue;
				for (int c2 = 0; c2 <= 1; ++ c2) {
					if (c2 == 0) lim2 = size[v];
					else lim2 = k;
					for (int j = 0; j <= lim2; ++ j) {
						if (!f[v][c2][j]) continue;
						int w = (ll) g[c1][i] * f[v][c2][j] % mod;
						if (c1 == 0 && c2 == 0) {
							int max = std::max(i,j + 1);
							if (max > k) continue;
							f[u][0][max] = dec(f[u][0][max] + w);
						}
						if (c1 == 1 && c2 == 0) {
							if (i >= j + 1) {
								f[u][1][i] = dec(f[u][1][i] + w);
							}
							else if (j + 1 <= k) f[u][0][j + 1] = dec(f[u][0][j+1] + w);
						} 
						if (c1 == 0 && c2 == 1) {
							if (j - 1 >= i) f[u][1][j-1] = dec(f[u][1][j-1] + w);
							else f[u][0][i] = dec(f[u][0][i] + w);
						}
						if (c1 == 1 && c2 == 1) {
							int max = std::max(i,j - 1);
							f[u][1][max] = dec(f[u][1][max] + w);
						}
					}
				}
			}
		} 
		size[u] += size[v];
	} 
	//printf("%d\n",u);
//	for (int i = 0; i <= n; ++ i) printf("%d ",f[u][0][i]); puts(" need match");
	//for (int i = 0; i <= n; ++ i) printf("%d ",f[u][1][i]); puts(" can match");
}
							
int inv(int x) { return x == 1 ? 1 : (ll) ( mod - mod / x ) * inv(mod % x) % mod; }					

int main() {
	scanf("%d",&n);
	for (int i = 1; i < n; ++ i) {
		scanf("%d%d",&u,&v);
		// u = (i + 1); v = rand() % (i + 1) + 1;
		ch[u].push_back(v);
		ch[v].push_back(u);
	}
	int big = 1;
	for (int i = 1; i <= n; ++ i)
		big = (ll) big * 2 % mod;
	for (int i = 1; i <= n; ++ i) {
		dfs(1,0,i);
		int tmp = 0;
		for (int j = 0; j <= n; ++ j)
			tmp = (tmp + (f[1][1][j]) ) % mod;
		//printf("%d\n",tmp);
		ans = (ans + (big - tmp + mod) % mod) % mod;
	//	return 0;
	} ans = (ll) (ans - 1 + mod) * inv(big) % mod;
	printf("%d",ans);
	return 0;
}