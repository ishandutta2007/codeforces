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
ll n,m;
const ll mn=25;
ll a[mn][mn],b[mn][mn];
ll c[mn];
bool solve() {
	for (ll x=0;x<n;x++) {
		bool good=false;
		for (ll i=0;i<m;i++) for (ll j=0;j<m;j++) {
			for (ll y=0;y<m;y++) c[y]=a[x][y];
			if (i!=j) swap(c[i],c[j]);
			bool ok=true;
			for (ll y=0;y<m;y++) {
				if (c[y]!=y+1) ok=false;
			}
			if (ok) good=true;
		}
		if (!good) return false;
	}
	return true;
}
int main() 
{
	ios_base::sync_with_stdio(false); cin.tie(0);
	scanf("%lld%lld",&n,&m);
	for (ll x=0;x<n;x++) for (ll y=0;y<m;y++) scanf("%lld",&b[x][y]);
	bool ans=false;
	for (ll i=0;i<m;i++) for (ll j=0;j<m;j++) {
		for (ll x=0;x<n;x++) for (ll y=0;y<m;y++) a[x][y]=b[x][y];
		if (i!=j) {
			for (ll x=0;x<n;x++) swap(a[x][i],a[x][j]);
		}
		if (solve()) ans=true;
	}
	if (ans) printf("YES\n");
	else printf("NO\n");
}