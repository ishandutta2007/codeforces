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
int main() 
{
	ios_base::sync_with_stdio(false); cin.tie(0);
	ll n,m; scanf("%lld%lld",&n,&m);
	ll minlen=INF;
	for (ll i=0;i<m;i++) {
		ll l,r; scanf("%lld%lld",&l,&r);
		chkmin(minlen,r-l+1);
	}
	printf("%lld\n",minlen);
	for (ll x=0;x<n;x++) {
		ll y=x%minlen;
		printf("%lld ",y);
	}
	printf("\n");
}