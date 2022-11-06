#include <iostream>
#include <assert.h>
using namespace std;
typedef long long ll;
typedef long double ld;
#define PB push_back
#define MP make_pair
#define MOD 1000000007LL
#define endl "\n"
const ll UNDEF = -1;
template<typename T> inline bool chkmax(T &aa, T bb) { return aa < bb ? aa = bb, true : false; }
template<typename T> inline bool chkmin(T &aa, T bb) { return aa > bb ? aa = bb, true : false; }
int main() {
	ios_base::sync_with_stdio(false);
	ll n; cin>>n;
	ll but=0;
	for (ll i=0;i<n;i++) {
		ll x; cin>>x; but+=x;
	}
	bool ok;
	if (n>1) ok=(but==n-1);
	else ok=(but==1);
	if (ok) cout<<"YES"<<endl;
	else cout<<"NO"<<endl;
	
}