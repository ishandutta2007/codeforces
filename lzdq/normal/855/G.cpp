#include<cstdio>
#include<algorithm>
using namespace std;
typedef long long ll;
const int MAXN=1e5+5;
int n,q;
int cnte,h[MAXN],to[MAXN<<1],nx[MAXN<<1];
inline void adde(int u,int v){
	cnte++;
	nx[cnte]=h[u];
	to[cnte]=v;
	h[u]=cnte;
}
int pre[MAXN];
int fnd(int x){
	if(x!=pre[x]) pre[x]=fnd(pre[x]);
	return pre[x];
}
int fa[MAXN],dep[MAXN];
ll siz[MAXN],sum[MAXN],blk[MAXN],ans;
inline ll Calc(int u){
	ll t=(n-blk[u])*(n-blk[u])-sum[u]-(n-siz[u])*(n-siz[u]);
	t*=blk[u];
	t+=2*blk[u]*(blk[u]-1)*(n-blk[u])+blk[u]*(blk[u]-1)*(blk[u]-2);
	return t;
}
void Dfs(int u){
	siz[u]=blk[u]=1;
	dep[u]=dep[fa[u]]+1;
	for(int i=h[u]; i; i=nx[i]){
		int v=to[i];
		if(v==fa[u]) continue;
		fa[v]=u;
		Dfs(v);
		siz[u]+=siz[v];
		sum[u]+=siz[v]*siz[v];
	}
	ans+=Calc(u);
	return ;
}
int main(){
	scanf("%d",&n);
	for(int i=1; i<n; i++){
		int u,v;
		scanf("%d%d",&u,&v);
		adde(u,v);
		adde(v,u);
	}
	for(int i=1; i<=n; i++)
		pre[i]=i;
	Dfs(1);
	printf("%lld\n",ans);
	scanf("%d",&q);
	while(q--){
		int x,y;
		scanf("%d%d",&x,&y);
		x=fnd(x),y=fnd(y);
		while(x!=y){
			if(dep[x]<dep[y]) swap(x,y);
			int f=fnd(fa[x]);
			ans-=Calc(f)+Calc(x);
			pre[x]=f;
			sum[f]=sum[f]-siz[x]*siz[x]+sum[x];
			blk[f]+=blk[x];
			ans+=Calc(x=f);
		}
		printf("%lld\n",ans);
	}
	return 0;
}