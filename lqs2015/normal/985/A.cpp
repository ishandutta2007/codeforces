#include<iostream>
#include<cstdio>
#include<cmath>
#include<algorithm>
using namespace std;
int n,a[111],ans1,ans2;
int main()
{
	scanf("%d",&n);
	for (int i=1;i<=n/2;i++) scanf("%d",&a[i]);
	sort(a+1,a+n/2+1);
	for (int i=1;i<=n/2;i++)
	{
		ans1+=abs(a[i]-(i*2-1));
	}
	for (int i=1;i<=n/2;i++)
	{
		ans2+=abs(a[i]-i*2);
	}
	printf("%d\n",min(ans1,ans2));
	return 0;
}