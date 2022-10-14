//#pragma GCC optimize("Ofast", "unroll-loops")
//#pragma GCC target("sse", "sse2", "sse3", "ssse3", "sse4", "avx")
#include <bits/stdc++.h>
#define ll long long
#define ull unsigned long long
#define int long long
#define YES puts("YES")
#define NO puts("NO")
#define Yes puts("Yes")
#define No puts("No")
#define edl puts("")
#define mc cerr<<"qwq\n"
#define error goto gg
#define def gg:
#define rd(x) x=read()
#define opl(x) printf("%lld",x)
#define opls(x) printf("%lld ",x)
#define opd(x) printf("%d",x)
#define opds(x) printf("%d ",x)
#define ver(x) for(int i=head[x];i;i=nxt[i])
#define up(i,x,y) for(int i=x,i##end=y;i<=i##end;++i)
#define pu(i,x,y) for(int i=x,i##end=y;i>=i##end;--i)
#define ft(x) for(int i=head[x];i;i=nxt[i])
#define upn up(i,1,n)
#define upm up(j,1,m)
#define pun pu(i,n,1)
#define pum pu(j,m,1)
#define up_(x) up(i,1,x)
#define pu_(x) pu(j,x,1)
#define ep emplace_back
#define fp for(auto to:
#define pf )
#define pii pair<int,int>
#define pis pair<int,string>
#define psi pair<string,int>
#define mkp make_pair
#define fi first
#define se second
#define mii map<int,int>
#define mis map<int,string>
#define msi map<string,int>
#define mvi map<vector<int>,int>
#define miv map<int,vector<int>>
#define rdn rd(n)
#define rdm rd(m)
#define rdk rd(k)
using namespace std;
int n, m, k;
int read()
{
    int s = 0, f = 1;
    char ch = getchar();
    while (ch < '0' || ch > '9')
    {
        if (ch == '-')
            f = -1;
        ch = getchar();
    }
    while (ch >= '0' && ch <= '9')
    {
        s = s * 10 + ch - '0';
        ch = getchar();
    }
    return s * f;
}

#define inf 1000000000000000000ll
ll Max(ll a=-inf,ll b=-inf,ll c=-inf,ll d=-inf,ll e=-inf,ll f=-inf,ll g=-inf,ll h=-inf)
{
	return max(max(max(a,b),max(c,d)),max(max(e,f),max(g,h)));
}
ll Min(ll a=inf,ll b=inf,ll c=inf,ll d=inf,ll e=inf,ll f=inf,ll g=inf,ll h=inf)
{
	return min(min(min(a,b),min(c,d)),min(min(e,f),min(g,h)));
}
#undef inf
void chkmin(int &x,int y)
{
	if(x>y)x=y;
}
void chkmax(int &x,int y)
{
	if(x<y)x=y;
}
const int maxn=4e5+10;
int head[maxn],to[maxn],nxt[maxn],w[maxn],val[maxn],tot;
int siz[maxn],mx[maxn],rt,vis[maxn];
double g[maxn];
int sum;
void add(int a,int b,int c)
{
	to[++tot]=b;
	nxt[tot]=head[a];
	head[a]=tot;
	w[tot]=c;
}
void getroot(int x,int fa)
{
	siz[x]=1;mx[x]=0;
	for(int i=head[x];i;i=nxt[i])
	{
		int v=to[i];
		if(v==fa)continue;
		if(vis[v])continue;
		getroot(v,x);
		siz[x]+=siz[v];
		mx[x]=max(mx[x],siz[v]);
	}
	mx[x]=max(mx[x],sum-siz[x]);
	if(mx[x]<mx[rt])rt=x;
}
double f1,f2;
double ans=1e20;
int root=0;
void calc(int x,int fa,int y,int ds)
{
	f1+=1.0*val[x]*ds*sqrt((double)ds);
	f2+=1.5*val[x]*sqrt((double)ds);
	g[y]+=1.5*val[x]*sqrt((double)ds);
	for(int i=head[x];i;i=nxt[i])
	{
		int v=to[i];
		if(v==fa)continue;
		calc(v,x,y,ds+w[i]);
	}
}
void dfs(int x)
{
	if(vis[x])return;
	vis[x]=1;
	f1=f2=0;
	for(int i=head[x];i;i=nxt[i])
	{
		int v=to[i];
		g[v]=0;
		calc(v,x,v,w[i]);
	}
	if(f1<ans)
	{
		ans=f1;root=x;
	}
	for(int i=head[x];i;i=nxt[i])
	{
		int v=to[i];
		if(f2-2*g[v]<0)
		{
			sum=siz[v];rt=0;
			getroot(v,x);
			dfs(rt);
		}
	}
}
signed main()
{
	int T=1;
	while(T--)
	{
		rdn;
		upn rd(val[i]);
		up_(n-1)
		{
			int x,y,z;rd(x);rd(y);rd(z);
			add(x,y,z);add(y,x,z);
		}
		mx[0]=n;rt=0;
		sum=n;
		getroot(1,0);
		dfs(rt);
		printf("%d %.10lf",root,ans);
	}
}
/*
  When you are coding,remember to:
	   - clear the arrays if a problem has many tasks.
	   - pay attention to some special cases(n=0,1).
	   - Don't code before think completely.
	   - ...
*/