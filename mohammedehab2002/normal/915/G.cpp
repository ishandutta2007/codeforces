#include <iostream>
#include <vector>
using namespace std;
#define mod 1000000007
int u[2000005],lp[2000005],p[2000005];
vector<int> v[2000005];
long long pow_log(long long x,int y)
{
	if (!y)
	return 1;
	long long ret=pow_log(x,y/2);
	ret=(ret*ret)%mod;
	if (y%2)
	ret=(ret*x)%mod;
	return ret;
}
int main()
{
	int n,k;
	scanf("%d%d",&n,&k);
	u[1]=1;
	p[1]=1;
	v[1].push_back(1);
	for (int i=2;i<=k;i++)
	{
		p[i]=pow_log(i,n);
		v[i].push_back(1);
		if (!lp[i])
		lp[i]=i;
		if (lp[i]==lp[i/lp[i]])
		u[i]=0;
		else
		u[i]=-u[i/lp[i]];
		if (!u[i])
		continue;
		for (int j=i;j<=k;j+=i)
		{
			v[j].push_back(i);
			if (!lp[j])
			lp[j]=i;
		}
	}
	int ans=0,res=0;
	for (int i=1;i<=k;i++)
	{
		for (int j:v[i])
		{
			ans-=p[(i-1)/j]*u[j];
			ans+=p[i/j]*u[j];
			ans=(ans+2LL*mod)%mod;
		}
		res=(res+(ans^i))%mod;
	}
	printf("%d",res);
}