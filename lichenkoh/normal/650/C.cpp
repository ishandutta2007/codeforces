#include <bits/stdc++.h>
#include <cstring>
#include <assert.h>
using namespace std;
typedef long long ll;
typedef long double ld;
#define PB push_back
#define MP make_pair
#define endl "\n"
const ll UNDEF = -1;
const ll INF=1e9+4;
template<typename T> inline bool chkmax(T &aa, T bb) { return aa < bb ? aa = bb, true : false; }
template<typename T> inline bool chkmin(T &aa, T bb) { return aa > bb ? aa = bb, true : false; }
template<class T> T extgcd(T a, T b, T& x, T& y) { for (T u = y = 1, v = x = 0; a;) { T q = b / a; swap(x -= q * u, u); swap(y -= q * v, v); swap(b -= q * a, a); } return b; }
template<class T> T mod_inv(T a, T m) { T x, y; extgcd(a, m, x, y); return (m + x % m) % m; }
ll n,m;
vector<vector<ll> > a;
const ll mn=1e6+4;
vector<ll> g[mn];
ll par[mn];
ll gid=0;
inline ll MK(ll x,ll y) {
	return x*m+y;
}
ll getid(ll x) {
	if (par[x]==x) return x;
	return par[x]=getid(par[x]);
}
void funion(ll x, ll y) {
	if (rand()%2) swap(x,y);
	x=getid(x);
	y=getid(y);
	par[x]=y;
}
ll dp[mn];
ll f(ll id) {
	if (dp[id]!=-1) return dp[id];
	ll ans=1;
	for (auto &nid:g[id]) {
		//if (id==nid) continue;
		chkmax(ans,1+f(nid));
		//printf("id:%lld nid:%lld f:%lld\n",id,nid,f(nid));
	}
	return dp[id]=ans;
}
int main() {
	scanf("%lld%lld\n",&n,&m);
	a.resize(n);
	for (ll i=0;i<n;i++) {
		a[i].resize(m);
		for (ll j=0;j<m;j++) scanf("%lld",&a[i][j]);
	}
	for (ll x=0;x<mn;x++) {
		par[x]=x;
	}
	for (ll x=0;x<n;x++) {
		map<ll,vector<ll> > z;
		for (ll y=0;y<m;y++) {
			ll v=a[x][y];
			z[v].PB(y);
		}
		for (auto &w:z) {
			ll v=w.first;
			if (w.second.size()) {
				ll fy=w.second[0];
				for (auto &y:w.second) {
					funion(MK(x,fy),MK(x,y));
				}
			}
		}
	}

	for (ll y=0;y<m;y++) {
		map<ll,vector<ll> > z;
		for (ll x=0;x<n;x++) {
			ll v=a[x][y];
			z[v].PB(x);
		}
		for (auto &w:z) {
			ll v=w.first;
			if (w.second.size()) {
				ll fx=w.second[0];
				for (auto &x:w.second) {
					funion(MK(fx,y),MK(x,y));
				}
			}
		}
	}
	for (ll x=0;x<n;x++) {
		map<ll,ll> h;
		for (ll y=0;y<m;y++) {
			ll v=a[x][y];
			h[v]=getid(MK(x,y));
		}
		auto it=h.begin();
		auto jt=it;
		jt++;
		while(jt!=h.end()) {
			g[jt->second].PB(it->second);
			it=jt;
			++jt;
		}
	}
	for (ll y=0;y<m;y++) {
		map<ll,ll> h;
		for (ll x=0;x<n;x++) {
			ll v=a[x][y];
			h[v]=getid(MK(x,y));
		}
		auto it=h.begin();
		auto jt=it;
		jt++;
		while(jt!=h.end()) {
			g[jt->second].PB(it->second);
			it=jt;
			++jt;
		}
	}
	memset(dp,-1,sizeof dp);
	for (ll x=0;x<n;x++) {
		for (ll y=0;y<m;y++) {
			ll id=getid(MK(x,y));
			ll ans=f(id);
			printf("%lld ",ans);
		}
		printf("\n");
	}
}