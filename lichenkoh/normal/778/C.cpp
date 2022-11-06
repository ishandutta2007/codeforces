#include <bits/stdc++.h>
#include <assert.h>
using namespace std;
typedef int ll;
typedef long double ld;
#define PB push_back
#define MP make_pair
#define MOD 1000000007LL
#define endl "\n"
#define fst first
#define snd second
const ll UNDEF = -1;
const ll INF=1e9+5;
template<typename T> inline bool chkmax(T &aa, T bb) { return aa < bb ? aa = bb, true : false; }
template<typename T> inline bool chkmin(T &aa, T bb) { return aa > bb ? aa = bb, true : false; }
typedef pair<ll,ll> pll;
typedef vector<ll> vll;
const ll md=5;
inline ll MK(ll x, ll y) {
	return (x<<md)|y;
}
inline ll fst(ll x) {return x>>md;}
inline ll snd(ll x) {return x&((1<<md)-1);}
const ll mn=3e5+2;
vector<ll> g[mn];
const ll maxc=26;
vll depth2vtx[mn];
void getdepth(ll x, ll k) {
	depth2vtx[k].PB(x);
	for (auto &ynode:g[x]) {
		ll y=fst(ynode);
		getdepth(y,k+1);
	}
}
ll gans;
void dfs(vll vx) {
	gans+=vx.size()-1;
	vll allv[maxc];
	for (auto &x:vx) {
		for (auto &ynode:g[x]) {
			ll y=fst(ynode); ll c=snd(ynode);
			allv[c].PB(y);
		}
	}
	for (ll c=0;c<maxc;c++) {
		if (allv[c].size()>=2) {
			dfs(allv[c]);
		}
	}
}
int main()
{
	ios_base::sync_with_stdio(false); cin.tie(0);
	ll n; scanf("%d\n",&n);
	for (ll i=0;i<n-1;i++) {
		ll s,t; char x; scanf("%d %d %c\n",&s,&t,&x);
		ll c=x-'a';
		g[s].PB(MK(t,c));
	}
	getdepth(1,-1);
	pll ans=MP(-INF,-INF);
	{
		gans=1;
		dfs(depth2vtx[0]);
		chkmax(ans,MP(gans,-1));
	}
	for (ll d=0;;d++) {
		ll sz=depth2vtx[d].size();
		if (sz==0) break;
		gans=sz;
		for (auto &x:depth2vtx[d]) {
			vll v;
			for (auto &ynode:g[x]) v.PB(fst(ynode));
			dfs(v);
		}
		chkmax(ans,MP(gans,-d-2));
	}
	printf("%d\n%d\n",n-ans.first,-ans.second);
}