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
const ll INF=1e9+100;
template<typename T> inline bool chkmax(T &aa, T bb) { return aa < bb ? aa = bb, true : false; }
template<typename T> inline bool chkmin(T &aa, T bb) { return aa > bb ? aa = bb, true : false; }
const ll mn=5004;
typedef pair<int,int> pii;
pii f[mn][mn];
vector<pii> g[mn];
int main() {
	ios_base::sync_with_stdio(false);
	ll n,m,T; scanf("%d %d %d",&n,&m,&T);
	for (ll i=0;i<m;i++) {
		ll u,v,t;
		scanf("%d %d %d",&u,&v,&t);
		g[u].PB(MP(v,t));
	}
	for (ll d=0;d<mn;d++) for (ll x=0;x<mn;x++) f[d][x]=MP(INF,-1ll);
	f[0][1]=MP(0ll,0ll);
	for (ll d=0;d<mn;d++) {
		for (ll x=0;x<n;x++) {
			ll v=f[d][x].first;
			if (v>=INF) continue;
			for (auto &w:g[x]) {
				ll y=w.first,t=w.second;
				if (v+t>T) continue;
				chkmin(f[d+1][y],MP(v+t,x));
			}
		}
	}
	ll bestd;
	for (ll d=mn-1;d>=0;d--) {
		if (f[d][n].first<=T) {bestd=d;break;}
	}
	vector<ll> v;
	ll x=n;
	for (ll d=bestd;d>=0;d--) {
		v.PB(x);
		x=f[d][x].second;
	}
	reverse(v.begin(),v.end());
	ll vsz=v.size();
	printf("%d\n",vsz);
	for (auto &w:v) printf("%d ",w);
	printf("\n");
}