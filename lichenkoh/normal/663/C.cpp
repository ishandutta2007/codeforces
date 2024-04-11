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
const ll INF=1ULL<<30ULL;
template<typename T> inline bool chkmax(T &a, T b) { return a < b ? a = b, true : false; }
template<typename T> inline bool chkmin(T &a, T b) { return a > b ? a = b, true : false; }
const ll MAXN=100004;
ll n,m;
ll seen[MAXN];
bool used[MAXN];
pair<ll,ll> ed[MAXN];
ll col[MAXN];
ll pick[MAXN];
ll gid=1;
ll gc=0;
bool insf;
vector<pair<ll,ll> > g[MAXN];
vector<ll> vans[2];
vector<ll> gvec;
inline bool picked(ll x) {
	return pick[x]==gid;
}
inline bool seened(ll x) {
	return seen[x]==gid;
}
inline void setpick(ll x, bool y) {
	if (y) {pick[x]=gid;}
	else assert(pick[x]!=gid);
}
inline void setseen(ll x) {
	seen[x]=gid;
}
ll solve(ll x) {
	bool good=true;
	used[x]=true;
	setseen(x);
	ll ans=picked(x);
	if (picked(x)) gvec.PB(x);
	for (auto &w: g[x]) {
		ll y=w.first;
		ll c=w.second;
		bool want;
		if (c==gc) {want=picked(x);}
		else {want=!picked(x);}
		if (seened(y)&&(want!=picked(y))) {good=false;}
		if (!seened(y)) {
			setpick(y,want);
			ll cand=solve(y);
			if (cand==UNDEF) {good=false;}
			ans+=cand;
		}
	}
	if (!good) return UNDEF;
	return ans;
}
int main() {
	ios_base::sync_with_stdio(false);
	scanf("%d %d",&n,&m);
	for (ll e=0;e<m;e++) {
		ll x,y; char c;
		scanf("%d %d %c",&x,&y,&c);
		col[e]=(c=='B')?0:1;
		g[x].PB(MP(y,col[e])); g[y].PB(MP(x,col[e]));
		ed[e]=MP(x,y);
	}
	for (ll x=0;x<MAXN;x++) {
		seen[x]=0;
		pick[x]=0;
	}
	gid=1;
	ll aans[2];
	for (ll k=0;k<2;k++) {
		gc=k;
		aans[k]=0;
		for (ll x=0;x<MAXN;x++) used[x]=false;
		for (ll e=0;e<m;e++) {
			if (col[e]==k) continue;
			ll x=ed[e].first; ll y=ed[e].second;
			if (used[x]||used[y]) continue;
			insf=false;
			gid++;
			setpick(x,true);
			gvec.clear();
			ll candx=solve(x);
			vector<ll> vecx=gvec;
			gid++;
			setpick(y,true);
			gvec.clear();
			ll candy=solve(y);
			vector<ll> vecy=gvec;
			if (candx==UNDEF) candx=INF;
			if (candy==UNDEF) candy=INF;
			if (candx<=candy) {
				for (auto &w: vecx) {
					vans[k].PB(w);
				}
			}
			else {
				for (auto &w: vecy) {
					vans[k].PB(w);
				}
			}
			ll cand=min(candx,candy);
			aans[k]+=cand;
			if (aans[k]>=INF||cand>=INF) aans[k]=INF;
		}
	}
	ll bestk=(aans[0]<aans[1])?0:1;
	ll final=aans[bestk];
	vector<ll> vfinal=vans[bestk];
	if (final>=INF) final=-1;
	printf("%d\n",final);
	if (final!=-1) {
		for (auto &w:vfinal) {
			printf("%d ",w);
		}
		printf("\n");
	}
}