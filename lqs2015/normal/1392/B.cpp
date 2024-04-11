#include<bits/stdc++.h>
using namespace std;
int test,n,mn,mx,a[222222];
long long k;
int main()
{
	scanf("%d",&test);
	while(test--)
	{
		scanf("%d",&n);
		scanf("%lld",&k);
		for (int i=1;i<=n;i++) scanf("%d",&a[i]); 
		mx=-1e9;mn=1e9;
		for (int i=1;i<=n;i++)
		{
			mx=max(mx,a[i]);
			mn=min(mn,a[i]);
		}
		if (k&1)
		{
			for (int i=1;i<=n;i++) printf("%d ",mx-a[i]);
			printf("\n");
		}
		else
		{
			for (int i=1;i<=n;i++) printf("%d ",a[i]-mn);
			printf("\n");
		}
	}
	return 0;
}