#include<bits/stdc++.h>
using namespace std;
struct edge{int to,nxt;}e[200005<<1];
int n,tot=0,ans=0,head[200005],c[200005];
inline void adde(int x,int y) {e[++tot]=(edge){y,head[x]},head[x]=tot;}
inline void dfs(int x,int fa=1)
{
	int t=1;
	for(int i=head[x];i;i=e[i].nxt)
		if(e[i].to!=fa)
		{
			while(t==c[x]||t==c[fa]) t++;
			c[e[i].to]=t,t++,dfs(e[i].to,x);
		}
	ans=max(ans,t-1);
}
int main()
{
	scanf("%d",&n),memset(head,0,sizeof(head));
	for(int i=1,x,y;i<n;i++) scanf("%d%d",&x,&y),adde(x,y),adde(y,x);
	c[1]=1,dfs(1),printf("%d\n",ans);
	for(int i=1;i<=n;i++) printf("%d%c",c[i],i==n?'\n':' ');
	return 0;
}