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
vector<pll> g[mn];
bool iscentroid[mn];
ll getCentroid(ll u,ll p,ll n) {
    ll cnt = 1;
    bool goodCenter = true;
    for (auto w : g[u]) {
    	ll v=w.first;
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
		ll y=w.first;
		if (y==p||iscentroid[y]) continue;
		ll childSubtreeSize=getSubtreeSize(y,x);
		selfSubtreeSize+=childSubtreeSize;
	}
	return selfSubtreeSize;
}
void dfs1(ll x,ll p,ll val,ll tenp,ll factor,map<ll,ll> &h) {
	val%=MOD;
	//printf("x:%lld p:%lld val:%lld tenp:%lld factor:%lld\n",
	//	x,p,val,tenp,factor);
	h[val]++;
	for (auto &w:g[x]) {
		ll y=w.first;
		if (y==p||iscentroid[y]) continue;
		ll k=w.second;
		ll nval=add(val,mul(k,tenp));
		dfs1(y,x,nval,mul(tenp,factor),factor,h);
	}
}
ll final=0;
void fullCentroidDecomposition(ll initv,ll p,ll n) {
	ll centroid=getCentroid(initv,p,n);
	vector<pll> subtreeRootsWithSizes;
	for (auto &w:g[centroid]) {
		ll y=w.first;
		if (y!=p&&(!iscentroid[y])) {
			ll sz=getSubtreeSize(y,centroid);
			subtreeRootsWithSizes.PB(MP(y,sz));
		}
	}
	/* Custom code starts here */
	map<ll,ll> allinv;
	ll inv10=mod_inv(10ll,MOD);
	for (auto &w:g[centroid]) {
		ll y=w.first,k=w.second;
		if (y!=p&&(!iscentroid[y])) {
			//printf("y:%lld centroid:%lld k:%lld\n",y,centroid,k);
			dfs1(y,centroid,k,inv10,inv10,allinv);
		}
	}
	final+=allinv[0];
	allinv[0]++;
	for (auto &edge:g[centroid]) {
		ll y=edge.first,k=edge.second;
		if (y!=p&&(!iscentroid[y])) {
			map<ll,ll> hinv,hfwd;
			dfs1(y,centroid,k,inv10,inv10,hinv);
			for (auto w:hinv) allinv[w.first]-=w.second;
			dfs1(y,centroid,mul(k,10),mul(10,10),10,hfwd);
			for (auto w:hfwd) {
				ll key=(MOD-w.first)%MOD;
				auto get=allinv.find(key);
				if (get!=allinv.end()) {
					//printf("centroid:%lld y:%lld okey:%lld key:%lld. Add %lld*%lld\n",
					//	centroid,y,w.first,key,w.second,get->second);
					final+=w.second*(get->second);
				}
			}
			for (auto w:hinv) allinv[w.first]+=w.second;
		}
	}
	/* Custom code ends here. Continue decomposing subtree.*/
	iscentroid[centroid]=true;
	for (auto &got:subtreeRootsWithSizes) {
		fullCentroidDecomposition(got.first,centroid,got.second);
	}
}
int main()
{
	ios_base::sync_with_stdio(false); cin.tie(0);
	memset(iscentroid,0,sizeof iscentroid);
	ll n,m; scanf("%lld%lld",&n,&m);
	MOD=m;
	for (ll i=0;i<n-1;i++) {
		ll u,v,w; scanf("%lld%lld%lld",&u,&v,&w);
		g[u].PB(MP(v,w));
		g[v].PB(MP(u,w));
	}
	fullCentroidDecomposition(0,-1,n);
	printf("%lld\n",final);
}