#include<bits/stdc++.h>
#define Accepted 0
using namespace std;
const int maxn=1e5;
int n,a,b,p[1111111],prime[111111],cnt,x,mn,mx;
bool f[111111];
long long ans,cost[1111111],aaa,rip,pre[1111111];
void Init()
{
	for (int i=2;i<=maxn;i++)
	{
		if (!f[i])
		{
			prime[++cnt]=i;
		}
		for (int j=1;j<=cnt && prime[j]*i<=maxn;j++)
		{
			f[i*prime[j]]=1;
			if (i%prime[j]==0) break;
		}
	}
}
long long sol(int ad,int pr)
{
	mn=1e9;mx=0;
	for (int i=2;i<=n;i++)
	{
		if (p[i]%pr==0) cost[i]=0;
		else if ((p[i]+1)%pr==0 || (p[i]-1)%pr==0) cost[i]=b;
		else 
		{
			cost[i]=-1;
			mn=min(mn,i);mx=max(mx,i);
		}
	}
	long long res=0;
	if (mn<=n)
	{
		res=1ll*(mx-mn+1)*a;
		for (int i=2;i<mn;i++) res+=cost[i];
		for (int i=mx+1;i<=n;i++) res+=cost[i];
		aaa=0;rip=0;
		for (int i=mn-1;i>=2;i--)
		{
			rip-=a;
			rip+=cost[i];
			aaa=max(aaa,rip);
		}
		res-=aaa;
		aaa=0;rip=0;
		for (int i=mx+1;i<=n;i++)
		{
			rip-=a;
			rip+=cost[i];
			aaa=max(aaa,rip);
		}
		res-=aaa;
	}
	else
	{
		aaa=1ll*n*a;rip=1ll*n*a;res=1e18;
		for (int i=1;i<=n;i++) pre[i]=pre[i-1]+cost[i];
		for (int i=n;i>=1;i--)
		{
			res=min(res,aaa+pre[i]-1ll*i*a);
			rip-=a;rip+=cost[i];
			aaa=min(aaa,rip);
		}
	}
	return res+1ll*b*abs(ad);
}
long long solve()
{
	long long res=1e18;
	for (int i=-1;i<=1;i++)
	{
		x=p[1]+i;
		for (int j=1;j<=cnt;j++)
		{
			if (x%prime[j]==0) 
			{
				res=min(res,sol(i,prime[j]));
				while(x%prime[j]==0) x/=prime[j];
			}
		}
		if (x>1) res=min(res,sol(i,x));
	}
	return res;
}
int main()
{
	scanf("%d%d%d",&n,&a,&b);
	ans=1e18;
	for (int i=1;i<=n;i++)
	{
		scanf("%d",&p[i]);
	}
	Init();
	ans=min(ans,solve());
	reverse(p+1,p+n+1);
	ans=min(ans,solve());
	printf("%lld\n",ans);
	return Accepted;
}