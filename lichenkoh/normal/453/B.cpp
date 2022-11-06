#include <stdio.h>
#include <assert.h>
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;
typedef int ll;
typedef long double ld;
#define PB push_back
#define MP make_pair
#define MOD 1000000007LL
#define endl "\n"
template<typename T> inline bool chkmax(T &a, T b) { return a < b ? a = b, true : false; }
template<typename T> inline bool chkmin(T &a, T b) { return a > b ? a = b, true : false; }
typedef pair<ll,ll> pll;
ll a[104];
const ll mp=17;
pll f[101][1<<mp];
vector<ll> primes;
const ll INF=1e18;
const ll my=60;
ll g[104];
int main() {
	for (ll x=2;x<=my;x++) {
		bool ok=true;
		for (ll y=2;y<x;y++) {
			if (x%y==0) ok=false;
		}
		if(ok) primes.PB(x);
	}
	assert(primes.size()<=mp);
	ll psz=primes.size();
	ll n; scanf("%d",&n);
	for (ll i=0;i<n;i++) scanf("%d",&a[i]);
	ll zlim=1ll<<psz;
	for (ll x=0;x<=n;x++) for (ll y=0;y<zlim;y++) {
		f[x][y]=MP(INF,INF);
	}
	for (ll y=1;y<=my;y++) {
		ll msk=0;
		for (ll k=0;k<psz;k++) {
			if (y%primes[k]==0) msk|=1ll<<k;
		}
		g[y]=msk;
	}
	f[0][0]=MP(0ll,0ll);
	for (ll x=0;x<n;x++) {
		for (ll z=0;z<zlim;z++) {
			ll v=f[x][z].first;
			if (v<INF) {
				for (ll y=1;y<=my;y++) {
					if (z&g[y]) continue;
					ll nz=z|g[y];
					pll nv=MP(v+abs(y-a[x]), y);
					chkmin(f[x+1][nz],nv);
				}
			}
		}
	}
	pair<pll,ll> abc=MP(MP(INF,INF),INF);
	for (ll z=0;z<zlim;z++) {
		chkmin(abc,MP(f[n][z],z));
	}
	ll z=abc.second;
	vector<ll> res;
	for (ll x=n;x>=1;x--) {
		ll y=f[x][z].second;
		res.PB(y);
		z^=g[y];
	}
	reverse(res.begin(),res.end());
	for (auto &w:res) printf("%d ",w);
	printf("\n");
}