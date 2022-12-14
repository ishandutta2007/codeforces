#include<iostream>
#include<cstdio>
using namespace std;
long long up,down,x,n,d,ans;
int main()
{
	scanf("%I64d%I64d",&n,&d);
	for (int i=1;i<=n;i++)
	{
		scanf("%I64d",&x);
		if (!x)
		{
			if (down<0) down=0;
			if (up<0)
			{
				up=d;
				ans++;
			}
		}
		else
		{
			down+=x;
			up+=x;
			if (down>d) 
			{
				printf("-1\n");
				return 0;
			}
			if (up>d) up=d;
		}
	}
	printf("%I64d\n",ans);
	return 0;
}