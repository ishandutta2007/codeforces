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
const ll mn=50000+4;
ll a[mn];
ll n;
set<ll> s;
bool gen(ll imid) {
	s.clear();
	for (ll i=0;i<n;i++) {
		ll x=a[i];
		while(x>imid) x>>=1;
		while(s.find(x)!=s.end()) x>>=1;
		if (x<=0) return false;
		s.insert(x);
	}
	return true;
}
int main() 
{
	ios_base::sync_with_stdio(false); cin.tie(0);
	 scanf("%lld",&n);
	for (ll i=0;i<n;i++) scanf("%lld",&a[i]);	
	sort(a,a+n);
	ll imin=0,imax=1e9+4;
	while(imin<imax) {
		ll imid=imin+(imax-imin)/2;
		bool get=gen(imid);
		if (!get) imin=imid+1;
		else imax=imid;
	}
	gen(imin);
	for (auto &w:s) printf("%lld ",w);
	printf("\n");
}