#include <iostream>
#include <algorithm>
#include <string.h>
#include <vector>
using namespace std;
pair<int,int> arr[1005];
int w[1005],b[1005],sw[1005],sv[1005],dp[1005],tmp[1005];
vector<int> v[1005];
int find(int x)
{
	if (arr[x].first!=x)
	arr[x].first=find(arr[x].first);
	return arr[x].first;
}
void Union(int x,int y)
{
	x=find(x);
	y=find(y);
	if (x==y)
	return;
	if (arr[x].second>arr[y].second)
	arr[y].first=x;
	else if (arr[y].second>arr[y].second)
	arr[x].first=y;
	else
	{
		arr[x].first=y;
		arr[y].second++;
	}
}
int main()
{
	int n,m,s;
	cin >> n >> m >> s;
	for (int i=0;i<n;i++)
	cin >> w[i];
	for (int i=0;i<n;i++)
	cin >> b[i];
	for (int i=0;i<n;i++)
	arr[i]=make_pair(i,0);
	for (int i=0;i<m;i++)
	{
		int a,b;
		cin >> a >> b;
		Union(a-1,b-1);
	}
	for (int i=0;i<n;i++)
	v[find(i)].push_back(i);
	for (int i=0;i<n;i++)
	{
		for (int x=0;x<v[i].size();x++)
		{
			sw[i]+=w[v[i][x]];
			sv[i]+=b[v[i][x]];
		}
	}
	for (int i=0;i<n;i++)
	{
		memset(tmp,0,sizeof(tmp));
		for (int x=s;x>=0;x--)
		{
			for (int j=0;j<v[i].size();j++)
			{
				if (x-w[v[i][j]]>=0)
				tmp[x]=max(tmp[x],dp[x-w[v[i][j]]]+b[v[i][j]]);
			}
			if (x-sw[i]>=0)
			tmp[x]=max(tmp[x],dp[x-sw[i]]+sv[i]);
		}
		for (int x=0;x<=s;x++)
		dp[x]=max(dp[x],tmp[x]);
	}
	cout << *max_element(dp,dp+1005);
}