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
const ll MAXN = 100008;
set<pair<ll,ll> > g[MAXN];
unordered_set<ll> h[MAXN];
unordered_set<ll> s;
int main() {
	ios_base::sync_with_stdio(false);
	ll n,m; scanf("%d %d",&n,&m);
	for (ll i=1;i<=m;i++) {
		ll src,t;
		scanf("%d %d",&src,&t);
		g[src].insert(MP(t,i));
		h[t].insert(src);
	}
	bool good=true;
	ll ans=0;
	ll z=-1;
	for (ll x=1;x<=n;x++) {
		if (h[x].size()==0) {
			if (z!=-1) good=false;
			z=x;
		}
	}
	if(!good) {
		printf("-1\n");
		return 0;
	}
	s.insert(z);
	for (ll ii=1;ii<n;ii++) {
		ll nz=-1;
		for (auto git=g[z].begin();git!=g[z].end();){
			ll y=git->first;
			if (s.find(y)!=s.end()) {
				g[z].erase(git++);
			}
			else {
				for (auto hit=h[y].begin();hit!=h[y].end();) {
					if(s.find(*hit)!=s.end()) {
						h[y].erase(hit++);
					}
					else ++hit;
				}
				if(h[y].empty()) {
					if(nz!=-1) {
						good=false;
						if(!good) {
							printf("-1\n");
							return 0;
						}
					}
					nz=y;
					ans=max(ans,git->second);
				}
				++git;
			}
		}
		if (nz==-1) {good=false; break;}
		s.insert(nz);
		z=nz;
	}
	if(!good) {
		printf("-1\n");
		return 0;
	}
	else {
		printf("%d\n",ans);
		return 0;
	}
}