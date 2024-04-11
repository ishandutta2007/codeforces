#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
const int maxn=2010;
const ll mo=998244353;
ll n,p,p1;
ll f[maxn],g[maxn][maxn];
ll ans[maxn];

ll powmod(ll a,ll b)
{
	ll ans=1;
	while (b)
	{
		if (b&1)	ans=(ans*a)%mo;
		a=(a*a)%mo;
		b>>=1;
	}
	return ans;
}
void init()
{
	cin>>n;
	ll a,b;
	cin>>a>>b;
	p=(a*powmod(b,mo-2))%mo;
	p1=(1-p+mo)%mo;
}
void prepare()
{
	g[0][0]=1;
	for (int i=1;i<=n;i++)
		for (int j=0;j<i;j++)
		{
			g[i][j]=(g[i][j]+g[i-1][j]*powmod(p,j))%mo;
			g[i][j+1]=(g[i][j+1]+g[i-1][j]*powmod(p1,i-1-j))%mo;
		}
}
int main()
{
	init();
	prepare();
	f[1]=1;
	for (int i=2;i<=n;i++)
	{
		ll tmp=0;
		for (int j=1;j<i;j++)
			tmp=(tmp+f[j]*g[i][j])%mo;
		f[i]=(1+mo-tmp)%mo;
	}
	ans[1]=0;
	for (int i=2;i<=n;i++)
	{
		ans[i]=f[i]*(i*(i-1)/2)%mo;
		for (int j=1;j<i;j++)
		{
			ans[i]=(ans[i]+f[j]*g[i][j]%mo*(ans[j]+ans[i-j]+i*(i-1)/2-(i-j)*(i-j-1)/2)%mo)%mo;
		}
		ans[i]=ans[i]*powmod((1+mo-f[i])%mo,mo-2)%mo;
	}
	cout<<ans[n]<<endl;
	return 0;
}