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
vector<ll> g[33];
ll vdx[]={1,0,-1,0};
ll vdy[]={0,1,0,-1};
ll ansx[33],ansy[33];
bool ok=true;
void f(ll v, ll p, ll x, ll y, ll r, ll d) {
	ansx[v]=x; ansy[v]=y;
	//printf("v:%lld x:%lld y:%lld\n",v,x,y);
	stack<ll> S;
	for (auto &ne:g[v]) {
		if (ne==p) continue;
		//printf("ne:%lld\n",ne);
		S.push(ne);
	}
	for (ll nd=0;nd<4;nd++) {
		if (d!=-1&&(d==(nd^2))) continue;
		if (S.empty()) break;
		ll ne=S.top(); S.pop();
		//printf("%lld: %lld %lld\n",d,vdx[d],vdy[d]);
		f(ne,v,x+vdx[nd]*r,y+vdy[nd]*r,r/2,nd);
	}
	if (!S.empty()) {
		ok=false;
	}
}
int main()
{
	ios_base::sync_with_stdio(false); cin.tie(0);
	ll n; scanf("%lld",&n);
	for (ll i=0;i<n-1;i++) {
		ll x,y; scanf("%lld%lld",&x,&y); g[x].PB(y);g[y].PB(x);
		//printf("%lld->%lld\n",x,y);
	}
	f(1,-1,0,0,5e17,-1);
	if (!ok) {
		printf("NO\n"); return 0;
	}
	printf("YES\n");
	for (ll v=1;v<=n;v++) printf("%lld %lld\n",ansx[v],ansy[v]);
}