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
string s[55];
ll b[55][3];
ll f[55][1<<3];
int main()
{
	ios_base::sync_with_stdio(false); cin.tie(0);
	ll n,m;
	cin>>n>>m;
	for (ll i=0;i<n;i++) cin>>s[i];
	for (ll i=0;i<(1<<3);i++) f[0][i]=INF;
	f[0][0]=0;
	for (ll x=0;x<n;x++) {
		for (ll k=0;k<3;k++) b[x][k]=INF;
		for (ll y=0;y<m;y++) {
			char c=s[x][y];
			ll g=min(y,m-y);
			if (c=='#'||c=='*'||c=='&') chkmin(b[x][0],g);
			if ('0'<=c&&c<='9') chkmin(b[x][1],g);
			if ('a'<=c&&c<='z') chkmin(b[x][2],g);
		}
		for (ll i=0;i<(1<<3);i++) f[x+1][i]=INF;
		for (ll z=0;z<(1<<3);z++) {
			ll now=f[x][z];
			if (now>=INF) continue;
			for (ll k=0;k<3;k++) {
				ll v=b[x][k];
				if (v<INF) {
					ll next=now+v;
					chkmin(f[x+1][z|(1<<k)],next);
				}
			}
		}
	}
	printf("%lld\n",f[n][(1<<3)-1]);
}