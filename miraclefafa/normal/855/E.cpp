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

ll dp[20][110][110],l,r,pd[20][110];
int ff[11000],q,b;
ll gquery(int base,int od,int rem) {
	ll &r=dp[base][od][rem];
	if (r!=-1) return r;
	r=0;
	if (rem==0) {
		if (od==0) return r=1;
		else return r=0;
	}
	r=(od?gquery(base,od-1,rem-1):0)*od+((base-od)?gquery(base,od+1,rem-1):0)*(base-od);
	return r;
}
ll query(ll x,int base) {
	VI d;
	while (x) d.pb(x%base),x/=base;
	ll ret=0;
	rep(i,1,SZ(d)) ret+=(base-1)*gquery(base,1,i-1);
	int state=0;
	per(i,0,SZ(d)) {
		rep(j,(i==SZ(d)-1)?1:0,d[i]) {
			int nsta=state;
			nsta^=(1<<j);
			ret+=gquery(base,ff[nsta],i);
		}
		state^=(1<<d[i]);
	}
	return ret;
}
int main() {
	memset(dp,-1,sizeof(dp));
	rep(i,1,10000) ff[i]=ff[i>>1]+(i&1);
	scanf("%d",&q);
	rep(i,0,q) {
		scanf("%d%lld%lld",&b,&l,&r);
		printf("%lld\n",query(r+1,b)-query(l,b));
	}
}