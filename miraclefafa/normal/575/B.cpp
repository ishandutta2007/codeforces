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

const int N=101000;
int n,u,v,k,ty,p[N][22],dep[N],up[N],down[N];
ll ret;
vector<PII> e[N];
void dfs1(int u,int f) {
//	printf("%d %d\n",u,f);
	p[u][0]=f; dep[u]=dep[f]+1;
	for (auto p:e[u]) if (p.fi!=f) dfs1(p.fi,u);
}

#define LOGN 18
int lca(int u,int v) {
	if (dep[u]>dep[v]) swap(u,v);
	per(i,0,LOGN) if (dep[p[v][i]]>=dep[u]) v=p[v][i];
	if (u==v) return u;
	per(i,0,LOGN) if (p[v][i]!=p[u][i]) u=p[u][i],v=p[v][i];
	return p[u][0];
}

void dfs2(int u,int f,int ty) {
	for (auto p:e[u]) if (p.fi!=f) {
		int v=p.fi;
		dfs2(v,u,p.se);
		up[u]+=up[v];
		down[u]+=down[v];
	}
	if (ty==1) {
		ret=(ret+powmod(2,up[u])-1)%mod;
	} else if (ty==2) {
		ret=(ret+powmod(2,down[u])-1)%mod;
	}
//	printf("ff %d %d %d %d %lld\n",u,up[u],down[u],ty,ret);
}

int main() {
	scanf("%d",&n);
	rep(i,1,n) {
		scanf("%d%d%d",&u,&v,&ty);
		if (ty==0) e[u].pb(mp(v,0)),e[v].pb(mp(u,0));
		else e[u].pb(mp(v,1)),e[v].pb(mp(u,2));
	}
	dfs1(1,0);
	rep(i,1,LOGN) rep(j,1,n+1) p[j][i]=p[p[j][i-1]][i-1];
	scanf("%d",&k);
	u=1;
	rep(i,0,k) {
		scanf("%d",&v);
		int w=lca(u,v);
		up[u]++; up[w]--; down[v]++; down[w]--;
		u=v;
	}
	dfs2(1,0,0);
	printf("%lld\n",ret);
}