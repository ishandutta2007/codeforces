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
int f[300005];
int jc[300005],njc[300005];
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
int zh(int n,int m)
{
	if(m<0||m>n)return 0;
	return 1LL*jc[n]*njc[m]%mod*njc[n-m]%mod;
}
int g[300005];
int main()
{
	jc[0]=1;
	for(int i=1;i<=300000;i++)jc[i]=1LL*i*jc[i-1]%mod;
	njc[300000]=ksm(jc[300000],mod-2);
	for(int i=299999;i>=0;i--)njc[i]=1LL*njc[i+1]*(i+1)%mod;
	f[0]=1;
	f[1]=1;
	for(int i=2;i<=300000;i++)
	{
		int now=1;
		f[i]=(f[i-1]+1LL*(i-1)*f[i-2])%mod;
	}
	g[0]=1;
	for(int i=1;i<=300000;i++)g[i]=1LL*g[i-1]*(2*i-1)%mod*2%mod;
	int t,n,ans;
	t=read();
	for(int greg=1;greg<=t;greg++)
	{
		n=read();
		ans=0;
		for(int i=0;i<=n/2;i+=2)
		{
			ans=(ans+1LL*zh(n-i,i)*g[i/2]%mod*f[n-2*i]%mod)%mod; 
		}
		printf("%d\n",ans);
	}
	return 0;
}