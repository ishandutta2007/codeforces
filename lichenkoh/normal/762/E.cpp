#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp> // Common file
#include <ext/pb_ds/tree_policy.hpp> // Including tree_order_statistics_node_update
#include <ext/pb_ds/detail/standard_policies.hpp>
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
template<class T> T extgcd(T a, T b, T& x, T& y) { for (T u = y = 1, v = x = 0; a;) { T q = b / a; swap(x -= q * u, u); swap(y -= q * v, v); swap(b -= q * a, a); } return b; }
template<class T> T mod_inv(T a, T m) { T x, y; extgcd(a, m, x, y); return (m + x % m) % m; }
ll mod_pow(ll a, ll n, ll mod) { ll ret = 1; ll p = a % mod; while (n) { if (n & 1) ret = ret * p % mod; p = p * p % mod; n >>= 1; } return ret; }
typedef pair<ll,ll> pll;

typedef vector<ll> vll;
using namespace __gnu_pbds;
typedef tree<
int,
null_type,
less<int>,
rb_tree_tag,
tree_order_statistics_node_update>
ordered_set;
const ll mf=1e4+2;
const ll mr=2e9;
vector<pll> gv[mf];
ll count_leq(vector<ll> &v, ll key) {
	ll imin=0,imax=v.size();
	while(imin<imax) {
		ll imid=(imin+imax)/2;
		if (v[imid]<=key) imin=imid+1;
		else imax=imid;
	}
	return imin+1;
}
ll solve(ll e,ll f) {
	vector<pll> line=gv[e];
	for (auto &w:gv[f]) {
		line.PB(MP(w.first-w.second,-w.first));
	}
	sort(line.begin(),line.end());
	ordered_set fly;
	ll ans=0;
	for (auto &w:line) {
		ll param=w.second;
		if (param>=0) {
			ll x=w.first;
			ll r=param;
			//ll hi=count_leq(fly,x+r);
			//ll lo=count_leq(fly,x);
			ll hi=fly.order_of_key(x+r+1);
			ll lo=fly.order_of_key(x+1);
			ll contrib=hi-lo;
			ans+=contrib;
		}
		else {
			ll xcoord=-param;
			fly.insert(xcoord);
		}
	}
	//if(ans)printf("e:%lld f:%lld ans:%lld\n",e,f,ans);
	return ans;
}
int main()
{
	ios_base::sync_with_stdio(false); cin.tie(0);
	ll n,klim; scanf("%lld%lld",&n,&klim);
	for (ll i=0;i<n;i++) {
		ll x,r,f;
		scanf("%lld%lld%lld",&x,&r,&f);
		gv[f].PB(MP(x,r));
	}
	//for (ll f=1;f<mf;f++) sort(gv.begin(),gv.end());
	ll final=0;
	for (ll e=1;e<mf;e++) {
		for (ll k=-klim;k<=klim;k++) {
			ll f=e+k;
			if (0<=f&&f<mf) {
				final+=solve(e,f);
			}
		}
	}
	printf("%lld\n",final);
}