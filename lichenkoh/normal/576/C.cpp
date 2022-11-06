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
vector<pll> p[1004];
const ll mn=1e6+4;
vll ans;
int main() 
{
	ios_base::sync_with_stdio(false); cin.tie(0);
	ll n; scanf("%d",&n);
	for (ll i=1;i<=n;i++) {
		ll x,y; scanf("%d%d",&x,&y);
		--x;
		ll block=x/1000;
		p[block].PB(MP(y,i));
	}
	for (ll block=0;block<1002;block++) {
		sort(p[block].begin(),p[block].end());
		ll bsz=p[block].size();
		if (block&1) {
			for (ll i=0;i<bsz;i++) {
				ans.PB(p[block][i].snd);
			}
		}
		else {
			for (ll i=bsz-1;i>=0;i--) {
				ans.PB(p[block][i].snd);
			}
		}
	}
	for (auto &w:ans) printf("%d ",w);
	printf("\n");
}