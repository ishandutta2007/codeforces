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
const ll INF=1e18;
template<typename T> inline bool chkmax(T &aa, T bb) { return aa < bb ? aa = bb, true : false; }
template<typename T> inline bool chkmin(T &aa, T bb) { return aa > bb ? aa = bb, true : false; }
ld dist(ld ax,ld ay,ld bx,ld by) {
	ld dx=(bx-ax);
	ld dy=(by-ay);
	return sqrt(dx*dx+dy*dy);
}
int main() {
	ios_base::sync_with_stdio(false);
	ll a,b,n;
	cin>>a>>b>>n;
	ld ans=5e18;
	for (ll i=0;i<n;i++) {
		ll x,y,v; cin>>x>>y>>v;
		chkmin(ans,dist(a,b,x,y)/v);
	}
	cout<<fixed<<setprecision(10);
	cout<<ans<<endl;
}