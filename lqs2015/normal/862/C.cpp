#include<iostream>
#include<cstdio>
using namespace std;
int n,x,cur,ans[111111],a;
int main()
{
	cin>>n>>x;
	if (n==1)
	{
		printf("YES\n%d\n",x);
		return 0;
	}
	if (n==2 && !x)
	{
		printf("NO\n");
		return 0;
	}
	else if (n==2)
	{
		printf("YES\n");
		printf("%d %d\n",0,x);
		return 0;
	}
	for (int i=1;i<=n-2;i++)
	{
		ans[i]=i;
		cur^=ans[i];
	}
	x^=cur;
	for (int i=n-1;i<=1000000;i++)
	{
		a=x^i;
		if (a!=i && a>=n-1 && a<=1000000) 
		{
			printf("YES\n");
			for (int j=1;j<=n-2;j++) printf("%d ",ans[j]);
			printf("%d %d\n",a,i);
			return 0;
		}
	}
	x=x^ans[n-2]^131072;
	ans[n-2]=131072;
	for (int i=n-2;i<=1000000;i++)
	{
		a=x^i;
		if (a!=i && a>=n-1 && a!=131072 && i!=131072 && a<=1000000) 
		{
			printf("YES\n");
			for (int j=1;j<=n-2;j++) printf("%d ",ans[j]);
			printf("%d %d\n",a,i);
			return 0;
		}
	}
	return 0;
}