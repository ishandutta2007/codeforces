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
const ll INF=1e9+5;
template<typename T> inline bool chkmax(T &aa, T bb) { return aa < bb ? aa = bb, true : false; }
template<typename T> inline bool chkmin(T &aa, T bb) { return aa > bb ? aa = bb, true : false; }
typedef pair<ll,ll> pll;
typedef vector<ll> vll;
const ll mn=3002;
ll f[mn][mn];
vll g[mn];
ll n,m;
void bfs(ll init) {
	for (ll y=1;y<=n;y++) {
		f[init][y]=INF;
	}
	queue<ll> q;
	f[init][init]=0;
	q.push(init);
	while(!q.empty()) {
		ll x=q.front(); q.pop();
		ll xdist=f[init][x];
		//printf("init:%d x:%d xdist:%d\n",init,x,xdist);
		for (auto &y:g[x]) {
			if (f[init][y]==INF) {
				f[init][y]=xdist+1;
				q.push(y);
			}
		}
	}
}
ll s[2],t[2],l[2];
int main() 
{
	ios_base::sync_with_stdio(false); cin.tie(0);
	scanf("%d%d",&n,&m);
	for (ll i=0;i<m;i++) {
		ll x,y; scanf("%d%d",&x,&y);
		g[x].PB(y); g[y].PB(x);
	}
	for (ll k=0;k<2;k++) {
		scanf("%d%d%d",&s[k],&t[k],&l[k]);
	}
	for (ll x=1;x<=n;x++) {
		bfs(x);
	}
	ll final=INF;
	if (f[s[0]][t[0]]<=l[0] && f[s[1]][t[1]]<=l[1]) {
		chkmin(final,f[s[0]][t[0]]+f[s[1]][t[1]]);
	}
//	printf("final:%d\n",final);
	for (ll x=1;x<=n;x++) for (ll y=1;y<=n;y++) {
		ll xy=f[x][y];
		ll ans[2];
		for (ll k=0;k<2;k++) {
			ans[k]=INF;
			for (ll sw=0;sw<2;sw++) {
				chkmin(ans[k], f[s[k]][x]+f[y][t[k]]);
				swap(s[k],t[k]);
			}
		}
		if (ans[0]+xy<=l[0]&&ans[1]+xy<=l[1]) {
			chkmin(final, xy+ans[0]+ans[1]);
		}
	}
	if (final>=INF) final=-1;
	else final=m-final;
	printf("%d\n",final);
}