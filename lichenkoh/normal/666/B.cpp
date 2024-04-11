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
const ll INF=1ULL<<28ULL;
const ll MAXN=3000+4;
unordered_set<ll> g[2][MAXN];
ll d[2][MAXN][MAXN];
vector<pair<ll,ll> > v[2][MAXN];
ll n;
void bfs(ll init, ll r) {
	for (ll x=0;x<n;x++) {
		d[r][init][x]=INF;
	}
	queue<ll> q;
	q.push(init);
	d[r][init][init]=0;
	while(!q.empty()) {
		ll x=q.front();
		q.pop();
		for (auto &w: g[r][x]) {
			if (d[r][init][w]==INF) {
				d[r][init][w] = d[r][init][x]+1;
				q.push(w);
			}
		}
	}
	for (ll x=0;x<n;x++) {
		if (x==init) continue;
		if (d[r][init][x]<INF) {
			v[r][init].PB(MP(-d[r][init][x],x));
		}
	}
	sort(v[r][init].begin(),v[r][init].end());
}

int main() {
	ios_base::sync_with_stdio(false);
	ll m; scanf("%d %d",&n,&m);
	for (ll i=0;i<m;i++) {
		ll x,y; scanf("%d %d",&x,&y);
		x--;y--;
		g[0][x].insert(y);
		g[1][y].insert(x);
	}
	for (ll r=0;r<2;r++) {
	for (ll init=0;init<n;init++) {
		bfs(init,r);
	}}
	ll final=0;
	ll vfinal[10];
	for (ll x=0;x<n;x++) {
		for (ll y=0;y<n;y++) {
			if (x==y) continue;
			if (d[0][x][y]>=INF) continue;
			vector<ll> bs;
			for (auto &w: v[1][x]) {
				ll val=w.second;
				if (val!=x&&val!=y) {
					bs.PB(val);
					if (bs.size()>=2) break;
				}
			}
			vector<ll> be;
			for (auto &w: v[0][y]) {
				ll val=w.second;
				if (val!=x&&val!=y) {
					be.PB(val);
					if (be.size()>=2) break;
				}
			}
			for (auto &s:bs) {
				for (auto &e:be) {
					if (s==e) continue;
					ll ans=d[0][s][x]+d[0][x][y]+d[0][y][e];
					if (ans>=INF) continue;
					if (ans>final) {
						vfinal[0]=s;
						vfinal[1]=x;
						vfinal[2]=y;
						vfinal[3]=e;
						final=ans;
					}
				}
			}
		}
	}
	for (ll i=0;i<4;i++) {
		vfinal[i]++;
	}
	printf("%d %d %d %d\n",vfinal[0],vfinal[1],vfinal[2],vfinal[3]);
}