#include <bits/stdc++.h>
using namespace std;
#define rep(i,a,n) for (int i=a;i<n;i++)
#define per(i,a,n) for (int i=n-1;i>=a;i--)
#define pb push_back
#define mp make_pair
#define all(x) (x).begin(),(x).end()
#define fi first
#define se second
#define SZ(x) ((int)(x).size())
typedef vector<int> VI;
typedef long long ll;
typedef pair<int,int> PII;
typedef double db;
mt19937 mrand(random_device{}()); 
const ll mod=1000000007;
int rnd(int x) { return mrand() % x;}
ll powmod(ll a,ll b) {ll res=1;a%=mod; assert(b>=0); for(;b;b>>=1){if(b&1)res=res*a%mod;a=a*a%mod;}return res;}
ll gcd(ll a,ll b) { return b?gcd(b,a%b):a;}
// head

const int N=3010;
int n,u,v,go[N][N],sz[N][N];
ll dp[N][N],ans;
vector<PII> g[N];
VI e[N];
void dfs(int u,int f,int br,int rt,int dis) {
	if (dis>=1) g[dis].pb(mp(u,rt));
	go[rt][u]=br;
	sz[rt][u]=1;
	for (auto v:e[u]) {
		if (v==f) continue;
		dfs(v,u,br==rt?v:br,rt,dis+1);
		sz[rt][u]+=sz[rt][v];
	}
}

int main() {
	scanf("%d",&n);
	rep(i,1,n) {
		scanf("%d%d",&u,&v);
		e[u].pb(v); e[v].pb(u);
	}
	rep(i,1,n+1) dfs(i,i,i,i,0);
	rep(i,1,n+1) {
		for (auto p:g[i]) {
			int u=p.fi,v=p.se;
			dp[u][v]=max(dp[go[u][v]][v],dp[u][go[v][u]]);
		//	printf("zz %d %d %d\n",u,v,(n-sz[u][go[u][v]])*(n-sz[v][go[v][u]]));
		//	printf("gg %d\n",go[u][v]);
			dp[u][v]+=(n-sz[u][go[u][v]])*(n-sz[v][go[v][u]]);

			ans=max(ans,dp[u][v]);
		}
	}
	printf("%lld\n",ans);
}