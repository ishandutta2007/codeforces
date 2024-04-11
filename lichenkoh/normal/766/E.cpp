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
vector<ll> g[mn];
ll a[mn];
ll gk;
ll gans;
#define fst first
#define snd second
pll dfs(ll x, ll p) {
	ll v=(a[x]>>gk)&1;
	pll have=MP(0LL,0LL);
	if (v==0) have.fst++;
	else have.snd++;
	for (auto &y:g[x]) {
		if (y==p) continue;
		pll child=dfs(y,x);
		gans+=child.fst*have.snd;
		gans+=child.snd*have.fst;
		if (v==1) swap(child.fst,child.snd);
		have.fst+=child.fst; have.snd+=child.snd;
	}
	return have;
}
int main() 
{
	ios_base::sync_with_stdio(false); cin.tie(0);
	ll n; scanf("%lld",&n);
	for (ll i=1;i<=n;i++) scanf("%lld",&a[i]);
	for (ll i=0;i<n-1;i++) {
		ll u,v; scanf("%lld%lld",&u,&v);
		g[u].PB(v);
		g[v].PB(u);
	}
	ll final=0;
	for (gk=0;gk<22;gk++) {
		gans=0;
		dfs(1,-1);
		final+=gans<<gk;
	}
	for (ll i=1;i<=n;i++) final+=a[i];
	printf("%lld\n",final);
}