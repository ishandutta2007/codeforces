#include<iostream>
#include<algorithm>
#include<cstdio>
using namespace std;
int n,c[333333];
main()
{
	scanf("%d",&n);
	for(int i=0;i<n;i++)scanf("%d",c+i);
	int ans=0;
	for(int i=n-1;i>=0;i--)
	{
		if(c[0]!=c[i])
		{
			ans=max(ans,i);
			break;
		}
	}
	for(int i=0;i<n;i++)
	{
		if(c[n-1]!=c[i])
		{
			ans=max(ans,n-1-i);
			break;
		}
	}
	printf("%d\n",ans);
}