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
int n,m,x,vis[N],dp[N],pre[N];
int cnt[N];
VI num[N],ret,d;
ll mygcd(ll a,ll b) { return b?mygcd(b,a%b):a;}
void dfs(int u) {
	if (u==-1) return;
	for (auto p:num[d[u]]) ret.pb(p);
	dfs(pre[u]);
}
ll inv(ll q,ll m) {
	if (q==0) return 0;
	assert(q>=0);
	ll a1=m,b1=0,a2=q,b2=1,a3,b3,t;
	while (a2!=1) {	t=a1/a2,a3=a1-t*a2,b3=b1-t*b2%m,
		a1=a2,a2=a3,b1=b2,b2=b3;if (b2<0) b2+=m;}
	return b2;
}

int ff(ll x,ll y,ll n) {
//	printf("%lld %lld %lld\n",x,y,n);
	int d=mygcd(x,n);
	x/=d; y/=d; n/=d;
	return y*inv(x,n)%n;
}
int main() {
	scanf("%d%d",&n,&m);
	rep(i,0,n) {
		scanf("%d",&x);
		vis[x]=1;
	}
	rep(i,0,m) if (!vis[i]) {
		int d=mygcd(m,i);
		cnt[d]++;
		num[d].pb(i);
	}
	rep(i,1,m+1) if (m%i==0) d.pb(i);
	rep(i,0,SZ(d)) {
		pre[i]=-1;
		rep(j,0,i) if (d[i]%d[j]==0) {
			if (dp[j]>dp[i]) {
				dp[i]=dp[j]; pre[i]=j;
			}
		}
		dp[i]+=cnt[d[i]];
//		printf("%d %d\n",i,dp[i]);
	}
	printf("%d\n",dp[SZ(d)-1]);
	dfs(SZ(d)-1);
	reverse(all(ret));
	assert(SZ(ret)==dp[SZ(d)-1]);
	int pre=1;
//	rep(i,0,SZ(ret)) printf("%d\n",ret[i]); puts("");
	rep(i,0,SZ(ret)) {
		printf("%d ",ff(pre,ret[i],m));
		pre=ret[i];
	}
}