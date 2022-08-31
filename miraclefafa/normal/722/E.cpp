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

const int N=201000,M=2010;
int n,m,k,s,e[M];
ll fac[N],fnv[N],dp[M][30],ret[30];
PII p[M];
ll way(int x,int y) {
	return fac[x+y]*fnv[x]%mod*fnv[y]%mod;
}
int main() {
	scanf("%d%d%d%d",&n,&m,&k,&s);
	fac[0]=fnv[0]=1;
	rep(i,1,n+m+1) fac[i]=fac[i-1]*i%mod,fnv[i]=powmod(fac[i],mod-2);
	rep(i,0,k) {
		scanf("%d%d",&p[i].fi,&p[i].se);
	}
	p[k]=mp(1,1);
	sort(p,p+k+1);
	int c=unique(p,p+k+1)-p;
	dp[0][0]=1;
	if (c<=k) s=(s+1)/2;
	rep(v,0,24) {
		e[v]=s;
		s=(s+1)/2;
	}
	rep(i,1,c) {
		rep(j,0,i) if (p[i].fi>=p[j].fi&&p[i].se>=p[j].se) {
			rep(v,0,23) dp[i][v+1]=(dp[i][v+1]+dp[j][v]*way(p[i].fi-p[j].fi,p[i].se-p[j].se))%mod;
		}
		rep(v,1,23) dp[i][v]=(dp[i][v]-dp[i][v+1])%mod;
	}
	ll r=0;
	rep(i,0,c) {
		rep(v,0,24) ret[v]=(ret[v]+dp[i][v]*way(n-p[i].fi,m-p[i].se))%mod;
	}
	rep(v,0,23) ret[v]=(ret[v]-ret[v+1])%mod;
	rep(v,0,24) r=(r+ret[v]*e[v])%mod;
	if (r<0) r+=mod;
	r=r*powmod(way(n-1,m-1),mod-2)%mod;
	printf("%lld\n",r);
}