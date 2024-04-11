#include <iostream>
#include <vector>
#include <algorithm>
#include <assert.h>
using namespace std;
typedef int ll;
typedef long double ld;
#define PB push_back
#define MP make_pair
const ll MOD = 1000000007LL;
const ll INF = 1ULL<<30ULL;
const ll UNDEF = -1;
template<typename T> inline bool chkmax(T &aa, T bb) { return aa < bb ? aa = bb, true : false; }
template<typename T> inline bool chkmin(T &aa, T bb) { return aa > bb ? aa = bb, true : false; }
ll n,q;
const ll MAXN=300000+4;
ll par[MAXN];
vector<ll> g[MAXN];
ll sz[MAXN], cent[MAXN], maxszchild[MAXN];
void getsize(ll x) {
	ll ans=1;
	ll mc=0;
	for (auto &w:g[x]) {
		getsize(w);
		ans+=sz[w];
		chkmax(mc,sz[w]);
	}
	maxszchild[x]=mc;
	sz[x]=ans;
}
void getcent(ll r) {
	for (auto &w: g[r]) getcent(w);
	if (maxszchild[r]<=sz[r]/2) {
		cent[r]=r;
		return;
	}
	for (auto &w: g[r]) {
		ll v=cent[w];
		while(v!=r) {
			ll upper=sz[r]-sz[v];
			ll mc=max(maxszchild[v],upper);
			if (mc<=sz[r]/2) {
				cent[r]=v;
				return;
			}
			v=par[v];
		}
	}
	assert(false);
}
int main() {
	scanf("%d %d",&n,&q);
	for (ll i=2;i<=n;i++) {
		scanf("%d",&par[i]);
		g[par[i]].PB(i);
	}
	getsize(1);
	getcent(1);
	for (ll i=0;i<q;i++) {
		ll r;
		scanf("%d",&r);
		printf("%d\n",cent[r]);
	}
}