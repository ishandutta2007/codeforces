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
#define N 600005
using namespace std;
mt19937_64 rnd(233333);
int fac[N],inv[N],n,m,a[N],s[N];
int quickPower(int x,int y)
{
	x%=mod;
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
	cin>>n>>m;
	map<int,int>Mp;
	for (int i=1;i<=n;i++)
	{
		cin>>a[i];
		// a[i]=rnd()%1000000000+1;
		s[i]=s[i-1]+a[i];
		Mp[s[i]]=i;
	}
	int x=0;
	for (int i=1;i<=n;i++)
		if (s[n]%2==0)
		{
			if (Mp.count(s[i]+s[n]/2))
			{
				x++;
			}
		}
	int ans=0;
	for (int i=0;i<=x;i++)
	{
		int lst=m-i;
		if (lst<0) break;
		ans=(ans+C(x,i)*C(m,i)%mod*fac[i]%mod*quickPower(lst*(lst-1)%mod,x-i)%mod*quickPower(lst,n-2*x)%mod)%mod;
	}
	cout<<ans<<endl;
}
signed main()
{
	fac[0]=1;
	for (int i=1;i<N;i++) fac[i]=fac[i-1]*i%mod;
	inv[N-1]=quickPower(fac[N-1],mod-2);
	for (int i=N-1;i>=1;i--) inv[i-1]=inv[i]*i%mod;
	
	int T=1;
	while (T--)
	{
		BellaKira();
	}
}