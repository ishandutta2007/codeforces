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

const int N=100100;
VI e[N];
map<int,int> id[N];
int dep[N],p[N][20],g[N][20],n,m,u,v,tot;
#define LOGN 17
int lca(int u,int v) {
	if (dep[u]>dep[v]) swap(u,v);
	per(i,0,LOGN) if (dep[p[v][i]]>=dep[u]) v=p[v][i];
	if (u==v) return u;
	per(i,0,LOGN) if (p[v][i]!=p[u][i]) u=p[u][i],v=p[v][i];
	return p[u][0];
}

const int inf=0x20202020;
int vis[N*20];
typedef int flowt;
namespace flow {
	const int M=2010000,N=2010000;
	int y[M],nxt[M],gap[N],fst[N],c[N],pre[N],q[N],dis[N];
	flowt f[M];
	int S,T,tot,Tn;
	void init(int s,int t,int tn) {
		tot=1; assert(tn<N);
		rep(i,0,tn) fst[i]=0;
		S=s;T=t;Tn=tn;
	}
	void add(int u,int v,flowt c1,flowt c2=0) {
		tot++;y[tot]=v;f[tot]=c1;nxt[tot]=fst[u];fst[u]=tot;
		tot++;y[tot]=u;f[tot]=c2;nxt[tot]=fst[v];fst[v]=tot;
	}
	flowt sap() {
		int u=S,t=1;flowt flow=0;
		rep(i,0,Tn) c[i]=fst[i],dis[i]=Tn,gap[i]=0;
		q[0]=T;dis[T]=0;pre[S]=0;
		rep(i,0,t) {
			int u=q[i];
			for (int j=fst[u];j;j=nxt[j]) if (dis[y[j]]>dis[u]+1&&f[j^1]) 
				q[t++]=y[j],dis[y[j]]=dis[u]+1;
		}
		rep(i,0,Tn) gap[dis[i]]++;
		while (dis[S]<=Tn) {
			while (c[u]&&(!f[c[u]]||dis[y[c[u]]]+1!=dis[u])) c[u]=nxt[c[u]];
			if (c[u]) {
				pre[y[c[u]]]=c[u]^1;
				u=y[c[u]];
				if (u==T) {
					flowt minf=inf;
					for (int p=pre[T];p;p=pre[y[p]]) minf=min(minf,f[p^1]);
					for (int p=pre[T];p;p=pre[y[p]]) f[p^1]-=minf,f[p]+=minf;
					flow+=minf;u=S;
				}
			} else {
				if (!(--gap[dis[u]])) break;
				int mind=Tn;
				c[u]=fst[u];
				for (int j=fst[u];j;j=nxt[j]) if (f[j]&&dis[y[j]]<mind) 
					mind=dis[y[j]],c[u]=j;
				dis[u]=mind+1;
				gap[dis[u]]++;
				if (u!=S) u=y[pre[u]];
			}
		}
		q[0]=T; vis[T]=1; t=1;
		rep(i,0,t) {
			int u=q[i];
			for (int j=fst[u];j;j=nxt[j]) if (!vis[y[j]]&&f[j^1]) q[t++]=y[j],vis[y[j]]=1;
		}
		return flow;
	}
};

void dfs(int u,int f) {
	p[u][0]=f; dep[u]=dep[f]+1;
	if (f) {
		g[u][0]=id[f][u];
	}
	rep(i,1,LOGN) {
		p[u][i]=p[p[u][i-1]][i-1];
		if (p[u][i]!=0) {
			g[u][i]=tot++;
			flow::add(g[u][i],g[u][i-1],inf);
			flow::add(g[u][i],g[p[u][i-1]][i-1],inf);
		}
	}
	for (auto v:e[u]) if (v!=f) {
		dfs(v,u);
	}
}
void add(int u,int w,int c) {
	int x=dep[u]-dep[w];
	per(i,0,LOGN) if ((1<<i)<=x) {
		flow::add(c,g[u][i],inf);
		int d=x-(1<<i);
		per(j,0,LOGN) if (d&(1<<j)) u=p[u][j];
		flow::add(c,g[u][i],inf);
		break;
	}
}
int main() {
	scanf("%d%d",&n,&m);
	flow::init(0,0,0);
	rep(i,1,n) {
		scanf("%d%d",&u,&v);
		e[u].pb(v); e[v].pb(u);
		id[u][v]=id[v][u]=m+i;
	}
	tot=m+n;
	dfs(1,0);
	flow::T=tot; flow::Tn=tot+1;
	rep(i,1,n) flow::add(m+i,tot,1);
	rep(i,0,m) {
		scanf("%d%d",&u,&v);
		flow::add(0,i+1,1);
		int w=lca(u,v);
		add(u,w,i+1); add(v,w,i+1);
	}
	printf("%d\n",flow::sap());
	VI r;
	rep(i,1,m+1) if (vis[i]) r.pb(i);
	printf("%d",SZ(r)); for (auto u:r) printf(" %d",u); puts("");
	r.clear();
	rep(i,1,n) if (!vis[m+i]) r.pb(i);
	printf("%d",SZ(r)); for (auto u:r) printf(" %d",u); puts("");
}