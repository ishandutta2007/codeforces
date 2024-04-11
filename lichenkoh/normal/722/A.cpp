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
	ll f; cin>>f;
	string s; cin>>s;
	ll h=(s[0]-'0')*10+(s[1]-'0');
	ll m=(s[3]-'0')*10+(s[4]-'0');
	if (f==12) {
		if (h==0) {
			h=1;
		}
		while(h>12) h-=10;
		while (m>59) m-=10;
	}
	else {
		while (h>23) h-=10;
		while (m>59) m-=10;
	}
	if (h<10) printf("0%lld",h);
	else printf("%lld",h);
	printf(":");
	if (m<10) printf("0%lld",m);
	else printf("%lld",m);
}