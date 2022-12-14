#include<iostream>
#include<cstdio>
#include<vector>
#include<deque>
using namespace std;
int n,m,x,y,cur,num[111111],dp[555][111111],val,nu,curval,ans;
vector<int> g[111111];
bool used[111111];
vector<pair<int,int> > shop;
deque<pair<int,int> > q;
void dfs(int i)
{
	cur++;
	used[i]=1;
	for (int j=0;j<g[i].size();j++)
	{
		int to=g[i][j];
		if (!used[to]) dfs(to);
	}
}
bool lucky(int i)
{
	while(i)
	{
		if (i%10!=4 && i%10!=7) return 0;
		i/=10;
	}
	return 1;
}
int main()
{
	scanf("%d%d",&n,&m);
	for (int i=1;i<=m;i++)
	{
		scanf("%d%d",&x,&y);
		g[x].push_back(y);
		g[y].push_back(x); 
	}
	for (int i=1;i<=n;i++)
	{
		if (!used[i])
		{
			cur=0;
			dfs(i);
			num[cur]++;
		}
	}
	shop.push_back(make_pair(-1,-1)); 
	for (int i=1;i<=n;i++)
	{
		if (num[i]) shop.push_back(make_pair(i,num[i])); 
	}
	for (int i=0;i<shop.size();i++) 
	{
		for (int j=1;j<=n;j++)
		dp[i][j]=1e9;
	}
	dp[0][0]=0;
	for (int i=1;i<shop.size();i++)
	{
		val=shop[i].first,nu=shop[i].second;
		for (int j=0;j<val;j++)
		{
			q.clear();
			for (int k=j,cur=1;k<=n;k+=val,cur++)
			{
				curval=dp[i-1][k]-cur;
				while(!q.empty())
				{
					if (q.back().first>=curval) q.pop_back();
					else break;
				}
				q.push_back(make_pair(curval,cur));
				if (q.front().second<cur-nu) q.pop_front();
				dp[i][k]=q.front().first+cur; 
			}
		}
	}
	ans=1e9;
	for (int i=1;i<=n;i++)
	{
		if (lucky(i))
		{
			ans=min(ans,dp[shop.size()-1][i]);
		}
	}
	if (ans>=1e8) printf("-1\n");
	else printf("%d\n",ans-1);
	return 0;
}