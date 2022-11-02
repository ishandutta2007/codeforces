#include<bits/stdc++.h>
using namespace std;

const int maxn=5010;
typedef long long ll;
ll mo=1e9+7;
int n,k;
ll powmod(ll a,ll b)
{
	ll ans=1;
	while (b)
	{
		if (b&1)	ans=(ans*a)%mo;
		b>>=1;
		a=(a*a)%mo;
	}
	return ans;
}
ll f[maxn][maxn];
int main()
{
	scanf("%d%d",&n,&k);
	f[0][0]=1;
	for (int i=0;i<k;i++)
		for (int j=0;j<=i;j++)
		{
			if (f[i][j]==0)	continue;
			f[i+1][j]=(f[i+1][j]+j*f[i][j])%mo;
			f[i+1][j+1]=(f[i+1][j+1]+(n-j)*f[i][j])%mo;
		}
	ll ans=0;
	for (int i=0;i<=k;i++)
	if (n-i>=0)
		ans=(ans+f[k][i]*powmod(2,n-i))%mo;
	printf("%lld\n",ans);
	return 0;
}