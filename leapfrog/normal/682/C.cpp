#include<bits/stdc++.h>
using namespace std;
struct edge{int to,w,nxt;}e[100005<<1];
int n,tot=0,ans=0,a[100005],head[100005],siz[100005];long long dis[100005];
inline void adde(int x,int y,int w) {e[++tot]=(edge){y,w,head[x]},head[x]=tot;}
inline void dfs(int x,int fa=0)
{
	siz[x]=1,dis[x]=max(dis[x],0ll);
	for(int i=head[x];i;i=e[i].nxt) if(e[i].to!=fa) dis[e[i].to]=dis[x]+e[i].w,dfs(e[i].to),siz[x]+=siz[e[i].to];
	if(dis[x]>a[x]) ans+=siz[x],siz[x]=0;
}
int main()
{
	scanf("%d",&n),memset(head,0,sizeof(head));
	for(int i=1;i<=n;i++) scanf("%d",a+i);
	for(int i=2,p,c;i<=n;i++) scanf("%d%d",&p,&c),adde(p,i,c);
	return dis[0]=0,dfs(1),printf("%d\n",ans),0;
}