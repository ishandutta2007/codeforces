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

const int N=88;
int n,K,m,u,v,c,dp[N][N][N][N];
vector<PII> e[N];
void upd(int &a,int b) {
	if (a>b) a=b;
}
int main() {
	scanf("%d%d",&n,&K);
	scanf("%d",&m);
	rep(i,0,m) {
		scanf("%d%d%d",&u,&v,&c); --u; --v;
		e[v].pb(mp(u,c));
	}
	memset(dp,0x20,sizeof(dp));
	rep(i,0,n) dp[0][i][i][i]=0;
	rep(c,0,K-1) rep(i,0,n) rep(mn,0,n) rep(mx,mn,n) if (dp[c][i][mn][mx]<=20000000) {
		assert(i==mn||i==mx);
		int r=dp[c][i][mn][mx];
		for (auto p:e[i]) if (p.fi<mn||p.fi>mx) upd(dp[c+1][p.fi][min(mn,p.fi)][max(mx,p.fi)],r+p.se);
	}
	int ans=0x20202020;
	rep(i,0,n) rep(mn,0,n) rep(mx,mn,n) ans=min(ans,dp[K-1][i][mn][mx]);
	if (ans>20000000) ans=-1;
	printf("%d\n",ans);
}