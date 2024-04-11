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
int main() {
	ios_base::sync_with_stdio(false);
	ll x,y; cin>>x>>y;
	if (x>y) swap(x,y);
	assert(x<=y);
	ll a[3];
	for (ll k=0;k<3;k++) a[k]=x;
	ll ans=0;
	while(1) {
		pair<ll,ll> m=MP(a[0],0);
		for (ll k=1;k<3;k++) chkmin(m,MP(a[k],k));
		if (m.first==y) break;
		ll j=m.second;
		ll sum=0; for (ll k=0;k<3;k++) sum+=a[k];
		ll other=min(y,sum-a[j]-1);
		a[j]=other;
		ans++;
		//for (ll k=0;k<3;k++) cout<<a[k]<<" ";
		//cout<<endl;
	}
	cout<<ans<<endl;
}