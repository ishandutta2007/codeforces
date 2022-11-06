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
const ll INF=1e9+4;
template<typename T> inline bool chkmax(T &aa, T bb) { return aa < bb ? aa = bb, true : false; }
template<typename T> inline bool chkmin(T &aa, T bb) { return aa > bb ? aa = bb, true : false; }
typedef pair<ll,ll> pll;
typedef vector<ll> vll;
const ll mn=2e5+4;
bool seen[mn];
vector<ll> g[mn];
vector<ll> vans;
void dfs(ll x) {
	seen[x]=true;
	vans.PB(x);
	for (auto &y:g[x]) {
		if (!seen[y]) {
			dfs(y);
			vans.PB(x);
		}
	}
}
int main()
{
	ios_base::sync_with_stdio(false); cin.tie(0);
	memset(seen,0,sizeof seen);
	ll n,m,k; scanf("%d%d%d",&n,&m,&k);
	for (ll i=0;i<m;i++) {
		ll x,y; scanf("%d %d",&x,&y);
		g[x].PB(y); g[y].PB(x);
	}
	dfs(1);
	ll len=((2*n)+k-1)/k;
	ll asz=vans.size();
	for (ll c=0;c<k;c++) {
		ll l=c*len, r=min(((c+1)*len)-1,asz-1);
		if (l<=r) {
			printf("%d ",r-l+1);
			for (ll x=l;x<=r;x++) {
				printf("%d ",vans[x]);
			}
			printf("\n");
		}
		else {
			printf("1 %d\n",vans[0]);
		}
	}
}