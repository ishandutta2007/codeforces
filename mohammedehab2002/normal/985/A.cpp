#include <iostream>
#include <algorithm>
using namespace std;
int arr[100005];
int main()
{
	int n;
	scanf("%d",&n);
	for (int i=0;i<n/2;i++)
	scanf("%d",&arr[i]);
	sort(arr,arr+n/2);
	int ans=(1<<30);
	for (int i=1;i<3;i++)
	{
		int cur=0;
		for (int x=i;x<=n;x+=2)
		cur+=abs(arr[(x-i)/2]-x);
		ans=min(ans,cur);
	}
	printf("%d",ans);
}