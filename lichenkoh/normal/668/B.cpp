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
const ll MAXN=2000000+8;
ll ans[MAXN];
int main() {
	ios_base::sync_with_stdio(false);
	ll n,q;
	scanf("%d %d",&n,&q);
	ll p[2];
	p[0]=0; p[1]=1;
	for (ll ii=0;ii<q;ii++) {
		ll t; scanf("%d",&t);
		if (t==1) {
			ll x; scanf("%d",&x);
			for (ll i=0;i<2;i++) {
				p[i]=(p[i]+x+n)%n;
			}
		}
		else {
			for (ll i=0;i<2;i++) {
				p[i]^=1;
			}
		}
	}
	for (ll x=0;x<n;x+=2) {
		ll a=(x+p[0]+n)%n;
		ll b=(x+p[1]+n)%n;
		ans[a]=x;
		ans[b]=x+1;
	}
	for (ll x=0;x<n;x++) {
		printf("%d ",ans[x]+1);
	}
	printf("\n");
}