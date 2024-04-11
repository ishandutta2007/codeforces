#include<bits/stdc++.h>
using namespace std;
struct edge{int to,nxt;}e[100005<<1];
int n,m,d,tot=0,ans,a[100005],head[100005],dep[5][100005];
inline void adde(int x,int y) {e[++tot]=(edge){y,head[x]},head[x]=tot;}
inline void dfs(int id,int x,int fa=0)
{
	dep[id][x]=dep[id][fa]+1;
	for(int i=head[x];i;i=e[i].nxt) if(e[i].to!=fa) dfs(id,e[i].to,x);
}
inline int gmx(int id)
{
	int wh=a[1];
	for(int i=1;i<=n;i++) if(dep[id][wh]<dep[id][a[i]]) wh=a[i];
	return wh;
}
int main()
{
	scanf("%d%d%d",&n,&m,&d),memset(head,0,sizeof(head)),d++;
	for(int i=1;i<=m;i++) scanf("%d",a+i);
	for(int i=1,x,y;i<n;i++) scanf("%d%d",&x,&y),adde(x,y),adde(y,x);
	dep[1][0]=0,dfs(1,1),dep[2][0]=0,dfs(2,gmx(1)),dep[3][0]=0,dfs(3,gmx(2));
	for(int i=1;i<=n;i++) if(dep[2][i]<=d&&dep[3][i]<=d) ans++;
	return printf("%d\n",ans),0;
}