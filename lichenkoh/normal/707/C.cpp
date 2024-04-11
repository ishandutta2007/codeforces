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
const ll lim=1e9+1;
int main() {
	ios_base::sync_with_stdio(false);
	ll x; cin>>x;
	if (x<=2) {
		cout<<-1<<endl;
	}
	else if (x%2==0) { // Handle b case
		ll m=x/2;
		cout<<m*m-1<<" "<<m*m+1<<endl;
	}
	else {
		ll x2=x*x;
		ll k=x2/2;
		cout<<k<<" "<<k+1<<endl;
	}
}