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
const int maxn=202020;
int tot;
int head[maxn],to[maxn],nxt[maxn],w[maxn],dis[maxn];
void add(int a,int b,int c)
{
	to[++tot]=b;w[tot]=c;
	nxt[tot]=head[a];head[a]=tot;
}
int fa[maxn];
int find(int x)
{
    return fa[x]==x?fa[x]:fa[x]=find(fa[x]);
}
void merge(int x,int y)
{
    int fx=find(x),fy=find(y);
    if(fx==fy)return;
    fa[fx]=fy;
}
void S(int x)
{
    up(i,1,x)fa[i]=i;
}
int q;
int aa[maxn],bb[maxn],cc[maxn];
void dfs(int x,int fa)
{
	for(int i=head[x];i;i=nxt[i])
	{
		int v=to[i];
		if(v==fa)continue;
		dis[v]=dis[x]^w[i];
		dfs(v,x);
	}
}
int f[200];
void ins(int x)
{
	pu(i,63,0)
	{
		if(!(x&(1ll<<i)))continue;
		if(f[i]==0)
		{
			f[i]=x;return;
		}
		x^=f[i];
	}
}
signed main()
{
	int T=1;
	while(T--)
	{
		rdn;rdm;
		S(n);
		up_(m)
		{
			int x,y,z;rd(x);rd(y);rd(z);
			if(find(x)==find(y))
			{
				aa[++q]=x;bb[q]=y;cc[q]=z;
			}
			else
			{
				fa[find(x)]=find(y);
				add(x,y,z);add(y,x,z);
			}
		}
		dfs(1,0);
		up_(q)
		{
		//	cout<<(dis[aa[i]]^dis[bb[i]]);edl;
			ins(dis[aa[i]]^dis[bb[i]]^cc[i]);
		}
		int ans=dis[n];
		pu(i,63,0)
		{
			ans=min(ans,ans^f[i]);
		}opl(ans);edl;
	}
}
/*
  When you are coding,remember to:
	   - clear the arrays if a problem has many tasks.
	   - pay attention to some special cases(n=0,1).
	   - Don't code before think completely.
	   - ...
*/