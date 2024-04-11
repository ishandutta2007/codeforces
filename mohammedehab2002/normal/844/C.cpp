#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
pair<int,int> arr[100005];
vector<vector<int> > ans;
bool vis[100005];
void dfs(int node)
{
	if (vis[node])
	return;
	vis[node]=1;
	ans[ans.size()-1].push_back(node+1);
	dfs(arr[node].second);
}
int main()
{
	int n;
	scanf("%d",&n);
	for (int i=0;i<n;i++)
	{
		scanf("%d",&arr[i].first);
		arr[i].second=i;
	}
	sort(arr,arr+n);
	for (int i=0;i<n;i++)
	{
		swap(arr[i].first,arr[i].second);
		arr[i].second=i;
	}
	sort(arr,arr+n);
	for (int i=0;i<n;i++)
	{
		if (!vis[i])
		{
			ans.push_back(vector<int>(0));
			dfs(i);
		}
	}
	printf("%d\n",ans.size());
	for (int i=0;i<ans.size();i++)
	{
		printf("%d",ans[i].size());
		for (int x=0;x<ans[i].size();x++)
		printf(" %d",ans[i][x]);
		printf("\n");
	}
}