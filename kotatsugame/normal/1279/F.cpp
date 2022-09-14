#include<iostream>
#include<algorithm>
#include<vector>
#include<cmath>
using namespace std;
int N,K,L;
string s;
bool A[1<<20];
int sum[1<<20];
pair<long long,int>calc(long long P)
{
	vector<pair<long long,int> >dp(N+1,make_pair(1e18,0));
	dp[0]=make_pair(0,0);
	for(int i=0;i<N;i++)
	{
		dp[i+1]=min(dp[i+1],dp[i]);
		int nxt=i+L;
		if(nxt>N)nxt=N;
		dp[nxt]=min(dp[nxt],make_pair(dp[i].first+sum[nxt]-sum[i]+P,dp[i].second+1));
	}
	return dp[N];
}
int f()
{
	int l=-1e9,r=1e9;
	sum[0]=0;
	for(int i=0;i<N;i++)sum[i+1]=sum[i]-A[i];
	while(r-l>1)
	{
		long long pe=(l+r)/2;
		pair<long long,int>X=calc(pe);
		if(X.second>K)l=pe;
		else r=pe;
	}
	pair<long long,int>X=calc(r);
	return -sum[N]+(int)X.first-r*K;
}
main()
{
	cin>>N>>K>>L>>s;
	if((long long)K*L>=N)
	{
		cout<<0<<endl;
		return 0;
	}
	for(int i=0;i<N;i++)A[i]='A'<=s[i]&&s[i]<='Z';
	int x=f();
	for(int i=0;i<N;i++)A[i]='a'<=s[i]&&s[i]<='z';
	int y=f();
	cout<<min(x,y)<<endl;
}