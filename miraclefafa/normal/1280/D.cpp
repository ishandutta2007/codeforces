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
pair<int,ll> dp[N][N],tmp[N];
int b[N],w;
VI e[N];
int sz[N],_,n,m,u,v;

void dfs(int u,int f) {
	sz[u]=1;
	dp[u][0]=mp(0,b[u]);
	for (auto v:e[u]) {
		if (v==f) continue;
		dfs(v,u);
		for (int i=0;i<sz[u]+sz[v];i++) tmp[i]=mp(-1,-1);
		for (int i=0;i<sz[u];i++) for (int j=0;j<=sz[v];j++) {
			tmp[i+j]=max(tmp[i+j],mp(dp[u][i].fi+dp[v][j].fi,dp[u][i].se+dp[v][j].se));
		}
		for (int i=0;i<sz[u]+sz[v];i++) dp[u][i]=tmp[i];
		sz[u]+=sz[v];
	}
	for (int i=sz[u]-1;i>=0;i--) {
		auto x=dp[u][i];
		if (x.se>0) x.fi++; x.se=0;
		dp[u][i+1]=max(dp[u][i+1],x);
	}
	//for (int i=0;i<=sz[u];i++) printf("%d %d %d %lld\n",u,i,dp[u][i].fi,dp[u][i].se);
}

void solve() {
	scanf("%d%d",&n,&m);
	rep(i,1,n+1) scanf("%d",b+i);
	rep(i,1,n+1) {
		scanf("%d",&w);
		b[i]=w-b[i];
	}
	rep(i,1,n+1) e[i].clear();
	rep(i,1,n) {
		scanf("%d%d",&u,&v);
		e[u].pb(v);
		e[v].pb(u);
	}
	rep(i,1,n+1) rep(j,0,n+1) dp[i][j]=mp(-1,-1);
	dfs(1,0);
	auto x=dp[1][m-1];
	if (x.se>0) x.fi++; x.se=0;
	printf("%d\n",x.fi);
}

int main() {
	for (scanf("%d",&_);_;_--) {
		solve();
	}
}