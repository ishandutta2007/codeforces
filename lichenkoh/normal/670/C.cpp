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
const ll MAXN=200000+8;
ll a[MAXN],b[MAXN],c[MAXN];
int main() {
	ios_base::sync_with_stdio(false);
	ll n; scanf("%d",&n);
	for (ll i=0;i<n;i++) scanf("%d",&a[i]);
	ll m;scanf("%d",&m);
	for (ll i=0;i<m;i++) scanf("%d",&b[i]);
	for (ll i=0;i<m;i++) scanf("%d",&c[i]);
	map<ll,ll> h;
	for (ll i=0;i<n;i++) {
		h[a[i]]++;
	}
	pair<pair<ll,ll>,ll> best=MP(MP(-1,-1),-1);
	for (ll i=0;i<m;i++) {
		pair<pair<ll,ll>,ll> cand=MP(MP(h[b[i]],h[c[i]]),i);
		best=max(best,cand);
	}
	printf("%d\n",best.second+1);
}