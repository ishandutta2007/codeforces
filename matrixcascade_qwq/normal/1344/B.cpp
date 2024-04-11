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
char c[2020][2020];
int vis[2020][2020];
void dfs(int x,int y)
{
	if(c[x][y]!='#'||vis[x][y])return;
	vis[x][y]=1;
	dfs(x+1,y);
	dfs(x,y+1);
	dfs(x-1,y);
	dfs(x,y-1);
}
int w1[2020],w2[2020];
signed main()
{
	int T=1;
	while(T--)
	{
		rdn;rdm;
		upn cin>>c[i]+1;
		int flag=1;
		upn
		{
			up(j,1,m)
			{
				if(c[i][j]=='#')w1[i]=w2[j]=1,flag=0;
			}
		}
		if(flag)
		{
			puts("0");return 0;
		}
		int q=0;
		upn
		{
			vector<int>v;
			up(j,1,m)
			{
				if(c[i][j]=='#')v.ep(j);
			}
			if(v.size()==0)
			{
				q=1;
				continue;
			}
			if(v.size()<=1)continue;
			up(j,0,v.size()-2)
			{
				if(v[j+1]-v[j]>1)
				{
					puts("-1");
					return 0;
				}
			}
		}
		int qq=0;
		up(i,1,m)
		{
			vector<int>v;
			up(j,1,n)
			{
				if(c[j][i]=='#')v.ep(j);
			}
			if(v.size()==0)
			{
				qq=1;
				continue;
			}
			if(v.size()<=1)continue;
			up(j,0,v.size()-2)
			{
				if(v[j+1]-v[j]>1)
				{
					puts("-1");
					return 0;
				}
			}
		}
		if(q+qq==1)
		{
			puts("-1");
			return 0;
		}
		int ans=0;
		upn
		{
			up(j,1,m)
			{
				if(c[i][j]=='.')continue;
				if(!vis[i][j])
				{
					++ans;
					dfs(i,j);
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