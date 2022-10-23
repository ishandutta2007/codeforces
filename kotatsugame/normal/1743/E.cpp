#include<iostream>
using namespace std;
int p1,p2;
long long t1,t2;
int H,S;
long long dp[5001];
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cin>>p1>>t1>>p2>>t2>>H>>S;
	for(int i=0;i<=H;i++)dp[i]=1e18;
	dp[H]=0;
	long long ans=1e18;
	for(int i=H;i>=1;i--)if(dp[i]<(long long)1e18)
	{
		{
			long long l=0,r=5e15;
			while(r-l>1)
			{
				long long mid=(l+r)/2;
				long long a1=mid/t1,a2=mid/t2;
				long long dm=i;
				if((dm+p1-S-1)/(p1-S)<=a1)
				{
					r=mid;
					continue;
				}
				dm-=a1*(p1-S);
				if((dm+p2-S-1)/(p2-S)<=a2)r=mid;
				else l=mid;
			}
			ans=min(ans,dp[i]+r);
		}
		for(int k=1;(k-1)*(p1-S)<i;k++)
		{
			long long wt=k*t1;//~5e15
			if(wt<t2)continue;
			int dm=i-(k-1)*(p1-S);
			long long a2=(wt-t2)/t2;
			if((dm+p2-S-1)/(p2-S)<=a2)break;
			dm-=a2*(p2-S);
			if(dm<=p1+p2-S)ans=min(ans,dp[i]+wt);
			else
			{
				dm-=p1+p2-S;
				dp[dm]=min(dp[dm],dp[i]+wt);
			}
		}
		for(int k=1;(k-1)*(p2-S)<i;k++)
		{
			long long wt=k*t2;//~5e15
			if(wt<t1)continue;
			int dm=i-(k-1)*(p2-S);
			long long a1=(wt-t1)/t1;
			if((dm+p1-S-1)/(p1-S)<=a1)break;
			dm-=a1*(p1-S);
			if(dm<=p1+p2-S)ans=min(ans,dp[i]+wt);
			else
			{
				dm-=p1+p2-S;
				dp[dm]=min(dp[dm],dp[i]+wt);
			}
		}
	}
	cout<<ans<<endl;
}