#include<cstdio>
const int N=1e6+5;
int n,m,q,ans;
int dis[N];
inline int find(int x)
{
	return dis[x]==x?x:(dis[x]=find(dis[x]));
}
inline void merge(int x,int y)
{
	dis[find(x)]=find(y);
	return;
}
signed main()
{
	int x,y;
	register int i;
	scanf("%d%d%d",&n,&m,&q);
	for(i=1;i<=n+m;i++)
		dis[i]=i;
	while(q--)
	{
		scanf("%d%d",&x,&y);
		merge(x,n+y);
	}
	for(i=1;i<=n+m;i++)
		if(dis[i]==i)
			ans++;
	printf("%d\n",ans-1);
	return 0;
}