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

int dp[110][22][22],tmp[22][22];
int n,k,u,v;
VI e[110];
void dfs(int u,int f) {
	dp[u][1][k+1]=1; // +1 
	dp[u][0][0]=1;
	for (auto v:e[u]) if (v!=f) {
		dfs(v,u);
		rep(p,0,k+2) rep(q,0,k+2) tmp[p][q]=dp[u][p][q],dp[u][p][q]=0;
		rep(p,0,k+2) rep(q,0,k+2) if (tmp[p][q]) {
			rep(s,0,k+1) rep(t,0,k+2) {
				(dp[u][max(p,s+1)][min(q,t+1)]+=(ll)tmp[p][q]*dp[v][s][t]%mod)%=mod;
			}
		}
	}
/*	rep(p,0,k+2) rep(q,0,k+2) if (dp[u][p][q]) {
		printf("%d %d %d %d\n",u,p,q,dp[u][p][q]);
	}*/
	rep(p,0,k+2) rep(q,0,k+2) tmp[p][q]=dp[u][p][q],dp[u][p][q]=0;
	rep(p,0,k+2) rep(q,0,k+2) if (q+p<=k+1) (dp[u][0][q]+=tmp[p][q])%=mod;
		else (dp[u][p][q]+=tmp[p][q])%=mod;
/*	rep(p,0,k+2) rep(q,0,k+2) if (dp[u][p][q]) {
		printf("%d %d %d %d\n",u,p,q,dp[u][p][q]);
	}*/
}
int main() {
	scanf("%d%d",&n,&k);
	rep(i,1,n) {
		scanf("%d%d",&u,&v);
		e[u].pb(v); e[v].pb(u);
	}
	if (k==0) {
		puts("1");
		return 0;
	}
	dfs(1,0);
	int ret=0;
	rep(q,0,k+2) (ret+=dp[1][0][q])%=mod;
	printf("%d\n",ret);
}