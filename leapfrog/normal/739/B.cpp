#include<bits/stdc++.h>
using namespace std;
struct edge{int to,w,nxt;}e[200005];
int n,tot=0,head[200005],a[200005],fa[200005][35],ans[200005];long long d[200005];
inline void adde(int x,int y,int w) {e[++tot]=(edge){y,w,head[x]},head[x]=tot;}
inline void dfs(int x)
{
	int t=x;for(int i=1;i<=30;i++) fa[x][i]=fa[fa[x][i-1]][i-1];
	for(int i=30;i>=0;i--) if(fa[t][i]&&d[x]-d[fa[t][i]]<=a[x]) t=fa[t][i];
	ans[fa[t][0]]--,ans[fa[x][0]]++;
	for(int i=head[x];i;i=e[i].nxt) fa[e[i].to][0]=x,d[e[i].to]=d[x]+e[i].w,dfs(e[i].to),ans[x]+=ans[e[i].to];
}
int main()
{
	scanf("%d",&n),memset(head,0,sizeof(head));
	for(int i=1;i<=n;i++) scanf("%d",a+i);
	for(int i=2,y,w;i<=n;i++) scanf("%d%d",&y,&w),adde(y,i,w);
	dfs(1);
	for(int i=1;i<=n;i++) printf("%d%c",ans[i],i==n?'\n':' ');
	return 0;
}