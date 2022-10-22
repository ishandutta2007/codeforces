#include<bits/stdc++.h>
#define ll long long
#define N 200010
#define mod 998244353
using namespace std;
int fir[N],to[N<<1],nxt[N<<1],cnt;ll f[N],fac[N];
void add(int u,int v){nxt[++cnt]=fir[u];fir[u]=cnt;to[cnt]=v;}
void dfs(int x,int fa)
{
	f[x]=1;int i,s=(x!=1);
	for (i=fir[x];i;i=nxt[i]) if (to[i]!=fa)
	{
		dfs(to[i],x);f[x]*=f[to[i]];f[x]%=mod;s++;
	}
	f[x]*=fac[s];f[x]%=mod;
}
int main()
{
	int n,i,u,v;cin>>n;fac[0]=1;for (i=1;i<=n;i++) fac[i]=fac[i-1]*i%mod;
	for (i=1;i<n;i++) scanf("%d%d",&u,&v),add(u,v),add(v,u);
	dfs(1,0);cout<<f[1]*n%mod;
}