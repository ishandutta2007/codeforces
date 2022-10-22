#include<cstdio>
#include<algorithm>
#include<cstring>
using namespace std;
typedef long long ll;
const int MAXN=1e6+5;
int n;
ll a[MAXN];
int stk[MAXN],tp;
int lc[MAXN],rc[MAXN],fa[MAXN];
int fx[MAXN],fy[MAXN],tx[MAXN],ty[MAXN];
int dfn[MAXN],rev[MAXN],siz[MAXN],son[MAXN],top[MAXN],dep[MAXN];
int rt;
void Dfs1(int u){
	dfn[u]=++*dfn;
	rev[*dfn]=u;
	siz[u]=1;
	int v=lc[u];
	if(v){
		fa[v]=u;
		dep[v]=dep[u]+1;
		Dfs1(v);
		siz[u]+=siz[v];
		if(siz[v]>siz[son[u]]) son[u]=v;
		tx[u]=tx[v];
	}else tx[u]=u;
	v=rc[u];
	if(v){
		fa[v]=u;
		dep[v]=dep[u]+1;
		Dfs1(v);
		siz[u]+=siz[v];
		if(siz[v]>siz[son[u]]) son[u]=v;
		ty[u]=ty[v];
	}else ty[u]=u;
	return ;
}
void Dfs2(int u){
	int v=son[u];
	if(v) top[v]=top[u],Dfs2(v);
	v=lc[u];
	if(v&&v!=son[u]) top[v]=v,Dfs2(v);
	v=rc[u];
	if(v&&v!=son[u]) top[v]=v,Dfs2(v);
	return ;
}
int Lca(int x,int y){
	while(top[x]!=top[y]){
		if(dep[top[x]]>dep[top[y]]) x=fa[top[x]];
		else y=fa[top[y]];
	}
	if(dep[x]>dep[y]) return y;
	return x;
}
ll ans;
bool b[MAXN];
ll f[MAXN][2],g[MAXN][2];
int m,p[MAXN];
int main(){
	//freopen("in2.txt","r",stdin);
	scanf("%d",&n);
	for(int i=1; i<=n; i++){
		scanf("%lld",a+i);
		while(tp&&a[stk[tp]]>=a[i]) rc[stk[tp]]=lc[i],lc[i]=stk[tp--];
		stk[++tp]=i;
	}
	while(tp>1) rc[stk[tp-1]]=stk[tp],tp--;
	rt=stk[tp];
	Dfs1(rt);
	top[rt]=rt;
	Dfs2(rt);
	tp=0;
	for(int i=1; i<=n; i++){
		while(tp&&a[stk[tp]]<=a[i])
			fy[stk[tp--]]=i-1;
		fx[i]=stk[tp]+1;
		stk[++tp]=i;
	}
	while(tp) fy[stk[tp--]]=n;
	for(int k=0; k<=62; k++){
		m=0;
		for(int i=1; i<=n; i++)
			if(b[i]=__builtin_popcountll(a[i])==k) p[++m]=i;
		if(!m) continue;
		for(int i=1; i<=n; i++){
			int u=rev[i],t=fa[u];
			f[u][0]=f[t][0];
			f[u][1]=f[t][1];
			g[u][0]=g[t][0];
			g[u][1]=g[t][1];
			if(t&&b[t]){
				if(lc[t]==u){
					f[u][0]+=siz[rc[t]]+1;
					f[u][1]+=(siz[rc[t]]+1)*(1ll-tx[t]);
				}else{
					g[u][0]-=siz[lc[t]]+1;
					g[u][1]+=(siz[lc[t]]+1)*(1ll+ty[t]);
				}
			}
		}
		for(int i=1; i<=m; i++){
			int u=p[i];
			int l=Lca(fx[u],fy[u]),y,v;
			if(l!=u){
				v=Lca(u,fx[u]);
				if(v==l){
					v=Lca(u,fy[u]);
					if(u!=v){
						y=lc[v];
						ans+=u*(f[u][0]-f[y][0])+(f[u][1]-f[y][1]);
						ans+=u*(g[u][0]-g[y][0])+(g[u][1]-g[y][1]);
						if(b[v]) ans+=(u-tx[v]+1ll)*(fy[u]-v+1);
					}
					y=rc[l];
					ans+=(g[y][0]-g[v][0])*(fy[u]-u+1);
					if(b[l]) ans+=(fy[u]-u+1ll)*(l-fx[u]+1);
				}else{
					if(u!=v){
						y=rc[v];
						ans+=u*(f[u][0]-f[y][0])+(f[u][1]-f[y][1]);
						ans+=u*(g[u][0]-g[y][0])+(g[u][1]-g[y][1]);
						if(b[v]) ans+=(ty[v]-u+1ll)*(v-fx[u]+1);
					}
					y=lc[l];
					ans+=(f[v][0]-f[y][0])*(u-fx[u]+1);
					if(b[l]) ans+=(u-fx[u]+1ll)*(fy[u]-l+1);
				}
			}
			ans+=(u-max(tx[u],fx[u])+1ll)*(min(ty[u],fy[u])-u+1);
			//ans++;
		}
	}
	printf("%lld\n",ans);
	return 0;
}