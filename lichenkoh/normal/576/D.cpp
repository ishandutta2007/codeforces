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
const ll INF=2e9;
template<typename T> inline bool chkmax(T &aa, T bb) { return aa < bb ? aa = bb, true : false; }
template<typename T> inline bool chkmin(T &aa, T bb) { return aa > bb ? aa = bb, true : false; }
typedef pair<ll,ll> pll;
typedef vector<ll> vll;
const ll mn=150;
vector<pair<ll,pll> > ve;
ll va[mn],vb[mn],vd[mn];
ll n,m;
typedef struct matt{
	bitset<mn> t[mn];
	void reset() {
		for (ll x=0;x<n;x++) t[x].reset();
	}
} mat;
typedef struct vect{
	bitset<mn> t;
	void reset() {
		t.reset();
	}
} vec;
bitset<mn> tmp[mn];
mat mul(mat a, mat b) {
	mat res;
	for (ll x=0;x<n;x++) tmp[x].reset();
	for (ll x=0;x<n;x++) for (ll y=0;y<n;y++) {
		tmp[y][x]=b.t[x][y];
	}
	for (ll x=0;x<n;x++) {
		for (ll y=0;y<n;y++) {
			res.t[x][y]= (a.t[x] & tmp[y]).any();
		}
	}
	return res;
}
mat go(ll l, ll k) {
	vector<ll> v;
	while(l>0) {
		if (l&1) {v.PB(1); l--;}
		else {v.PB(0); l/=2;}
	}
	reverse(v.begin(),v.end());
	mat res;
	res.reset();
	for (ll x=0;x<n;x++) res.t[x][x]=true;
	mat orig;
	orig.reset();
	for (ll i=0;i<=k;i++) {
		orig.t[va[i]][vb[i]]=true;
	}
	for (auto &w:v) {
		if (w==0) {
			res=mul(res,res);
		}
		else {
			res=mul(res,orig);
		}
	}
	//for (ll x=0;x<n;x++) {for (ll y=0;y<n;y++) printf("%d ",res.t[x][y]); printf("\n");}
	//printf("\n");
	return res;
}

vec mulv(vec inp, ll k) {
	vec res;
	res.reset();
	for (ll i=0;i<=k;i++) {
		if (inp.t[va[i]]) res.t[vb[i]]=true;
	}
	return res;
}
vec mulv2(vec inp, mat a) {
	vec res;
	res.reset();
	for (ll x=0;x<n;x++) for (ll y=0;y<n;y++) {
		if (inp.t[x]&&a.t[x][y]) res.t[y]=true;
	}
	return res;
}
bool cur[mn],nxt[mn];
ll canhit(vec res, ll k) {
	if (res.t[n-1]) return 0;
	for (ll i=0;i<=n;i++) {
		res=mulv(res,k);
		if (res.t[n-1]) return i+1;
	}
	return INF;
}

int main()
{
	ios_base::sync_with_stdio(false); cin.tie(0);
	scanf("%d%d",&n,&m);
	for (ll i=0;i<m;i++) {
		ll a,b,d;
		scanf("%d%d%d",&a,&b,&d);
		--a; --b;
		ve.PB(MP(d,MP(a,b)));
	}
	sort(ve.begin(),ve.end());
	for (ll i=0;i<m;i++) {
		vd[i]=ve[i].fst;
		va[i]=ve[i].snd.fst;
		vb[i]=ve[i].snd.snd;
	}
	vec res;
	res.reset();
	res.t[0]=true;
	ll final=INF;
	ll lastd=0;
	for (ll i=0;i<m;i++) {
		ll changed=vd[i]-lastd;
		lastd=vd[i];
		res=mulv2(res,go(changed,i-1));
		//for (ll x=0;x<n;x++) printf("%d ",res.t[x]);
		//printf(" end %d\n",i);
		ll got=canhit(res,i);
		if (got<INF) {
			chkmin(final,got+vd[i]);
		}
	}
	if (final>=INF) printf("Impossible\n");
	else printf("%d\n",final);
}