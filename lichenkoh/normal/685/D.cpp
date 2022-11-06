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
const ll MAXN=100000+4;
const ll INF=2e9+1;
vector<pair<ll,pair<ll,ll> > > vp;
vector<ll> vy;
const ll DSZ=300*100000;
int delta[DSZ];
long long ans[MAXN];
int main() {
	ll n,k; scanf("%d %d",&n,&k);
	set<ll> sy;
	for (ll i=0;i<n;i++) {
		ll x,y; scanf("%d %d",&x,&y);
		sy.insert(y);
		vp.PB(MP(x,MP(-1,y)));
		vp.PB(MP(x+k,MP(1,y)));
	}
	sort(vp.begin(),vp.end());
	ll ly=*(sy.begin());
	ll idx=0;
	map<ll,ll> hy;
	for (auto &y:sy) {
		idx+=min(k,y-ly);
		hy[y]=idx;
		//printf("y:%d idx:%d\n",y,idx);
		ly=y;
	}
	ll vysz=vy.size();
	for (ll i=0;i<vysz;i++) delta[i]=0;
	for (ll c=1;c<=n;c++) ans[c]=0;
	ll ex=vp.rbegin()->first;
	for (auto &w:vp) {
		ll x=w.first;
		ll dx=ex-x;
		ll t=-w.second.first;
		ll y=w.second.second;
		ll iy=hy[y];
		for (ll i=iy;i<iy+k;i++) {
			ans[delta[i]]-=dx;
			delta[i]+=t;
			ans[delta[i]]+=dx;
		}
	}
	for (ll c=1;c<=n;c++) {
		printf("%I64d ",ans[c]);
	}
	printf("\n");
}