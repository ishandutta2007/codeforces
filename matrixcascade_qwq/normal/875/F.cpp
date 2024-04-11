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
struct node
{
	int u,v,w;
}c[202020];
int cmp(node a,node b)
{
	return a.w>b.w;
}
const int maxn=202020;
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
int f[maxn];
signed main()
{
	int T=1;
	while(T--)
	{
		rdn;rdm;
		up_(m)
		{
			rd(c[i].u);rd(c[i].v);rd(c[i].w);
		}
		sort(c+1,c+m+1,cmp);
		S(n);
		int ans=0;
		up_(m)
		{
			int x=find(c[i].u),y=find(c[i].v);
			if(x==y)
			{
				if(f[x]==0)
				{
					ans+=c[i].w;f[x]=1;
				}
			}
			else
			{
				if(f[x]==0&&f[y]==0)
				{
					ans+=c[i].w;
					fa[y]=x;
				}
				else if(f[x]+f[y]==1)
				{
					ans+=c[i].w;
					fa[y]=x;
					f[x]=1;
				}
			}
		}
		opl(ans);
	}
}
/*
  When you are coding,remember to:
	   - clear the arrays if a problem has many tasks.
	   - pay attention to some special cases(n=0,1).
	   - Don't code before think completely.
	   - ...
*/