#include <cstdio>
#define MAX 100005
#define MOD 1000000007
typedef long long int ll;

struct edge{
	int n, p;
	void var(int _n, int _p){
		n = _n;
		p = _p;
	}
}edges[MAX];
int g[MAX], edgeSize, n, v[MAX];
ll dp[MAX][2];

inline void addEdge(int f, int t){
	edges[++ edgeSize].var(t, g[f]);
	g[f] = edgeSize;
}
void dfs(int x){
	dp[x][0] = 1;
	dp[x][1] = 0;
	for(int p = g[x]; p; p = edges[p].p){
		int y = edges[p].n;
		dfs(y);
		dp[x][1] = (dp[x][1] * dp[y][0]) % MOD;
		dp[x][1] = (dp[x][1] + dp[x][0] * dp[y][1]) % MOD;
		dp[x][0] = (dp[x][0] * dp[y][0]) % MOD;
	}
	if(v[x] == 1)
		dp[x][1] = dp[x][0];
	else
		dp[x][0] = (dp[x][0] + dp[x][1]) % MOD;
}
int main(){
	int i, t;
	scanf("%d", &n);
	for(i = 2; i <= n; ++ i){
		scanf("%d", &t);
		addEdge(t + 1, i);
	}
	for(i = 1; i <= n; ++ i)
		scanf("%d", &v[i]);
	dfs(1);
	printf("%d\n", int(dp[1][1]));
	return 0;
}