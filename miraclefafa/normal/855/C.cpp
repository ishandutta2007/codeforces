#include <cstdio>
#include <cstring>
#include <cmath>
#include <algorithm>
#include <vector>
#include <string>
#include <map>
#include <set>
#include <cassert>
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
const ll mod=1000000007;
ll powmod(ll a,ll b) {ll res=1;a%=mod; assert(b>=0); for(;b;b>>=1){if(b&1)res=res*a%mod;a=a*a%mod;}return res;}
// head

const int N=101000;
ll dp[N][12][3],tmp[12][3],ret;
int sz[N],n,m,u,v,k,x;
VI e[N];
void upd(ll &x,ll y) {
	x=(x+y)%mod;
}
void dfs(int u,int f) {
	dp[u][0][0]=k-1;
	dp[u][1][1]=1;
	dp[u][0][2]=m-k;
	sz[u]=1;
	for (auto v:e[u]) if (v!=f) {
		dfs(v,u);
		rep(j,0,x+1) rep(k,0,3) tmp[j][k]=0;
		rep(j1,0,sz[u]+1) rep(j2,0,sz[v]+1) if (j1+j2<=x) {
			upd(tmp[j1+j2][0],dp[u][j1][0]*(dp[v][j2][0]+dp[v][j2][1]+dp[v][j2][2]));
			upd(tmp[j1+j2][1],dp[u][j1][1]*dp[v][j2][0]);
			upd(tmp[j1+j2][2],dp[u][j1][2]*(dp[v][j2][0]+dp[v][j2][2]));
		}
		sz[u]=min(sz[u]+sz[v],x);
		rep(j,0,sz[u]+1) rep(k,0,3) dp[u][j][k]=tmp[j][k];
	}

}
int main() {
	scanf("%d%d",&n,&m);
	rep(i,1,n) {
		scanf("%d%d",&u,&v);
		e[u].pb(v); e[v].pb(u);
	}
	scanf("%d%d",&k,&x);
	dfs(1,0);
	rep(j,0,x+1) rep(k,0,3) upd(ret,dp[1][j][k]);
	printf("%lld\n",ret);
}