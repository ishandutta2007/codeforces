#include <bits/stdc++.h>
#include <assert.h>
using namespace std;
typedef long long ll;
typedef long double ld;
#define PB push_back
#define MP make_pair
const ll MOD = 1000000007LL;
const ll INF = 1ULL<<60ULL;
const ll UNDEF = -1;
template<typename T> inline bool chkmax(T &aa, T bb) { return aa < bb ? aa = bb, true : false; }
template<typename T> inline bool chkmin(T &aa, T bb) { return aa > bb ? aa = bb, true : false; }

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
const ll mn=1e4+4;
ll p[mn];
ll f[2][mn];
int main() 
{
	ios_base::sync_with_stdio(false); cin.tie(0);
	ll n,c; scanf("%lld %lld",&n,&c);
	for (ll i=0;i<n;i++) scanf("%lld",&p[i]);
	ll init=0;
	for (ll i=0;i<n;i++) {
		ll s;scanf("%lld",&s);
		init+=min(p[i],s);
		p[i]-=s;
		//printf("i:%lld p:%lld\n",i,p[i]);
	}
	f[0][0]=0;
	for (ll x=1;x<=n;x++) {
		ll cur=x&1,pre=cur^1;
		for (ll y=0;y<=x;y++) {
			// Put on right
			ll ans=INF;
			if (y<x) {
				chkmin(ans,y*c+max(0ll,p[x-1])+f[pre][y]);
			}
			if (y>0) {
				// Put on left
				ll add=max(0ll,-p[x-1]);
				ll cand=f[pre][y-1]+add;
				chkmin(ans, cand);
			}
			f[cur][y]=ans;
			//printf("x:%lld y:%lld ans:%lld %s\n",x,y,ans,left?"left":"right");
		}
	}
	{
		ll ans=INF;
		for (ll y=0;y<=n;y++) {
			chkmin(ans,f[n&1][y]);
		}
		ll final=ans+init;
		printf("%lld\n",final);
	}
}