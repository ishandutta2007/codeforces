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
ll px[3],py[3];
int main() 
{
	ios_base::sync_with_stdio(false); cin.tie(0);
	for (ll i=0;i<3;i++) {
		scanf("%lld%lld",px+i,py+i);
	}
	set<pll> s;
	for (ll i=0;i<3;i++) {
		ll dx=0,dy=0;
		for (ll j=0;j<3;j++) {
			if (i==j) continue;
			dx+=px[j]-px[i];
			dy+=py[j]-py[i];
		}
		ll x=px[i]+dx,y=py[i]+dy;
		s.insert(MP(x,y));
	}
	printf("%lld\n",(ll)s.size());
	for (auto &w:s) {
		printf("%lld %lld\n",w.first,w.second);
	}
}