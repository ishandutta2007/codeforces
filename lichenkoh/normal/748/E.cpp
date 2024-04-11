#include <bits/stdc++.h>
#include <cstring>
#include <assert.h>
using namespace std;
typedef int ll;
typedef pair<ll,ll> pll;
typedef long double ld;
#define PB push_back
#define MP make_pair
#define endl "\n"
const ll UNDEF = -1;
const ll INF=2e9;
template<typename T> inline bool chkmax(T &aa, T bb) { return aa < bb ? aa = bb, true : false; }
template<typename T> inline bool chkmin(T &aa, T bb) { return aa > bb ? aa = bb, true : false; }
template<class T> T extgcd(T a, T b, T& x, T& y) { for (T u = y = 1, v = x = 0; a;) { T q = b / a; swap(x -= q * u, u); swap(y -= q * v, v); swap(b -= q * a, a); } return b; }
template<class T> T mod_inv(T a, T m) { T x, y; extgcd(a, m, x, y); return (m + x % m) % m; }
const ll mn=1e6+2;
const ll mx=1e7+2;
ll n,k;
ll a[mn];
ll dp[mx];
void init(ll imid) {
	for (ll x=0;x<imid;x++) dp[x]=0;
	dp[imid]=1;
	for (ll x=imid+1;x<mx;x++) {
		dp[x]=max(dp[x-1],dp[x/2]+dp[(x+1)/2]);
	}
}
bool solve(ll imid) {
	init(imid);
	long long have=0;
	for (ll i=n-1;i>=0;i--) {
		ll x=a[i];
		//printf("imid:%d x:%d gets dp:%d k:%d\n",imid,x,dp[x],k);
		have+=dp[x];
		if (have>=k) return true;
	}
	return false;
}
int main() {
	scanf("%d%d",&n,&k);
	for (ll i=0;i<n;i++) scanf("%d",a+i);
	sort(a,a+n);
	long long sum=0; for (ll i=0;i<n;i++) sum+=a[i];
	if (sum<k) {
		printf("-1\n");
		return 0;
	}
	ll imin=1,imax=mx;
	while(imin<imax) {
		ll imid=imin+(imax-imin)/2;
		if (solve(imid)) imin=imid+1;
		else imax=imid;
	}
	printf("%d\n",imin-1);
}