#include <iostream>
#include <set>
using namespace std;
int arr[100005],gr[256];
set<int> g[256];
int main()
{
	int n,k;
	scanf("%d%d",&n,&k);
	for (int i=0;i<n;i++)
	scanf("%d",&arr[i]);
	for (int i=0;i<256;i++)
	{
		g[i].insert(i);
		gr[i]=i;
	}
	for (int i=0;i<n;i++)
	{
		if (gr[arr[i]]!=arr[i] || g[arr[i]].size()>1)
		continue;
		for (int x=max(arr[i]-k+1,0);;x++)
		{
			if (gr[x]!=x)
			continue;
			g[x].insert(arr[i]);
			auto it=g[x].end();
			it--;
			if (*it-*g[x].begin()<=k)
			{
				for (int j=*g[x].begin();j<=*it;j++)
				gr[j]=*g[x].begin();
				arr[i]=x;
				break;
			}
			g[x].erase(arr[i]);
		}
	}
	for (int i=0;i<n;i++)
	printf("%d ",gr[arr[i]]);
}