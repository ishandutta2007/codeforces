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
	ll n,m; cin>>n>>m;
	bool bw=true;
	for (ll i=0;i<n;i++) {
		for (ll j=0;j<m;j++) {
			char c;cin>>c;
			if (!(c=='W'||c=='B'||c=='G')) {
				bw=false;
			}
		}
	}
	if (bw) {
		printf("#Black&White\n");
	}
	else printf("#Color\n");
}