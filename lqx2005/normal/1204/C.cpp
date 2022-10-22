#include<bits/stdc++.h>
typedef long long ll;
using namespace std;
const ll N=100;
const ll M=1000000;
const ll INF=1e12;
ll f[N+5][N+5];
ll p[M+5];
bool vis[M+5];
ll n,m,x;
char w;
int main()
{
	scanf("%lld",&n);
	for(ll i=1;i<=n;i++)
	{
		for(ll j=1;j<=n;j++)
		{
			cin>>w;
			x=w-'0';
			if(x==1) f[i][j]=1;
			else f[i][j]=INF;
		}
	}
	for(ll i=1;i<=n;i++) f[i][i]=0;
	for(ll k=1;k<=n;k++)
	{
		for(ll i=1;i<=n;i++)
		{
			for(ll j=1;j<=n;j++)
			{
				if(f[i][j]>f[i][k]+f[k][j])
				{
					f[i][j]=f[i][k]+f[k][j];
				}
			}
		}
	}
	scanf("%lld",&m);
	for(ll i=1;i<=m;i++) scanf("%lld",&p[i]);
	ll now=1,step=0;
	for(ll i=2;i<=m-1;i++)
	{
		if(f[p[now]][p[i+1]]==f[p[now]][p[i]]+f[p[i]][p[i+1]])
		{
			vis[i]=1;
			step++;
		}
		else
		{
			now=i;
		}
	}
	printf("%lld\n",m-step);
	for(ll i=1;i<=m;i++)
	{
		if(!vis[i]) printf("%lld ",p[i]);
	}
	printf("\n");
	return 0;
}