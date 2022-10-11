#include <bits/stdc++.h>
using namespace std;
int n,arr[1000005];
vector<int> v[(1<<22)];
void dfs(int a,int i)
{
	if (v[a].size()==2)
	return;
	for (int j:v[a])
	{
		if (j==i)
		return;
	}
	v[a].push_back(i);
	for (int j=0;j<22;j++)
	{
		if (a&(1<<j))
		dfs((a^(1<<j)),i);
	}
}
bool check(int ans)
{
	for (int i=0;i<n;i++)
	{
		int tmp=(ans^(ans&arr[i]));
		if (v[tmp].size()==2 && v[tmp][1]>i)
		return 1;
	}
	return 0;
}
int main()
{
	scanf("%d",&n);
	for (int i=0;i<n;i++)
	scanf("%d",&arr[i]);
	for (int i=n-1;i>=0;i--)
	dfs(arr[i],i);
	int ans=0;
	for (int i=21;i>=0;i--)
	{
		if (check(ans^(1<<i)))
		ans^=(1<<i);
	}
	printf("%d",ans);
}