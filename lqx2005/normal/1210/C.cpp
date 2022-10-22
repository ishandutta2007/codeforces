#include<bits/stdc++.h>
#define sit set<LL>::iterator
#define int long long
typedef long long LL;
using namespace std;
const int maxn=100000;
const LL mod=1e9+7;
struct edge
{
	int to,nxt;
}e[maxn*3+5];
set<LL> g[maxn+5];
map<LL,LL> c[maxn+5];
int h[maxn+5],cnt=0;
int n;
LL a[maxn+5];
LL ans=0;
LL Gcd(LL a,LL b)
{
	if(b==0) return a;
	return Gcd(b,a%b);
}
LL GCD(LL a,LL b)
{
	if(a==0) return b;
	if(b==0) return a;
	return Gcd(a,b);
}
void add(int u,int v)
{
	cnt++;
	e[cnt].to=v;
	e[cnt].nxt=h[u];
	h[u]=cnt;
	return;
}
void add(LL a,LL b,LL x,LL y)
{
	c[a][b]+=c[x][y];
	return;
}
void dfs(int u,int fa)
{
	for(sit it=g[fa].begin();it!=g[fa].end();it++)
	{
		int gcd=GCD(*it,a[u]);
		g[u].insert(gcd);
		add(u,gcd,fa,*it);
		int cnt=c[fa][*it];
		gcd=gcd%mod;
		cnt*=gcd;
		cnt%=mod;
		ans=(ans+cnt)%mod;
	}
	g[u].insert(a[u]);
	c[u][a[u]]++;
	ans=(ans+a[u])%mod;
	for(register int i=h[u];i;i=e[i].nxt)
	{
		int v=e[i].to;
		if(v==fa) continue;
		dfs(v,u);
	}
	return;
}
signed main()
{
	scanf("%lld",&n);
	for(register int i=1;i<=n;i++) 
		scanf("%lld",&a[i]);
	int u,v;
	for(register int i=1;i<=n-1;i++)
	{
		scanf("%lld%lld",&u,&v); 
		add(u,v);
		add(v,u);
	}
	dfs(1,0);
	printf("%lld\n",ans);
	return 0;
}