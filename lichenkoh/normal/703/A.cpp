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
	ll n; cin>>n;
	ll a=0,b=0;
	for (ll i=0;i<n;i++) {
		ll x,y; cin>>x>>y;
		if (x>y) a++;
		else if (x<y) b++;
	}
	if (a>b) cout<<"Mishka"<<endl;
	else if (a<b) cout<<"Chris"<<endl;
	else cout<<"Friendship is magic!^^"<<endl;
}