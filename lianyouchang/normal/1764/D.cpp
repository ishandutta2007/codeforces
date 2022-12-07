// Problem: D. Doremy's Pegging Game
// Contest: Codeforces - Codeforces Global Round 24
// URL: https://codeforces.com/contest/1764/problem/D
// Memory Limit: 512 MB
// Time Limit: 1500 ms

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
// #define mod 998244353
#define int ll
#define N 5005
using namespace std;
int fac[100005];
int C[N][N];
int F[N][N];
int n,mod;
inline int calc(int x,int y)
{
	if (F[x][y]) return F[x][y];
	for (int i=0;i<=n-x-y-2;i++)
		F[x][y]=(F[x][y]+fac[x-1+y]*x%mod*C[x+y-1+i][i]%mod*C[n-x-y-2][i]%mod*fac[i]%mod)%mod;
	return F[x][y];
}
void BellaKira()
{
	cin>>n>>mod;
	int ans=0;
	fac[0]=1;
	for (int i=1;i<=5000;i++) fac[i]=fac[i-1]*i%mod;
	C[0][0]=1;
	for (int i=1;i<=n;i++)
	{
		C[i][0]=1;
		for (int j=1;j<=i;j++) 
			C[i][j]=(C[i-1][j-1]+C[i-1][j])%mod;
	}
	if (n%2==0)
	{
		for (int i=1;i<=n;i++)
			for (int j=i+1;j<=n;j++)
				if (j-i!=n/2)
				{
					int x=i-n/2;
					if (x<=0) x+=n;
					int y=j-n/2;
					if (y<=0) y+=n;
					if (x>y) swap(x,y);
					int v=(y-x+1);
					if (x<=min(i,j)&&max(i,j)<=y) v=n-v+2;int o;
					if (j-i+1<=n/2)
						o=n-v-(j-i+1);
						else o=n-v-(n-(j-i+1)+2);
					ans=(ans+calc(v,o))%mod;
				} else
				{
					ans=(ans+fac[n-2]*2%mod)%mod;
					// cout<<i<<" "<<j<<" "<<fac[n-2]*2%mod<<'\n';
				}
	} else
	{
		for (int i=1;i<=n;i++)
			for (int j=i+1;j<=n;j++)
				if (j-i<=n/2)
				{
					int x=i-n/2;
					int y=j+n/2;
					while (y>n) y-=n;
					while (x<=0) x+=n;
					if (x>y) swap(x,y);
					int v=y-x+1;
					if (x<=i&&j<=y) v=n-v+2;
					int o=n-v-(j-i+1);
					ans=(ans+calc(v,o))%mod;
					// cout<<i<<" "<<j<<" "<<v<<" "<<F[v]<<'\n';
				} else
				{
					int x=i+n/2;
					int y=j-n/2;
					while (y<=0) y+=n;
					while (x>n) x-=n;
					if (x>y) swap(x,y);
					int v=y-x+1;
					if (x<=i&&j<=y) v=n-v+2;
					int o=n-v-(n-(j-i+1)+2);
					ans=(ans+calc(v,o))%mod;
					// cout<<i<<" "<<j<<" "<<v<<" "<<F[v]<<'\n';
				}
	}
	cout<<ans<<'\n';
					
					
		
}
signed main()
{
	IOS;cin.tie(0); 
	int T=1;
	while (T--)
	{
		BellaKira();
	}
}