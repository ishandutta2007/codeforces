#include <bits/stdc++.h>
#include <cstring>
#include <assert.h>
using namespace std;
typedef long long ll;
typedef pair<ll,ll> pll;
typedef long double ld;
#define PB push_back
#define MP make_pair
#define endl "\n"
const ll UNDEF = -1;
const ll INF=2e9;
template<typename T> inline bool chkmax(T &aa, T bb) { return aa < bb ? aa = bb, true : false; }
template<typename T> inline bool chkmin(T &aa, T bb) { return aa > bb ? aa = bb, true : false; }
template<class T> T extgcd(T a, T b, T& x, T& y) { for (T u = y = 1, v = x = 0; a;) { T q = b / a; swap(x -= q * u, u); swap(y -= q * v, v); swap(b -= q * a, a); } return b; }
template<class T> T mod_inv(T a, T m) { T x, y; extgcd(a, m, x, y); return (m + x % m) % m; }
const ll mn=2e5+4;
vector<ll> g[mn];
ll val[mn];
ll par[mn];
ll subtreeSize[mn];
ll initSubtreeSize(ll x, ll p) {
	if (subtreeSize[x]!=UNDEF) return subtreeSize[x];
	par[x]=p;
	ll ans=val[x];
	for (auto &y:g[x]) {
		if (y==p) continue;
		ans+=initSubtreeSize(y,x);
	}
	return subtreeSize[x]=ans;
}
ll getCentroid(ll all, ll initx) {
	ll x=initx;
	while(1) {
		pll largest=MP(-1ll,-1ll);
		for (auto &y:g[x]) {
			if (y==par[x]) continue;
			chkmax(largest,MP(subtreeSize[y],y));
		}
		if (par[x]!=-1) {
			chkmax(largest,MP(all-subtreeSize[x],par[x]));
		}
		//printf("x:%lld has %lld %lld\n",x,largest.first,largest.second);
		if (largest.first<=all/2) return x;
		else x=largest.second;
	}
}
vector<ll> obtain;
void dfs(ll x,ll p) {
	if (val[x]) obtain.PB(x);
	val[x]=0;
	for (auto &y:g[x]) {
		if (y==p) continue;
		dfs(y,x);
	}
}
vector<vector<ll> > pool;
int main() {
	ll n,k;
	scanf("%lld%lld",&n,&k);
	for (ll i=0;i<n-1;i++) {
		ll x,y; scanf("%lld%lld",&x,&y);
		--x; --y;
		g[x].PB(y); g[y].PB(x);
	}
	memset(val,0,sizeof val);
	for (ll i=0;i<2*k;i++) {
		ll x; scanf("%lld",&x);
		--x;
		val[x]=1;
	}
	memset(subtreeSize,-1,sizeof subtreeSize);
	initSubtreeSize(0,-1);
	ll centroid=getCentroid(2*k,0);
	for (auto &y:g[centroid]) {
		if (y==par[centroid]) continue;
		dfs(y,centroid);
		pool.PB(obtain);
		obtain.clear();
	}
	if (val[centroid]) {
		obtain.PB(centroid);
		val[centroid]=0;
		pool.PB(obtain);
		obtain.clear();
	}
	for (ll x=0;x<n;x++) {
		if (val[x]) obtain.PB(x);
	}
	pool.PB(obtain);
	ll pn=pool.size();
	priority_queue<pll> pq; // Max pq
	for (ll i=0;i<pn;i++) {
		if(pool[i].size())pq.push(MP(pool[i].size(),i));
	}
	printf("1\n%lld\n",centroid+1);
	while(pq.size()>=2) {
		auto a=pq.top(); pq.pop();
		auto b=pq.top(); pq.pop();
		--a.first; --b.first;
		ll ai=a.second,bi=b.second;
		printf("%lld %lld %lld\n",(pool[ai].back()+1),(pool[bi].back())+1,centroid+1);
		pool[ai].pop_back(); pool[bi].pop_back();
		if (a.first) pq.push(a);
		if (b.first) pq.push(b);
	}
	assert(pq.empty());

}