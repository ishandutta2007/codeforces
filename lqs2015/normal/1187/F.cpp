#include<bits/stdc++.h>
using namespace std;
const int mod=1e9+7;
int n,l[222222],r[222222],p[222222],all,x,sum,cur,ans;
int intersect(int x,int y)
{
	return max(min(r[y],r[x])-max(l[x],l[y])+1,0);
}
int intersect3(int x,int y,int z)
{
	return max(min(min(r[y],r[x]),r[z])-max(max(l[x],l[y]),l[z])+1,0);
}
int binpow(int a,int t)
{
	int res=1,p=a;
	for (int i=t;i;i>>=1)
	{
		 if (i&1) res=1ll*res*p%mod;
		 p=1ll*p*p%mod;
	}
	return res;
}
int dd(int x,int y)
{
	int all=1ll*(r[x]-l[x]+1)*(r[y]-l[y]+1)%mod,g=intersect(x,y);
	return 1ll*(all-g)*binpow(all,mod-2)%mod;
}
int calc(int x)
{
	int all=1ll*(r[x]-l[x]+1)*(r[x+1]-l[x+1]+1)%mod*(r[x+2]-l[x+2]+1)%mod,g=0;
	g=(1ll*intersect(x,x+1)*(r[x+2]-l[x+2]+1)%mod+1ll*intersect(x+1,x+2)*(r[x]-l[x]+1)%mod-intersect3(x,x+1,x+2))%mod;
	return 1ll*(all-g)*binpow(all,mod-2)%mod;
}
int main()
{
	scanf("%d",&n);
	for (int i=1;i<=n;i++)
	{
		scanf("%d",&l[i]);
	}
	for (int i=1;i<=n;i++)
	{
		scanf("%d",&r[i]);
	}
	sum=1;
	for (int i=1;i<n;i++)
	{
		p[i]=dd(i,i+1);
		sum=(sum+p[i])%mod;
	}
	ans=sum;
	for (int i=1;i<n;i++)
	{
		ans=(1ll*(1ll*sum-p[i-1]-p[i+1]-p[i])%mod*p[i]+ans)%mod;
		if (i>1)
		{
			ans=(ans+calc(i-1))%mod;
		}
		if (i<n-1)
		{
			ans=(ans+calc(i))%mod;
		}
		ans=(ans+p[i])%mod;
	}
	printf("%d\n",(ans+mod)%mod);
	return 0;
}