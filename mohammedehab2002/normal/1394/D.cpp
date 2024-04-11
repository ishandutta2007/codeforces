#include <bits/stdc++.h>
using namespace std;
bool vis[200005];
vector<int> v[200005];
int t[200005],h[200005],f[200005],s[200005];
long long dp[200005][2];
void dfs(int node,int p,bool r=0)
{
	vis[node]=1;
	vector<pair<long long,long long> > tmp;
	for (int u:v[node])
	{
		if (u!=p)
		{
			dfs(u,node);
			tmp.push_back({dp[u][1]-dp[u][0],dp[u][0]});
		}
	}
	sort(tmp.begin(),tmp.end());
	for (int i=0;i<2;i++)
	{
		int ff=f[node]+(!r && !i),ss=s[node]+(!r && i)+tmp.size();
		long long cur=0;
		for (auto p:tmp)
		cur+=p.second;
		dp[node][i]=1LL*max(ff,ss)*t[node]+cur;
		for (auto p:tmp)
		{
			ff++;
			ss--;
			cur+=p.first;
			dp[node][i]=min(dp[node][i],1LL*max(ff,ss)*t[node]+cur);
		}
	}
}
int main()
{
	int n;
	scanf("%d",&n);
	for (int i=1;i<=n;i++)
	scanf("%d",&t[i]);
	for (int i=1;i<=n;i++)
	scanf("%d",&h[i]);
	for (int i=1;i<n;i++)
	{
		int a,b;
		scanf("%d%d",&a,&b);
		if (h[a]>h[b])
		swap(a,b);
		if (h[a]==h[b])
		{
			v[a].push_back(b);
			v[b].push_back(a);
		}
		else
		{
			f[a]++;
			s[b]++;
		}
	}
	long long ans=0;
	for (int i=1;i<=n;i++)
	{
		if (!vis[i])
		{
			dfs(i,0,1);
			ans+=dp[i][0];
		}
	}
	printf("%I64d",ans);
}