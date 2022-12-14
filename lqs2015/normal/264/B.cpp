#include<bits/stdc++.h>
using namespace std;
const int maxn=100000;
vector<int> v[111111];
int n,a[111111],dp[111111],cur,ans;
void Init()
{
	for (int i=2;i<=maxn;i++)
	{
		for (int j=i;j<=maxn;j+=i)
		{
			v[j].push_back(i);
		}
	}
}
int main()
{
	Init();
	scanf("%d",&n);
	for (int i=1;i<=n;i++) scanf("%d",&a[i]);
	sort(a+1,a+n+1);
	for (int i=1;i<=n;i++)
	{
		cur=1;
		for (int j=0;j<v[a[i]].size();j++)
		{
			cur=max(cur,dp[v[a[i]][j]]+1);
		}
		ans=max(ans,cur);
		for (int j=0;j<v[a[i]].size();j++)
		{
			dp[v[a[i]][j]]=max(dp[v[a[i]][j]],cur);
		}
	}
	printf("%d\n",ans);
	return 0;
}