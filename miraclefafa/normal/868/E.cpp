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

const int inf=0x20202020,N=55;
int n,u,v,w,dp[N][N][N][N],pd[N][N],g[N][N],s,m,cnt[N];
VI e[N],nxt[N][N];
void dfs2(int u,int f) {
	for (auto v:e[u]) if (v!=f) {
		dfs2(v,u);
		cnt[u]+=cnt[v];
	}
}
int gao(int u,int v,int sz1,int sz2) {
	if (sz1+sz2==0) return 0;
	if (sz1==0) return inf;
	int &r=dp[u][v][sz1][sz2];
	if (r!=inf) return r;
	if (SZ(nxt[u][v])==1&&nxt[u][v][0]==-1) {
		nxt[u][v].clear();
//		printf("%d %d: ",u,v);
		for (auto w:e[v]) {
			if (w!=u) nxt[u][v].pb(w);// ,printf("%d ",w);
		}
//		puts("");
	}
	VI &pnt=nxt[u][v];
	if (pnt.empty()) {
		return r=g[u][v]+gao(v,u,sz2,0);
	}
//	vector<vector<int> > pd(SZ(pnt)+1,VI(sz1+1,0));
	rep(i,0,SZ(pnt)) rep(k,0,sz1+1) gao(v,pnt[i],k,sz1+sz2-k);
	rep(i,0,SZ(pnt)+1) rep(j,0,sz1+1) pd[i][j]=0;
	pd[0][0]=inf;
	rep(i,0,SZ(pnt)) rep(j,0,sz1+1) rep(k,0,sz1+1-j) {
		pd[i+1][j+k]=max(pd[i+1][j+k],min(pd[i][j],gao(v,pnt[i],k,sz1+sz2-k)));
	}
	return r=pd[SZ(pnt)][sz1]+g[u][v];
}
int main() {
	memset(dp,0x20,sizeof(dp));
	scanf("%d",&n);
	rep(i,1,n+1) rep(j,1,n+1) nxt[i][j].pb(-1);
	rep(i,1,n) {
		scanf("%d%d%d",&u,&v,&w),e[u].pb(v),e[v].pb(u);
		g[u][v]=g[v][u]=w;
	}
	scanf("%d",&s);
	scanf("%d",&m);
	rep(i,0,m) {
		scanf("%d",&u);
		cnt[u]++;
	}
	dfs2(s,0);
	int ret=inf;
	for (auto v:e[s]) ret=min(ret,gao(s,v,cnt[v],m-cnt[v]));
	printf("%d\n",ret);
}