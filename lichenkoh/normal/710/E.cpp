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
const ll INF=2e18;
template<typename T> inline bool chkmax(T &aa, T bb) { return aa < bb ? aa = bb, true : false; }
template<typename T> inline bool chkmin(T &aa, T bb) { return aa > bb ? aa = bb, true : false; }
typedef pair<ll,ll> pll;
ll x,y;
ll solve(ll n) {
	if (n==0) return 0;
	else if (n==1) return x;
	else if (n%2==0) {
		ll costx=(n/2)*x;
		ll costy=y;
		ll ans= solve(n/2)+min(costx,costy);
		//printf("n:%lld ans:%lld\n",n,ans);
		return ans;
	}
	else {
		ll ans= min(solve(n+1),solve(n-1))+x;
		//printf("n:%lld ans:%lld\n",n,ans);
		return ans;
	}
}
int main() {
	ios_base::sync_with_stdio(false);
	ll n; cin>>n>>x>>y;
	cout<<solve(n)<<endl;
}