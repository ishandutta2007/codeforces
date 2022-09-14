#include<iostream>
#include<vector>
#include<algorithm>
#include<deque>
using namespace std;
int N,M;
long long sum[5050];
main()
{
	cin>>N>>M;
	vector<int>X(N);
	vector<pair<int,int> >Y(M);
	for(int i=0;i<N;i++)cin>>X[i];
	for(int i=0;i<M;i++)cin>>Y[i].first>>Y[i].second;
	sort(X.begin(),X.end());
	sort(Y.begin(),Y.end());
	vector<long long>dp(N+1,1e18);
	dp[0]=0;
	for(int i=0;i<M;i++)
	{
		int p=Y[i].first,c=Y[i].second;
		sum[0]=0;
		for(int j=0;j<N;j++)
		{
			sum[j+1]=sum[j]+abs(X[j]-p);
		}
		deque<pair<long long,int> >P;
		for(int j=0;j<=N;j++)
		{
			long long now=dp[j]-sum[j];
			while(!P.empty()&&P.back().first>=now)P.pop_back();
			P.push_back(make_pair(now,j));
			if(P.front().second+c<j)P.pop_front();
			dp[j]=P.front().first+sum[j];
		}
	}
	if(dp[N]==(long long)1e18)cout<<-1<<endl;
	else cout<<dp[N]<<endl;
}