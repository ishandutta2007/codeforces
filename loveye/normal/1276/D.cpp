#include<cstdio>
#include<iostream>
#include<cstring>
#include<algorithm>
#include<vector>
#include<cstdlib>
using namespace std;

typedef long long ll;
#define fr(i,l,r) for(int i = (l);i <= (r);++i)
#define rf(i,l,r) for(int i = (l);i >= (r);--i)
#define fo(i,l,r) for(int i = (l);i < (r);++i)
#define foredge(i,u,v) for(int i = fir[u],v;v = to[i],i;i = nxt[i])
#define filein(File) freopen(File".in","r",stdin)
#define fileout(File) freopen(File".out","w",stdout)
#define mp make_pair
#define fi first
#define se second
typedef pair<int,int> pii;

const int N = 2e5 + 5,MOD = 998244353;
int n,fid[N];
vector<pii> G[N];
ll dp[N][3];
ll qpow(ll a,int x) {
	ll res=  1;
	for(;x;x >>= 1,a = a * a % MOD)
		if(x & 1) res = res * a % MOD;
	return res;
}
void dfs(int u,int fa) {
	int v; vector<ll> tmp;
	for(auto p : G[u]) {
		v = p.se;
		if(v == fa) fid[u] = p.fi,tmp.push_back(1);
		else dfs(v,u),tmp.push_back(dp[v][2]);
	}
	tmp.push_back(1);
	rf(i,int(tmp.size())-2,0) tmp[i] = tmp[i+1] * tmp[i] % MOD;
	ll res = 1;
	fo(i,0,G[u].size()) {
		v = G[u][i].se;
		if(v == fa) (dp[u][0] += res * tmp[i+1]) %= MOD;
		else {
			ll num = dp[v][1] * res % MOD * tmp[i+1];
			if(G[u][i].fi <= fid[u]) (dp[u][0] += num) %= MOD;
			else (dp[u][1] += num) %= MOD;
			(dp[u][2] += num) %= MOD;
			res = res * dp[v][0] % MOD;
		}
	}
	(dp[u][1] += res) %= MOD; //choose inf
	(dp[u][2] += res) %= MOD; //choose inf
}
int main() {
	scanf("%d",&n);
	for(int i = 1,u,v;i < n;++i) {
		scanf("%d%d",&u,&v);
		G[u].push_back(mp(i,v));
		G[v].push_back(mp(i,u));
	}
	dfs(1,0);
	printf("%lld\n",(dp[1][2] + MOD) % MOD);
	return 0;
}