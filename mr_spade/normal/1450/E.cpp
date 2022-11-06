#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<algorithm>
using std::min;
const int N=205,inf=0x3f3f3f3f;
int n,m;
int dis[N],dw[N];
int w[N][N];
inline int find(int x)
{
	if(dis[dis[x]]==dis[x])
		return dis[x];
	int y=find(dis[x]);
	dw[x]^=dw[dis[x]];
	return dis[x]=y;
}
inline void merge(int x,int y)
{
	if(find(x)==find(y))
	{
		if(dw[x]==dw[y])
			puts("NO"),exit(0);
		return;
	}
	dw[dis[x]]=dw[x]^dw[y]^1;dis[dis[x]]=dis[y];
	return;
}
signed main()
{
	int x,y,ww;
	register int i,j,k;
	scanf("%d%d",&n,&m);
	memset(w,0x3f,sizeof(w));
	for(i=1;i<=n;i++)
		dis[i]=i,w[i][i]=0;
	while(m--)
	{
		scanf("%d%d%d",&x,&y,&ww);merge(x,y);
		if(ww==1)
			w[x][y]=min(w[x][y],1),w[y][x]=min(w[y][x],-1);
		else
			w[x][y]=min(w[x][y],1),w[y][x]=min(w[y][x],1);
	}
	for(k=1;k<=n;k++)
		for(i=1;i<=n;i++)
			for(j=1;j<=n;j++)
				if(w[i][j]>w[i][k]+w[k][j])
					w[i][j]=w[i][k]+w[k][j];
	for(k=1;k<=n;k++)
		for(i=1;i<=n;i++)
			for(j=1;j<=n;j++)
				if(w[i][j]>w[i][k]+w[k][j])
					puts("NO"),exit(0);
	int ans=0;x=1;
	for(i=1;i<=n;i++)
		for(j=1;j<=n;j++)
			if(w[i][j]>ans)
				ans=w[i][j],x=i;
	printf("YES\n%d\n",ans);
	for(i=1;i<=n;i++)
		printf("%d%c",w[x][i]+n,i==n?'\n':' ');
	return 0;
}