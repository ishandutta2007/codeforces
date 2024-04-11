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
string a;
ll gn;
const ll mn=1e3+4;
ll f[mn];
ll g[mn];
ll restr[26];
int main() 
{
	ios_base::sync_with_stdio(false); cin.tie(0);
	cin>>gn>>a;
	for (ll i=0;i<26;i++) cin>>restr[i];
	ll n=gn;
	for (ll x=0;x<=n;x++) g[x]=INF;
	g[0]=0;
	memset(f,0,sizeof f);
	f[0]=1;
	ll ans2=0;
	for (ll x=0;x<n;x++) {
		ll maxlen=INF;
		for (ll y=x+1;y<=n;y++) {
			ll ch=(a[y-1]-'a');
			chkmin(maxlen,restr[ch]);
			ll len=y-x;
			if (len>maxlen) break;
			else {
				f[y]+=f[x];
				f[y]%=MOD;
				chkmin(g[y],g[x]+1);
				chkmax(ans2,len);
			}
		}
	}
	ll ans1=f[n]%MOD;	
	ll ans3=g[n];
	printf("%lld\n%lld\n%lld\n",ans1,ans2,ans3);
}