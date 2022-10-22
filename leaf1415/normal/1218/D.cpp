#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <utility>
#include <stdio.h>
#include <cassert>
#include <time.h>
#define llint long long

using namespace std;
typedef pair<int, int> P;

struct edge{
	int to, cost;
	edge(int a, int b){
		to = a, cost = b;
	}
};

int n, m;
vector<edge> G[100005];
vector<P> pvec;
vector<int> vec[45];
int pedge[100005];
int sum;

llint inv2;
llint dp[1<<17], dp2[1<<17], a[1<<17];
int tour;

int order[100005];
int Prev[100005][17];
int depth[100005];

int N = 1<<17;
llint mod = 1000000007;

int id = 1;
void dfs(int v, int p, int d)
{
	order[v] = id++;
	Prev[v][0] = p, depth[v] = d;
	for(int i = 0; i < G[v].size(); i++){
		if(G[v][i].to == p){
			pedge[v] = i;
			continue;
		}
		if(order[G[v][i].to]){
			if(order[G[v][i].to] < order[v]) pvec.push_back(make_pair(v, i));
			continue;
		}
		dfs(G[v][i].to, v, d+1);
	}
}

int getLCA(int u, int v){
	int x = u, y = v;
	if(depth[y] > depth[x]) swap(x, y);
	
	for(int i = 16; i >= 0; i--){
		if(depth[x] - (1<<i) >= depth[y]) x = Prev[x][i];
	}
	if(x == y) return x;
	for(int i = 16; i >= 0; i--){
		if(Prev[x][i] != Prev[y][i]){
			x = Prev[x][i];
			y = Prev[y][i];
		}
	}
	x = Prev[x][0];
	return x;
}

void fwt(llint f[], int n)
{
	int N = 1 << n;
	for(int i = 0; i < n; i++){
		for(int j = 0; j < N; j++){
			if(j & (1<<i)) continue;
			llint x = f[j], y = f[j|(1<<i)];
			f[j] = (x + y) % mod, f[j|(1<<i)] = (x - y + mod) % mod;
		}
	}
}

void ifwt(llint f[], int n)
{
	int N = 1 << n;
	for(int i = 0; i < n; i++){
		for(int j = 0; j < N; j++){
			if(j & (1<<i)) continue;
			llint x = f[j], y = f[j|(1<<i)];
			f[j] = (x + y) * inv2 % mod, f[j|(1<<i)] = (x - y + mod) * inv2 % mod;
		}
	}
}


llint modpow(llint a, llint n)
{
	if(n == 0) return 1;
	if(n % 2){
		return ((a%mod) * (modpow(a, n-1)%mod)) % mod;
	}
	else{
		return modpow((a*a)%mod, n/2) % mod;
	}
}

void calc()
{
	for(int i = 0; i < N; i++) dp[i] = 0;
	dp[sum] = 1;
	fwt(dp, 17);
	
	for(int i = 1; i <= tour; i++){
		for(int j = 0; j < N; j++) a[j] = 0;
		for(int j = 0; j < vec[i].size(); j++) a[vec[i][j]]++;
		
		fwt(a, 17);
		for(int j = 0; j < N; j++) dp[j] *= a[j], dp[j] %= mod;
	}
	ifwt(dp, 17);
}

int main(void)
{
	clock_t stime = clock();
	inv2 = modpow(2, mod-2);
	
	scanf("%d %d", &n, &m);
	int u, v, w; sum = 0;
	for(int i = 1; i <= m; i++){
		scanf("%d %d %d", &u, &v, &w);
		G[u].push_back(edge(v, w));
		G[v].push_back(edge(u, w));
		sum ^= w;
	}
	
	pedge[1] = -1;
	dfs(1, 0, 0);
	
	for(int i = 1; i <= 16; i++){
		for(int j = 1; j <= n; j++){
			Prev[j][i] = Prev[Prev[j][i-1]][i-1];
		}
	}
	
	int id = 1;
	for(int i = 0; i < pvec.size(); i++){
		int u = pvec[i].first, v = G[u][pvec[i].second].to;
		vec[id].push_back(G[u][pvec[i].second].cost);
		int lca = getLCA(u, v);
		
		int p = u;
		while(p != lca){
			vec[id].push_back(G[p][pedge[p]].cost);
			p = G[p][pedge[p]].to;
		}
		p = v;
		while(p != lca){
			vec[id].push_back(G[p][pedge[p]].cost);
			p = G[p][pedge[p]].to;
		}
		id++;
	}
	tour = id-1;
	
	calc();
	for(int i = 0; i < N; i++) dp2[i] = dp[i];
	mod = 998244853, inv2 = modpow(2, mod-2);
	calc();
	
	for(int i = 0; i < N; i++){
		if(dp[i] || dp2[i]){
			printf("%d %I64d", i, dp2[i]);
			return 0;
		}
	}
	return 0;
}