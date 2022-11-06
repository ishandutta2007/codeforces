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
const ll MAXN=1e5+8;
vector<ll> g[MAXN];
ll sz[MAXN];
ll ch[MAXN];
ll getsz(ll x, ll p) {
	ll ans=1;
	ll child=0;
	for (auto &w:g[x]) {
		ans+=getsz(w,x);
		child++;
	}
	ch[x]=child;
	sz[x]=ans;
	return ans;
}
ld f[MAXN];
void getf(ll x, ll p) {
	if (x==1) {
		f[x]=1;
	}
	else {
		ld sumsz=sz[p]-sz[x]-1;
		ll chp=ch[p];
		assert(chp>0);
		ld ans=1+f[p]+(sumsz)/2;
		f[x]=ans;
	}
	for (auto &w:g[x]) {
		getf(w,x);
	}
}
int main() {
	int _n; scanf("%d",&_n); ll n=_n;
	for (ll x=2;x<=n;x++) {
		int _y; scanf("%d",&_y); ll y=_y;
		g[y].PB(x);
	}
	getsz(1,-1);
	getf(1,-1);
	for (ll x=1;x<=n;x++) {
		printf("%.8f ", (double)f[x]);
	}
	printf("\n");
}