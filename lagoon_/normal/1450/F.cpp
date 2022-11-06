#include<bits/stdc++.h>
#define re register
int a[100100],b[100100],d[100100];
int main()
{
	re int T;
	scanf("%d",&T);
	for(;T--;)
	{
		re int n,ans,bl=1,nn=1;
		scanf("%d",&n);ans=n-1;
		for(re int i=1;i<=n;i++)
		{
			scanf("%d",&a[i]);
			b[a[i]]++;
			if(b[a[i]]*2>n+1)bl=0;
		}
		d[a[1]]++;d[a[n]]++;nn++;
		for(re int i=2;i<=n;i++)
		{
			if(a[i]!=a[i-1])ans--;
			else
			{
				d[a[i]]++;
				d[a[i-1]]++;
				nn++;
			}
		}
		for(re int i=1;i<=n;i++)if(d[i]>nn)ans+=d[i]-nn;
		if(!bl)puts("-1");
		else printf("%d\n",ans);
		for(re int i=1;i<=n;i++)d[i]=b[i]=0;
	}
}