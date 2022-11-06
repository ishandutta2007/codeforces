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
const int mn=2e5+4;
ll segn;
void modify(int l, int r, int value, ll *t) {
	ll n=segn;
	++r;
  for (l += n, r += n; l < r; l >>= 1, r >>= 1) {
    if (l&1) chkmax(t[l++], value);
    if (r&1) chkmax(t[--r], value);
  }
}

int query(int p, ll *t) {
	ll n=segn;
  int res = 0;
  for (p += n; p > 0; p >>= 1) chkmax(res, t[p]);
  return res;
}
vll vb;
ll lower_bound_idx(ll x) {
	ll imin=0,imax=vb.size();
	while(imin<imax) {
		ll imid=(imin+imax)/2;
		if (vb[imid]<x) imin=imid+1;
		else imax=imid;
	}
	return imin;
}
ll upper_bound_idx(ll x) {
	ll idx=lower_bound_idx(x);
	if (vb[idx]>x) --idx;
	return idx;
}
void doins(ll l, ll r, ll val, ll *t) {
	//printf("%d->%d gets %d\n",l,r,val);
	if (l>r) return;
	ll li=lower_bound_idx(l),ri=upper_bound_idx(r);
	chkmax(li,0);chkmax(ri,0);
	chkmin(li,segn);chkmin(ri,segn);
	if (li<=ri) {
		//printf("Index %d->%d gets %d\n",vb[li],vb[ri],val);
		modify(li,ri,val,t);
	}
}
int segup[4*mn];
int segleft[4*mn];

int vx[mn],vy[mn]; char vc[mn];
set<ll> doneup,doneleft;
int main()
{
	ios_base::sync_with_stdio(false); cin.tie(0);
	ll n,q; scanf("%d %d\n",&n,&q);	
	for (ll ii=0;ii<q;ii++) {
		scanf("%d %d %c\n",&vx[ii],&vy[ii],&vc[ii]);
	}
	set<ll> sx;
	for (ll i=0;i<q;i++) {
		sx.insert(vx[i]);
		sx.insert(vy[i]);
	}
	for (auto &w:sx) vb.PB(w);
	segn=vb.size();
	for (ll i=0;i<q;i++) {
		if (vc[i]=='U') {
			ll x=vx[i];
			if (doneup.find(x)!=doneup.end()) printf("0\n");
			else {
				doneup.insert(x);
				ll bx=lower_bound_idx(x);
				//printf("Query:%d idx:%d\n",x,bx);
				ll ylo=query(bx, segup)+1;
				ll yhi=vy[i];
				printf("%d\n",max(0,yhi-ylo+1));
				doins(ylo,yhi,x,segleft);
			}
		}
		else {
			ll y=vy[i];
			ll x=vx[i];
			if (doneleft.find(x)!=doneleft.end()) printf("0\n");
			else {
				doneleft.insert(x);
				ll by=lower_bound_idx(y);
				//printf("Query:%d idx:%d\n",y,by);
				ll xlo=query(by, segleft)+1;
				ll xhi=vx[i];
				printf("%d\n",max(0,xhi-xlo+1));
				doins(xlo,xhi,y,segup);
			}
		}
	}
}