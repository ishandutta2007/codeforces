#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
using namespace std;
vector<pair<int,int> > v[100005];
int dp[100005][2],k;
void dfs(int node,int pnode)
{
	vector<pair<int,int> > tmp;
	set<int> s;
	int ans=0;
	for (int i=0;i<v[node].size();i++)
	{
		if (v[node][i].first!=pnode)
		{
			dfs(v[node][i].first,node);
			tmp.push_back(make_pair(dp[v[node][i].first][0]+v[node][i].second,v[node][i].first));
		}
	}
	sort(tmp.begin(),tmp.end());
	for (int i=tmp.size()-1;i>max((int)tmp.size()-k,-1);i--)
	{
		dp[node][0]+=tmp[i].first;
		s.insert(tmp[i].second);
	}
	dp[node][1]=dp[node][0];
	for (int i=0;i<v[node].size();i++)
	{
		if (v[node][i].first!=pnode)
		{
			if (s.find(v[node][i].first)==s.end())
			dp[node][1]=max(dp[node][1],dp[v[node][i].first][1]+dp[node][0]+v[node][i].second);
			else
			dp[node][1]=max(dp[node][1],dp[v[node][i].first][1]+dp[node][0]-dp[v[node][i].first][0]+((tmp.size()>=k)? tmp[tmp.size()-k].first:0));
		}
	}
}
int main()
{
	int n;
	scanf("%d%d",&n,&k);
	for (int i=1;i<n;i++)
	{
		int a,b,c;
		scanf("%d%d%d",&a,&b,&c);
		v[a].push_back(make_pair(b,c));
		v[b].push_back(make_pair(a,c));
	}
	dfs(0,0);
	printf("%d",max(dp[0][0],dp[0][1]));
}