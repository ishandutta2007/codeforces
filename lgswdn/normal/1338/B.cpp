#include<bits/stdc++.h>
using namespace std;
const int N=1e5+9;
struct edge{int to,nxt;}e[N*2]; int hd[N],tot;
void add(int u,int v){e[++tot]=(edge){v,hd[u]};hd[u]=tot;}
int n,deg[N],root,d[N],f[N],ans; bool od=0,ev=0;
void dfs(int u,int fa){
	d[u]=d[fa]+1;
	if(deg[u]==1){f[u]=1;if(d[u]%2) od=1; else ev=1;}
	for(int i=hd[u],v;i;i=e[i].nxt)
		if((v=e[i].to)!=fa)
			dfs(v,u),f[u]+=(deg[v]==1);
	ans-=max(0,f[u]-1);
}
int main(){
	scanf("%d",&n); ans=n-1;
	for(int i=1,u,v;i<n;i++)
		scanf("%d%d",&u,&v),deg[u]++,deg[v]++,add(u,v),add(v,u);
	for(int i=1;i<=n;i++)
		if(deg[i]>1){root=i;break;}
	dfs(root,0);
	printf("%d %d",(od&ev?3:1),ans);
	return 0;
}