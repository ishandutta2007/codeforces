#include<iostream>
#include<cstdio>
using namespace std;
int n,m,prime[11111],cnt,sum,re,i,j;
bool f[111111];
int main()
{
	for (i=2;i<=110000;i++)
	{
		for (int j=i+i;j<=110000;j+=i)
		f[j]=1;
	}
	for (i=2;i<=110000;i++)
	{
		if (!f[i]) prime[++cnt]=i;
	}
	cin>>n>>m;
	for (i=1;i<=cnt;i++)
	{
		if (prime[i]>=n-1) 
		{
			sum=prime[i];
			break;
		}
	}
	printf("%d %d\n",sum,sum);
	for (i=1;i<n;i++)
	{
		if (i<=sum-n+1) printf("%d %d %d\n",i,i+1,2);
		else printf("%d %d %d\n",i,i+1,1);
	}
	re=m-n+1;
	for (i=1;i<=n;i++)
	{
		for (j=i+2;j<=n;j++)
		{
			if (re<1) break;
			printf("%d %d %d\n",i,j,1000000000);
			re--;
		}
		if (re<1) break;
	}
	return 0;
}