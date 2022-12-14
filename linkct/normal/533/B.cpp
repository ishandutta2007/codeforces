#include <cstdio>
#include <cstring>
#include <iostream>
using namespace std;
const int MAXN = 500005;
typedef long long int ll;

struct edge{
	int n, p;
	void var(int _n, int _p){
		n = _n, p = _p;
	}
}edges[MAXN];
int g[MAXN], edgeSize, f[MAXN], val[MAXN], n;
ll dp[MAXN][2];

void addEdge(int fr, int t){
	edges[++ edgeSize].var(t, g[fr]);
	g[fr] = edgeSize;
}
inline ll max(ll a, ll b){return a > b ? a : b;}
void dfs(int x){
	int p, v;
	ll pre[2] = {0}, now[2] = {0};
	for(p = g[x]; p; p = edges[p].p){
		v = edges[p].n;
		dfs(v);
		if(p == g[x]){
			now[0] = dp[v][0];
			now[1] = dp[v][1];
			continue;
		}
		pre[0] = now[0], pre[1] = now[1];
		now[0] = max(pre[0], max(pre[0] + dp[v][0], pre[1] + dp[v][1]));
		now[1] = max(pre[1], max(pre[1] + dp[v][0], pre[0] + dp[v][1]));
	}
	dp[x][0] = now[0];
	dp[x][1] = max(now[1], now[0] + val[x]);
}
int main(){
	int i;
	memset(dp, 0xbf, sizeof(dp));
	scanf("%d", &n);
	for(i = 1; i <= n; ++ i){
		scanf("%d%d", &f[i], &val[i]);
		if(i != 1) addEdge(f[i], i);
	}
	dfs(1);
	cout << max(dp[1][1], dp[1][0]) << endl;
	return 0;
}