#include <iostream>
#include <vector>
#include <algorithm>
#include <assert.h>
using namespace std;
typedef int ll;
typedef long double ld;
#define PB push_back
#define MP make_pair
#define MOD 1000000007LL
#define endl "\n"
const ll UNDEF = -1;
template<typename T> inline bool chkmax(T &a, T b) { return a < b ? a = b, true : false; }
template<typename T> inline bool chkmin(T &a, T b) { return a > b ? a = b, true : false; }
const ll MAXN=1e6+4;
int p[MAXN];
int ans[MAXN];
bool seen[MAXN];
vector<ll> g[MAXN];
vector<ll> act;
void dfs(ll x) {
	if (seen[x]) return;
	seen[x]=true;
	act.PB(x);
	for (auto &w:g[x]) {
		if(!seen[w]) dfs(w);
	}
}
int main() {
	ios_base::sync_with_stdio(false);
	int n,m; scanf("%d %d",&n,&m);
	for (ll i=0;i<n;i++) scanf("%d",&p[i]);
	for (ll i=0;i<m;i++) {
		ll x,y;
		scanf("%d %d",&x,&y); x--;y--;
		g[x].PB(y); g[y].PB(x);
	}
	for (ll x=0;x<MAXN;x++) seen[x]=false;
	for (ll x=0;x<n;x++) {
		act.clear();
		dfs(x);
		sort(act.begin(),act.end());
		vector<ll> v;
		for (auto &w:act) v.PB(p[w]);
		sort(v.rbegin(),v.rend());
		ll vsz=v.size();
		for (ll i=0;i<vsz;i++) {
			ans[act[i]]=v[i];
		}
	}
	for (ll i=0;i<n;i++) printf("%d ",ans[i]);
}