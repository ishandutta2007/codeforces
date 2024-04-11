#include <iostream>
#include <stdio.h>
using namespace std;
int arr[200005],ans[200005];
int main()
{
	int n;
	scanf("%d",&n);
	int l=-(1<<30);
	for (int i=0;i<n;i++)
	{
		scanf("%d",&arr[i]);
		if (arr[i]==0)
		l=i;
		ans[i]=i-l;
	}
	l=(1<<30);
	for (int i=n-1;i>=0;i--)
	{
		if (arr[i]==0)
		l=i;
		ans[i]=min(ans[i],l-i);
	}
	for (int i=0;i<n;i++)
	printf("%d ",ans[i]);
}