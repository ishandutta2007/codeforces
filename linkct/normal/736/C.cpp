#include <cstdio>
const int MAXN = 105, MAXK = 55;
typedef long long int LL;
const LL MOD = 1000000007LL;

LL dp[MAXN][MAXK];
int n, G[MAXN], nxt[MAXN << 1], to[MAXN << 1], edgeSize;
int size[MAXN], m;

void dfs(int x, int fa){
	int p, i, j; LL cur, f, g, f_, g_; size[x] = 1;
	for(p = G[x]; p; p = nxt[p]){
		if(to[p] == fa) continue;
		dfs(to[p], x); size[x] += size[to[p]];
	} if(size[x] == 1){dp[x][m - 1] = dp[x][m * 2] = 1; return;}
	for(p = G[x], dp[x][m * 2] = 1; p; p = nxt[p]){
		if(to[p] == fa) continue;
		for(i = cur = 0; i <= m * 2; ++ i)
			cur = (cur + dp[to[p]][i]) % MOD;
		dp[x][m * 2] = dp[x][m * 2] * cur % MOD;
	}
	for(i = - m; i < 0; ++ i){
		for(p = G[x], f = 1, g = 0; p; p = nxt[p]){
			if(to[p] == fa) continue;
			for(j = i + 2, cur = 0; j < - i; ++ j)
				cur = (cur + dp[to[p]][j + m]) % MOD;
			f_ = f * cur % MOD;
			g_ = (g * (cur + dp[to[p]][i + 1 + m]) + f * dp[to[p]][i + 1 + m]) % MOD;
			f = f_, g = g_;
		} dp[x][i + m] = g;
	}
	for(i = 0; i < m; ++ i){
		for(p = G[x], f = 1, g = 0; p; p = nxt[p]){
			if(to[p] == fa) continue;
			for(j = - i, cur = 0; j <= i; ++ j)
				cur = (cur + dp[to[p]][j + m]) % MOD;
			f_ = f * cur % MOD;
			g_ = (g * (cur + dp[to[p]][i + 1 + m]) + f * dp[to[p]][i + 1 + m]) % MOD;
			f = f_, g = g_;
		} dp[x][i + m] = g;
	}
}
void addEdge(int u, int v){
	nxt[++ edgeSize] = G[u];
	to[G[u] = edgeSize] = v;
}
int main(){
	int i, u, v; LL ans = 0LL;
	scanf("%d%d", &n, &m);
	for(i = 1; i < n; ++ i){
		scanf("%d%d", &u, &v);
		addEdge(u, v), addEdge(v, u);
	}
	if(m == 0){
		printf("1\n");
		return 0;
	} dfs(1, -1);
	for(i = 0; i <= m; ++ i)
		ans = (ans + dp[1][m + i]) % MOD;
	printf("%d\n", int(ans));
	return 0;
}