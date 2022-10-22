#include <bits/stdc++.h>
using namespace std;
#define N 600005
#define pb push_back
int n,tp,st[N],cur[N],a[2][N];bool vs[N];char b[2][2][N];
struct Edge {int u,v,w;};vector<Edge> e[N];
void dfs(int u)
{
	for(int i=cur[u];i<e[u].size();i=cur[u])
	{
		cur[u]=i+1;if(vs[e[u][i].w]) continue;
		vs[e[u][i].w]=1;dfs(e[u][i].v);
	}st[++st[0]]=u;
}
int main()
{
	scanf("%d",&n);
	for(int i=1,u,v;i<=n;++i)
	{
		scanf("%d %d",&u,&v);
		e[u].pb((Edge) {u,v,i});e[v].pb((Edge) {v,u,i});
		e[u].pb((Edge) {u,v,n+i});e[v].pb((Edge) {v,u,n+i});
	}
	for(int i=1,t;i<=n*2;++i)
	{
		st[0]=0;dfs(i);t=st[0]/2;
		if(!t) continue;if(t<2) {printf("-1");return 0;}
		for(int j=1;j<t;j+=2)
		{
			b[0][0][tp+j]='L';b[0][0][tp+j+1]='R';
			b[0][1][tp+j]='L';b[0][1][tp+j+1]='R';
		}if(t&1) b[0][0][tp+t]='U',b[0][1][tp+t]='D';
		b[1][0][tp+1]='U';b[1][1][tp+1]='D';
		for(int j=2;j<t;j+=2)
		{
			b[1][0][tp+j]='L';b[1][0][tp+j+1]='R';
			b[1][1][tp+j]='L';b[1][1][tp+j+1]='R';
		}if(!(t&1)) b[1][0][tp+t]='U',b[1][1][tp+t]='D';
		for(int j=1;j<=t;++j) a[0][tp+j]=st[j],a[1][tp+j]=st[st[0]-j];tp+=t;
	}printf("%d %d\n\n",2,n);
	for(int i=0;i<2;++i,putchar('\n')) for(int j=1;j<=n;++j)
		printf("%d ",a[i][j]);putchar('\n');
	for(int i=0;i<2;++i,putchar('\n'),putchar('\n'))
		for(int j=0;j<2;++j,putchar('\n')) for(int k=1;k<=n;++k)
			putchar(b[i][j][k]);return 0;
}