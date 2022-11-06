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

template<class T> T extgcd(T a, T b, T& x, T& y) { for (T u = y = 1, v = x = 0; a;) { T q = b / a; swap(x -= q * u, u); swap(y -= q * v, v); swap(b -= q * a, a); } return b; }
template<class T> T mod_inv(T a, T m) { T x, y; extgcd(a, m, x, y); return (m + x % m) % m; }
ll mod_pow(ll a, ll n, ll mod) { ll ret = 1; ll p = a % mod; while (n) { if (n & 1) ret = ret * p % mod; p = p * p % mod; n >>= 1; } return ret; }
const ll MLOG=62;
void gauss(vector<ll> &a) {
	ll n=a.size();
	ll r=0;
	for (ll k=0;k<MLOG;k++) {
		ll msk=1ll<<k;
		for (ll x=r;x<n;x++) {
			if (a[x]&msk) {
				swap(a[x],a[r]);
				for (ll s=r+1;s<n;s++) {
					if (a[s]&msk) a[s]^=a[r];
				}
				r++;
				break;
			}
		}
	}
	a.resize(r);
}

ll n,m;
const ll mn=1e5+4;
bool seen[mn];
ll xorv[mn];
vector<ll> cyc;
vector<pll> g[mn];
vector<ll> active;
void dfs(ll x, ll p, ll v) {
	if (seen[x]) {
		// Cycle found
		//printf("x:%lld p:%lld v:%lld xorv:%lld\n",x,p,v,xorv[x]);
		cyc.PB(v^xorv[x]);
	}
	else {
		active.PB(x);
		xorv[x]=v;
		seen[x]=true;
		for (auto &w:g[x]) {
			ll y=w.first,t=w.second;
			if (y==p) continue;
			dfs(y,x,v^t);
		}
	}
}
ll solve(ll a,vector<ll> cyc,ll k) {
	ll cs=cyc.size();
	if (cs==0) return a;
	ll msk=1ll<<k;
	bool all0=true;
	for (ll x=0;x<cs;x++) if(cyc[x]&msk) all0=false;
	ll numodd;
	if (all0) numodd=0;
	else numodd=mod_pow(2,cs-1,MOD);
	ll numeven=mod_pow(2,cs,MOD)-numodd;
	if (a==0) return numodd;
	else return numeven;
}
ll go(ll init) {
	active.clear();
	cyc.clear();
	dfs(init,-1,0);
	if (active.size()<=1) return 0;
	gauss(cyc);
	ll final=0;
	for (ll k=0;k<MLOG;k++) {
		ll cnt[2]; cnt[0]=0,cnt[1]=0;
		for (auto &x:active) {
			ll d=1&(xorv[x]>>k);
			cnt[d]++;
		}
		for (ll a=0;a<2;a++) for (ll b=0;b<2;b++) {
			ll all;
			if (a==b) all=cnt[a]*(cnt[b]-1);
			else all=cnt[a]*cnt[b];
			ll got=solve(a^b,cyc,k);
			ll cand=(got*all)%MOD;
			ll add=(cand*mod_pow(2,k,MOD))%MOD;
			//if(cand)printf("k:%lld a:%lld b:%lld got:%lld all:%lld product:%lld add:%lld\n",k,a,b,got,all,cand,add);
			final=(final+add)%MOD;
		}
	}
	final=(final*mod_inv(2ll,MOD))%MOD;
	return final;
}
int main()
{
	ios_base::sync_with_stdio(false); cin.tie(0);
	scanf("%lld %lld",&n,&m);
	for (ll i=0;i<m;i++) {
		ll u,v,t; scanf("%lld%lld%lld",&u,&v,&t);
		g[u].PB(MP(v,t));
		g[v].PB(MP(u,t));
	}
	memset(seen,0,sizeof seen);
	ll ans=0;
	for (ll x=1;x<=n;x++) {
		if (!seen[x]) {
			ll cand=go(x);
			ans=(cand+ans)%MOD;
		}
	}
	printf("%lld\n",ans);
}