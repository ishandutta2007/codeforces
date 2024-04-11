#include <cstdio>
#include <cstring>
#include <cmath>
#include <algorithm>
#include <vector>
#include <string>
#include <map>
#include <set>
#include <cassert>
using namespace std;
#define rep(i,a,n) for (int i=a;i<n;i++)
#define per(i,a,n) for (int i=n-1;i>=a;i--)
#define pb push_back
#define mp make_pair
#define all(x) (x).begin(),(x).end()
#define fi first
#define se second
#define SZ(x) ((int)(x).size())
typedef vector<int> VI;
typedef long long ll;
typedef pair<int,int> PII;
const ll mod=1000000007;
ll powmod(ll a,ll b) {ll res=1;a%=mod; assert(b>=0); for(;b;b>>=1){if(b&1)res=res*a%mod;a=a*a%mod;}return res;}
// head

const int N=901000;
vector<PII> e[N];
VI ve;
ll dis[N];
int vis[N],tot;
set<pair<ll,int> > hs;
int nd[2][N],n,q,s,ty,u,v,w,l,r;
void add(int u,int v,int w) {
	e[u].pb(mp(v,w));
//	printf("%d %d %d\n",u,v,w);
}
void dijkstra(int S,int n) {
	rep(i,1,n+1) dis[i]=1ll<<60,vis[i]=0;
	dis[S]=0;
	rep(i,1,n+1) hs.insert(mp(dis[i],i));
	rep(i,1,n+1) {
		int u=hs.begin()->se; hs.erase(hs.begin());
		vis[u]=1;
		rep(j,0,SZ(e[u])) {
			int v=e[u][j].fi;
			if (dis[v]>dis[u]+e[u][j].se) {
				hs.erase(mp(dis[v],v));
				dis[v]=dis[u]+e[u][j].se;
				hs.insert(mp(dis[v],v));
			}
		}
	}
}
void build(int p,int l,int r,int ty) {
	nd[ty][p]=++tot;
	if (l==r) {
		if (ty==0) add(nd[0][p],l,0);
		if (ty==1) add(l,nd[1][p],0);
		return;
	}
	int md=(l+r)>>1;
	build(p+p,l,md,ty);
	build(p+p+1,md+1,r,ty);
	if (ty==0) {
		add(nd[0][p],nd[0][p+p],0);
		add(nd[0][p],nd[0][p+p+1],0);
	} else {
		add(nd[1][p+p],nd[1][p],0);
		add(nd[1][p+p+1],nd[1][p],0);
	}
}
void modify(int p,int l,int r,int tl,int tr,int ty) {
	if (tl==l&&tr==r) ve.pb(nd[ty][p]);
	else {
		int md=(l+r)>>1;
		if (tr<=md) modify(p+p,l,md,tl,tr,ty);
		else if (tl>md) modify(p+p+1,md+1,r,tl,tr,ty);
		else modify(p+p,l,md,tl,md,ty),modify(p+p+1,md+1,r,md+1,tr,ty);
	}
}
int main() {
	scanf("%d%d%d",&n,&q,&s);
	tot=n+1;
	build(1,1,n,0);
	build(1,1,n,1);
	rep(i,1,q+1) {
		scanf("%d%d",&ty,&v);
		if (ty==1) {
			scanf("%d%d",&u,&w);
			add(v,u,w);
		} else {
			scanf("%d%d%d",&l,&r,&w);
			ve.clear();
			modify(1,1,n,l,r,ty-2);
			if (ty==2) {
				for (auto u:ve) add(v,u,w);
			} else {
				for (auto u:ve) add(u,v,w);
			}
		}
	}
	dijkstra(s,tot-1);
	rep(i,1,n+1) {
		if (dis[i]>=(1ll<<50)) dis[i]=-1;
		printf("%lld ",dis[i]);
	}
	puts("");
}