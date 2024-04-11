#include <bits/stdc++.h>
#include <assert.h>
using namespace std;
typedef long long ll;
typedef long double ld;
#define PB push_back
#define MP make_pair
#define endl "\n"
const ll UNDEF = -1;
const ll INF=1e9;
template<typename T> inline bool chkmax(T &aa, T bb) { return aa < bb ? aa = bb, true : false; }
template<typename T> inline bool chkmin(T &aa, T bb) { return aa > bb ? aa = bb, true : false; }
template<class T> T extgcd(T a, T b, T& x, T& y) { for (T u = y = 1, v = x = 0; a;) { T q = b / a; swap(x -= q * u, u); swap(y -= q * v, v); swap(b -= q * a, a); } return b; }
template<class T> T mod_inv(T a, T m) { T x, y; extgcd(a, m, x, y); return (m + x % m) % m; }
ll mod_pow(ll a, ll n, ll mod) { ll ret = 1; ll p = a % mod; while (n) { if (n & 1) ret = ret * p % mod; p = p * p % mod; n >>= 1; } return ret; }

typedef pair<ll,ll> pll;
ll MOD;
inline ll mul(ll x,ll y) {
	return (x*y)%MOD;
}
inline ll add(ll x,ll y) {
	return (MOD+MOD+x+y)%MOD;
}
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
const ll mn=1e5+4;
vector<ll> g[mn];
bool iscentroid[mn];
ll getCentroid(ll u,ll p,ll n) {
    ll cnt = 1;
    bool goodCenter = true;
    for (auto w : g[u]) {
      ll v=w;
      if (v == p||iscentroid[v]) continue;
      ll res = getCentroid(v, u, n);
      if (res >= 0)
        return res;
      ll size = -res;
      goodCenter &= size <= n / 2;
      cnt += size;
    }
    goodCenter &= n - cnt <= n / 2;
    return goodCenter ? u : -cnt;
  }
ll getSubtreeSize(ll x,ll p) {
	ll selfSubtreeSize=1;
	for (auto &w:g[x]) {
		ll y=w;
		if (y==p||iscentroid[y]) continue;
		ll childSubtreeSize=getSubtreeSize(y,x);
		selfSubtreeSize+=childSubtreeSize;
	}
	return selfSubtreeSize;
}
char vans[mn];
void fullCentroidDecomposition(ll initv,ll p,ll n, ll d) {
	ll centroid=getCentroid(initv,p,n);
	vector<pll> subtreeRootsWithSizes;
	for (auto &w:g[centroid]) {
		ll y=w;
		if (y!=p&&(!iscentroid[y])) {
			ll sz=getSubtreeSize(y,centroid);
			subtreeRootsWithSizes.PB(MP(y,sz));
		}
	}
	/* Custom code starts here */
	vans[centroid]='A'+d;
	/* Custom code ends here. Continue decomposing subtree.*/
	iscentroid[centroid]=true;
	for (auto &got:subtreeRootsWithSizes) {
		fullCentroidDecomposition(got.first,centroid,got.second,d+1);
	}
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0);
	ll n; scanf("%lld",&n);
	for (ll i=0;i<n-1;i++) {
		ll a,b; scanf("%lld%lld",&a,&b);
		--a; -- b;
		g[a].PB(b);
		g[b].PB(a);
	}
	fullCentroidDecomposition(0,-1,n,0);
	for (ll x=0;x<n;x++) {
		printf("%c ",vans[x]);
	}
	printf("\n");
}