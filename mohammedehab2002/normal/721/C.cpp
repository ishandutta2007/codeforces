#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
using namespace std;
#define mp make_pair
#define f first
#define s second
#define inf (1<<30)
vector<pair<int,int> > v[5005];
int n,m,t;
int dp[5005][5005],par[5005][5005];
int main()
{
	cin >> n >> m >> t;
	for (int i=0;i<m;i++)
	{
		int a,b,c;
		cin >> a >> b >> c;
		v[a].push_back(make_pair(b,c));
	}
	for (int i=1;i<=n;i++)
	{
		for (int x=1;x<=n;x++)
		dp[i][x]=inf;
	}
	queue<pair<int,int> > q;
	q.push(mp(1,1));
	dp[1][1]=0;
	int ans=1;
	while (!q.empty())
	{
		int node=q.front().f,d=q.front().s;
		if (node==n)
		ans=d;
		for (int i=0;i<v[node].size();i++)
		{
			if (dp[node][d]+v[node][i].s<dp[v[node][i].f][d+1] && dp[node][d]+v[node][i].s<=t)
			{
				q.push(mp(v[node][i].f,d+1));
				dp[v[node][i].f][d+1]=dp[node][d]+v[node][i].s;
				par[v[node][i].f][d+1]=node;
			}
		}
		q.pop();
	}
	cout << ans << endl;
	vector<int> path;
	int cur=n;
	for (int i=ans;i>1;i--)
	{
		path.push_back(par[cur][i]);
		cur=par[cur][i];
	}
	reverse(path.begin(),path.end());
	path.push_back(n);
	for (int i=0;i<path.size();i++)
	cout << path[i] << ' ';
}