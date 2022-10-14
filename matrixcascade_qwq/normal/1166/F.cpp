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
int fa[maxn];set<int>s[maxn];
int find(int x)
{
    return fa[x]==x?fa[x]:fa[x]=find(fa[x]);
}
void merge(int x,int y)
{
    int fx=find(x),fy=find(y);
    if(fx==fy)return;
    if(s[fx].size()>s[fy].size())
    {
    	fa[fy]=fx;
    	fp s[fy] pf
    	{
    		s[fx].insert(to);
		}
		s[fy].clear();
	}
	else
	{
    	fa[fx]=fy;
    	fp s[fx] pf
    	{
    		s[fy].insert(to);
		}
		s[fx].clear();
	}
}
void S(int x)
{
    up(i,1,x)fa[i]=i;
}

miv mp[maxn];
signed main()
{
	int T=1;
	while(T--)
	{
		rdn;rdm;int c,q;rd(c);rd(q);
		S(n);
		upm
		{
			int x,y,z;rd(x);rd(y);rd(z);
			mp[x][z].ep(y);
			s[find(x)].insert(y);s[find(y)].insert(x);
			if(mp[x][z].size()>1)
			{
				merge(mp[x][z][0],y);
			}
			mp[y][z].ep(x);
			if(mp[y][z].size()>1)
			{
				merge(mp[y][z][0],x);
			}
		}
		while(q--)
		{
			char opt;cin>>opt;
			if(opt=='+')
			{
				int x,y,z;rd(x);rd(y);rd(z);
				mp[x][z].ep(y);
				s[find(x)].insert(y);s[find(y)].insert(x);
				if(mp[x][z].size()>1)
				{
					merge(mp[x][z][0],y);
				}
				mp[y][z].ep(x);
				if(mp[y][z].size()>1)
				{
					merge(mp[y][z][0],x);
				}
			}
			else
			{
				int x,y;rd(x);rd(y);
				if(find(x)==find(y)||s[find(x)].count(y))
				{
					Yes;
				}
				else No;
			}
		}
		
	}
}
/*

*/
/*
  When you are coding,remember to:
	   - clear the arrays if a problem has many tasks.
	   - pay attention to some special cases(n=0,1).
	   - Don't code before think completely.
	   - ...
*/