#include <bits/stdc++.h>
#include <assert.h>
using namespace std;
typedef int ll;
typedef long double ld;
#define PB push_back
#define MP make_pair
#define MOD 1000000007LL
#define endl "\n"
#define fst first
#define snd second
const ll UNDEF = -1;
const ll INF=1e18;
template<typename T> inline bool chkmax(T &aa, T bb) { return aa < bb ? aa = bb, true : false; }
template<typename T> inline bool chkmin(T &aa, T bb) { return aa > bb ? aa = bb, true : false; }
typedef pair<ll,ll> pll;
typedef vector<ll> vll;
const ll mn=5e5+4;
string vs[mn];
ll vslen[mn];
int main() 
{
	ios_base::sync_with_stdio(false); cin.tie(0);
	ll n; cin>>n;
	for (ll i=0;i<n;i++) {
		cin>>vs[i];
		vslen[i]=vs[i].length();
	}
	for (ll i=n-2;i>=0;i--) {
		bool is_smaller=false;
		ll largerdiff=-1;
		ll mx=min(vslen[i],vslen[i+1]);
		for (ll x=0;x<mx;x++) {
			if (vs[i][x]<vs[i+1][x]) {
				is_smaller=true; break;
			}
			else if (vs[i][x]>vs[i+1][x]) {
				largerdiff=x; break;
			}
		}
		if (is_smaller) continue;
		if (largerdiff!=-1) {
			vslen[i]=largerdiff;
		}
		chkmin(vslen[i],vslen[i+1]);
	}
	for (ll i=0;i<n;i++) {
		cout<<vs[i].substr(0,vslen[i])<<endl;
	}
}