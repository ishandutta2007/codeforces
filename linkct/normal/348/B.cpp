#include <cstdio>
const int MAXN = 100005;
typedef long long int ll;

int n, g[MAXN], nxt[MAXN << 1], to[MAXN << 1], val[MAXN], son[MAXN], edgeSize;
ll sum[MAXN], mul[MAXN], cur[MAXN];

ll gcd(ll a, ll b){return b ? gcd(b, a % b) : a;}
void dfs(int x, int fa){
	int p;
	sum[x] = val[x]; mul[x] = 1;
	for(p = g[x]; p; p = nxt[p])
		if(to[p] != fa){
			dfs(to[p], x);
			son[x] ++;
			sum[x] += sum[to[p]];
			if(mul[x] / gcd(mul[x], mul[to[p]]) * double(mul[to[p]]) > 1e13) mul[x] = ll(1e13);
			else mul[x] = mul[x] / gcd(mul[x], mul[to[p]]) * mul[to[p]];
		}
	if(!son[x]) cur[x] = sum[x] = val[x];
	else{
		ll tmp = 0x3f3f3f3f3f3f3f3fLL;
		for(p = g[x]; p; p = nxt[p])
			if(to[p] != fa && cur[to[p]] / mul[x] < tmp)
				tmp = cur[to[p]] / mul[x];
		cur[x] = tmp * son[x] * mul[x];
		mul[x] *= son[x];
	}
}
void addEdge(int u, int v){
	edgeSize ++;
	nxt[edgeSize] = g[u];
	g[u] = edgeSize;
	to[edgeSize] = v;
}
int main(){
	int i, u, v;
	scanf("%d", &n);
	for(i = 1; i <= n; ++ i)
		scanf("%d", &val[i]);
	for(i = 1; i < n; ++ i){
		scanf("%d%d", &u, &v);
		addEdge(u, v);
		addEdge(v, u);
	}
	dfs(1, -1);
	printf("%I64d\n", sum[1] - cur[1]);
	return 0;
}