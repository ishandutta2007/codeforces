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

const ll mn=2e5+4;
vector<ll> g[mn];
ll vs[mn],vt[mn],vc[mn];
ll ei=0;
void ae(ll x, ll y) {
	vs[ei]=x;vt[ei]=y;
	g[x].PB(ei);
	ei++;
}
ll dp[mn];
ll f(ll e) {
	if (dp[e]!=0) return dp[e];
	ll p=vs[e],x=vt[e];
	ll col=vc[x];
	for (auto &w:g[x]) {
		ll c=vt[w];
		if (c==p) continue;
		ll ccol=f(w);
		if (col!=ccol) return dp[e]=-1;
	}
	//printf("p:%d x:%d col:%d\n",p+1,x+1,col);
	return dp[e]=col;
}
bool solve(ll x) {
	for (auto &e:g[x]) {
		ll got=f(e);
		if (got==-1) return false;
	}
	return true;
}
int main() {
	ll n; scanf("%d",&n);
	for (ll i=0;i<n-1;i++) {
		ll u,v;
		scanf("%d%d",&u,&v);
		--u;--v;
		ae(u,v); ae(v,u);
	}
	for (ll i=0;i<n;i++) scanf("%d",&vc[i]);
	for (ll x=0;x<n;x++) {
		bool got=solve(x);
		if (got) {
			printf("YES\n%d\n",x+1); return 0;
		}
	}
	printf("NO\n");
}