#include<bits/stdc++.h>
#define re register
int a[400100],b[400100];
int main()
{
	re int n,ans=0;
	scanf("%d",&n);
	for(re int i=1;i<=n;i++)
	{
		scanf("%d",&a[i]);
	}
	for(re int ii=1;ii<=25;ii++)
	{
		re int I=(1<<ii)-1,II=(1<<ii-1)-1;
		for(re int i=1;i<=n;i++)
		{
			b[i]=(a[i]&I);
		}
		re int num=0;
		re int nn=0;
		std::sort(b+1,b+n+1);
		while(nn<n&&b[nn+1]<=II)nn++;
		re int ta=nn+1;
		for(re int i=1;i<=nn;i++)
		{
			while(ta>1&&b[ta-1]+b[i]>II)ta--;
			num^=((nn+1-std::max(ta,i+1))&1);
		}
		ta=n+1;
		for(re int i=nn+1;i<=n;i++)
		{
			while(ta>nn+1&&b[ta-1]+b[i]>II+2*(1<<ii-1))ta--;
			num^=((n+1-std::max(ta,i+1))&1);
		}
		ta=n;
		for(re int i=1;i<=nn;i++)
		{
			while(ta>nn&&b[ta]+b[i]>II+(1<<ii-1))ta--;
			num^=((ta-nn)&1);
		}
		ans+=(num<<ii-1);
	}
	printf("%d\n",ans);
}