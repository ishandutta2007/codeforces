#include<cstdio>
int n,m,a[1010],x,y,i,j;double p[1010][1010],t;
int main()
{
	scanf("%d%d",&n,&m);
	for(i=1;i<=n;++i)scanf("%d",a+i);
	for(i=1;i<=n;++i)for(j=1;j<=n;++j)p[i][j]=a[i]>a[j];
	while(m--)
	{
		scanf("%d%d",&x,&y);p[x][y]=p[y][x]=.5;
		for(i=1;i<=n;++i)if(i!=x&&i!=y)p[i][x]=p[i][y]=(p[i][x]+p[i][y])/2,p[x][i]=p[y][i]=(p[x][i]+p[y][i])/2;
	}
	for(i=1;i<=n;++i)for(j=n;j>i;--j)t+=p[i][j];
	printf("%f",t);
}