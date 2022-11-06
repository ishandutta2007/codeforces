#include <bits/stdc++.h>
#include <assert.h>
using namespace std;
typedef int ll;
typedef long double ld;
#define PB push_back
#define MP make_pair
#define MOD 1000000007LL
#define endl "\n"
const ll UNDEF = -1;
const ll INF=1e9;
template<typename T> inline bool chkmax(T &aa, T bb) { return aa < bb ? aa = bb, true : false; }
template<typename T> inline bool chkmin(T &aa, T bb) { return aa > bb ? aa = bb, true : false; }
typedef pair<ll,ll> pll;
typedef vector<ll> vll;
#define fst first
#define snd second
const ll mn=1e6+2;
map<ll,vector<ll> > invf;
ll f[mn];
ll g[mn],h[mn];
int main()
{
	ios_base::sync_with_stdio(false); cin.tie(0);
	ll n; scanf("%d",&n);
	for (ll x=1;x<=n;x++) {
		scanf("%d",&f[x]);
		invf[f[x]].PB(x);
	}
	ll mid=1;
	for (auto &rgot:invf) {
		ll r=rgot.fst;
		h[mid]=r;
		for (auto &inv:rgot.snd) {
			g[inv]=mid;
		}
		mid++;
	}
	ll m=mid-1;

	/*printf("%d\n",m);
	for (ll x=1;x<=n;x++) printf("%d ",g[x]);
	printf("\n");
	for (ll x=1;x<=m;x++) printf("%d ",h[x]);
	printf("\n");*/

	bool ok=true;
	for (ll x=1;x<=m;x++) {
		if (g[h[x]]!=x) {ok=false; break;}
	}
	for (ll x=1;x<=n;x++) {
		if (h[g[x]]!=f[x]) {ok=false; break;}
	}
	if (!ok) {
		printf("-1\n");
		return 0;
	}
	printf("%d\n",m);
	for (ll x=1;x<=n;x++) printf("%d ",g[x]);
	printf("\n");
	for (ll x=1;x<=m;x++) printf("%d ",h[x]);
	printf("\n");
}