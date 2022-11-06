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
	ll n;cin>>n; char x; cin>>x;
	n--;
	ll g=n/4;
	ll ans=0;
	if (n%2==0) {
		ans=g*12+g*4;
	}
	else {
		ans=(g)*12+g*4+1+6;
	}
	map<char,ll> h;
	ll idx=1;
	for (char c='f';c>='d';c--) {
		h[c]=idx;
		idx++;
	}
	for (char c='a';c<='c';c++) {
		h[c]=idx;
		idx++;
	}
	//cout<<h[x]<<":"<<ans<<":"<<x<<endl;
	ans+=h[x];
	cout<<ans<<endl;
}