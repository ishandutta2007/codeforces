#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
int arr[200005],cnt[200005],res[200005];
vector<int> v[200005];
void dfs(int node,int pnode,int d,int gcd)
{
	int ans=1;
	for (int i=1;i*i<=arr[node];i++)
	{
		if (arr[node]%i==0)
		{
			cnt[i]++;
			if (i*i!=arr[node])
			cnt[arr[node]/i]++;
		}
		if (cnt[i]>=d)
		ans=max(ans,i);
		if (cnt[arr[node]/i]>=d)
		ans=max(ans,arr[node]/i);
	}
	ans=max(ans,gcd);
	if (!gcd)
	gcd=arr[node];
	else
	gcd=__gcd(gcd,arr[node]);
	res[node]=ans;
	for (int i=0;i<v[node].size();i++)
	{
		if (v[node][i]!=pnode)
		dfs(v[node][i],node,d+1,gcd);
	}
	for (int i=1;i*i<=arr[node];i++)
	{
		if (arr[node]%i==0)
		{
			cnt[i]--;
			if (i*i!=arr[node])
			cnt[arr[node]/i]--;
		}
	}
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
	dfs(1,0,0,0);
	for (int i=1;i<=n;i++)
	printf("%d ",res[i]);
}