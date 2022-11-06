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
template<typename T> inline bool chkmax(T &a, T b) { return a < b ? a = b, true : false; }
template<typename T> inline bool chkmin(T &a, T b) { return a > b ? a = b, true : false; }
const ll MAXN=502;
ll c[MAXN];
bool f[MAXN][MAXN];
int main() {
	ios_base::sync_with_stdio(false);
	ll n,k;scanf("%d %d",&n,&k);
	for (ll i=0;i<n;i++) {
		scanf("%d",&c[i]);
	}
	for (ll x=0;x<MAXN;x++) for (ll y=0;y<MAXN;y++) f[x][y]=false;
	f[0][0]=true;
	for (ll i=0;i<n;i++) {
		ll v=c[i];
		for (ll x=MAXN-v-1;x>=0;x--) {
			ll nx=x+v;
			for (ll y=MAXN-v-1;y>=0;y--) {
				ll ny=y+v;
				f[nx][y]|=f[x][y];
				f[nx][ny]|=f[x][y];
			}
		}
	}
	vector<ll> ans;
	for (ll y=0;y<MAXN;y++) {
		if (f[k][y]) ans.PB(y);
	}
	printf("%d\n",ans.size());
	for (auto &w:ans) printf("%d ",w);
	printf("\n");
}