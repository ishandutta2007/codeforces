#include<bits/stdc++.h>
using namespace std;
#define re register
#define int long long
int x[500100],y[500100],bo[500100];
const int mod=1e9+7,inv2=(mod+1)/2;
long long cc(re int a,re int b)
{
	return (long long)x[a]*y[b]-(long long)y[a]*x[b];
}
signed main()
{
	re int n,ans=0,j=1,xx=0,yy=0,sm=0;
	re long long sum=0,squ=0;
	scanf("%lld",&n);
	for(re int i=1;i<=n;i++)scanf("%lld%lld",&x[i],&y[i]);
	for(re int i=1;i<n;i++)
	{
		sum+=cc(i,i+1);
	}
	sum+=cc(n,1);
	if(sum<0)sum=-sum,reverse(x+1,x+n+1),reverse(y+1,y+n+1);
	for(re int i=1;i<=n;i++)
	{
		re long long nw=squ;
		xx=(xx-x[i]+mod)%mod;yy=(yy-y[i]+mod)%mod;
		while((nw+cc(j,i))<=sum/2.0L)
		{squ=nw;
			if(!bo[j])sm=(sm+nw)%mod,xx=(xx+x[j]+mod)%mod,yy=(yy+y[j]+mod)%mod,bo[j]=1;
			nw+=cc(j,j%n+1);
			j=j%n+1;//printf("**%d %lld %lld\n",j,nw,nw+cc(j,i));
		}
		if((--j)==0)j=n;//printf("**%d %d %d %lld %lld\n",i,j,ans,squ,nw);
		re int xc=((sm+(long long)xx*y[i]+(long long)(mod-yy)*x[i])%mod+mod)%mod;
		ans=(ans+xc)%mod;
		if((squ+cc(j,i))*2==sum)ans=(ans-((squ+cc(j,i))%mod+mod)*inv2%mod+mod)%mod;
		sm=(sm-(j>i?j-i:(j-i+n))*(cc(i,i%n+1)%mod+mod)%mod+mod)%mod;squ-=cc(i,i%n+1);
		bo[i]=0;
	}
	printf("%lld\n",((sum%mod*((long long)n*(n-3)/2%mod)%mod-2ll*ans+2ll*mod)%mod+mod)%mod);
}