#include <bits/stdc++.h>
#include <assert.h>
using namespace std;
typedef long long ll;
typedef double ld;
#define PB push_back
#define MP make_pair
#define MOD 1000000007LL
#define endl "\n"
template<typename T> inline bool chkmax(T &a, T b) { return a < b ? a = b, true : false; }
template<typename T> inline bool chkmin(T &a, T b) { return a > b ? a = b, true : false; }
typedef pair<ll,ll> pll;
const ll mn=20;
ld a[mn][mn];
ll n;
const ll mz=1<<20;
ld dp[mz][mn];
ld solve(ll z, ll x) {
	if (dp[z][x]>=-1) return dp[z][x];
	ld best=0;
	if (z==(1<<(n-1))-1) {
		return a[0][x];
	}
	for (ll y=1;y<n;y++) {
		ll msk=1<<(y-1);
		if ((z&msk)==0) {
			ll nz=z|msk;
			ld cand=solve(nz,x)*a[x][y]+solve(nz,y)*a[y][x];
			chkmax(best,cand);
		}
	}
	//printf("z:%lld x:%lld ans:%f\n",z,x,best);
	return dp[z][x]=best;
}
int main() {
	cin>>n;
	for (ll x=0;x<n;x++) for (ll y=0;y<n;y++) cin>>a[x][y];
	if (n==1) {
		printf("%.8f\n",1.0);
		return 0;
	}
	for (ll z=0;z<mz;z++) for (ll x=0;x<mn;x++) dp[z][x]=-2;
	ld ans=0;
	for (ll x=1;x<n;x++) {
		chkmax(ans, solve(1<<(x-1),x));
	}
	printf("%.8f\n",ans);
}