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

string day[]={ "monday", "tuesday", "wednesday", "thursday", "friday", "saturday", "sunday"};
ll mo[]={31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
int main() 
{
	ios_base::sync_with_stdio(false); cin.tie(0);
	string a,b; cin>>a>>b;
	ll x,y;
	for (ll i=0;i<7;i++) if (day[i]==a) x=i;
	for (ll i=0;i<7;i++) if (day[i]==b) y=i;
	bool ans=false;
	for (ll m=0;m<11;m++) {
		ll diff=(y-x+7)%7;
		ll diff2=mo[m]%7;
		if (diff==diff2)ans=true;
	}
	if (ans) printf("YES\n");
	else printf("NO\n");
}