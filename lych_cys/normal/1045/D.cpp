#include<bits/stdc++.h>

using namespace std;

#define N 300000

int n,m,x,y,tot,head[N],fa[N];
double z,son[N],a[N],ans;
struct edge{int v,nxt;}e[N];

void add(int x,int y){e[++tot].v=y; e[tot].nxt=head[x]; head[x]=tot;}

void dfs(int u){
	for (int i=head[u],v;i;i=e[i].nxt)
		if ((v=e[i].v)!=fa[u]){
			fa[v]=u; dfs(v);
			son[u]+=1-a[v];
		}
}

int main(){
	scanf("%d",&n);
	for (int i=1;i<=n;++i) scanf("%lf",a+i);
	for (int i=1;i<n;++i){
		scanf("%d%d",&x,&y); add(++x,++y); add(y,x);
	}
	dfs(1);
	scanf("%d",&m);
	a[0]=1;
	for (int i=1;i<=n;++i) ans+=a[fa[i]]*(1-a[i]);
	while (m--){
		scanf("%d%lf",&x,&z); ++x;
		ans-=a[fa[x]]*(1-a[x])+a[x]*son[x];
		son[fa[x]]-=1-a[x];
		a[x]=z;
		ans+=a[fa[x]]*(1-a[x])+a[x]*son[x];
		son[fa[x]]+=1-a[x];
		printf("%.8lf\n",ans);
	}
	
	return 0;
}