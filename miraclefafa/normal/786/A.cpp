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

const int N=7010;
int k[3],a[3][N],dp[3][N],wn[3][N];
PII q[N*2];
int n;
int main() {
	scanf("%d",&n);
	scanf("%d",&k[0]); rep(i,0,k[0]) scanf("%d",&a[0][i]);
	scanf("%d",&k[1]); rep(i,0,k[1]) scanf("%d",&a[1][i]);
	rep(i,1,n) wn[0][i]=k[0],wn[1][i]=k[1];
	memset(dp,-1,sizeof(dp));
	q[0]=mp(0,0);
	q[1]=mp(1,0);
	int t=2;
	dp[0][0]=dp[1][0]=0;
	rep(i,0,t) {
		int u=q[i].fi,v=q[i].se;
//		printf("%d %d %d\n",u,v,dp[u][v]);
		if (dp[u][v]==0) {
			rep(j,0,k[u^1]) {
				int uu=u^1,vv=(v+n-a[uu][j])%n;
				if (dp[uu][vv]==-1) {
					dp[uu][vv]=1;
					q[t++]=mp(uu,vv);
				}
			}
		} else {
			rep(j,0,k[u^1]) {
				int uu=u^1,vv=(v+n-a[uu][j])%n;
				--wn[uu][vv];
				if (dp[uu][vv]==-1&&wn[uu][vv]==0) {
					dp[uu][vv]=0;
					q[t++]=mp(uu,vv);
				}
			}

		}
	}
	rep(j,0,2) {
		rep(i,1,n) {
			if (dp[j][i]==-1) printf("Loop "); else if (dp[j][i]==0) printf("Lose "); else printf("Win ");
		}
		puts("");
	}
}