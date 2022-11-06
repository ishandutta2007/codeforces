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
const ll mn=1e5+5;
ll b[mn];
int main() 
{
	ios_base::sync_with_stdio(false); cin.tie(0);
	ll x=0;
	ll p=0;
	for (ll k=1;k<=60;k++) {
		for (ll i=0;i<k;i++) {
			if (x<=80) {
				//printf("x:%lld nim:%lld\n",x,p);
				b[x]=p;
				x++;
			}
		}
		if (x>80) break;
		p++;
	}
	ll n; scanf("%lld",&n);
	ll nim=0;
	for (ll i=0;i<n;i++) {
		ll x; scanf("%lld",&x);
		nim^=b[x];
	}
	if (nim==0) {
		printf("YES\n");
	}
	else {
		printf("NO\n");
	}
}