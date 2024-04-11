#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<map>
#define int long long
#define mod 1000000007
using namespace std;
inline int read()
{
	int n=0,f=1,ch=getchar();
	while(ch<'0'||ch>'9')
	{
		if(ch=='-')f=-1;
		ch=getchar();
	}
	while(ch>='0'&&ch<='9')
	{
		n=n*10+ch-'0';
		ch=getchar();
	}
	return n*f;
}
int dp[51][51][2],jc[51],njc[51];
int ksm(int n,int k)
{
	int ans=1;
	while(k>=1)
	{
		if(k&1)ans=1LL*ans*n%mod;
		k>>=1;
		n=1LL*n*n%mod;
	}
	return ans;
}
int c(int n,int m)
{
	if(m<0||m>n)return 0;
	return 1LL*jc[n]*njc[n-m]%mod*njc[m]%mod;
}
signed main()
{
	int n,k,gre;
	n=read();
	k=read();
	jc[0]=1;
	for(int i=1;i<=n;i++)jc[i]=1LL*jc[i-1]*i%mod;
	njc[n]=ksm(jc[n],mod-2);
	for(int i=n-1;i>=0;i--)njc[i]=1LL*njc[i+1]*(i+1)%mod;
	dp[1][0][0]=1;
	dp[1][0][1]=0;
	for(int i=2;i<=n;i++)
	{
		for(int j=1;j<=i;j++)
		{
			dp[i][j][1]=1LL*i*(dp[i-1][j-1][0]);
			dp[i][j][0]=1LL*i*(dp[i-1][j][1])%mod;
		}
		//printf("%lld\n",dp[3][1][0]);
		for(int j=1;j<=i-2;j++)
		{
			if(i-1-j<j)continue;
			for(int k=0;k<=i;k++)
			{
				for(int sth=0;sth<=k;sth++)
				{
					if(i-1-j==j)gre=(mod+1)/2;
					else gre=1;
					dp[i][k][0]=(dp[i][k][0]+1LL*gre*i%mod*c(i-1,j)%mod*(dp[j][sth][1])%mod*(dp[i-1-j][k-sth][1])%mod)%mod;
					if(sth==k)continue;
					dp[i][k][1]=(dp[i][k][1]+1LL*gre*i%mod*c(i-1,j)%mod*(dp[j][sth][0]+dp[j][sth][1])%mod*(dp[i-1-j][k-1-sth][0]+dp[i-1-j][k-1-sth][1])%mod)%mod;
					dp[i][k][1]=(dp[i][k][1]+mod-1LL*gre*i%mod*c(i-1,j)%mod*(dp[j][sth][1])%mod*(dp[i-1-j][k-1-sth][1])%mod)%mod;
				}
			}
		}
		//for(int k=0;k<=i;k++)printf("%d %d ",dp[i][k][0],dp[i][k][1]);
		//printf("\n");
	}
	printf("%lld\n",(dp[n][k][0]+dp[n][k][1])%mod*njc[n]%mod*jc[n-1]%mod);
	return 0;
}