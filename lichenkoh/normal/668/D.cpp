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
const ll MAXN=100000+8;
template<typename T> inline bool chkmax(T &a, T b) { return a < b ? a = b, true : false; }
template<typename T> inline bool chkmin(T &a, T b) { return a > b ? a = b, true : false; }
// T[i] += value
void add(ll *t, ll i, ll value, ll maxn) {
  for (; i < maxn; i |= i + 1)
    t[i] += value;
}

// sum[0..i]
ll sum(ll *t, ll i) {
  ll res = 0;
  for (; i >= 0; i = (i & (i + 1)) - 1)
    res += t[i];
  return res;
}
ll ga[MAXN],gt[MAXN],gx[MAXN];
set<ll> sx;
ll ssx[MAXN];
set<ll> st[MAXN];
vector<ll>sst[MAXN];
ll sstsz[MAXN];
ll *gf[MAXN];
ll binsearch(ll n, ll *t, ll key) {
	ll imin=0,imax=n;
	while(imin<imax) {
		ll imid=imin+(imax-imin)/2;
		if (t[imid]<key) imin=imid+1;
		else imax=imid;
	}
	return imin;
}
ll binsearchv(ll n, vector<ll> &t, ll key) {
	ll imin=0,imax=n;
	while(imin<imax) {
		ll imid=imin+(imax-imin)/2;
		if (t[imid]<key) imin=imid+1;
		else imax=imid;
	}
	return imin;
}

int main() {
	ll n; scanf("%d",&n);
	for (ll i=0;i<n;i++) {
		ll ai,ti,xi; scanf("%d %d %d",&ai,&ti,&xi);
		ga[i]=ai; gt[i]=ti; gx[i]=xi;
		sx.insert(xi);
	}
	ll sxn=0;
	for (auto &w:sx) {
		ssx[sxn]=w;
		sxn++;
	}
	for (ll i=0;i<n;i++) {
		gx[i]=binsearch(sxn,ssx,gx[i]);
	}
	for (ll i=0;i<n;i++) {
		st[gx[i]].insert(gt[i]);
	}
	for (ll k=0;k<sxn;k++) {
		for (auto &w: st[k]) {
			sst[k].PB(w);
		}
		sstsz[k]=sst[k].size();
	}
	for (ll i=0;i<n;i++) {
		ll k=gx[i];
		//printf("%d %d: %d\n",sstsz[k],gt[i],binsearchv(sstsz[k],sst[k],gt[i]));
		gt[i]=binsearchv(sstsz[k],sst[k],gt[i]);
	}
	for (ll k=0;k<sxn;k++) {
		gf[k] = new ll[sstsz[k]+2];
		//gf[k]=(ll*)malloc((sstsz[k]+2)*sizeof(ll));
		for (ll j=0;j<sstsz[k]+1;j++) {
			gf[k][j]=0;
		}
	}
	for (ll i=0;i<n;i++) {
		ll k=gx[i];
		ll t=gt[i];
		if (ga[i]==1) {
			add(gf[k],t,1,sstsz[k]);
		}
		else if (ga[i]==2) {
			add(gf[k],t,-1,sstsz[k]);
		}
		else {
			ll ans=sum(gf[k],t);
			printf("%d\n",ans);
		}
	}
}