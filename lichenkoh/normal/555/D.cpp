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
const ll INF=1e18;
template<typename T> inline bool chkmax(T &aa, T bb) { return aa < bb ? aa = bb, true : false; }
template<typename T> inline bool chkmin(T &aa, T bb) { return aa > bb ? aa = bb, true : false; }
typedef pair<ll,ll> pll;
typedef vector<ll> vll;
const ll mn=2e5+2;
ll vx[mn];
ll n,m;
ll get_geq(ll x) {
	ll imin=0,imax=n;
	while(imin<imax) {
		ll imid=(imin+imax)/2;
		if (vx[imid]<x) imin=imid+1;
		else imax=imid;
	}
	if (0<=imin&&imin<n&&vx[imin]>=x) return imin;
	return -1;
}
ll get_leq(ll x) {
	ll imin=0,imax=n;
	while(imin<imax) {
		ll imid=(imin+imax)/2;
		if (vx[imid]<=x) imin=imid+1;
		else imax=imid;
	}
	--imin;
	if (0<=imin&&imin<n&&vx[imin]<=x) return imin;
	return -1;
}
const ll RIGHT=1;
map<ll,ll> h[2];
ll f(ll dir, ll a, ll l) {
	//printf("dir:%d a:%d l:%d\n",dir,a,l);
	if (l==0) return a;
	auto it=h[dir].find(a);
	if (it!=h[dir].end()) {
		ll diff=it->second-l;
		assert(diff!=0);
		ll freshl=(l%diff)+diff;
		if (freshl<l) l=freshl;
	}
	h[dir][a]=l;
	ll newa;
	if (dir==RIGHT) {
		newa=get_leq(vx[a]+l);
	}
	else {
		newa=get_geq(vx[a]-l);
	}
	if (newa==-1||newa==a) {
		dir^=1;
		if (dir==RIGHT) {
			newa=get_leq(vx[a]+l);
		}
		else {
			newa=get_geq(vx[a]-l);
		}
	}
	if (newa==-1||newa==a) return a;
	ll newl=l-abs(vx[newa]-vx[a]);
	ll newdir=dir^1;
	return f(newdir,newa,newl);
}
ll oldIdxToNew[mn];
ll newIdxToOld[mn];
pll px[mn];
int main()
{
	ios_base::sync_with_stdio(false); cin.tie(0);
	scanf("%d%d",&n,&m);
	for (ll i=0;i<n;i++) {
		scanf("%d",&px[i].fst);
		px[i].snd=i+1;
	}
	sort(px,px+n);
	for (ll i=0;i<n;i++) {
		newIdxToOld[i]=px[i].snd;
		oldIdxToNew[px[i].snd]=i;
	}
	for (ll i=0;i<n;i++) vx[i]=px[i].fst;
	for (ll i=0;i<m;i++) {
		ll olda,l;
		scanf("%d%d",&olda,&l);
		ll a=oldIdxToNew[olda];
		//printf("olda:%d is %d\n",olda,vx[a]);
		for (ll d=0;d<2;d++) h[d].clear();
		ll ans=f(RIGHT,a,l);
		ll oldans=newIdxToOld[ans];
		printf("%d\n",oldans);
	}
}