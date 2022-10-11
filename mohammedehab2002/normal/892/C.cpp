#include <iostream>
#include <algorithm>
using namespace std;
int arr[100005];
int main()
{
	int n,cnt=0;
	scanf("%d",&n);
	for (int i=0;i<n;i++)
	scanf("%d",&arr[i]),cnt+=(arr[i]==1);
	if (cnt)
	{
		printf("%d",n-cnt);
		return 0;
	}
	int ans=n+1;
	for (int i=0;i<n-1;i++)
	{
		int gcd=__gcd(arr[i],arr[i+1]);
		for (int x=i+1;x<n;x++)
		{
			gcd=__gcd(arr[x],gcd);
			if (gcd==1)
			{
				ans=min(ans,x-i);
				break;
			}
		}
	}
	if (ans==n+1)
	printf("-1");
	else
	printf("%d",ans+n-1);
}