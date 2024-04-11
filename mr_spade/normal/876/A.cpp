#include<cstdio>
int n,a,b,c;
int now(1),ans;
signed main()
{
	int i;
	scanf("%d%d%d%d",&n,&a,&b,&c);
	for(i=2;i<=n;i++)
	{
		if(now==1)
		{
			if(a<=b)
				ans+=a,now=2;
			else
				ans+=b,now=3;
		}
		else if(now==2)
		{
			if(a<=c)
				ans+=a,now=1;
			else
				ans+=c,now=3;
		}
		else
		{
			if(b<=c)
				ans+=b,now=1;
			else
				ans+=c,now=2;
		}
	}
	printf("%d\n",ans);
	return 0;
}