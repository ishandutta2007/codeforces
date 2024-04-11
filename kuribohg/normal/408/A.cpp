#include<iostream>
#include<cstdio>
#include<cstring>
#include<string>
#include<algorithm>
using namespace std;
int n,a[1001],p[1001],k,ans=2e9;
int main()
{
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
	{
		scanf("%d",&p[i]);
		a[i]+=15*p[i];
	}
	for(int i=1;i<=n;i++)
		for(int j=1;j<=p[i];j++)
		{
			scanf("%d",&k);
			a[i]+=5*k;
		}
	for(int i=1;i<=n;i++)
		if(a[i]<ans) ans=a[i];
	printf("%d\n",ans);
	return 0;
}