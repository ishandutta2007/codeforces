#include <iostream>
#include <stdio.h>
using namespace std;
int arr[100005];
int main()
{
	int n;
	scanf("%d",&n);
	for (int i=0;i<n;i++)
	{
		int a;
		scanf("%d",&a);
		for (int x=1;x*x<=a;x++)
		{
			if (a%x==0)
			arr[x]++,arr[a/x]++;
			if (x*x==a)
			arr[x]--;
		}
	}
	int ans=1;
	for (int i=2;i<=100000;i++)
	ans=max(ans,arr[i]);
	printf("%d",ans);
}