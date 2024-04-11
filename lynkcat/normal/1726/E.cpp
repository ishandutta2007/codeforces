#include<bits/stdc++.h>
#define poly vector<int>
#define IOS ios::sync_with_stdio(false)
#define ll long long
#define mp make_pair
#define mt make_tuple
#define pa pair < int,int >
#define fi first
#define se second
#define inf 1e18
#define mod 998244353
#define int ll
#define N 1000005
using namespace std;
int n,f[N];
int fac[N],inv[N];
int facf[N];
int quickPower(int x,int y)
{
	int res=1;
	while (y)
	{
		if (y&1) res=res*x%mod;
		x=x*x%mod;
		y>>=1;
	}
	return res;
}
inline int C(int x,int y)
{
	if (x<y||y<0) return 0;
	return fac[x]*inv[y]%mod*inv[x-y]%mod;
}
void BellaKira()
{
	cin>>n;
	f[0]=1;
	for (int i=1;i<=n;i++)
	{
		f[i]=f[i-1];
		if (i>=2)
		{
			f[i]=(f[i]+f[i-2]*(i-1)%mod)%mod;
		}
	}
	int ans=f[n];
	for (int i=1;4*i<=n;i++)
		ans=(ans+quickPower(2,i)%mod*facf[2*i-1]%mod*C(n-2*i,2*i)%mod*f[n-4*i]%mod)%mod;
	cout<<ans<<endl;
}
signed main()
{
	fac[0]=1;
	for (int i=1;i<N;i++) fac[i]=fac[i-1]*i%mod;
	inv[N-1]=quickPower(fac[N-1],mod-2);
	for (int i=N-1;i>=1;i--) inv[i-1]=inv[i]*i%mod;
	facf[0]=facf[1]=1;
	for (int i=2;i<N;i++) facf[i]=facf[i-2]*i%mod;
	IOS;
	cin.tie(0);
	int T=1;
	cin>>T;
	while (T--)
	{
		BellaKira();
	}
}