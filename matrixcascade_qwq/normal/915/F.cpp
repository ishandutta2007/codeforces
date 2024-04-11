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

const int maxn=1e6+10;
struct node
{
	int x,y,w,ww;
}w[maxn];
int cmp(node a,node b)
{
	return a.w<b.w;
}
int cmp2(node a,node b)
{
	return a.ww>b.ww;
}
int a[maxn],fa[maxn],siz[maxn];
int find(int x)
{
    return fa[x]==x?fa[x]:fa[x]=find(fa[x]);
}
void merge(int x,int y)
{
    int fx=find(x),fy=find(y);
    if(fx==fy)return;
    fa[fx]=fy;
    siz[fy]+=siz[fx];siz[fx]=0;
}
void S(int x)
{
    up(i,1,x)fa[i]=i,siz[i]=1;;
}
signed main()
{
	int T=1;
	while(T--)
	{
		rdn;
		upn
		{
			a[i]=read();
		}
		up_(n-1)
		{
			rd(w[i].x);rd(w[i].y);w[i].w=max(a[w[i].x],a[w[i].y]);
			w[i].ww=min(a[w[i].x],a[w[i].y]);
		}
		S(n);
		sort(w+1,w+n,cmp);
		int ans1=0,ans2=0;
		up(i,1,n-1)
		{
			int fx=find(w[i].x),fy=find(w[i].y);
			ans1+=siz[fx]*siz[fy]*w[i].w;
			merge(fx,fy);
		}
		sort(w+1,w+n,cmp2);
		S(n);
		up(i,1,n-1)
		{
			int fx=find(w[i].x),fy=find(w[i].y);
			ans2+=siz[fx]*siz[fy]*w[i].ww;
			merge(fx,fy);
		}
		opl(ans1-ans2);
	}
}
/*
  When you are coding,remember to:
	   - clear the arrays if a problem has many tasks.
	   - pay attention to some special cases(n=0,1).
	   - Don't code before think completely.
	   - ...
*/