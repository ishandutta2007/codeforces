#include<iostream>
#include<cstdio>
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
int jc[400005],njc[400005];
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
int a[400005];
int main()
{
	int n;
	n=read();
	for(int i=0;i<=n;i++)a[i]=read();
	while(n>=1&&a[n]==0)n--;
	if(n==0)
	{
		printf("0\n");
		return 0;
	}
	jc[0]=1;
	for(int i=1;i<=400000;i++)jc[i]=1LL*i*jc[i-1]%mod;
	njc[400000]=ksm(jc[400000],mod-2);
	for(int i=399999;i>=0;i--)njc[i]=1LL*(i+1)*njc[i+1]%mod;
	int ans=0;
	for(int i=0;i<=n;i++)
	{
		if(i==0||a[i]==a[i-1])
		{
			ans=(ans+1LL*jc[i+a[i]-1]*njc[i]%mod*njc[a[i]-1]%mod)%mod;
			continue;
		}
		for(int j=a[i-1]-1;j>=a[i];j--)
		{
			ans=(ans+1LL*1LL*jc[i+j-1]*njc[i-1]%mod*njc[j]%mod)%mod;
		}
		ans=(ans+1LL*jc[i+a[i]-1]*njc[i]%mod*njc[a[i]-1]%mod)%mod;
	}
	for(int j=a[n]-1;j>=0;j--)
	{
		ans=(ans+1LL*1LL*jc[n+j]*njc[n]%mod*njc[j]%mod)%mod;
	}
	printf("%d\n",(ans+mod-1)%mod);
	return 0;
}