#include<cstdio>
const int N=205;
int dis[N];
inline int find(int v)
{
	return dis[v]==v?v:(dis[v]=find(dis[v]));
}
inline void merge(int u,int v)
{
	dis[find(u)]=find(v);
	return;
}
int n,m;
char s[N][N];
signed main()
{
	register int i,j;
	scanf("%d%d",&n,&m);
	for(i=1;i<=n+m;i++)
		dis[i]=i;
	for(i=1;i<=n;i++)
	{
		scanf("%s",s[i]+1);
		for(j=1;j<=m;j++)
			if(s[i][j]=='#')
				merge(i,n+j);
	}
	for(i=1;i<=n;i++)
		for(j=1;j<=m;j++)
			if(s[i][j]=='.'&&find(i)==find(n+j))
				return puts("NO"),0;
	puts("YES");
	return 0;
}