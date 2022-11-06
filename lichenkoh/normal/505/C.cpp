#include <bits/stdc++.h>
#include <assert.h>
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
const ll mn=30000+4;
const ll smn=3*173+4;
const ll ml=2*smn;
//map<ll,ll> f[mn];
ll f[mn][ml];
ll gem[mn];
ll n,d;
ll atr(ll a) {
	return a-smn+d;
}
ll rta(ll r) {
	return r-d+smn;
}
int main() {
	scanf("%d%d",&n,&d);
	memset(gem,0,sizeof gem);
	for (ll i=0;i<n;i++) {
		ll p; scanf("%d",&p);
		gem[p]++;
	}
	memset(f,-1,sizeof f);
	ll base=smn+d;
	f[d][rta(d)]=gem[0]+gem[d];
	ll ans=0;
	for (ll x=0;x<mn;x++) {
		for (ll a=0;a<ml;a++) {
			ll ol=atr(a); ll v=f[x][a];
			if (v==-1) continue;
			chkmax(ans,v);
			for (ll l=max(1,ol-1);l<=ol+1;l++) {
				ll y=x+l;
				if (y<mn) {
					//if(gem[y])printf("x:%d y:%d. ol:%d l:%d %d+%d\n",x,y,ol,l,v,gem[y]);
					chkmax(f[y][rta(l)],v+gem[y]);
				}
			}
		}
	}
	printf("%d\n",ans);
}