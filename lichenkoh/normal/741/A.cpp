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
const ll mn=104;
ll a[mn];
ll n;
ll solve(ll ox) {
	ll x=ox;
	x=a[x];
	for (ll t=1;t<=n+5;t++) {
		if (x==ox) return t;
		x=a[x];
	}
	return -1;
}
int main() 
{
	ios_base::sync_with_stdio(false); cin.tie(0);
	scanf("%lld",&n);
	for (ll x=1;x<=n;x++) scanf("%lld",&a[x]);
	ll ans=1;
	for (ll x=1;x<=n;x++) {
		ll l=solve(x);
		if (0==(l%2)) l/=2;
		if (l==-1) {
			printf("-1\n");
			return 0;
		}
		ll g=__gcd(l,ans);
		ans=(l*ans)/g;
	}
	printf("%lld\n",ans);
}