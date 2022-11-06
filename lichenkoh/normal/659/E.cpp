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
template<typename T> inline bool chkmax(T &a, T b) { return a < b ? a = b, true : false; }
template<typename T> inline bool chkmin(T &a, T b) { return a > b ? a = b, true : false; }
const ll MAXN=100000+5;
vector<ll> g[MAXN];
ll seen[MAXN];
ll ret=1;
void dfs(ll x, ll p, ll k) {
	seen[x]=k;
	for (auto &w:g[x]) {
		if (w==p) continue;
		if (seen[w]==k) ret=0;
		if (seen[w]==0) {
			dfs(w,x,k);
		}
	}
}
int main() {
	ios_base::sync_with_stdio(false);
	ll n,m; scanf("%I64d %I64d",&n,&m);
	for (ll i=0;i<m;i++) {
		ll x,y;
		scanf("%I64d %I64d",&x,&y);
		g[x].PB(y); g[y].PB(x);
	}
	for (ll i=0;i<=n;i++) seen[i]=0;
	ll k=1;
	ll ans=0;
	for (ll x=1;x<=n;x++) {
		if (seen[x]) continue;
		ret=1;
		dfs(x,-1,k);
		ans+=ret;
		k++;
	}
	printf("%I64d\n",ans);
}