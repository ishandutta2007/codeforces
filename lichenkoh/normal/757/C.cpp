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
ll gid=0;
ll getid() {
	ll id=gid;
	gid++;
	return id;
}
const ll mn=1e5+4;
const ll mm=1e6+4;
set<ll> idtov[mm];
ll vtoid[mm];
const ll MAXFACT=mm;
ll fact[MAXFACT+1];
inline ll mul(ll x,ll y) {return (((long long)x)*((long long)y))%MOD;}
int main()
{
	ios_base::sync_with_stdio(false); cin.tie(0);
	ll n,m; scanf("%lld%lld",&n,&m);
	{
		ll id=getid();
		for (ll x=0;x<m;x++) {idtov[id].insert(x); vtoid[x]=id;}
	}
	for (ll k=0;k<n;k++) {
		ll g; scanf("%lld",&g);
		map<ll,ll> cnt;
		for (ll j=0;j<g;j++) {
			ll x; scanf("%lld",&x);
			--x;
			cnt[x]++;
		}
		map<ll,vector<ll> > rcnt;
		for (auto &w:cnt) {
			rcnt[w.snd].PB(w.fst);
		}
		for (auto &cw:rcnt) {
			map<ll,vector<ll> > h;
			for (auto &x:cw.snd) {
				ll id=vtoid[x];
				h[id].PB(x);
			}
			for (auto &w:h) {
				ll oid=w.fst;
				if (w.snd.size()==idtov[oid].size()) continue;
				ll nid=getid();
				for (auto &x:w.snd) {
					//printf("x:%lld oid:%lld nid:%lld\n",x,oid,nid);
					idtov[oid].erase(x);
					idtov[nid].insert(x);
					vtoid[x]=nid;
				}
			}
		}
		//for (ll x=0;x<m;x++) printf("x:%lld id:%lld\n",x,vtoid[x]);
	}

  ll got=1;
  for (ll x=0;x<MAXFACT;x++) {
    fact[x]=got;
    got=mul(got,x+1);
  }
	ll ans=1;
	for (ll id=0;id<gid;id++) {
		ans=mul(ans,fact[idtov[id].size()]);
	}
	printf("%lld\n",ans);
}