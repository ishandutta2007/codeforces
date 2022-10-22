#include<cstdio>
#include<algorithm>
#include<cstring>
using namespace std;
typedef long long ll;
const int MAXN=3e5+5;
int n,m,q;
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
void Dfs(int u){
	dep[u]=dep[fa[u]]+1;
	for(int i=h[u]; i; i=nx[i]){
		int v=to[i];
		if(v==fa[u]) continue;
		fa[v]=u;
		Dfs(v);
	}
	return ;
}
int cnt[MAXN];
int a[MAXN],b[MAXN],c[MAXN];
void Print(int y,int c){
	if(y!=c) Print(fa[y],c);
	printf("%d ",y);
	return ;
}
int f[MAXN][2];
void Dfs2(int u){
	for(int i=h[u]; i; i=nx[i]){
		int v=to[i];
		if(v==fa[u]) continue;
		Dfs2(v);
		if(cnt[v]) f[v][0]=f[v][1]+1;
		else f[v][1]=f[v][0];
		int f0=min(f[u][0]+f[v][0],f[u][1]+f[v][1]+1),f1=min(f[u][0]+f[v][1],f[u][1]+f[v][0]);
		f[u][0]=f0;
		f[u][1]=f1;
	}
	f[u][1]=min(f[u][1],f[u][0]);
	return ;
}
int main(){
	scanf("%d%d",&n,&m);
	for(int i=1; i<=n; i++)
		pre[i]=i;
	while(m--){
		int u,v;
		scanf("%d%d",&u,&v);
		int x=fnd(u),y=fnd(v);
		if(x==y) continue;
		pre[x]=y;
		adde(u,v);
		adde(v,u);
	}
	Dfs(1);
	scanf("%d",&q);
	for(int i=1; i<=q; i++){
		scanf("%d%d",a+i,b+i);
		int x=a[i],y=b[i];
		if(dep[x]>dep[y]) swap(x,y);
		while(dep[x]<dep[y]){
			cnt[y]^=1;
			y=fa[y];
		}
		if(x==y){
			c[i]=x;
			continue;
		}
		while(x!=y){
			cnt[x]^=1;
			cnt[y]^=1;
			x=fa[x];
			y=fa[y];
		}
		c[i]=x;
	}
	bool ans=1;
	for(int i=2; i<=n; i++)
		if(cnt[i]) ans=0;
	if(ans){
		puts("YES");
		for(int i=1; i<=q; i++){
			int x=a[i],y=b[i];
			printf("%d\n",dep[x]+dep[y]-dep[c[i]]*2+1);
			while(x!=c[i]){
				printf("%d ",x);
				x=fa[x];
			}
			Print(y,c[i]);
			puts("");
		}
	}else{
		Dfs2(1);
		puts("NO");
		printf("%d\n",min(f[1][0],f[1][1]+1));
	}
	return 0;
}