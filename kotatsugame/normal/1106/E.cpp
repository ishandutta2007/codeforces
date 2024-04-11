#include<iostream>
#include<cstdio>
#include<algorithm>
#include<vector>
#include<queue>
using namespace std;
const long long INF=8e18;
int n,m,k;
long long dp[201][1<<17];
vector<pair<pair<int,int>,int> >a[1<<17];
main()
{
	scanf("%d%d%d",&n,&m,&k);
	for(int i=0;i<k;i++)
	{
		int s,t,d,w;scanf("%d%d%d%d",&s,&t,&d,&w);
		a[s-1].push_back(make_pair(make_pair(w,d),t-1));
	}
	priority_queue<pair<pair<int,int>,int> >P;
	int id=0;
	for(int i=0;i<=n;i++)for(int j=0;j<=m;j++)dp[j][i]=INF;
	dp[0][0]=0;
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<a[i].size();j++)P.push(a[i][j]);
		while(!P.empty()&&P.top().second<i)P.pop();
		long long W=0;
		int t=i+1;
		if(!P.empty())
		{
			W=P.top().first.first;
			t=P.top().first.second;
		}
		for(int j=m;j>=0;j--)
		{
			dp[j][t]=min(dp[j][t],dp[j][i]+W);
			if(j<m)
			{
				dp[j+1][i+1]=min(dp[j+1][i+1],dp[j][i]);
			}
		}
	}
	long long ans=INF;
	for(int j=0;j<=m;j++)ans=min(ans,dp[j][n]);
	cout<<ans<<endl;
}