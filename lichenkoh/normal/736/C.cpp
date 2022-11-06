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
inline ll mul(ll x,ll y) {return (x*y)%MOD;}
inline ll add(ll x,ll y) {return (x+y)%MOD;}
const ll mn=102;
const ll mk=22;
vector<ll> g[mn];
ll n,k;
ll dp[mn][2][mk];
ll f(ll x, ll p, ll above, ll dist) {
	if (dist<0||dist>k) return 0;
	if (dp[x][above][dist]!=UNDEF) {
		return dp[x][above][dist];
	}
	ll ans;
	if (above||dist==0) {
		ll prod=1;
		for (auto &y:g[x]) {
			if (y==p) continue;
			ll cand=(f(y,x,1,dist+1) + f(y,x,0,dist) + f(y,x,0,dist-1))%MOD;
			//printf("y:%lld cand:%lld prod:%lld\n",y,cand,prod);
			prod=mul(prod,cand);
		}
		ans=prod;
	}
	else {
		ll done=0;
		ll fly=1;
		for (auto &y:g[x]) {
			if (y==p) continue;
			ll all=(f(y,x,1,dist+1) + f(y,x,0,dist) + f(y,x,0,dist-1))%MOD;
			ll notrans=(f(y,x,1,dist+1) + f(y,x,0,dist))%MOD;
			ll trans=f(y,x,0,dist-1);
			done=mul(done,all);
			done=add(done,mul(fly,trans));
			fly=mul(fly,notrans);
		}
		ans=done;
	}
	//printf("x:%lld a:%lld dist:%lld ans:%lld\n",x,above,dist,ans);
	return dp[x][above][dist]=ans;
}
int main()
{
	ios_base::sync_with_stdio(false); cin.tie(0);
	scanf("%lld%lld",&n,&k);
	for (ll i=0;i<n-1;i++) {
		ll u,v; scanf("%lld%lld",&u,&v);
		g[u].PB(v);
		g[v].PB(u);
	}
	//for (ll x=1;x<=n;x++) {
	//	for (auto &y:g[x]) printf("%lld %lld\n",x,y);
	//}
	for (ll x=0;x<mn;x++) for (ll ab=0;ab<2;ab++) for (ll y=0;y<mk;y++) {
		dp[x][ab][y]=-1;
	}
	ll ans=0;
	for (ll d=0;d<=k;d++) {
		ans=add(ans,f(1,-1,0,d));
	}
	printf("%lld\n",ans);
}