#include <iostream>
#include <algorithm>
using namespace std;
int arr[1005];
int main()
{
	int n,k;
	scanf("%d%d",&n,&k);
	for (int i=0;i<n;i++)
	scanf("%d",&arr[i]);
	sort(arr,arr+n);
	int ans=0;
	for (int i=0;i<n;i++)
	{
		while (2*k<arr[i])
		{
			k*=2;
			ans++;
		}
		k=max(k,arr[i]);
	}
	printf("%d",ans);
}