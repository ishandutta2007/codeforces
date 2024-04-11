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
mt19937 mrand(random_device{}()); 
const ll mod=1000000007;
int rnd(int x) { return mrand() % x;}
ll powmod(ll a,ll b) {ll res=1;a%=mod; assert(b>=0); for(;b;b>>=1){if(b&1)res=res*a%mod;a=a*a%mod;}return res;}
ll gcd(ll a,ll b) { return b?gcd(b,a%b):a;}
// head

const int N=410000;
VI e[N],te[N];
int mark[N],w[N],q[N],deg[N],f[N],pr[N];
ll val[N],dp[N],ans;
int _,n,m,s;

void adde(int u,int v) {
	//printf("ee %d %d\n",u,v);
	te[u].pb(v); te[v].pb(u);
}

void dfs(int u,int f) {
	dp[u]=0;
	for (auto v:te[u]) {
		if (v==f) continue;
		dfs(v,u);
		dp[u]=max(dp[u],dp[v]);
	}
	dp[u]=max(0ll,dp[u]+val[u]);
	//printf("%d %lld\n",u,dp[u]);
}

bool dfs2(int u,int f,int rt) {
	if (u==rt) {
		ans+=val[u]; val[u]=0;
		return 1;
	}
	for (auto v:te[u]) {
		if (v==f) continue;
		if (dfs2(v,u,rt)) {
			ans+=val[u]; val[u]=0;
			return 1;
		}
	}
	return 0;
}

int main() {
	scanf("%d%d",&n,&m);
	rep(i,0,n) {
		scanf("%d",w+i);
	}
	rep(i,0,m) {
		int u,v;
		scanf("%d%d",&u,&v);
		--u; --v;
		e[u].pb(v);
		e[v].pb(u);
		deg[u]++; deg[v]++;
	}
	int t=0;
	rep(i,0,n) {
		if (deg[i]==1) q[t++]=i;
		f[i]=-1;
	}
	rep(i,0,t) {
		int u=q[i];
		mark[u]=1;
		for (auto v:e[u]) if (!mark[v]) {
			f[u]=v;
			--deg[v];
			if (deg[v]==1) q[t++]=v;
		}
	}
	int fs=-1;
	rep(i,0,n) if (!mark[i]) fs=i;
	rep(i,0,n) pr[i]=i;
	if (fs!=-1) {
		rep(i,0,n) if (!mark[i]) pr[i]=fs;
	}
	rep(i,0,n) val[pr[i]]+=w[i];
	rep(i,0,n) if (f[i]!=-1) {
		adde(pr[i],pr[f[i]]);
	}
	//rep(i,0,n) printf("%d %lld\n",i,val[i]);
	scanf("%d",&s);
	s=pr[s-1];
	if (fs==-1) {
		dfs(s,-1);
		printf("%lld\n",dp[s]);
		return 0;
	}
	dfs2(s,-1,fs);
	dfs(fs,-1);
	printf("%lld\n",dp[fs]+ans);
}