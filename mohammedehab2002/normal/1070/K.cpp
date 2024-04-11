#include <iostream>
#include <vector>
using namespace std;
int arr[100005];
int main()
{
	int n,k,sum=0;
	scanf("%d%d",&n,&k);
	for (int i=0;i<n;i++)
	{
		scanf("%d",&arr[i]);
		sum+=arr[i];
	}
	if (sum%k)
	{
		printf("No");
		return 0;
	}
	int cur=0,l=-1;
	vector<int> ans;
	for (int i=0;i<n;i++)
	{
		cur+=arr[i];
		if (cur>=sum/k)
		{
			if (cur>sum/k)
			{
				printf("No");
				return 0;
			}
			ans.push_back(i-l);
			cur=0;
			l=i;
		}
	}
	if (l!=n-1)
	{
		printf("No");
		return 0;
	}
	printf("Yes\n");
	for (int i:ans)
	printf("%d ",i);
}