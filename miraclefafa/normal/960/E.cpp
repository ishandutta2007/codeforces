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
const ll mod=1000000007;
ll powmod(ll a,ll b) {ll res=1;a%=mod; assert(b>=0); for(;b;b>>=1){if(b&1)res=res*a%mod;a=a*a%mod;}return res;}
ll gcd(ll a,ll b) { return b?gcd(b,a%b):a;}
// head

const int N=201000;
int n,val[N],u,v;
VI e[N];
ll dp[N],up[N][2],down[N][2],cnt[N][2],ret;
void dfs(int u,int f) {
	dp[u]=val[u];
	cnt[u][1]=1;
	up[u][1]=down[u][1]=val[u];
	for (auto v:e[u]) if(v!=f) {
		dfs(v,u);
		rep(p1,0,2) rep(p2,0,2) {
			// p1 p2
			dp[u]=(dp[u]+up[u][p1]*cnt[v][p2]+(1-2*p1)*down[v][p2]*cnt[u][p1])%mod;
			dp[u]=(dp[u]+up[v][p1]*cnt[u][p2]+(1-2*p1)*down[u][p2]*cnt[v][p1])%mod;
		}
		rep(p1,0,2) {
			cnt[u][p1]=(cnt[u][p1]+cnt[v][p1^1])%mod;
			up[u][p1]=(up[u][p1]+up[v][p1^1]+(2*p1-1)*val[u]*cnt[v][p1^1])%mod;
			down[u][p1]=(down[u][p1]+val[u]*cnt[v][p1^1]-down[v][p1^1])%mod;
		}
	}
	ret+=dp[u];
}

int main() {
	scanf("%d",&n);
	rep(i,1,n+1) scanf("%d",val+i);
	rep(i,1,n) {
		scanf("%d%d",&u,&v);
		e[u].pb(v); e[v].pb(u);
	}
	dfs(1,0);
	ret%=mod;
	if (ret<0) ret+=mod;
	printf("%lld\n",ret);
}