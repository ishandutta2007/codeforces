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
const ll lim=(1000LL*1000LL*1000LL*1000LL*1000LL*1000LL)+2;
int main()
{
	ios_base::sync_with_stdio(false); cin.tie(0);
	vector<ll> v;
	{
		ll x=1,y=1;
		while(1) {
			v.PB(y);
			ll z=y+x;
			x=y; y=z;
			if (z>=lim || z<0) break;
		}
	}
	reverse(v.begin(),v.end());
	//for (auto &w:v) printf("%lld ",w);
	//printf("\n");
	ll imin=0,imax=v.size();
	ll x; cin>>x;
	while(imin<imax) {
		ll imid=imin+(imax-imin)/2;
		if (v[imid]>x) imin=imid+1;
		else imax=imid;
	}
	ll ans=v.size()-1-imin;
	printf("%lld\n",ans);
}