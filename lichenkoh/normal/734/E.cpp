#include <bits/stdc++.h>
#include <assert.h>
using namespace std;
typedef int ll;
typedef long double ld;
#define PB push_back
#define MP make_pair
#define MOD 1000000007LL
#define endl "\n"
const ll UNDEF = -1;
const ll INF=1e9;
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
ll n;
ll vc[mn];
vector<ll> g[mn];
bool seen[mn];
ll dist[mn];
void dfs(ll x) {
	for (auto &y:g[x]) {
		if (dist[y]==-1) {
			dist[y]=dist[x]+1;
			dfs(y);
		}
	}
}
vector<ll> h[mn];
void pre(ll x, ll r) {
	seen[x]=true;
	for (auto &y:h[x]) {
		if (seen[y]) continue;
		if (vc[y]!=vc[x]) {
			g[r].PB(y);
			g[y].PB(r);
			pre(y,y);
		}
		else {
			pre(y,r);
		}
	}
}
int main() 
{
	ios_base::sync_with_stdio(false); cin.tie(0);
	scanf("%d",&n);
	for (ll i=1;i<=n;i++) scanf("%d",&vc[i]);
	for (ll i=0;i<n-1;i++) {
		ll x,y;scanf("%d%d",&x,&y);
		h[x].PB(y);
		h[y].PB(x);
	}
	memset(seen,0,sizeof seen);
	pre(1,1);
	for (ll x=1;x<=n;x++) dist[x]=-1;
	dist[1]=0; dfs(1);
	pair<ll,ll> best=MP(-1ll,-1ll);
	for (ll x=1;x<=n;x++) chkmax(best,MP(dist[x],x));
	for (ll x=1;x<=n;x++) dist[x]=-1;
	dist[best.second]=0;dfs(best.second);
	ll diam=0;
	for (ll x=1;x<=n;x++) chkmax(diam,dist[x]);
	ll final=(1+diam)/2;
	printf("%d\n",final);
}