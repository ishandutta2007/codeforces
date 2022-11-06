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
ld p[20];
ld vans[20];
ld f[1<<20];
int main() 
{
	ios_base::sync_with_stdio(false); cin.tie(0);
	ll n,k; scanf("%lld%lld",&n,&k);
	for (ll i=0;i<n;i++) {
		double d; scanf("%lf",&d);
		p[i]=d;
	}
	ll nonzero=0;
	for (ll i=0;i<n;i++) {
		if (p[i]>1e-9) nonzero++;
	}
	k=min(k,nonzero);
	f[0]=1;
	ll zlim=1<<n;
	for (ll z=0;z<zlim;z++) {
		ld all=0;
		for (ll x=0;x<n;x++) {
			ll msk=1<<x;
			if (!(z&msk)) all+=p[x];
		}
		if (all<1e-9) continue;
		for (ll x=0;x<n;x++) {
			ll msk=1<<x;
			if (!(z&msk)) {
				f[z|msk]+=f[z]*p[x]/all;
			}
		}
	}
	for (ll x=0;x<n;x++) vans[x]=0;
	for (ll z=0;z<zlim;z++) {
		if (__builtin_popcountll(z)==k) {
			for (ll x=0;x<n;x++) {
				ll msk=1<<x;
				if (z&msk) {
					vans[x]+=f[z];
				}
			}
		}
	}
	for (ll x=0;x<n;x++) printf("%.10f ",(double)vans[x]);
	printf("\n");
}