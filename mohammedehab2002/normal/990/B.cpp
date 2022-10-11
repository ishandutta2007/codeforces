#include <iostream>
#include <algorithm>
using namespace std;
int arr[200005];
int main()
{
	int n,k;
	scanf("%d%d",&n,&k);
	for (int i=0;i<n;i++)
	scanf("%d",&arr[i]);
	sort(arr,arr+n);
	int ans=0;
	for (int i=0;i<n;)
	{
		int f=i;
		while (f<n && arr[i]==arr[f])
		f++;
		if (f==n || arr[f]>arr[i]+k)
		ans+=f-i;
		i=f;
	}
	printf("%d",ans);
}