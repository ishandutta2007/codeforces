#include<bits/stdc++.h>
#define re register
long long f[5010],g[5010];
int x[5010],a[5010],b[5010],c[5010],d[5010];
int main()
{
	re int n,s,e;
	scanf("%d%d%d",&n,&s,&e);
	for(re int i=1;i<=n;i++)scanf("%d",&x[i]);
	for(re int i=1;i<=n;i++)scanf("%d",&a[i]);
	for(re int i=1;i<=n;i++)scanf("%d",&b[i]);
	for(re int i=1;i<=n;i++)scanf("%d",&c[i]);
	for(re int i=1;i<=n;i++)scanf("%d",&d[i]);
	memset(f,63,sizeof(f));f[0]=0;
	if(s>e)
	{
		for(re int i=1;i<=n;i++)std::swap(a[i],c[i]),std::swap(b[i],d[i]);
		std::swap(s,e);
	}
	for(re int i=1;i<=n;i++)
	{
		memcpy(g,f,sizeof(f));
		memset(f,63,sizeof(f));
		for(re int j=(i!=1&&(i<=s||i>e));j<=i;j++)
		{
			if(i==s)
			{
				f[j]=std::min(f[j],g[j]+d[i]-x[i]);
				if(j)f[j-1]=std::min(f[j-1],g[j]+c[i]+x[i]);
			}else if(i==e)
			{
				f[j]=std::min(f[j],g[j]+a[i]+x[i]);
				f[j+1]=std::min(f[j+1],g[j]+b[i]-x[i]);
			}else
			{
				f[j]=std::min(f[j],g[j]+a[i]+d[i]);
				if(j)f[j]=std::min(f[j],g[j]+b[i]+c[i]);
				f[j+1]=std::min(f[j+1],g[j]+b[i]+d[i]-2*x[i]);
				if(j)f[j-1]=std::min(f[j-1],g[j]+a[i]+c[i]+2*x[i]);
			}//printf("****%d %d %lld %d\n",i,j,f[j],d[i]-x[i]);
		}
	}
	printf("%lld\n",f[0]);
}