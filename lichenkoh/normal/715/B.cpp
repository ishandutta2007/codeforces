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
const ll mn=1e5+4;
ll dist[2][mn];
ll par[mn];
vector<pll> g[mn];
map<ll,ll> emp;
ll n,t;
void dij(ll s, ll k) {
	priority_queue<pll,vector<pll>,greater<pll> > pq;
	for (ll x=0;x<n;x++) {dist[k][x]=INF; par[x]=UNDEF;}
	dist[k][s]=0;
	par[s]=UNDEF;
	pq.push(MP(0,s));
	while(!pq.empty()) {
		auto got=pq.top(); pq.pop();
		ll x=got.second,d=got.first;
		if (d>dist[k][x]) continue;
		for (auto &w:g[x]) {
			ll y=w.first,len=w.second;
			if (len>=INF) continue;
			ll alt=d+len;
			if (alt<dist[k][y]) {
				dist[k][y]=alt;
				par[y]=x;
				pq.push(MP(alt,y));
			}
		}
	}
}
vector<ll> au,av,aw;
map<pll,ll> em;
int main() {
	ios_base::sync_with_stdio(false);
	ll m,L,s; scanf("%lld %lld %lld %lld %lld",&n,&m,&L,&s,&t);
	map<pll,ll> ans;
	for (ll i=0;i<m;i++) {
		ll u,v,w; scanf("%lld %lld %lld",&u,&v,&w);
		em[MP(u,v)]=w;
		em[MP(v,u)]=w;
		if (w==0) {
			emp[u]=v;
			emp[v]=u;
			w=INF;
			ans[MP(u,v)]=INF;
		}
		else {
			au.PB(u);av.PB(v);aw.PB(w);
		}
		//printf("g %lld<->%lld\n",u,v);
		g[u].PB(MP(v,w));
		g[v].PB(MP(u,w));
	}
	dij(s,0);
	//printf("Orig:%lld\n",dist[t]);
	if (dist[0][t]<L) {
		printf("NO\n");
	}
	else if (dist[0][t]==L) {
		printf("YES\n");
		for (auto &w:ans) {
			ll u=w.first.first,v=w.first.second,weight=w.second;
			printf("%lld %lld %lld\n",u,v,weight);
		}
		for (ll i=0;i<au.size();i++) printf("%lld %lld %lld\n",au[i],av[i],aw[i]);
	}
	else {
		for (ll x=0;x<n;x++) {
			for (auto &w:g[x]) {
				if (w.second==INF) w.second=1;
			}
		}
		dij(s,1);
		ll extra=L-dist[1][t]+1;
		if (extra>=1) {
			ll x=t;
			ll travel=0;
			while(1) {
				assert(x!=s);
				ll y=par[x];
				ll u=x,v=par[x];
				if (ans.find(MP(u,v))==ans.end()) swap(u,v);
				if (ans.find(MP(u,v))!=ans.end()) {
					if (dist[0][y]<INF) {
						ll left=L-dist[0][y]-travel;
						if (left>=1) {
							ans[MP(u,v)]=left;
							break;
						}
					}
					ans[MP(u,v)]=1;
					travel+=1;
				}
				else {
					travel+=em[MP(x,y)];
				}
				x=y;
			}
			printf("YES\n");
			for (auto &w:ans) {
				ll u=w.first.first,v=w.first.second,weight=w.second;
				printf("%lld %lld %lld\n",u,v,weight);
			}
			for (ll i=0;i<au.size();i++) printf("%lld %lld %lld\n",au[i],av[i],aw[i]);
			return 0;
		}
		printf("NO\n");
	}
}