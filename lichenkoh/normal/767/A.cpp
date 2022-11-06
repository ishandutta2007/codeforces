#include <bits/stdc++.h>
#include <assert.h>
using namespace std;
typedef long long ll;
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
const ll mn=1e5+4;
ll daytonum[mn];
ll numtoday[mn];
vll ans[mn];
int main()
{
	ios_base::sync_with_stdio(false); cin.tie(0);
	ll n; cin>>n;
	for (ll i=1;i<=n;i++) {cin>>daytonum[i];}
	for (ll i=1;i<=n;i++) numtoday[daytonum[i]]=i;
	ll d=0;
	for (ll num=n;num>=1;num--) {
		chkmax(d,numtoday[num]);
		ans[d].PB(num);
	}
	for (ll i=1;i<=n;i++) {
		for ( auto &w:ans[i]) printf("%d ",w);
		printf("\n");
	}
}