#include <iostream>
#include <vector>
#include <map>
using namespace std;
map<vector<int>,int> m;
int arr[100005],ans[5005],c[100005];
int main()
{
	int n;
	scanf("%d",&n);
	int cur=0;
	for (int i=0;i<n;i++)
	{
		scanf("%d",&arr[i]);
		vector<int> v;
		if (arr[i]<0)
		{
			v.push_back(-1);
			arr[i]*=-1;
		}
		for (int x=2;x*x<=arr[i];x++)
		{
			int cnt=0;
			while (arr[i]%x==0)
			{
				arr[i]/=x;
				cnt^=1;
			}
			if (cnt)
			v.push_back(x);
		}
		if (arr[i]>1)
		v.push_back(arr[i]);
		if (!m[v])
		m[v]=++cur;
		if (arr[i])
		arr[i]=m[v];
	}
	for (int i=0;i<n;i++)
	{
		int curr=0;
		for (int x=i;x<n;x++)
		{
			if (arr[x])
			{
				c[arr[x]]++;
				if (c[arr[x]]==1)
				curr++;
			}
			ans[max(curr,1)]++;
		}
		for (int x=i;x<n;x++)
		c[arr[x]]--;
	}
	for (int i=1;i<=n;i++)
	printf("%d ",ans[i]);
}