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
map<string,ll> h;
const ll mn=2e5+4;
ll p[mn];
ll ffind(ll x) {
	if (p[x] != x) {
		p[x] = ffind(p[x]);
	}
	return p[x];
}
void funion(ll x, ll y) {
	if (rand()&1) swap(x,y); 
	ll xr = ffind(x);
	ll yr = ffind(y);
	p[xr] = yr;
}
int main()
{
	ios_base::sync_with_stdio(false); cin.tie(0);
	ll n,m,q; cin>>n>>m>>q;
	for (ll i=0;i<n;i++) {
		string s; cin>>s;
		h[s]=i*2;
	}
	for (ll i=0;i<2*n;i++) p[i]=i;
	for (ll i=0;i<m;i++) {
		ll t; string x,y;
		cin>>t>>x>>y;
		ll idx=h[x],idy=h[y];
		if (t==1) {
			if (ffind(idx)==ffind(idy^1)) {
				printf("NO\n");
			}
			else {
				funion(idx,idy);
				funion(idx^1,idy^1);
				printf("YES\n");
			}
		}
		else {
			if (ffind(idx)==ffind(idy)) {
				printf("NO\n");
			}
			else {
				funion(idx,idy^1);
				funion(idx^1,idy);
				printf("YES\n");
			}
		}
	}
	for (ll i=0;i<q;i++) {
		string x,y; cin>>x>>y;
		ll idx=h[x],idy=h[y];
		if (ffind(idx)==ffind(idy)) {
			printf("1\n");
		}
		else if (ffind(idx)==ffind(idy^1)) {
			printf("2\n");
		}
		else printf("3\n");
	}
}