#include <bits/stdc++.h>
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
typedef double db;
mt19937 mrand(random_device{}()); 
const ll mod=1000000007;
int rnd(int x) { return mrand() % x;}
ll powmod(ll a,ll b) {ll res=1;a%=mod; assert(b>=0); for(;b;b>>=1){if(b&1)res=res*a%mod;a=a*a%mod;}return res;}
ll gcd(ll a,ll b) { return b?gcd(b,a%b):a;}
// head

const int N=201000;
const int inf=1<<30;

int p[N][22],dep[N],ddep[N],n,u,v,qq,k,r,mark[N],mdep;
PII fv[N],pp[N],val[N];
VI e[N];

void dfs(int u,int f) {
	dep[u]=dep[f]+1;
	p[u][0]=f;
	if (mark[u]) val[u]=mp(dep[u],u);
	else val[u]=mp(inf,-1);
	for (auto v:e[u]) {
		if (v==f) continue;
		dfs(v,u);
	}
}

#define LOGN 19
int lca(int u,int v) {
	if (dep[u]>dep[v]) swap(u,v);
	per(i,0,LOGN) if (dep[p[v][i]]>=dep[u]) v=p[v][i];
	if (u==v) return u;
	per(i,0,LOGN) if (p[v][i]!=p[u][i]) u=p[u][i],v=p[v][i];
	return p[u][0];
}

int q[N],f[N],vis[N],sz[N],ms[N];
int findd(int u) {
	int t=1;q[0]=u;f[u]=-1;
	rep(i,0,t) {
		u=q[i];
		rep(j,0,e[u].size()) {
			int v=e[u][j];
			if (!vis[v]&&v!=f[u]) f[q[t++]=v]=u;
		}
		ms[q[i]]=0;
		sz[q[i]]=1;
	}
	for (int i=t-1;i>=0;i--) {
		ms[q[i]]=max(ms[q[i]],t-sz[q[i]]);
		if (ms[q[i]]*2<=t) return q[i];
		sz[f[q[i]]]+=sz[q[i]];
		ms[f[q[i]]]=max(ms[f[q[i]]],sz[q[i]]);
	}
	return 0;
}

VI vec;

void dfs2(int u,int f,int dep) {
	if (dep>mdep) pp[dep]=mp(inf,-1),mdep=dep;
	pp[dep]=min(pp[dep],val[u]);
	ddep[u]=dep;
	vec.pb(u);
	for (auto v:e[u]) {
		if (v==f||vis[v]) continue;
		dfs2(v,u,dep+1);
	}
}

void gao(int u) {
	u=findd(u);
	vec.clear();
	mdep=0; pp[0]=mp(inf,-1);
	dfs2(u,-1,0);
	rep(i,1,mdep+1) pp[i]=min(pp[i-1],pp[i]);
	for (auto x:vec) if (ddep[x]<=k) fv[x]=min(fv[x],pp[min(mdep,k-ddep[x])]);
	vis[u]=1;
	for (auto v:e[u]) if (!vis[v]) gao(v);
}

int dis(int u,int v) {
	int w=lca(u,v);
	return dep[u]+dep[v]-2*dep[w];
}

int find(int x) {
	return f[x]==x?x:f[x]=find(f[x]);
}

bool check(int u,int v) {
	if (dis(u,v)<=k) return 1;
	int pu=-1,pv=-1;
	if (fv[u].se!=-1) pu=find(fv[u].se);
	if (fv[v].se!=-1) pv=find(fv[v].se);
	if (pu!=-1&&pv!=-1&&pu==pv) return 1;
	if (pu!=-1&&dis(pu,v)<=k) return 1;
	if (pv!=-1&&dis(pv,u)<=k) return 1;
	return 0;
}

int main() {
	scanf("%d%d%d",&n,&k,&r);
	rep(i,1,n) {
		scanf("%d%d",&u,&v);
		e[u].pb(v);
		e[v].pb(u);
	}
	rep(i,0,r) {
		scanf("%d",&u);
		mark[u]=1;
	}
	dfs(1,0);
	rep(j,1,LOGN) rep(i,1,n+1) p[i][j]=p[p[i][j-1]][j-1];
	rep(i,1,n+1) fv[i]=mp(inf,-1);
	gao(1);
	rep(i,1,n+1) f[i]=i;
	rep(i,1,n+1) if (mark[i]) {
		assert(fv[i].se!=-1);
		int u=find(i),v=find(fv[i].se);
		if (dep[u]>dep[v]) swap(u,v);
		f[v]=u;
	}
	//rep(i,1,n+1) printf("%d %d\n",fv[i].fi,fv[i].se);
	for (scanf("%d",&qq);qq;qq--) {
		scanf("%d%d",&u,&v);
		puts(check(u,v)?"YES":"NO");
	}
}