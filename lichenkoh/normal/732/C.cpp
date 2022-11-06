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
const ll INF=5e18;
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
	ll b[3],a[3];
	for (ll i=0;i<3;i++) scanf("%lld",&b[i]);
	ll final=INF;
	for (ll s=0;s<3;s++) for (ll e=0;e<3;e++) {
		if (s<=e) {
			// Special case: 1 day
			for (ll x=0;x<3;x++) a[x]=b[x];
			for (ll x=s;x<=e;x++) a[x]--;
			ll me=-INF;
			for (ll x=0;x<3;x++) chkmax(me,a[x]);
			if (me<=0) {
				ll ans=0;
				for (ll x=0;x<3;x++) ans-=a[x];
				chkmin(final,ans);
			}
		}
		{
			for (ll x=0;x<3;x++) a[x]=b[x];
			for (ll x=s;x<3;x++) a[x]--;
			for (ll x=0;x<e;x++) a[x]--;
			ll me=-INF;
			for (ll x=0;x<3;x++) chkmax(me,a[x]);
			if (me<0) me=0;
			for (ll x=0;x<3;x++) a[x]-=me;
			ll ans=0; for (ll x=0;x<3;x++) ans-=a[x];
			chkmin(final,ans);
		}
	}
	printf("%lld\n",final);
}