#include <bits/stdc++.h>
#include <assert.h>
using namespace std;
typedef int ll;
typedef long double ld;
#define PB push_back
#define MP make_pair
#define MOD 1000000007LL
#define endl "\n"
const ll UNDEF = -1;
template<typename T> inline bool chkmax(T &a, T b) { return a < b ? a = b, true : false; }
template<typename T> inline bool chkmin(T &a, T b) { return a > b ? a = b, true : false; }
const ll MAXN=300004;
unordered_set<ll> g[MAXN];

void copygraph(ll dest, ll src) {
	//printf("dest: %d. src: %d\n",dest,src);
	vector<ll> tmp;
	for (auto it=g[dest].begin();it!=g[dest].end();) {
		ll y=*it;
		if (y==dest) continue;
		if (g[y].find(src)==g[y].end()) {
			g[y].erase(dest);
			g[dest].erase(it++);
		}
		else {
			++it;
		}
	}
	for (auto &y: tmp) g[dest].erase(y);
	for (auto &y: g[src]) {
		g[y].erase(src);
	}
	g[src].clear();
}
ll combine(ll x, ll y) {
	ll xr=x;
	ll yr=y;
	assert(xr!=yr);
	//if (g[xr].size()<g[yr].size()) {
	if (g[xr].size()<g[yr].size()) {
		copygraph(xr,yr);
		return yr;
	}
	else {
		copygraph(yr,xr);
		return xr;
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	ll n,m,k; scanf("%d %d %d",&n,&m,&k);
	for (ll i=0;i<m;i++) {
		ll ai,bi;
		scanf("%d %d",&ai,&bi);
		g[ai].insert(bi);
		g[bi].insert(ai);
	}
	if (n-1-g[1].size() < k) {
		printf("impossible\n");
		return 0;
	}
	unordered_set<ll> s;
	for (ll x=2;x<=n;x++) s.insert(x);
	while(1) {
		ll ssz=s.size();
		if (ssz<=1) break;
		bool done=false;
		for (auto &x:s) {
			if (g[x].size()>=s.size()-1) continue;
			for (auto &y:s) {
				if (x!=y&&g[x].find(y)==g[x].end()) {
					ll r = combine(x,y);
					s.erase(r);
					done=true;
					break;
				}
			}
			if (done) break;
		}
		if(!done) break;
	}
	bool ok=true;
	if (s.size()>k) ok=false;
	for (auto &y:s) {
		if (g[1].find(y)!=g[y].end()) {
			ok=false; break;
		}
	}
	if (ok) printf("possible\n");
	else printf("impossible\n");
}