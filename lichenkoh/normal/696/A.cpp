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
const ll INF=1LL<<60LL;
template<typename T> inline bool chkmax(T &aa, T bb) { return aa < bb ? aa = bb, true : false; }
template<typename T> inline bool chkmin(T &aa, T bb) { return aa > bb ? aa = bb, true : false; }
vector<ll> getp(ll x) {
	vector<ll> ans;
	while(x>0) {
		ans.PB(x);
		x/=2;
	}
	return ans;
}
int main() {
	ios_base::sync_with_stdio(false);
	ll q; cin>>q;
	map<ll,ll> h;
	for (ll ii=0;ii<q;ii++) {
		ll typ; cin>>typ;
		if (typ==1) {
			ll x,y,c; cin>>x>>y>>c;
			vector<ll> px=getp(x);
			vector<ll> py=getp(y);
			ll got=0;
			for (auto &wx:px) for (auto &wy:py) if (wx==wy) {chkmax(got,wx);}
			for (auto &wx:px) {
				if (wx==got) break;
				h[wx]+=c;
			}
			for (auto &wy:py) {
				if (wy==got) break;
				h[wy]+=c;
			}
		}
		else {
			ll x,y; cin>>x>>y;
			vector<ll> px=getp(x);
			vector<ll> py=getp(y);
			ll got=0;
			for (auto &wx:px) for (auto &wy:py) if (wx==wy) {chkmax(got,wx);}
			ll ans=0;
			for (auto &wx:px) {
				if (wx==got) break;
				auto it=h.find(wx);
				if (it!=h.end()) ans+=it->second;
			}
			for (auto &wx:py) {
				if (wx==got) break;
				auto it=h.find(wx);
				if (it!=h.end()) ans+=it->second;
			}
			cout<<ans<<endl;
		}
	}
}