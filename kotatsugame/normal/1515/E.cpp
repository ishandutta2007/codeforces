#include<iostream>
using namespace std;
int N,M;
long long dp[404][404];
long long fac[404],inv[404];
long long modpow(long long a,long long b){return b?modpow(a*a%M,b/2)*(b%2?a:1)%M:1;}
long long comb(int a,int b)
{
	return fac[a]*inv[b]%M*inv[a-b]%M;
}
main()
{
	cin>>N>>M;
	N++;
	fac[0]=1;
	for(int i=1;i<=N;i++)fac[i]=fac[i-1]*i%M;
	inv[N]=modpow(fac[N],M-2);
	for(int i=N;i--;)inv[i]=inv[i+1]*(i+1)%M;
	dp[0][0]=1;
	for(int i=0;i<N;i++)
	{
		for(int k=2;i+k<=N;k++)
		{
			int use=k-1;
			long long way=0;
			for(int j=0;j<use;j++)
			{
				int l=j,r=use-j-1;
				(way+=comb(l+r,l))%=M;
			}
			for(int u=0;u<=i;u++)
			{
				(dp[i+k][u+k-1]+=dp[i][u]*comb(u+k-1,k-1)%M*way%M)%=M;
			}
		}
	}
	long long ans=0;
	for(int u=0;u<=N;u++)(ans+=dp[N][u])%=M;
	cout<<ans<<endl;
}