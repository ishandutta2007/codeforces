#include<bits/stdc++.h>
#define ll long long
#define mod 1000000007
#define N 40000010
using namespace std;
ll f[10010][60],g[10010][60],inv[200];
bool nop[N];int p[N],cnt;
void mem(int n)
{
	for (int i=2;i<=n;i++)
	{
		if (!nop[i]) p[++cnt]=i;
		for (int j=1;j<=cnt && i*p[j]<=n;j++)
		{
			nop[i*p[j]]=1;if (i%p[j]==0) break;
		}
	}
}
ll qpow(ll x,ll y)
{
	ll res=1;
	while (y)
	{
		if (y&1) (res*=x)%=mod;(x*=x)%=mod;y>>=1;
	}
	return res;
}
int main()
{
	mem(N-10);ll n,o,ans=1;int k,i,j;cin>>n>>k;o=n;
	for (i=1;i<=100;i++) inv[i]=qpow(i,mod-2);
	for (i=1;(ll)p[i]*p[i]<=o;i++) if (n%p[i]==0)
	{
		int s=0;while (n%p[i]==0) n/=p[i],s++;
		memset(f,0,sizeof(f));memset(g,0,sizeof(g));f[0][s]=1;g[0][s+1]=0;
		for (j=s;j>=0;j--) g[0][j]=g[0][j+1]+f[0][j]*inv[j+1];
		for (j=1;j<=k;j++)
		{
			for (int l=0;l<=s;l++)
			{
				f[j][l]=g[j-1][l];f[j][l]%=mod;
			}
			g[j][s+1]=0;
			for (int l=s;l>=0;l--)
			{
				g[j][l]=g[j][l+1]+f[j][l]*inv[l+1];g[j][l]%=mod;
			}
		}
		ll r=1,e=0;
		for (j=0;j<=s;j++) (e+=r*f[k][j])%=mod,(r*=p[i])%=mod;
		ans*=e;ans%=mod;
	}
	if (n!=1)
	{
		int s=1;memset(f,0,sizeof(f));memset(g,0,sizeof(g));f[0][s]=1;g[0][s+1]=0;
		for (j=s;j>=0;j--) g[0][j]=g[0][j+1]+f[0][j]*inv[j+1];
		for (j=1;j<=k;j++)
		{
			for (int l=0;l<=s;l++)
			{
				f[j][l]=g[j-1][l];f[j][l]%=mod;
			}
			g[j][s+1]=0;
			for (int l=s;l>=0;l--)
			{
				g[j][l]=g[j][l+1]+f[j][l]*inv[l+1];g[j][l]%=mod;
			}
		}
		ll r=1,e=0;
		for (j=0;j<=s;j++) (e+=r*f[k][j])%=mod,(r*=n)%=mod;
		ans*=e;ans%=mod;
	}
	cout<<ans;
}