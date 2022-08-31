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

const int N=501000;
int n,k,_;
ll dp[N][2];
vector<PII> e[N];
void dfs(int u,int f) {
	ll sm=0;
	vector<ll> dd;
	for (auto p:e[u]) {
		int v=p.fi;
		if (v==f) continue;
		dfs(v,u);
		// 0 <=k 1 <= k-1
		ll w0=dp[v][0],w1=dp[v][1]+p.se;
		sm+=w0;
		dd.pb(w1-w0);
	}
	sort(all(dd)); reverse(all(dd));
	dp[u][0]=dp[u][1]=sm;
	rep(i,0,SZ(dd)) {
		sm+=max(dd[i],0ll);
		if (i+1<k) dp[u][1]=max(dp[u][1],sm);
		if (i+1<=k) dp[u][0]=max(dp[u][0],sm);
	}
//	printf("gg %d %lld %lld\n",u,dp[u][0],dp[u][1]);
}

void solve() {
	scanf("%d%d",&n,&k);
	rep(i,1,n+1) e[i].clear();
	rep(i,1,n) {
		int u,v,w;
		scanf("%d%d%d",&u,&v,&w);
		e[u].pb(mp(v,w)); e[v].pb(mp(u,w));
	}
	dfs(1,0);
	printf("%lld\n",dp[1][0]);
}

int main() {
	for (scanf("%d",&_);_;_--) {
		solve();
	}
}