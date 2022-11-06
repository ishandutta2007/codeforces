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
const ll INF=1e9;
template<typename T> inline bool chkmax(T &aa, T bb) { return aa < bb ? aa = bb, true : false; }
template<typename T> inline bool chkmin(T &aa, T bb) { return aa > bb ? aa = bb, true : false; }
typedef pair<ll,ll> pll;
typedef vector<ll> vll;
const ll mn=2e5+4;
ll vc[mn];
vector<ll> g[mn];
void dfs(ll x, ll p) {
	ll col=1;
	while (col==vc[p]||col==vc[x]) col++;
	for (auto &y:g[x]) {
		if (y==p) continue;
		while (col==vc[p]||col==vc[x]) col++;
		//printf("%d->%d %d\n",x,y,col);
		vc[y]=col;
		dfs(y,x);
		col++;
	}
}
int main()
{
	ios_base::sync_with_stdio(false); cin.tie(0);
	ll n; scanf("%d",&n);
	for (ll i=0;i<n-1;i++) {
		ll x,y; scanf("%d%d",&x,&y);
		g[x].PB(y);
		g[y].PB(x);
	}
	vc[1]=1;
	dfs(1,0);
	ll ans=1;
	for (ll x=1;x<=n;x++) chkmax(ans,vc[x]);
	printf("%d\n",ans);
	for (ll x=1;x<=n;x++) printf("%d ",vc[x]);
	printf("\n");
}