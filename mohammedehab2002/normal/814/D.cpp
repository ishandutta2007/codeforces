#include <iostream>
#include <stdio.h>
#include <vector>
#include <math.h>
using namespace std;
vector<int> v[1005];
pair<pair<long long,long long>,long long> arr[1005];
long long dp[1005][2][2];
int par[1005];
long long distsq(long long x1,long long y1,long long x2,long long y2)
{
	return ((x1-x2)*(x1-x2)+(y1-y2)*(y1-y2));
}
int sign(int x)
{
	if (x)
	return -1;
	return 1;
}
void dfs(int node)
{
	long long sum[2][2]={{0,0},{0,0}};
	for (int i=0;i<v[node].size();i++)
	{
		dfs(v[node][i]);
		for (int x=0;x<=1;x++)
		{
			for (int j=0;j<=1;j++)
			sum[x][j]+=dp[v[node][i]][x][j];
		}
	}
	for (int i=0;i<=1;i++)
	{
		for (int x=0;x<=1;x++)
		{
			long long tmp=arr[node].second*arr[node].second;
			dp[node][i][x]=max(sum[i^1][x]+tmp*sign(i),sum[i][x^1]+tmp*sign(x));
		}
	}
}
int main()
{
    int n;
    scanf("%d",&n);
    for (int i=0;i<n;i++)
    scanf("%I64d%I64d%I64d",&arr[i].first.first,&arr[i].first.second,&arr[i].second);
    for (int i=0;i<n;i++)
    {
    	int idx=-1;
    	for (int x=0;x<n;x++)
    	{
    		if (distsq(arr[i].first.first,arr[i].first.second,arr[x].first.first,arr[x].first.second)<=(arr[i].second-arr[x].second)*(arr[i].second-arr[x].second) && arr[i].second<arr[x].second)
    		{
    			if (idx==-1)
    			idx=x;
    			else if (arr[idx].second>arr[x].second)
    			idx=x;
			}
		}
		par[i]=idx;
		if (idx!=-1)
		v[idx].push_back(i);
	}
	long long ans=0;
	for (int i=0;i<n;i++)
	{
		if (par[i]==-1)
		{
			dfs(i);
			ans+=dp[i][0][0];
		}
	}
	printf("%.9lf",(double)ans*acos(-1));
}