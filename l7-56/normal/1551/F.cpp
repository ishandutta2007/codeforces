#include<bits/stdc++.h>
using namespace std;

const int maxn = 110, mod = 1e9 + 7;
int cnt[maxn],ans,n,k,T,dp[maxn][maxn];

struct Edge{
	int v,nxt;
}e[maxn << 1];
int h[maxn],cnt_e;
void add(int x, int y){
	e[++cnt_e] = (Edge){y, h[x]};
	h[x] = cnt_e; return;
}

void dfs(int u, int pre, int stp){
	cnt[stp]++;
	for(int i = h[u]; i; i = e[i].nxt){
		int v = e[i].v;
		if(v == pre) continue;
		dfs(v, u, stp + 1);
	}
}

int main(){
	scanf("%d", &T);
	while(T--){
		memset(h, 0, sizeof h); cnt_e = 0;
		scanf("%d%d", &n, &k);
		for(int i = 1; i < n; ++i){
			int u,v;
			scanf("%d%d", &u, &v);
			add(u, v); add(v, u);
		}
		if(k == 2){
			printf("%d\n", n * (n - 1) / 2);
			continue;
		}
		
		ans = 0;
		for(int rt = 1; rt <= n; ++rt){
			memset(dp, 0, sizeof dp);
			for(int i = 1; i < n; ++i)
				dp[i][0] = 1;
			for(int s = h[rt]; s; s = e[s].nxt){
				memset(cnt, 0, sizeof cnt);
				dfs(e[s].v, rt, 1);
				for(int i = 1; i < n; ++i)
					for(int j = k; j > 0; --j)
						dp[i][j] = (dp[i][j] + dp[i][j - 1] * cnt[i] % mod) % mod;
			}
			for(int i = 1; i < n; ++i) ans = (ans + dp[i][k]) % mod;
		}
		
		printf("%d\n", ans);
	}
	return 0;
}