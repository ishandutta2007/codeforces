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
ll p[mn],q[mn];
vector<ll> g[mn];
bool seen[mn];
void dfs(ll x) {
	if (seen[x]) return;
	seen[x]=true;
	for (auto &y:g[x]) dfs(y);
}
bool found[mn];
ll findroot(ll x) {
	if (p[x]==x) return x;
	if (found[x]) return x;
	found[x]=true;
	return findroot(p[x]);
}
int main() 
{
	ios_base::sync_with_stdio(false); cin.tie(0);
	ll n; scanf("%lld",&n);
	for (ll x=1;x<=n;x++) {
		scanf("%lld",p+x);
	}
	ll same=findroot(1);
	for (ll x=1;x<=n;x++) {
		q[x]=p[x];
		if (x==p[x]) same=x;
		ll y=p[x];
		if (y!=x) {
			g[x].PB(y);
			g[y].PB(x);
		}
	}
	memset(seen,0,sizeof seen);
	memset(found,0,sizeof found);
	ll comp=0;
	for (ll x=1;x<=n;x++) {
		if (!seen[x]) {
			ll r=findroot(x);
			dfs(r);
			q[r]=same;
			comp++;
		}
	}
	ll ans=0;
	for (ll x=1;x<=n;x++) {
		if (p[x]!=q[x]) ans++;
	}
	printf("%lld\n",ans);
	for (ll x=1;x<=n;x++) {
		printf("%lld ",q[x]);
	}
	printf("\n");
}