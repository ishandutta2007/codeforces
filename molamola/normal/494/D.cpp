#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <memory.h>
#include <math.h>
#include <assert.h>
#include <queue>
#include <map>
#include <set>
#include <string>
#include <algorithm>
#include <iostream>
#include <functional>
#include <unordered_map>
#include <unordered_set>
#include <list>
#include <bitset>

using namespace std;
typedef pair<int, int> Pi;
typedef long long ll;
#define Fi first
#define Se second
#define pb(x) push_back(x)
#define sz(x) (int)x.size()
#define rep(i, n) for(int i=0;i<n;i++)
#define all(x) x.begin(), x.end()
typedef tuple<int, int, int> t3;
typedef pair<ll, ll> PL;

vector <Pi> E[100010];
int down[100010], vis[100010];
int n;

const int MOD = 1e9 + 7;

Pi S[100010];
Pi PP[100010];

void get_dfs(int x, int fa, int L, Pi &A){
	down[x] = 1;
	A.Fi = (A.Fi + L) % MOD;
	A.Se = (A.Se + (ll)L * L) % MOD;
	for(auto e : E[x])if(e.Se != fa && vis[e.Se] == 0){
		get_dfs(e.Se, x, (L + e.Fi) % MOD, A);
		down[x] += down[e.Se];
	}
}

void down_dfs(int x, int fa){
	down[x] = 1;
	for(auto e : E[x])if(e.Se != fa && vis[e.Se] == 0){
		down_dfs(e.Se, x);
		down[x] += down[e.Se];
	}
}

void put_dfs(int x, int fa, int L, Pi &A, int L0){
	PP[x].Se = (PP[x].Se + A.Se + A.Fi * 2LL * L + ((ll)L * L) % MOD * L0) % MOD;
	PP[x].Fi = (PP[x].Fi + A.Fi + (ll)L0 * L) % MOD;
	for(auto e : E[x])if(e.Se != fa && vis[e.Se] == 0){
		put_dfs(e.Se, x, (L + e.Fi) % MOD, A, L0);
	}
}

void Do(int x){
	down_dfs(x, -1);
	int c = x, h = down[x] / 2;
	while(1){
		int f = 0;
		for(auto e : E[c])if(vis[e.Se] == 0 && down[e.Se] < down[c] && down[e.Se] > h){
			c = e.Se; f = 1; break;
		}
		if(f == 0)break;
	}
	vector <int> near;
	vector <Pi> G;
	vector <int> lu;
	Pi tot = Pi(0, 0);
	int L0 = 1;
	for(auto e : E[c])if(!vis[e.Se]){
		near.pb(e.Se);
		Pi A = Pi(0, 0);
		get_dfs(e.Se, c, e.Fi, A);
		G.pb(A);
		lu.pb(e.Fi);
		tot.Fi = (tot.Fi + A.Fi) % MOD;
		tot.Se = (tot.Se + A.Se) % MOD;
		L0 += down[e.Se];
	}
	for(int i=0;i<sz(near);i++){
		int u = near[i];
		Pi A = Pi(tot.Fi - G[i].Fi, tot.Se - G[i].Se);
		if(A.Fi < 0)A.Fi += MOD;
		if(A.Se < 0)A.Se += MOD;
		put_dfs(u, c, lu[i], A, L0 - down[u]);
	}
	PP[c].Se = (PP[c].Se + tot.Se) % MOD;
	PP[c].Fi = (PP[c].Fi + tot.Fi) % MOD;
	vis[c] = 1;
	for(int e : near){
		Do(e);
	}
}

int dep[100010], ST[100010], EN[100010], ce;
int up[100010][20];
int Ldep[100010];
t3 DP[100010];

void DFS(int x, int fa){
	get<0>(DP[x]) = 1;
	ST[x] = ++ce;
	for(auto e : E[x])if(e.Se != fa){
		dep[e.Se] = dep[x] + 1;
		Ldep[e.Se] = (Ldep[x] + e.Fi) % MOD;
		up[e.Se][0] = x;
		for(int i=1;i<20;i++)up[e.Se][i] = up[ up[e.Se][i-1] ][i-1];
		DFS(e.Se, x);
		int L = e.Fi;
		int a0 = get<0>(DP[e.Se]);
		int a1 = get<1>(DP[e.Se]);
		int a2 = get<2>(DP[e.Se]);
		get<0>(DP[x]) += a0;
		get<1>(DP[x]) = (a1 + get<1>(DP[x]) + (ll)L * a0) % MOD;
		get<2>(DP[x]) = (get<2>(DP[x]) + ((ll)L * L) % MOD * a0 + (ll)2 * L * a1 + a2) % MOD;
	}
	EN[x] = ce;
}

int lca(int x, int y){
	if(dep[x] < dep[y])swap(x, y);
	rep(i, 20)if(1<<i & (dep[x] - dep[y]))x = up[x][i];
	for(int i=19;i>=0;i--)if(up[x][i] != up[y][i])x = up[x][i], y = up[y][i];
	return x == y ? x : up[x][0];
}

void solve(){
	scanf("%d", &n);
	rep(i, n-1){
		int x, y, z; scanf("%d%d%d", &x, &y, &z);
		E[x].pb(Pi(z, y));
		E[y].pb(Pi(z, x));
	}
	Do(1);
	DFS(1, -1);
	int q; scanf("%d", &q);
	while(q--){
		int u, v; scanf("%d%d", &u, &v);
		if(ST[v] <= ST[u] && ST[u] <= EN[v]){
			ll ans = PP[u].Se;
			ll C = 0;
			ll a0 = n;
			ll a1 = PP[v].Fi;
			ll a2 = PP[v].Se;
			a0 -= get<0>(DP[v]);
			a1 -= get<1>(DP[v]);
			a2 -= get<2>(DP[v]);
			ll L = Ldep[u] - Ldep[v];
			if(L < 0)L += MOD;
			C += (L * L) % MOD * a0;
			C += 2LL * L * a1;
			C += a2;
			ans -= 2 * C;
			ans %= MOD;
			if(ans < 0)ans += MOD;
			printf("%lld\n", ans);
		}
		else{
			ll ans = -PP[u].Se;
			int a0 = get<0>(DP[v]);
			int a1 = get<1>(DP[v]);
			int a2 = get<2>(DP[v]);
			int lc = lca(u, v);
			ll L = Ldep[u] + Ldep[v] - 2LL * Ldep[lc];
			if(L < 0)L += MOD;
			ans += 2LL * (L * L) % MOD * a0;
			ans += 4LL * L * a1;
			ans += 2LL * a2;
			ans %= MOD;
			if(ans < 0)ans += MOD;
			printf("%lld\n", ans);
		}
	}
}

int main(){
	int Tc = 1; //scanf("%d", &Tc);
	for(int tc=1;tc<=Tc;tc++){
		solve();
	}
	return 0;
}