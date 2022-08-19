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

const int inf=0x20202020;
const int M=100000,N=1000;

VI p;
vector<PII> e[N];
int n,m,s,t,vis[N],pt[N];
int u[M],v[M],g[M],f[M],ful[M],ff[M],id[M];

typedef int flowt;
namespace flow {
	int y[M],nxt[M],gap[N],fst[N],c[N],pre[N],q[N],dis[N],id[M];
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
		q[0]=S; t=1;
		rep(i,0,Tn) vis[i]=0; vis[S]=1;
		rep(i,0,t) {
			int u=q[i];
			for (int j=fst[u];j;j=nxt[j]) if (f[j]&&!vis[y[j]]) {
				vis[y[j]]=1;
				q[t++]=y[j];
			}
		}
		return flow;
	}
};

void dfs(int u,int d,int r) {
	vis[u]=1;
	if (u==r) {
		p=VI(pt,pt+d);
		return;
	}
	for (auto p:e[u]) {
		int v=p.fi;
		if (!vis[v]) {
			pt[d]=p.se;
			dfs(v,d+1,r);
		}
	}
}


int main() {
	scanf("%d%d%d%d",&n,&m,&s,&t);
	--s; --t;
	flow::init(s,t,n);
	rep(i,0,m) {
		scanf("%d%d%d",u+i,v+i,g+i); --u[i]; --v[i];
		if (g[i]) flow::add(u[i],v[i],1),flow::add(v[i],u[i],inf);
		else flow::add(u[i],v[i],inf);
		if (g[i]) e[u[i]].pb(mp(v[i],i));
	}
	e[t].pb(mp(s,m));
	int r=flow::sap();
	printf("%d\n",r);
	int tot=0;
	rep(i,0,m) {
		if (vis[u[i]]&&!vis[v[i]]) ful[i]=1,tot++;
		if (ful[i]&&!g[i]) assert(0);
	}
	assert(tot==r);
	rep(i,0,m) if (g[i]) {
		rep(j,0,n) vis[j]=0;
		dfs(v[i],0,u[i]);
		for (auto w:p) f[w]++;
		f[i]++;
	}
	rep(i,0,m) {
		if (ful[i]) ff[i]=f[i]; else ff[i]=f[i]+1;
	}
	rep(i,0,m) {
		if (ful[i]) printf("%d %d\n",f[i],f[i]);
		else printf("%d %d\n",f[i],f[i]+1);
	}
}