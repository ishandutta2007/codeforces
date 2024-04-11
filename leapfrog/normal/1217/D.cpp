#include<bits/stdc++.h>
using namespace std;
struct edge{int to,id,nxt;}e[5005<<1];
int n,m,tot=0,k=0,head[5005],f[5005],vis[5005],ans[5005];
inline void adde(int x,int y,int id) {e[++tot]=(edge){y,id,head[x]},head[x]=tot;}
inline void dfs(int x)
{
	if(vis[x]) return;else vis[x]=1,f[x]=1;
	for(int i=head[x];i;i=e[i].nxt) if(f[e[i].to]) ans[e[i].id]=2;else ans[e[i].id]=1,dfs(e[i].to);
	f[x]=0;
}
int main()
{
	scanf("%d%d",&n,&m),memset(head,0,sizeof(head)),memset(vis,0,sizeof(vis));
	for(int i=1,x,y;i<=m;i++) scanf("%d%d",&x,&y),adde(x,y,i);
	for(int i=1;i<=n;i++) if(!vis[i]) dfs(i);
	for(int i=1;i<=n;i++) if(ans[i]==2) k=1;
	printf("%d\n",k+1);
	if(k==0) for(int i=1;i<=m;i++) printf("1%c",i==n?'\n':' ');
	else for(int i=1;i<=m;i++) printf("%d%c",ans[i],i==n?'\n':' ');
	return 0;
}