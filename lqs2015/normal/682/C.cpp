#include<iostream>
#include<vector>
using namespace std;
vector<pair<long long,long long> > g[111111];
long long n,a[111111],x,y,s;
bool vis[111111];
void dfs(long long i,long long n)
{
	vis[i]=1;
	if (n<0) n=0;
	for (long long j=0;j<g[i].size();j++)
	{
		if (!vis[g[i][j].first] && n+g[i][j].second<=a[g[i][j].first])
		{
			s++;
			dfs(g[i][j].first,n+g[i][j].second);
		}
	}
}
int main()
{
	cin>>n;
	s=1;
	for (long long i=1;i<=n;i++)
	{
		cin>>a[i];
	}
	for (long long i=1;i<n;i++)
	{
		cin>>x>>y;
		g[i+1].push_back(make_pair(x,y));
		g[x].push_back(make_pair(i+1,y));  
	}
	dfs(1,0);
	cout<<n-s<<endl;
	return 0;
}