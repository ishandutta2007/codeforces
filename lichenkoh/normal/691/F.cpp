#include <vector>
#include <iostream>
#include <algorithm>
#include <assert.h>
using namespace std;
typedef long long ll;
typedef long double ld;
#define PB push_back
#define MP make_pair
#define MOD 1000000007LL
#define endl "\n"
const ll UNDEF = -1;
const ll MAXQ=3*1000*1000;
ll h[MAXQ+1];
ll res[MAXQ+1];

int main() {
	ios_base::sync_with_stdio(false);
	int _n; scanf("%d",&_n); ll n=_n;
	for (ll i=0;i<=MAXQ;i++) h[i]=0;
	for (ll i=0;i<n;i++) {
		int x;
		scanf("%d",&x);
		h[x]++;
	}
	for (ll i=0;i<=MAXQ;i++) res[i]=0;
	for (ll l=1;l<=MAXQ;l++) {
		ll r=MAXQ/l;
		ll curr=h[l];
		if (l<=r) res[(l*l)+1]+=curr*(curr-1);
		for (ll x=l+1;x<=r;x++) {
			res[(l*x)+1]+=2*curr*h[x];
		}
	}
	for (ll i=1;i<=MAXQ;i++) {
		res[i]+=res[i-1];
	}
	int m; scanf("%d",&m);
	ll all=n*(n-1);
	for (ll i=0;i<m;i++) {
		int q; scanf("%d",&q);
		ll ans=all-res[q];
		printf("%I64d\n",ans);
	}
}