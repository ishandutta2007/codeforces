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
	ios_base::sync_with_stdio(false); cin.tie(0);
	map<ll,ll> h;
	ll t; cin>>t;
	for (ll jj=0;jj<t;jj++) {
		char c; cin>>c; ll x; cin>>x;
		if (c=='+'||c=='-') {
			ll y=0;
			for (ll k=0;k<19;k++) {
				y*=2;
				y+=(x%10)%2;
				x/=10;
			}
			if (c=='+') h[y]++;
			else h[y]--;
		}
		else {
			ll y=0;
			for (ll k=0;k<19;k++) {
				y*=2;
				y+=(x%10)%2;
				x/=10;
			}
			auto it=h.find(y);
			if (it==h.end()) cout<<0<<endl;
			else cout<<it->second<<endl;
		}
	}
}