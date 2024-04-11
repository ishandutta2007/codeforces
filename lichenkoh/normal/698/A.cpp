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
ll f[4][104],a[104];
int main() 
{
	ios_base::sync_with_stdio(false); cin.tie(0);
	ll n; scanf("%lld",&n);
	for (ll i=0;i<n;i++) {
		scanf("%lld",&a[i]);
	}
	memset(f,0,sizeof f);
	f[0][0]=0;
	for (ll x=0;x<n;x++) {
		for (ll k=0;k<=2;k++) {
			chkmax(f[0][x+1],f[k][x]);
			for (ll c=1;c<=2;c++) {
				if ((0!=(c&a[x]))&&(0==(c&k))) {
					chkmax(f[c][x+1],f[k][x]+1);
				}
			}
		}
	}
	ll ans=0;
	for (ll k=0;k<=2;k++) chkmax(ans,f[k][n]);
	printf("%lld\n",n-ans);
}