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
const ll UNDEF = -1;
const ll INF=1e18;
template<typename T> inline bool chkmax(T &aa, T bb) { return aa < bb ? aa = bb, true : false; }
template<typename T> inline bool chkmin(T &aa, T bb) { return aa > bb ? aa = bb, true : false; }
typedef pair<ll,ll> pll;
typedef vector<ll> vll;
const ll mn=1e6+4;
ll t[mn];
vector<ll> g[mn];
ll dp[mn];
ll third,twothird,numthird;
ll dfs(ll x) {
	ll ans=t[x];
	for (auto &y:g[x]) ans+=dfs(y);
	return dp[x]=ans;
}
pll final=MP(-1ll,-1ll);
ll root;
ll f(ll x) {
	ll ans=-1;
	for (auto &y:g[x]) {
		ll got=f(y);
		if (got!=-1) {
			assert(dp[got]==third);
			if (ans==-1) ans=got;
			else {
				assert(dp[ans]==third);
				final=MP(got,ans);
			}
		}
	}
	if (x!=root&&dp[x]==2*third && ans!=-1) {
		assert(dp[ans]==third);
		final=MP(x,ans);
	}
	if (dp[x]==third) ans=x;
	if (ans!=-1) assert(dp[ans]==third);
	return ans;
}
int main() 
{
	ios_base::sync_with_stdio(false); cin.tie(0);
	ll n; scanf("%lld",&n);
	ll sum=0;
	for (ll x=1;x<=n;x++) {
		ll a;
		scanf("%lld%lld",&a,&t[x]);
		sum+=t[x];
		if (a>0) g[a].PB(x);
		else root=x;
	}
	if (sum%3!=0) {printf("-1\n"); return 0;}
	third=sum/3;
	dfs(root); f(root);
	if (final.fst==-1) {printf("-1\n"); return 0;}
	else printf("%lld %lld\n",final.fst,final.snd);
}