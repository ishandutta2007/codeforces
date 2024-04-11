#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
int N;
string S[20];
int cnt[20],mc[20],ap[20];
vector<pair<int,int> >vis[20];
int sum[1<<20];
int dp[1<<20];
main()
{
	cin>>N;
	for(int i=0;i<N;i++)
	{
		cin>>S[i];
		mc[i]=0;
		for(char c:S[i])
		{
			cnt[i]+=c=='('?1:-1;
			if(mc[i]>cnt[i])
			{
				vis[i].push_back(make_pair(mc[i],ap[i]));
				ap[i]=0;
				mc[i]=cnt[i];
			}
			if(mc[i]==cnt[i])ap[i]++;
		}
		vis[i].push_back(make_pair(mc[i],ap[i]));
		sort(vis[i].begin(),vis[i].end());
	}
	for(int i=0;i<1<<N;i++)dp[i]=-1;
	dp[0]=0;
	int ans=0;
	for(int i=0;i<1<<N;i++)if(dp[i]>=0)
	{
		if(ans<dp[i])ans=dp[i];
		int now=sum[i];
		for(int j=0;j<N;j++)if(!(i>>j&1))
		{
			auto it=lower_bound(vis[j].begin(),vis[j].end(),make_pair(-now,0));
			if(it!=vis[j].end()&&it->first==-now)
			{
				ans=max(ans,dp[i]+it->second);
			}
			if(now+mc[j]<0)continue;
			int nxt=dp[i];
			if(now+mc[j]==0)nxt+=ap[j];
			int ni=i|1<<j;
			sum[ni]=now+cnt[j];
			if(dp[ni]<nxt)dp[ni]=nxt;
		}
	}
	cout<<ans<<endl;
}