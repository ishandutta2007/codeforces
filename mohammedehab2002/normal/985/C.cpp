#include <iostream>
#include <algorithm>
using namespace std;
int arr[100005];
int main()
{
	int n,k,l;
	scanf("%d%d%d",&n,&k,&l);
	for (int i=0;i<n*k;i++)
	scanf("%d",&arr[i]);
	sort(arr,arr+n*k);
	long long sum=arr[0];
	int last=0;
	for (int i=0;i<=n*k;i++)
	{
		if (i==n*k || arr[i]-arr[0]>l)
		{
			n--;
			for (int x=1;x<i;x++)
			{
				if (x-last==k || i-x-1<n)
				{
					sum+=arr[x];
					last=x;
					n--;
				}
			}
			break;
		}
	}
	if (n)
	sum=0;
	printf("%I64d",sum);
}