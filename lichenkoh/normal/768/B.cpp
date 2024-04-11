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
	ll n,l,r; scanf("%lld%lld%lld",&n,&l,&r);
	ll t=0;
	for (ll x=0;x<60;x++) if (n&(1LL<<x)) t=x;
	ll final=0;
	for (ll x=l;x<=r;x++) {
		ll y=x;
		ll k=0;
		while(y>0&&(y%2)==0) {y/=2; k++;}
		ll got=(n>>(t-k))&1;
		//printf("x:%lld k:%lld got:%lld\n",x,k,got);
		final+=got;
	}
	printf("%lld\n",final);
}