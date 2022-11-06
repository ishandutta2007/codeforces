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

int main() 
{
	ios_base::sync_with_stdio(false); cin.tie(0);
	string s; cin>>s;
	ll last=-1;
	ll sl=s.length();
	ll ans=0;
	for (ll x=0;x<sl;x++) {
		char c=s[x];
		if (c=='A'||c=='E'||c=='I'||c=='O'||c=='U'||c=='Y') {
			chkmax(ans,x-last);
			last=x;
		}
	}
	chkmax(ans,sl-last);
	cout<<ans<<endl;
}