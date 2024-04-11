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
inline ll MK(ll x,ll y) {
	return (x<<32)|y;
}
int main()
{
	ios_base::sync_with_stdio(false); cin.tie(0);
	ll n; scanf("%lld",&n);
	map<ll,vector<pll> > h;
	for (ll i=0;i<n;i++) {
		ll t[3];
		scanf("%lld%lld%lld",&t[0],&t[1],&t[2]);
		for (ll x=0;x<3;x++) for (ll y=x+1;y<3;y++) {
			ll z;
			for (z=0;z<3;z++) if (z!=x&&z!=y) break;
			ll a=t[x],b=t[y],c=t[z];
			if (a>b) swap(a,b);
			h[MK(a,b)].PB(MP(c,i+1));
		}
	}
	pair<ll,pll> best=MP(-1ll,MP(-1ll,-1ll));
	for (auto &w:h) {
		ll key=w.first;
		ll x=key>>32,y=key&0xffffffff;
		pll c1=MP(0ll,-1ll);
		pll c2=MP(0ll,-1ll);
		ll vs=w.second.size();
		for (ll i=0;i<vs;i++) {
			chkmax(c1,w.second[i]);
		}
		for (ll i=0;i<vs;i++) {
			if (w.second[i]!=c1) chkmax(c2,w.second[i]);
		}
		ll z=c1.first+c2.first;
		ll inp=min(x,min(y,z));
		chkmax(best,MP(inp,MP(c1.second,c2.second)));
	}
	if (best.second.second==-1){
		printf("1\n%lld\n",best.second.first);
	}
	else {
		printf("2\n%lld %lld\n",best.second.first,best.second.second);
	}

}