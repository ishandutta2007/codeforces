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
const ll mn=1000+2;
ll n,m,wlim;
ll wv[mn],bv[mn];
vector<ll> g[mn];
bool seen[mn];
vector<ll> gather;
pll dfs(ll x) {
	if (seen[x]) return MP(0ll,0ll);
	gather.PB(x);
	seen[x]=true;
	pll ans=MP(wv[x],bv[x]);
	for (auto &y:g[x]) {
		pll got=dfs(y);
		ans.first+=got.first;
		ans.second+=got.second;
	}
	return ans;
}
vector<ll> wa,ba;
vector<vector<ll> > ga;
ll f[2][mn];
int main() 
{
	ios_base::sync_with_stdio(false); cin.tie(0);
	scanf("%lld%lld%lld",&n,&m,&wlim);
	for (ll x=1;x<=n;x++) scanf("%lld",wv+x);
	for (ll x=1;x<=n;x++) scanf("%lld",bv+x);
	for (ll i=0;i<m;i++) {
		ll x,y; scanf("%lld%lld",&x,&y);
		g[x].PB(y);
		g[y].PB(x);
	}
	memset(seen,0,sizeof seen);
	for (ll x=1;x<=n;x++) {
		if (!seen[x]) {
			gather.clear();
			pll got=dfs(x);
			wa.PB(got.first);
			ba.PB(got.second);
			ga.PB(gather);
		}
	}
	for (ll w=0;w<=wlim;w++) f[0][w]=-INF;
	f[0][0]=0;
	ll k=wa.size();
	ll cur=0,nxt=1;
	for (ll i=0;i<k;i++) {
		for (ll w=0;w<=wlim;w++) f[nxt][w]=f[cur][w];
		{
			ll wi=wa[i],bi=ba[i];
			for (ll w=wlim;w>=wi;w--) {
				chkmax(f[nxt][w],f[cur][w-wi]+bi);
			}
		}
		{
			for (auto &g:ga[i]) {
				ll wi=wv[g],bi=bv[g];
				for (ll w=wlim;w>=wi;w--) {
					chkmax(f[nxt][w],f[cur][w-wi]+bi);
				}
			}
		}
		swap(cur,nxt);
	}
	ll ans=-INF;
	for (ll w=0;w<=wlim;w++) {
		chkmax(ans,f[cur][w]);
	}
	printf("%lld\n",ans);
}