#include <bits/stdc++.h>
#include <assert.h>
using namespace std;
typedef long long ll;
typedef long double ld;
#define PB push_back
#define MP make_pair
#define MOD 1000000007LL
#define endl "\n"
const ll UNDEF = -1;
const ll INF=1e18;
template<typename T> inline bool chkmax(T &aa, T bb) { return aa < bb ? aa = bb, true : false; }
template<typename T> inline bool chkmin(T &aa, T bb) { return aa > bb ? aa = bb, true : false; }
typedef pair<ll,ll> pll;

#ifdef DEBUG
     #define debug(args...)            {dbg,args; cerr<<endl;}
#else
    #define debug(args...)              // Just strip off all debug tokens
#endif

struct debugger
{
    template<typename T> debugger& operator , (const T& v)
    {    
        cerr<<v<<" ";    
        return *this;    
    }
} dbg;
const ll mn=1e5+4;
ll a[mn],d[mn];
bool seen[mn];
ll n,m;
bool ok(ll n) {
	memset(seen,0,sizeof seen);
	seen[0]=true;
	ll need=0;
	for (ll x=n-1;x>=0;x--) {
		ll e=d[x];
		if (seen[e]) {
			need--; chkmax(need,0ll);
		}
		else {
			seen[e]=true;
			need+=a[e];
		}
	}
	if (need<=0) {
		for (ll x=1;x<=m;x++) if (!seen[x]) return false;
		return true;
	}
	return false;
}
int main() 
{
	ios_base::sync_with_stdio(false); cin.tie(0);
	scanf("%lld%lld",&n,&m);
	for (ll x=0;x<n;x++) scanf("%lld",&d[x]);
	for (ll x=1;x<=m;x++) scanf("%lld",&a[x]);
	ll imin=0,imax=n+1;
	while(imin<imax) {
		ll imid=imin+(imax-imin)/2;
		if (!ok(imid)) imin=imid+1;
		else imax=imid;
	}
	ll ans=imin;
	if (ans==n+1) ans=-1;
	printf("%lld\n",ans);
}