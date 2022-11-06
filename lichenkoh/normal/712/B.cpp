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
	string s; cin>>s;
	ll n=s.length();
	if (n&1) {
		cout<<-1<<endl;
	}
	else {
		ll u=0,r=0;
		for (auto &w:s) {
			if (w=='U')u++;
			else if (w=='D')u--;
			else if (w=='R')r++;
			else if (w=='L')r--;
		}
		u=abs(u);r=abs(r);
		ll ans=u/2+r/2;
		if (u&1) ans++;
		cout<<ans<<endl;
	}
}