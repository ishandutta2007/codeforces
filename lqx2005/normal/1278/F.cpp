#include<bits/stdc++.h>
#define int long long
using namespace std;
const int mod=998244353;
const int maxn=5100;
int n,m,k;
int S[maxn][maxn];
int qpow(int a,int b)
{
	int res=1;
	for(;b>0;b/=2,a=a*a%mod) if(b%2) res=res*a%mod;
	return res;
}
signed main()
{
	scanf("%lld%lld%lld",&n,&m,&k);
	S[0][0]=1;
	for(int i=1;i<=k;i++)
	{
		for(int j=1;j<=k;j++)
		{
			if(i<j) continue;
			S[i][j]=S[i-1][j]*j+S[i-1][j-1];
			S[i][j]%=mod;
		}
	}
	int sum=1,p=1,q=qpow(m,mod-2),tot=n;
	int ans=0;
	for(int i=0;i<=k;i++)
	{
		ans+=sum*p%mod*S[k][i]%mod;
		ans%=mod;
		p=p*q%mod;
		sum=sum*tot%mod;
		tot--;
	}
	printf("%lld\n",ans);
	return 0;
	
	
}