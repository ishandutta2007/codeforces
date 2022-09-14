#include<cstdio>
#include<vector>
#include<algorithm>
using namespace std;
int T,N,A[3030];
main()
{
	scanf("%d",&T);
	for(;T--;)
	{
		scanf("%d",&N);
		vector<vector<int> >idx(N);
		for(int i=0;i<N;i++)
		{
			scanf("%d",&A[i]);
			idx[A[i]-1].push_back(i);
		}
		vector<pair<int,int> >E;
		vector<int>cnt(N);
		vector<vector<pair<int,int> > >to(N);
		for(int i=0;i<N;i++)
		{
			int a=A[i]-1;
			cnt[a]++;
			for(int j=cnt[a];j<idx[a].size();j++)
			{
				to[i].push_back(make_pair(idx[a][j],-1));
				E.push_back(make_pair(i,j-cnt[a]));
			}
		}
		sort(E.begin(),E.end(),[&to](const pair<int,int>&a,const pair<int,int>&b)
		{
			int au=a.first,ai=a.second;
			int bu=b.first,bi=b.second;
			return to[au][ai].first-au<to[bu][bi].first-bu;
		});
		vector<int>dp(N+1);
		for(pair<int,int>e:E)
		{
			int lst=to[e.first][e.second].first;
			fill(dp.begin()+e.first,dp.begin()+lst,0);
			int now=1;
			for(int u=e.first+1;u<lst;u++)
			{
				now=max(now,dp[u]+1);
				dp[u+1]=max(dp[u+1],dp[u]);
				for(pair<int,int>ne:to[u])
				{
					if(ne.first>=lst)break;
					dp[ne.first]=max(dp[ne.first],dp[u]+ne.second);
				}
			}
			to[e.first][e.second].second=now;
		}
		fill(dp.begin(),dp.end(),0);
		int ans=0;
		for(int u=0;u<N;u++)
		{
			ans=max(ans,dp[u]);
			dp[u+1]=max(dp[u+1],dp[u]);
			for(pair<int,int>ne:to[u])
			{
				dp[ne.first]=max(dp[ne.first],dp[u]+ne.second);
			}
		}
		printf("%d\n",N-1-ans);
	}
}