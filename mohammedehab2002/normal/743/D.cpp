#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
vector<int> v[200005];
long long s[200005],dp[200005],arr[200005];
void dfs(int node,int pnode)
{
	s[node]=arr[node];
	for (int i=0;i<v[node].size();i++)
	{
		if (v[node][i]!=pnode)
		dfs(v[node][i],node),s[node]+=s[v[node][i]],dp[node]=max(dp[node],dp[v[node][i]]);
	}
	dp[node]=max(dp[node],s[node]);
}
long long dfs2(int node,int pnode)
{
	long long ans=-(1LL<<62);
	vector<long long> c;
	for (int i=0;i<v[node].size();i++)
	{
		if (v[node][i]!=pnode)
		c.push_back(dp[v[node][i]]);
	}
	sort(c.begin(),c.end());
	if (c.size()>1)
	ans=max(ans,c[c.size()-1]+c[c.size()-2]);
	for (int i=0;i<v[node].size();i++)
	{
		if (v[node][i]!=pnode)
		ans=max(ans,dfs2(v[node][i],node));
	}
	return ans;
}
int main()
{
	int n;
	cin >> n;
	for (int i=1;i<=n;i++)
	cin >> arr[i],dp[i]=-(1LL<<62);
	for (int i=1;i<n;i++)
	{
		int a,b;
		cin >> a >> b;
		v[a].push_back(b);
		v[b].push_back(a);
	}
	dfs(1,0);
	long long ans=dfs2(1,0);
	if (ans!=-(1LL<<62))
	cout << ans;
	else
	cout << "Impossible";
}