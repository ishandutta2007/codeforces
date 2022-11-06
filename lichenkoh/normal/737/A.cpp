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
const ll mn=2e5+4;
ll c[mn],v[mn],g[mn];
ll n,k,s,tlim;
ll solve(ll f) {
	ll t=0;
	for (ll i=1;i<=k+1;i++) {
		ll d=g[i]-g[i-1];
		if (f<d) {return INF;}
		ll timetaken=3*d-min(f,2*d);
		t+=timetaken;
		//printf("d:%lld t:%lld\n",d,t);
		if (g[i]>=s) break;
	}
	return t;
}
int main() 
{
	ios_base::sync_with_stdio(false); cin.tie(0);
	 scanf("%lld%lld%lld%lld",&n,&k,&s,&tlim);
	for (ll i=0;i<n;i++) {
		scanf("%lld%lld",c+i,v+i);
	}
	for (ll i=0;i<k;i++) {
		scanf("%lld",g+i);
		//printf("Got:%lld\n",g[i]);
	}
	g[k]=s;
	g[k+1]=0;
	sort(g,g+k+2);
	//for (ll i=0;i<=k+1;i++) printf("%lld ",g[i]);
	//	printf("\n");
	//solve(8); return 0;
	ll imin=0,imax=4+(1000*1000*1000);
	while(imin<imax) {
		ll imid=(imin+imax)/2;
		ll f=imid;
		ll t=solve(f);
		//printf("f:%lld t:%lld\n",f,t);
		if (!(t<=tlim)) {
			imin=imid+1;
		}
		else imax=imid;
	}
	ll ans=INF;
	for (ll i=0;i<n;i++) {
		if (v[i]>=imin) chkmin(ans,c[i]);
	}
	if(ans>=INF) ans=-1;
	printf("%lld\n",ans);
}