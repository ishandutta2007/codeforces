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
const ll INF=1LL<<60LL;
template<typename T> inline bool chkmax(T &aa, T bb) { return aa < bb ? aa = bb, true : false; }
template<typename T> inline bool chkmin(T &aa, T bb) { return aa > bb ? aa = bb, true : false; }
const ll MAXN=1e5+4;
ll a[MAXN];
int main() {
	ios_base::sync_with_stdio(false);
	ll n; scanf("%d",&n);
	for (ll i=0;i<n;i++) scanf("%d",&a[i]);
	ll ans=1;
	ll v=1;
	for (ll i=1;i<n;i++) {
		if (a[i]>a[i-1]) v++;
		else v=1;
		chkmax(ans,v);
	}
	chkmax(ans,v);
	printf("%d\n",ans);
}