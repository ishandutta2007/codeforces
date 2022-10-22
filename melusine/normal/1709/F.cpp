#include<iostream>
#include<cstdio>
#define mod 998244353
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
int ksm(int n,int k)
{
	int ans=1;
	while(k>=1)
	{
		if(k&1)ans=1LL*ans*n%mod;
		n=1LL*n*n%mod;
		k>>=1;
	}
	return ans;
} 
int r[600001],tr,lll;
void ntt(int* f,int flag)
{
	for(int i=1;i<tr;i++)if(i<r[i])swap(f[i],f[r[i]]);
	for(int j=1;j<tr;j<<=1)
	{
		int tt=ksm(3,(mod-1)/(j<<1));
		if(flag==-1)tt=ksm(tt,mod-2);
		for(int k=0;k<tr;k+=(j<<1))
		{
			int t=1;
			for(int l=0;l<j;l++,t=1LL*t*tt%mod)
			{
				int sth=f[k+l],sth2=1LL*f[j+k+l]*t%mod;
				f[k+l]=(sth+sth2)%mod;
				f[k+j+l]=(sth+mod-sth2)%mod;
			}
		}
	}
	if(flag==-1)
	{
		int sth=ksm(tr,mod-2);
		for(int i=0;i<tr;i++)f[i]=1LL*f[i]*sth%mod;
	}
}
int a[600004],b[600004];
int dp[16][200005];
int main()
{
	int n,k,f,now;
	n=read();
	k=read();
	f=read();
	for(int j=0;j<=k;j++)dp[1][j]=1;
	for(int i=2;i<=n;i++)
	{
		for(int sth=0;sth<=k;sth++)a[sth]=dp[i-1][sth];
		tr=1;
		lll=0;
		while(tr<=2*k)tr<<=1,lll++;
		for(int sth=k+1;sth<tr;sth++)a[sth]=0;
		for(int j=0;j<tr;j++)r[j]=(r[j>>1]>>1)|((j&1)<<(lll-1));
		ntt(a,1);
		for(int j=0;j<tr;j++)a[j]=1LL*a[j]*a[j]%mod;
		ntt(a,-1);
		now=0;
		for(int j=tr-1;j>k;j--)now=(now+a[j])%mod;
		for(int sth=k;sth>=0;sth--)
		{
			dp[i][sth]=(dp[i][sth]+now)%mod;
			dp[i][sth]=(dp[i][sth]+1LL*a[sth]*(k-sth+1)%mod)%mod;
			now=(now+a[sth])%mod;
		}
	}
	int ans=0;
	for(int j=0;j<=f;j++)
	{
		ans=(ans+1LL*dp[n][j]%mod*dp[n][f-j]%mod)%mod;
	}
	printf("%d\n",ans);
	return 0;
}