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
ll l[mn],r[mn];
int main() 
{
	ios_base::sync_with_stdio(false); cin.tie(0);
	ll n; scanf("%lld",&n);
	for (ll i=1;i<=n;i++) scanf("%lld%lld",&l[i],&r[i]);
	ll al=0,ar=0;
	for (ll i=1;i<=n;i++) {
		al+=l[i]; ar+=r[i];
	}
	pll ans=MP(abs(al-ar),0ll);
	for (ll i=1;i<=n;i++) {
		ll nl=al-l[i]+r[i];
		ll nr=ar-r[i]+l[i];
		chkmax(ans,MP(abs(nl-nr),i));
	}
	printf("%lld\n",ans.second);
}