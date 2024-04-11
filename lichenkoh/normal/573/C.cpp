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
const ll mn=1e5+4;
vll g[mn];
ll cnt[mn];
bool ok[mn];
void dfs(ll x, ll p) {
	if (g[x].size()>=3) {
		cnt[x]++;
		return;
	}
	ok[x]=0;
	for (auto &y:g[x]) {
		if (y==p) continue;
		dfs(y,x);
	}
}
void process(ll x) {
	if (cnt[x]<=2&&g[x].size()==cnt[x]+1) {
		ok[x]=false;
	}
}
vll h[mn];
bool final=true;
bool seen[mn];
void f(ll x, ll p) {
	if (h[x].size()>=3) final=false;
	seen[x]=true;
	for (auto &y:h[x]) {
		if (y!=p) f(y,x);
	}
}
int main()
{
	ios_base::sync_with_stdio(false); cin.tie(0);
	ll n; scanf("%d",&n);
	for (ll i=0;i<n-1;i++) {
		ll x,y;
		scanf("%d%d",&x,&y);
		g[x].PB(y); g[y].PB(x);
	}
	for (ll x=1;x<=n;x++) ok[x]=1;
	for (ll x=1;x<=n;x++) {
		if (g[x].size()==1) dfs(x,-1);
	}
	for (ll x=1;x<=n;x++) {
		if (ok[x]) process(x);
	}
	for (ll x=1;x<=n;x++) {
		if (ok[x]) {
			//printf("okx:%d\n",x);
			for (auto &y:g[x]) {
				if (ok[y]) h[x].PB(y);
			}
		}
	}
	ll s=-1;
	for (ll x=1;x<=n;x++) {
		if (ok[x]) s=x;
	}
	if (s!=-1) {
		f(s,-1);
	}
	for (ll x=1;x<=n;x++) {
		if (ok[x]&&seen[x]==false) final=false;
	}
	if (final) printf("Yes\n");
	else printf("No\n");
}