#include <bits/stdc++.h>
#include <assert.h>
using namespace std;
typedef long long ll;
typedef long double ld;
#define PB push_back
#define MP make_pair
#define MOD 1000000007LL
#define endl "\n"
#define fst first
#define snd second
#define all(x) x.begin(),x.end()
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
ll a[1024];
string t="Bulbasaur";
ll b[1024];
int main() 
{
	ios_base::sync_with_stdio(false); cin.tie(0);
	string s; cin>>s;
	ll n=s.length();
	memset(a,0,sizeof a);
	for (ll i=0;i<n;i++) {
		ll x=s[i];
		a[x]++;
	}
	memset(b,0,sizeof b);
	for (auto &w:t) {
		ll x=w;
		b[x]++;
	}
	ll ans=INF;
	for (ll x=0;x<1024;x++) {
		ll need=b[x],have=a[x];
		if (need>0) {
			ll cand=have/need;
			chkmin(ans,cand);
		}
	}
	printf("%lld\n",ans);
}