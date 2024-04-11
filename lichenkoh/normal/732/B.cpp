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
const ll mn=504;
ll a[mn],b[mn];pll f[mn][mn];
int main() 
{
	ios_base::sync_with_stdio(false); cin.tie(0);
	ll n,k; scanf("%lld%lld",&n,&k);
	for (ll x=0;x<n;x++) scanf("%lld",&a[x]);
	for (ll x=0;x<mn;x++)for (ll y=0;y<mn;y++) f[x][y]=MP(INF,INF);
	f[0][k]=MP(0ll,-1ll);
	for (ll x=0;x<n;x++) for (ll y=0;y<=k;y++) {
		ll v=f[x][y].first;
		if (v>=INF) continue;
		for (ll ny=0;ny<=k;ny++) {
			if (y+ny<k) continue;
			ll cost=max(0ll,ny-a[x]);
			chkmin(f[x+1][ny],MP(v+cost,y));
		}
	}
	pair<ll,ll> best=MP(INF,INF);
	for (ll y=0;y<=k;y++) {
		chkmin(best,MP(f[n][y].first,y));
	}
	printf("%lld\n",best.first);
	ll y=best.second;
	for (ll x=n;x>=1;x--) {
		b[x-1]=y;
		y=f[x][y].second;
	}
	for (ll x=0;x<n;x++) chkmax(b[x],a[x]);
	for (ll x=0;x<n;x++) printf("%lld ",b[x]);
	printf("\n");
}