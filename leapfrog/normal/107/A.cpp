#include<bits/stdc++.h>
using namespace std;
struct edge{int to,w,nxt;}e[2005];
struct node{int x,y,d;}r[2005];
int n,m,et,ct=0,head[1005],in[1005],ou[1005];
inline void adde(int x,int y,int w) {e[++et]=(edge){y,w,head[x]},head[x]=et;}
inline void dfs(int x,int d=(int)0x3f3f3f3f3f3f3f3f)
{
	if(!head[x]) r[ct].y=x,r[ct].d=d;
	for(int i=head[x];i;i=e[i].nxt) dfs(e[i].to,min(e[i].w,d));
}
int main()
{
	scanf("%d%d",&n,&m),ct=et=0,memset(head,0,sizeof(head)),memset(in,0,sizeof(in)),memset(ou,0,sizeof(ou));
	for(int i=1,x,y,w;i<=m;i++) scanf("%d%d%d",&x,&y,&w),adde(x,y,w),in[y]++,ou[x]++;
	for(int i=1;i<=n;i++) if(in[i]==0&&ou[i]==1) r[++ct].x=i,dfs(i);
	printf("%d\n",ct);
	for(int i=1;i<=ct;i++) printf("%d %d %d\n",r[i].x,r[i].y,r[i].d);
	return 0;
}