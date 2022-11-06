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
template<typename T> inline bool chkmax(T &a, T b) { return a < b ? a = b, true : false; }
template<typename T> inline bool chkmin(T &a, T b) { return a > b ? a = b, true : false; }
const ll INF=3e18;
const ll MAXL=8000+4;
const ll MAXN=1000+4;
ll a[MAXN];
pair<ll,ll> g[MAXN][MAXL];
int h[MAXN][MAXL];
vector<ll> dv;
ll dvsz;
ll trans[MAXN][MAXL];
ll getdi(ll x) {
	ll imin=0,imax=dvsz;
	while(imin<imax) {
		ll imid=(imin+imax)/2;
		if (dv[imid]<x) imin=imid+1;
		else imax=imid;
	}
	return imin;
}

ll hasd[MAXL];
int main() {
	ll n,k; scanf("%I64d %I64d",&n,&k);
	for (ll i=0;i<n;i++) {
		scanf("%I64d",&a[i]);
	}
	if (k==1) {
		pair<ll,ll> ans=MP(a[0],0LL);
		for (ll i=1;i<n;i++) {
			chkmin(ans,MP(a[i],i));
		}
		printf("1\n%I64d\n",ans.second+1);
		return 0;
	}
	set<ll> s;
	ll dlim=sqrt(k)+1;
	for (ll d=1;d<=dlim;d++) {
		if (0==k%d) {
			s.insert(d); s.insert(k/d);
		}
	}
	for (auto &w:s) {
		dv.PB(w);
		//printf("%I64d ",w);
	}
	dvsz=dv.size();
	for (ll x=1;x<dvsz;x++) hasd[x]=UNDEF;
	vector<ll> pv;
	for (ll x=1;x<dvsz;x++) {
		if (hasd[x]!=UNDEF) continue;
		pv.PB(x);
		ll v=dv[x];
		for (ll y=x+1;y<dvsz;y++) {
			if (hasd[y]!=UNDEF) continue;
			ll w=dv[y];
			if (w%v==0) {
				hasd[y]=x;
			}
		}
	}
	ll pvsz=pv.size();
	for (ll x=0;x<n;x++) {
		for (ll l=0;l<dvsz;l++) {
			trans[x][l]=1;
		}
	}
	for (ll l=1;l<dvsz;l++) {
		ll hd=hasd[l];
		if (hd==UNDEF) hd=l;
		ll p=dv[hd];
		ll tmpl=dv[l];
		ll r=getdi(tmpl/p);
		ll pe=1;
		while(tmpl%p==0) {
			tmpl/=p;
			pe*=p;
		}
		//printf("%I64d->%I64d: p:%I64d pe:%I64d\n",dv[r],dv[l],p,pe);
		for (ll x=0;x<n;x++) {
			ll got=trans[x][r];
			if (a[x]%pe==0) {
				//printf("A: a[x]:%I64d gets %I64d\n",a[x],got*p);
				trans[x][l]=got*p;
			}
			else {
				//printf("B: a[x]:%I64d gets %I64d\n",a[x],got);
				trans[x][l]=got;
			}
			//assert(trans[x][l]==__gcd(dv[l],a[x]));
		}
	}
	for (ll x=0;x<n;x++) for (ll l=0;l<dvsz;l++) {
		trans[x][l]=getdi(dv[l]/trans[x][l]);
	}
	for (ll y=0;y<dvsz;y++) g[n][y]=MP(INF,INF);
	g[n][0]=MP(0LL,0LL);
	for (ll x=n-1;x>=0;x--) for (ll y=0;y<dvsz;y++) {
		pair<ll,ll> av=g[x+1][y];
		ll ny=trans[x][y];
		pair<ll,ll> bv=g[x+1][ny];
		bv.first++;
		bv.second+=a[x];
		if (av<bv) {
			g[x][y]=av;
			h[x][y]=y;
		}
		else {
			g[x][y]=bv;
			h[x][y]=ny;
		}
	}
	vector<ll> ans;
	{
		ll x=0,y=dvsz-1;
		if (g[x][y].first==INF) {
			printf("-1\n"); return 0;
		}
		while(1) {
			//printf("Getting ans x:%I64d y:%I64d\n",x,y);
			if (x==n&&y==0) break;
			ll ny=h[x][y];
			if (ny!=y) {
				ans.PB(x);
			}
			y=ny;
			x++;
		}
	}
	ll asz=ans.size();
	/*if (asz!=oldans) {
		printf("%I64d != %I64d (oldans)\n",asz,oldans);
		assert(false);
	}*/
	printf("%I64d\n",asz);
	for (auto &w:ans) {
		printf("%I64d ",w+1);
	}
	printf("\n");
}