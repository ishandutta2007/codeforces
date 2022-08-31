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

const int N=201000;
int n,k,u,v;
VI e[N];
ll ret,r[10],dp[N][10],s[N];
void dfs(int u,int f) {
	s[u]=1;
	dp[u][0]=1;
	for (auto v:e[u]) if (v!=f) {
		dfs(v,u);
		s[u]+=s[v];
		rep(p1,0,k) rep(p2,0,k) r[(p1+p2)%k]+=dp[u][p1]*dp[v][p2];
		rep(p1,0,k) dp[u][p1]+=dp[v][p1];
	}
	ll w=dp[u][k-1];
	per(p1,0,k-1) dp[u][p1+1]=dp[u][p1]; dp[u][0]=w;
//	rep(p1,0,k) printf("%d %d %lld\n",u,p1,dp[u][p1]);
	ret+=s[u]*(n-s[u]);
}
int main() {
	scanf("%d%d",&n,&k);
	rep(i,1,n) {
		scanf("%d%d",&u,&v);
		e[u].pb(v); e[v].pb(u);
	}
	dfs(1,0);
//	printf("%lld %lld %lld\n",ret,r[0],r[1]);
	rep(i,1,k) ret+=(k-i)*r[i];
	printf("%lld\n",ret/k);
}