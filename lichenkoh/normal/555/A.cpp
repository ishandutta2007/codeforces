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

int main() 
{
	ios_base::sync_with_stdio(false); cin.tie(0);
	ll n,k;
	scanf("%d%d",&n,&k);
	ll disas=0;
	ll best=0;
	for (ll i=0;i<k;i++) {
		ll m; scanf("%d",&m);
		disas+=m-1;
		bool ok=true;
		for (ll j=1;j<=m;j++) {
			ll x; scanf("%d",&x);
			if (x==j) {
				best++;
			}
			else ok=false;
		}
	}
	best--;
	chkmax(best,0);
	ll ans=max(0,disas+n-1-2*best);
	printf("%d\n",ans);
}