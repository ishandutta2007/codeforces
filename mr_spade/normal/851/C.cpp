#include<cstdio>
const int N=1005;
int num,n,s,ans;
int a[N],b[N],c[N],d[N],e[N];
bool book[N];
signed main()
{
	int i,j,k;
	scanf("%d",&n);
	for(i=1;i<=n;i++)
		scanf("%d%d%d%d%d",&a[i],&b[i],&c[i],&d[i],&e[i]);
	for(i=1;i<=n;i++)
	{
		s=a[i]*a[i]+b[i]*b[i]+c[i]*c[i]+d[i]*d[i]+e[i]*e[i];
		for(j=1;j<=n;j++)
		{
			for(k=j+1;k<=n;k++)
			{
				if(j==i||k==i)
					continue;
				num=s-a[i]*(a[j]+a[k])+a[j]*a[k]-b[i]*(b[j]+b[k])+b[j]*b[k]-c[i]*(c[j]+c[k])+c[j]*c[k]-d[i]*(d[j]+d[k])+d[j]*d[k]-e[i]*(e[j]+e[k])+e[j]*e[k];
				if(num>0)
				{
					book[i]=1;
					break;
				}
			}
			if(book[i])
				break;
		}
		if(!book[i])
			ans++;
	}
	printf("%d\n",ans);
	for(i=1;i<=n;i++)
		if(!book[i])
			printf("%d\n",i);
	return 0;
}