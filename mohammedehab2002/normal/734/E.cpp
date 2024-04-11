#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
vector<int> v[200005];
int arr[200005],dp[200005],ans=0;
bool dont[200005];
int dfs(int node)
{
	dont[node]=1;
	vector<int> tmp;
	for (int i=0;i<v[node].size();i++)
	{
		if (arr[node]==arr[v[node][i]])
		{
			while (v[v[node][i]].size())
			{
				if (!dont[v[v[node][i]].back()])
				v[node].push_back(v[v[node][i]].back());
				v[v[node][i]].pop_back();
			}
			dont[v[node][i]]=1;
		}
		else if (!dont[v[node][i]])
		{
			dfs(v[node][i]);
			tmp.push_back(dp[v[node][i]]);
			dp[node]=max(dp[node],dp[v[node][i]]+1);
		}
	}
	sort(tmp.begin(),tmp.end());
	ans=max(ans,dp[node]);
	if (tmp.size()>1)
	ans=max(ans,tmp[tmp.size()-1]+tmp[tmp.size()-2]+2);
	return dp[node];
}
int main()
{
	int n;
	scanf("%d",&n);
	for (int i=1;i<=n;i++)
	scanf("%d",&arr[i]);
	for (int i=1;i<n;i++)
	{
		int a,b;
		scanf("%d%d",&a,&b);
		v[a].push_back(b);
		v[b].push_back(a);
	}
	dfs(1);
	printf("%d",(ans+1)/2);
}