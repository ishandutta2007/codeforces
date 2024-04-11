#include <iostream>
#include <vector>
using namespace std;
bool prime[2000005];
int arr[1005];
vector<int> ans[2];
int main()
{
	for (int i=2;i<2000005;i++)
	{
		if (!prime[i])
		{
			for (int x=2*i;x<2000005;x+=i)
			prime[x]=1;
		}
	}
	int n;
	scanf("%d",&n);
	for (int i=0;i<n;i++)
	scanf("%d",&arr[i]);
	for (int i=0;i<n;i++)
	{
		if (arr[i]==1)
		ans[1].push_back(arr[i]);
		for (int x=i+1;x<n;x++)
		{
			if (!prime[arr[i]+arr[x]] && ans[0].empty())
			ans[0].push_back(arr[i]),ans[0].push_back(arr[x]);
		}
	}
	for (int i=0;i<n;i++)
	{
		if (!prime[arr[i]+1] && arr[i]!=1)
		{
			ans[1].push_back(arr[i]);
			break;
		}
	}
	if (ans[1].size()>ans[0].size())
	ans[0]=ans[1];
	if (ans[0].empty())
	ans[0].push_back(arr[0]);
	printf("%d\n",ans[0].size());
	for (int i=0;i<ans[0].size();i++)
	printf("%d ",ans[0][i]);
}