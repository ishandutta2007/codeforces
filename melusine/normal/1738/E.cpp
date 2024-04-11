#include<bits/stdc++.h>
#define int long long
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
int jc[100005],njc[100005];
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
int tl[100005],tr[100005],dp[100005],cnt;
int a[100005],qzh[100005];
int cm[100005];
int zh(int n,int m)
{
	if(m<0||m>n)return 0;
	return 1LL*jc[n]*njc[m]%mod*njc[n-m]%mod;
}
signed main()
{
	jc[0]=1;
	for(int i=1;i<=100000;i++)jc[i]=1LL*i*jc[i-1]%mod;
	njc[100000]=ksm(jc[100000],mod-2);
	for(int i=99999;i>=0;i--)njc[i]=1LL*(i+1)*njc[i+1]%mod;
	cm[0]=1;
	for(int i=1;i<=100003;i++)cm[i]=2LL*cm[i-1]%mod; 
	int t,n,k,now,x,sl,sr;
	t=read();
	for(int greg=1;greg<=t;greg++)
	{
		n=read();
		a[0]=1;
		for(int i=1;i<=n;i++)a[i]=read();
		a[n+1]=1;
		qzh[0]=a[0];
		for(int i=1;i<=n+1;i++)qzh[i]=qzh[i-1]+a[i];
		cnt=0;
		x=n+1; 
		for(int i=0;i<=n+1;i++)
		{
			while(x>=i+1&&qzh[n+1]-qzh[x-1]<qzh[i])x--;
			if(x>=i+1&&qzh[n+1]-qzh[x-1]==qzh[i]&&a[i]!=0)
			{
				tl[++cnt]=i+1;
				tr[cnt]=x-1;
				dp[cnt]=0;
				//printf("%lld %lld\n",tl[cnt],tr[cnt]);
			}
		}
		int het=1;
		for(int i=cnt;i>=1;i--)
		{
			if(tl[i]>tr[i])
			{
				het=2;
				dp[i]=1;
				continue;
			}
			sl=0;
			sr=0;
			while(a[tl[i]+sl]==0)sl++;
			while(a[tr[i]-sr]==0)sr++;
			if(sl>=tr[i]-tl[i]+1)
			{
				dp[i]=cm[tr[i]-tl[i]];
				het=cm[tr[i]-tl[i]+2];
				continue;
			}
			int sth1=0;
			for(int i=0;i<=min(sl,sr);i++)sth1=(sth1+1LL*zh(sl,i)*zh(sr,i)%mod)%mod;
			dp[i]=(1LL*sth1*(het))%mod;
			int sth2=0;
			for(int i=0;i<=min(sl,sr)+1;i++)sth2=(sth2+1LL*zh(sl+1,i)*zh(sr+1,i)%mod)%mod;
			het=(1LL*sth2*(het)%mod)%mod;
			//printf("%lld %lld %lld\n",i,dp[i],het);
		}
		printf("%lld\n",dp[1]);
	}
	return 0;
}