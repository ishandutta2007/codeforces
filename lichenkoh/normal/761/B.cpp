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
const ll mn=200;
ll a[mn],b[mn];
bool c[mn];
int main() 
{
	ios_base::sync_with_stdio(false); cin.tie(0);
	ll n,L; cin>>n>>L;
	for (ll i=0;i<n;i++) cin>>a[i];
	for (ll i=0;i<n;i++) cin>>b[i];
	memset(c,0,sizeof c);
	for (ll i=0;i<n;i++) {
		c[a[i]]=true;
	}
	for (ll s=0;s<L;s++) {
		bool ok=true;
		for (ll i=0;i<n;i++) {
			if (!c[(s+b[i])%L]) {
				ok=false;
				break;
			}
		}
		if (ok) {
			printf("YES\n");
			return 0;
		}
	}
	printf("NO\n");
}