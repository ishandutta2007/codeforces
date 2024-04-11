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
int jc[100005],njc[100005];
int main()
{
	int n,k;
	n=read();
	k=read();
	if(k>=n)
	{
		printf("%d\n",ksm(2,n));
		return 0;
	}
	jc[0]=1;
	for(int i=1;i<=n;i++)jc[i]=1LL*i*jc[i-1]%mod;
	njc[n]=ksm(jc[n],mod-2);
	for(int i=n-1;i>=0;i--)njc[i]=1LL*(i+1)*njc[i+1]%mod;
	int ans=0;
	for(int i=0;i<=k;i++)ans=(ans+1LL*jc[n]*njc[i]%mod*njc[n-i]%mod)%mod;
	printf("%d\n",ans);
	return 0;
}