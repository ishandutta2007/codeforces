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
	string s; cin>>s;
	ll c=s[0]-'a'; ll d=s[1]-'1';
	ll ans=0;
	for (ll x=-1;x<=1;x++) for (ll y=-1;y<=1;y++) {
		if (x==0&&y==0) continue;
		ll a=c+x,b=d+y;
		if (a>=0&&a<8&&0<=b&&b<8) ans++;
	}
	cout<<ans<<endl;
}