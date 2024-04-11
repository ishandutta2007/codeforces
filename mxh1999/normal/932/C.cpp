#include<bits/stdc++.h>
using namespace std;

const int maxn=1000010;
int n,a,b;
int ans[maxn];
void doit(int x,int y)
{
	for (int i=1;i<=x;i++)
	{
		ans[i*a]=(i-1)*a+1;
		for (int j=(i-1)*a+1;j<i*a;j++)
			ans[j]=j+1;
	}
	for (int i=1;i<=y;i++)
	{
		ans[x*a+i*b]=x*a+(i-1)*b+1;
		for (int j=x*a+(i-1)*b+1;j<x*a+i*b;j++)
			ans[j]=j+1;
	}
	for (int i=1;i<=n;i++)
		printf("%d ",ans[i]);
}
int main()
{
	scanf("%d%d%d",&n,&a,&b);
	for (int i=1;i<=n;i++)	ans[i]=i;
	for (int i=0;i*a<=n;i++)
	{
		if ((n-i*a)%b==0)
		{
			doit(i,(n-i*a)/b);
			return 0;
		}
	}
	printf("-1\n");
	return 0;
}