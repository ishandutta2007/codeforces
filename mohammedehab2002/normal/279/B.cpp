#include <iostream>
using namespace std;
int arr[100005];
int main()
{
	int n,t;
	scanf("%d%d",&n,&t);
	for (int i=0;i<n;i++)
	scanf("%d",&arr[i]);
	int r=0,sum=0,ans=0;
	for (int i=0;i<n;i++)
	{
		while (r<n && sum<=t)
		sum+=arr[r++];
		if (sum>t)
		{
			r--;
			sum-=arr[r];
		}
		ans=max(ans,r-i);
		sum-=arr[i];
	}
	printf("%d",ans);
}