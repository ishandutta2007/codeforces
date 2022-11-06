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
template<typename T> inline bool chkmax(T &aa, T bb) { return aa < bb ? aa = bb, true : false; }
template<typename T> inline bool chkmin(T &aa, T bb) { return aa > bb ? aa = bb, true : false; }
const ll MAXN=100000+8;
vector<ll> g[MAXN];
bool seen[MAXN];
ll col[MAXN];
bool ok=true;
void dfs(ll x, ll c) {
	if (seen[x]) {
		if (col[x]!=c) ok=false;
		return;
	}
	seen[x]=true;
	col[x]=c;
	for (auto &w:g[x]) {
		dfs(w,c^1);
		if (!ok) {
			return;
		}
	}
}
int main() {
	ios_base::sync_with_stdio(false);
	ll n,m; scanf("%d %d",&n,&m);
	for (ll i=0;i<m;i++) {
		ll x,y; scanf("%d %d",&x,&y);
		g[x].PB(y);
		g[y].PB(x);
	}
	for (ll x=0;x<=n;x++) {
		seen[x]=false; col[x]=-1;
	}
	for (ll x=1;x<=n;x++) {
		if (!seen[x]) dfs(x,0);
	}
	if (!ok) {
		printf("-1\n");
		return 0;
	}
	vector<ll> ans[2];
	for (ll x=1;x<=n;x++) {
		if (col[x]==0||col[x]==1) {
			ans[col[x]].PB(x);
		}
	}
	for (ll k=0;k<2;k++){
		printf("%d\n",ans[k].size());
		for (auto &w:ans[k]) printf("%d ",w);
		printf("\n");
	}
}