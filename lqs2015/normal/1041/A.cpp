#include<iostream>
#include<cstdio>
using namespace std;
int n,a[1111],mn,mx;
int main()
{
	scanf("%d",&n);
	mn=2e9;
	for (int i=1;i<=n;i++)
	{
		scanf("%d",&a[i]);
		mn=min(mn,a[i]);
		mx=max(mx,a[i]);
	}
	printf("%d\n",mx-mn-n+1);
	return 0;
}