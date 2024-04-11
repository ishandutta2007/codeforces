#include <bits/stdc++.h>
#include <assert.h>
using namespace std;
typedef long long ll;
typedef long double ld;
#define PB push_back
#define MP make_pair
#define MOD 1000000007LL
#define endl "\n"
#define fst first
#define snd second
const int UNDEF = -1;
const int INF=1e9;
template<typename T> inline bool chkmax(T &aa, T bb) { return aa < bb ? aa = bb, true : false; }
template<typename T> inline bool chkmin(T &aa, T bb) { return aa > bb ? aa = bb, true : false; }
typedef pair<ll,ll> pll;
typedef vector<ll> vll;
const int mn=1e5+4;
int va[mn],vb[mn],vc[mn];
int p[mn];
int ffind(int x) {
	if (p[x] != x) {
		p[x] = ffind(p[x]);
	}
	return p[x];
}
void funion(int x, int y) {
	if (rand()&1) swap(x,y); 
	int xr = ffind(x);
	int yr = ffind(y);
	p[xr] = yr;
}
bool gok=true;
int vcol[mn];
vector<int> g[mn];
void dfs(int x, int col) {
	if (vcol[x]==UNDEF) {
		vcol[x]=col;
		for (auto &y:g[x]) {
			dfs(y,col^1);
		}
	}
	else {
		if (vcol[x]!=col) gok=false;
	}
}
int main()
{
	ios_base::sync_with_stdio(false); cin.tie(0);
	srand(time(0));
	int n,m; scanf("%d%d",&n,&m);
	for (int i=0;i<m;i++) {
		scanf("%d%d%d",&va[i],&vb[i],&vc[i]);
	}
	for (int x=0;x<=n;x++) p[x]=x;
	for (int i=0;i<m;i++) {
		if (vc[i]==1) funion(va[i],vb[i]);
	}
	for (int i=0;i<m;i++) {
		if (vc[i]==0) {
			int x=ffind(va[i]),y=ffind(vb[i]);
			g[x].PB(y);
			g[y].PB(x);
		}
	}
	memset(vcol,-1,sizeof vcol);
	for (int x=1;x<=n;x++) {
		if (vcol[x]==UNDEF) dfs(x,0);
	}
	if (!gok) {printf("0\n"); return 0;}
	for (int i=0;i<m;i++) {
		funion(va[i],vb[i]);
	}
	ll ans=0;
	for (int x=1;x<=n;x++) {
		if (p[x]==x) {
			ans++;
		}
	}
	ll final=1;
	for (ll x=0;x<ans-1;x++) final=(final*2)%MOD;
	printf("%lld\n",final%MOD);
}