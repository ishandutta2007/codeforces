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
const ll mn=1e5+4;
ll x[mn];
int main() {
	ios_base::sync_with_stdio(false);
	ll n; scanf("%I64d",&n);
	for (ll i=0;i<n;i++) {
		scanf("%I64d",&x[i]);
	}
	sort(x,x+n);
	x[n]=1e18;
	n++;
	ll q; scanf("%I64d",&q);
	for (ll i=0;i<q;i++) {
		ll m; scanf("%I64d",&m);
		ll imin=0,imax=n;
		while(imin<imax) {
			ll imid=(imin+imax)/2;
			if (x[imid]<=m) imin=imid+1;
			else imax=imid;
		}
		printf("%I64d\n",imin);
	}
}