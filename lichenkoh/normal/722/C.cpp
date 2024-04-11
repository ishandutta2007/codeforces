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
ll a[mn],p[mn];
ll getsum(ll x, ll y) {
	return p[y]-p[x-1];
}
int main() 
{
	ios_base::sync_with_stdio(false); cin.tie(0);
	ll n; scanf("%lld",&n);
	for (ll i=1;i<=n;i++) scanf("%lld",&a[i]);
	p[0]=0;
	for (ll i=1;i<=n;i++) p[i]=p[i-1]+a[i];
	map<ll,ll,greater<ll> > h;
	h[0]++;
	h[getsum(1,n)]++;
	set<ll> s; s.insert(0); s.insert(n+1);
	for (ll ii=0;ii<n;ii++) {
		ll x; scanf("%lld",&x);
		auto it=s.lower_bound(x);
		ll r=(*it)-1;
		--it;
		ll l=(*it)+1;
		{
			ll tmp=getsum(l,r);
			//printf("%lld %lld %lld\n",l,r,tmp);
			auto it=h.find(tmp);
			if ((it->second)==1) h.erase(it);
			else (it->second)--;
		}
		h[getsum(l,x-1)]++;
		h[getsum(x+1,r)]++;
		s.insert(x);
		{
			auto jt=h.begin();
			printf("%lld\n",jt->first);
		}
		/*for (auto &w:h) {
			printf("%lld->%lld ",w.first,w.second);
		}
		printf("\n");*/
	}
}