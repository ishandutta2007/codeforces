#include<iostream>
#include<cstdio>
#define int long long
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
int b[300005],csl[300005];
int a[300005];
signed main()
{
	int k,n,ph=0,lc=0;
	n=read();
	k=read();
	for(int i=1;i<=n;i++)
	{
		b[i]=read();
	}
	for(int i=n;i>=k+1;i--)
	{
		a[i]=ph-lc;
		ph-=lc;
		if(a[i]>=b[i])
		{
			csl[i]=0;
		}
		else csl[i]=(b[i]-a[i]-1)/k+1;
		ph+=csl[i]*k;
		lc+=csl[i];
		if(i+k<=n)lc-=csl[i+k];
		//printf("%lld\n",csl[i]);
	}
	int ans=0;
	for(int i=k;i>=1;i--)
	{
		a[i]=ph-lc;
		ph-=lc;
		if(i+k<=n)lc-=csl[i+k];
		ans=max(ans,(b[i]-a[i]-1)/i+1);
	}
	for(int i=k+1;i<=n;i++)ans+=csl[i];
	printf("%lld\n",ans);
	return 0;
}