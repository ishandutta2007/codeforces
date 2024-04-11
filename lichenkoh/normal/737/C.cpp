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
ll n,s;
const ll mn=2e5+4;
ll a[mn];
ll b[mn];
ll c[mn];
ll gap[mn];
int main() 
{
	ios_base::sync_with_stdio(false); cin.tie(0);
	ll n,s; scanf("%lld%lld",&n,&s); --s;
	for (ll i=0;i<n;i++) scanf("%lld",a+i);
	ll addfinal=0;
	if (a[s]!=0) {addfinal++; a[s]=0;}
	ll ava=0;
	for (ll i=0;i<n;i++) {
		if (a[i]==0&&i!=s) ava++;
	}
	memset(b,0,sizeof b);memset(c,0,sizeof c);
	for (ll i=0;i<n;i++) {b[a[i]]++;c[a[i]]++;}
	gap[0]=-ava;
	for (ll i=0;i<=n;i++) {
		gap[i+1]=gap[i];
		if (b[i]==0) gap[i+1]++;
	}
	ll final=0;
	ll sum=0;
	for (ll k=n;k>=0;k--) {
		sum+=b[k];
		ll cand=min(sum,gap[k]);
		//printf("k:%lld sum:%lld gap:%lld\n",k,sum,gap[k]);
		chkmax(final,cand);
	}
	final+=ava+addfinal;
	printf("%lld\n",final);
}