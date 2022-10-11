#include <iostream>
#include <stdlib.h>
#include <string.h>
#include <algorithm>
using namespace std;
int par[105];
bool vis[105];
long long go(int x,int st)
{
	if (x==st)
	return 1;
	if (vis[x])
	{
		printf("-1");
		exit(0);
	}
	vis[x]=1;
	return 1+go(par[x],st);
}
int main()
{
	long long res=1;
	int n;
	scanf("%d",&n);
	for (int i=1;i<=n;i++)
	scanf("%d",&par[i]);
	for (int i=1;i<=n;i++)
	{
		memset(vis,0,sizeof(vis));
		long long ans=go(par[i],i);
		if (ans%2==0)
		ans/=2;
		res=res/__gcd(res,ans)*ans;
	}
	printf("%I64d",res);
}