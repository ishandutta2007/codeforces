#include <bits/stdc++.h>
using namespace std;
#define rep(i,a,n) for (int i=a;i<n;i++)
#define per(i,a,n) for (int i=n-1;i>=a;i--)
#define pb push_back
#define mp make_pair
#define all(x) (x).begin(),(x).end()
#define SZ(x) ((int)(x).size())
#define fi first
#define se second
typedef vector<int> VI;
typedef long long ll;
typedef pair<int,int> PII;
const ll mod=1000000007;
ll powmod(ll a,ll b) {ll res=1;a%=mod;for(;b;b>>=1){if(b&1)res=res*a%mod;a=a*a%mod;}return res;}
// head

const int N=201000;
VI e[N],son[N];
int f[N],pp[N],dep[N],fg1[N],fg2[N],e1[N],e2[N],te[N],vis[N];
int p[N][22];
int n,m,q,u,v,w;
int find(int u) { return f[u]=(f[u]==u?u:find(f[u]));}
void dfs(int u,int f) {
	pp[u]=f; vis[u]=1;
	for (int v:e[u]) {
		if (v==f) continue;
		dep[v]=dep[u]+1;
		dfs(v,u);
	}
}
void dfss(int u) {
	vis[u]=1;
	for (int v:son[u]) {
		dep[v]=dep[u]+1;
		dfss(v);
	}
}
void sfd(int u) {
	vis[u]=1;
	for (int v:son[u]) {
		sfd(v);
		fg1[u]+=fg1[v]; fg2[u]+=fg2[v];
	}
	if (fg1[u]&&fg2[u]) throw 1;
}

#define LOGN 19
int lca(int u,int v) {
	if (dep[u]>dep[v]) swap(u,v);
	per(i,0,LOGN) if (dep[p[v][i]]>=dep[u]) v=p[v][i];
	if (u==v) return u;
	per(i,0,LOGN) if (p[v][i]!=p[u][i]) u=p[u][i],v=p[v][i];
	return p[u][0];
}
int main() {
//	freopen("in.txt","r",stdin);
	scanf("%d%d%d",&n,&m,&q);
	rep(i,1,n+1) f[i]=i;
	rep(i,0,m) {
		scanf("%d%d",e1+i,e2+i);
	}
	rep(i,0,m) {
		u=e1[i], v=e2[i];
		if (find(u)!=find(v)) {
			e[u].pb(v); e[v].pb(u);
			f[find(u)]=find(v);
			te[i]=1;
		} else te[i]=0;
	}
	rep(i,1,n+1) vis[i]=0;
	rep(i,1,n+1) if (!vis[i]) dfs(i,0);
	rep(i,1,n+1) f[i]=i;
	rep(i,0,m) if (!te[i]) {
		u=find(e1[i]), v=find(e2[i]);
		while (u!=v) {
			if (dep[u]<dep[v]) swap(u,v);
			f[u]=find(pp[u]); u=f[u];
		}
	}
	rep(i,1,n+1) if (find(i)==i) {
		p[i][0]=find(pp[i]);
		son[p[i][0]].pb(i);
	}
	rep(i,1,n+1) vis[i]=find(i)!=i;
	rep(i,1,n+1) if (!vis[i]) {
		dep[i]=1; dfss(i);
	}
	rep(i,1,LOGN) rep(j,1,n+1) p[j][i]=p[p[j][i-1]][i-1];
	rep(i,0,q) {
		scanf("%d%d",&u,&v);
		u=find(u); v=find(v);
		w=lca(u,v);
//		printf("%d %d %d\n",u,v,w);
		if (w==0) {
			puts("No"); return 0;
		}
		fg1[u]++; fg1[w]--;
		fg2[v]++; fg2[w]--;
	}
//	rep(i,1,n+1) printf("%d %d %d\n",i,fg1[i],fg2[i]);
	try {
		rep(i,1,n+1) vis[i]=find(i)!=i;
		rep(i,1,n+1) if (!vis[i]) sfd(i);
	} catch(int e) {
		puts("No");
		return 0;
	}
	puts("Yes");
}