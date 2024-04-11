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
bool used[mn],done[mn];
ll a[mn],b[mn],p[mn],s[mn];
stack<int> h[mn];
vector<ll> v;
ll vsz;
ll get(ll x) {
	ll imin=0,imax=vsz;
	while (imin<imax) {
		ll imid=(imin+imax)/2;
		if (v[imid]<x) imin=imid+1;
		else imax=imid;
	}
	if (imin<vsz&&v[imin]==x) return imin;
	return -1;
}
int main() 
{
	ll n,m; scanf("%lld%lld",&n,&m);
	for (ll x=1;x<=n;x++) scanf("%lld",&p[x]);
	for (ll x=1;x<=m;x++) scanf("%lld",&s[x]);
	memset(used,0,sizeof used);
	memset(done,0,sizeof done);
	memset(a,0,sizeof done);
	memset(b,0,sizeof done);
	set<ll> ss;
	for (ll x=1;x<=n;x++) ss.insert(p[x]);
	for (auto &w:ss) v.PB(w);
	vsz=v.size();
	for (ll x=1;x<=n;x++) {
		ll idx=get(p[x]);
		if (idx!=-1) h[idx].push(x);
	}
	for (ll k=0;k<32;k++) {
		for (ll y=1;y<=m;y++) {
			if (!used[y]) {
				ll idx=get(s[y]);
				if (idx!=-1&&(!h[idx].empty())) {
					ll x=h[idx].top();
					h[idx].pop();
					done[x]=true;
					used[y]=true;
					a[y]=k;
					b[x]=y;
				}
				s[y]=(s[y]+1)/2;
			}
		}
	}
	{
		ll c=0,u=0;
		for (ll x=1;x<=n;x++) {
			c+=done[x];
		}
		for (ll x=1;x<=m;x++) {
			u+=a[x];
		}
		printf("%lld %lld\n",c,u);
		for (ll x=1;x<=m;x++) printf("%lld ",a[x]);
		printf("\n");
		for (ll x=1;x<=n;x++) printf("%lld ",b[x]);
		printf("\n");
	}
}