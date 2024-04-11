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
int phi[100005];
int pri[100005],cnt;
bool vis[100005];
int gcd(int n,int m)
{
	while(n^=m^=n^=m%=n);
	return m;
}
long long lcm(int n,int m)
{
	return 1LL*n*m/gcd(n,m);
}
int main()
{
	int n;
	n=read();
	phi[1]=0;
	for(int i=2;i<=n;i++)
	{
		if(!vis[i])
		{
			pri[++cnt]=i;
			phi[i]=i-1;
		}
		for(int j=1;j<=cnt&&i*pri[j]<=n;j++)
		{
			vis[i*pri[j]]=true;
			if(i%pri[j]==0)
			{
				phi[i*pri[j]]=phi[i]*pri[j];
				break;
			}
			phi[i*pri[j]]=phi[i]*(pri[j]-1);
		}
	}
	int ans=0;
	for(int i=1;i<=n;i++)
	{
		for(int j=i;j<=n-1;j+=i)
		{
			ans=(ans+1LL*lcm(n-j,i)%mod*phi[j/i]%mod)%mod;
		}
	}
	printf("%d\n",ans);
	return 0;
}