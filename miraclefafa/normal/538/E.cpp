#include <bits/stdc++.h>
using namespace std;
#define rep(i,a,n) for (int i=a;i<n;i++)
#define per(i,a,n) for (int i=n-1;i>=a;i--)
#define pb push_back
#define mp make_pair
#define all(x) (x).begin(),(x).end()
#define SZ(x) ((int)(x).size())
#define fi first
#define se second
typedef vector<int> VI;
typedef long long ll;
typedef pair<int,int> PII;
const ll mod=1000000007;
ll powmod(ll a,ll b) {ll res=1;a%=mod;for(;b;b>>=1){if(b&1)res=res*a%mod;a=a*a%mod;}return res;}
// head

const int N=201000;
VI e[N];
int n,m,u,v,dp[N],mf[N];
void dfs(int u,int f,int ty) {
	// ty=0 max
	if (ty==0) dp[u]=0; else dp[u]=1<<30;
	mf[u]=0;
	int lv=0;
	rep(i,0,SZ(e[u])) {
		int v=e[u][i];
		if (v==f) continue;
		dfs(v,u,ty^1);
		mf[u]+=mf[v];
		if (ty==0) dp[u]+=dp[v];
		else dp[u]=min(dp[v],dp[u]);
		lv++;
	}
	if (lv==0) mf[u]=1,dp[u]=1;
}
int main() {
	scanf("%d",&n);
	rep(i,1,n) {
		scanf("%d%d",&u,&v);
		e[u].pb(v); e[v].pb(u);
	}
	dfs(1,0,0);
	int ans1=dp[1];
	dfs(1,0,1);
	int ans2=dp[1];
	printf("%d %d\n",mf[1]+1-ans2,ans1);
}