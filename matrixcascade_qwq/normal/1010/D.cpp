/*
qwq
*/


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
#define mkp make_pair
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
int ls[maxn],rs[maxn],f[maxn],typ[maxn],fa[maxn],b[maxn],val[maxn];
int vis[maxn];
int dfs1(int x)
{
	int ans;
//	cout<<x<<'\n';
	if(typ[x]==1)
	{
		ans=(dfs1(ls[x])&dfs1(rs[x]));
	}
	else if(typ[x]==2)
	{
		ans=(dfs1(ls[x])^dfs1(rs[x]));
	}
	else if(typ[x]==3)
	{
		ans=(1-dfs1(ls[x]));
	}
	else if(typ[x]==4)
	{
		ans=(dfs1(ls[x])|dfs1(rs[x]));
	}
	else 
	{
		ans=f[x];
	}
	val[x]=ans;
	return ans;
}
void dfs2(int x)
{
	vis[x]=1;
	if(ls[x]&&b[ls[x]])dfs2(ls[x]);
	if(rs[x]&&b[rs[x]])dfs2(rs[x]);
}
signed main()
{
	int T=1;
	while(T--)
	{
		rd(n);
		upn
		{
			string s;
			cin>>s;
			if(s=="AND")
			{
				rd(ls[i]);rd(rs[i]);typ[i]=1;
			}
			else if(s=="XOR")
			{
				rd(ls[i]);rd(rs[i]);typ[i]=2;
			}
			else if(s=="NOT")
			{
				rd(ls[i]);typ[i]=3;
			}
			else if(s=="OR")
			{
				rd(ls[i]);rd(rs[i]);typ[i]=4;
			}
			else
			{
				rd(f[i]);typ[i]=5;
			}
		}
		upn
		{
			if(ls[i])fa[ls[i]]=i;
			if(rs[i])fa[rs[i]]=i;
		}
		val[1]=dfs1(1);
		upn
		{
			if(!fa[i])continue;
			if(typ[fa[i]]==1)
			{
				if(i==ls[fa[i]])
				{
					if(val[rs[fa[i]]]==1)b[i]=1;
				}
				else
				{
					if(val[ls[fa[i]]]==1)b[i]=1;
				}
			}
			if(typ[fa[i]]==2)
			{
				b[i]=1;
			}
			if(typ[fa[i]]==3)
			{
				b[i]=1;
			}
			if(typ[fa[i]]==4)
			{
				if(i==ls[fa[i]])
				{
					if(val[rs[fa[i]]]==0)b[i]=1;
				}
				else
				{
					if(val[ls[fa[i]]]==0)b[i]=1;
				}
			}
		}
		b[1]=1;
		dfs2(1);
		upn
		{
			if(typ[i]==5)
			{
				cout<<(vis[i]^val[1]);
			}
		}
	}
}
/*
  When you are coding,remember to:
	   - clear the arrays if a problem has many tasks.
	   - pay attention to some special cases(n=0,1).
	   - Don't code before think completely.
	   - ...
*/