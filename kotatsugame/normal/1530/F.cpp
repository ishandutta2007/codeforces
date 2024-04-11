#pragma GCC target("avx2")
#pragma GCC optimize("O3")
#pragma GCC optimize("unroll-loops")
#include<iostream>
#include<algorithm>
using namespace std;
const unsigned int mod=31607;
const unsigned int inv1e4=3973;
int N,A[21][21];
unsigned int dp[1<<23];
unsigned int pre[1<<23];
main()
{
	cin>>N;
	for(int i=0;i<N;i++)for(int j=0;j<N;j++)cin>>A[i][j];
	const int md=1<<N,nd=1<<N+1;
	dp[(1<<N+2)-1]=1;
	for(int i=0;i<N;i++)
	{
		for(int j=0;j<1<<N+2;j++)pre[j]=dp[j];
		int allp=1;
		for(int j=0;j<N;j++)
		{
			unsigned int p=A[i][j]*inv1e4%mod;
			unsigned int q=(1+mod-p)%mod;
			allp=allp*p%mod;
			int l=j,r=N-j-1;
			const int nj=1<<j;
			if(i==j)
			{
				if(N-i-1==j)
				{
					for(int a=0;a<1<<r;a++)
					{
						int L=a<<j+1;
						int R=L|1<<l;
						for(int b=L;b<R;b++)
						{
							dp[b]+=(dp[b|nj]+dp[b|md]+dp[b|nd]+dp[b|nj|md]+dp[b|nj|nd]+dp[b|md|nd]+dp[b|nj|md|nd])%mod*q;
							dp[b]%=mod;
							dp[b|nj]=dp[b|nj]*p%mod;
							dp[b|md]=dp[b|md]*p%mod;
							dp[b|nd]=dp[b|nd]*p%mod;
							dp[b|nj|md]=dp[b|nj|md]*p%mod;
							dp[b|nj|nd]=dp[b|nj|nd]*p%mod;
							dp[b|md|nd]=dp[b|md|nd]*p%mod;
							dp[b|nj|md|nd]=dp[b|nj|md|nd]*p%mod;
						}
					}
				}
				else
				{
					for(int a=0;a<1<<r+1;a++)
					{
						int na=a&1<<r?a^1<<r|1<<r+1:a;
						int L=na<<j+1;
						int R=L|1<<l;
						for(int b=L;b<R;b++)
						{
							dp[b]+=(dp[b|nj]+dp[b|md]+dp[b|nj|md])*q;
							dp[b]%=mod;
							dp[b|nj]=dp[b|nj]*p%mod;
							dp[b|md]=dp[b|md]*p%mod;
							dp[b|nj|md]=dp[b|nj|md]*p%mod;
						}
					}
				}
			}
			else
			{
				if(N-i-1==j)
				{
					for(int a=0;a<1<<r+1;a++)
					{
						int L=a<<j+1;
						int R=L|1<<l;
						for(int b=L;b<R;b++)
						{
							dp[b]+=(dp[b|nj]+dp[b|nd]+dp[b|nj|nd])*q;
							dp[b]%=mod;
							dp[b|nj]=dp[b|nj]*p%mod;
							dp[b|nd]=dp[b|nd]*p%mod;
							dp[b|nj|nd]=dp[b|nj|nd]*p%mod;
						}
					}
				}
				else
				{
					for(int a=0;a<1<<r+2;a++)
					{
						int L=a<<j+1;
						int R=L|nj;
						for(int b=0;b<nj;b++)dp[L+b]+=dp[L+nj+b]*q;
						for(int b=L;b<R;b++)dp[b]%=mod;
						L+=nj,R+=nj;
						for(int b=L;b<R;b++)dp[b]=dp[b]*p%mod;
					}
				}
			}
		}
		for(int j=0;j<1<<N+2;j++)
		{
			int now=pre[j]*allp%mod;
			if(dp[j]<now)dp[j]+=mod;
			dp[j]-=now;
		}
	}
	int ans=(1+mod-dp[0])%mod;
	cout<<ans<<endl;
}