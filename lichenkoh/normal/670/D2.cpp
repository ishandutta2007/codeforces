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
const ll MAXN=100000+8;
ll a[MAXN],b[MAXN];
int main() {
	ios_base::sync_with_stdio(false);
	ll n,k; scanf("%I64d %I64d",&n,&k);
	for (ll i=0;i<n;i++) scanf("%I64d",&a[i]);
	for (ll i=0;i<n;i++) scanf("%I64d",&b[i]);
	ll imin=0,imax=(5e9)+1;
	while(imin<imax) {
		ll imid=imin+(imax-imin)/2;
		ll left=k;
		for (ll i=0;i<n;i++) {
			ll need=imid*a[i];
			ll sub=max(0LL,need-b[i]);
			left-=sub;
			if (left<0) break;
		}
		if (left>=0) imin=imid+1;
		else imax=imid;
	}
	printf("%I64d\n",imin-1);
}