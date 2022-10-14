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
const int maxn=404040;
int cnt=1;
int fa[maxn][20],sum[maxn][20],val[maxn];	
signed main()
{
	int T=1;
	while(T--)
	{
		int lst=0;
		int q;rd(q);
		fa[1][0]=0;up(i,0,19)sum[1][i]=val[0]=1e17;
		while(q--)
		{
			int opt,x,y;
			rd(opt);rd(x);rd(y);
			x^=lst;y^=lst;
			if(opt==1)
			{
				val[++cnt]=y;
				if(val[x]>=y)
				{
					fa[cnt][0]=x;
				}
				else
				{
					pu(i,19,0)
					{
						if(val[fa[x][i]]<y)x=fa[x][i];
					}
					fa[cnt][0]=fa[x][0];
				}
				sum[cnt][0]=val[fa[cnt][0]];
				up(i,1,19)
				{
					fa[cnt][i]=fa[fa[cnt][i-1]][i-1];
					sum[cnt][i]=sum[cnt][i-1]+sum[fa[cnt][i-1]][i-1];
					if(fa[cnt][i]==0)sum[cnt][i]=1e17;
					
				}
			}
			else
			{
				int ans=1;
				y-=val[x];
				if(y<0)
				{
					ans=0;
				}
				else
				{
					pu(i,19,0)
					{
						if(sum[x][i]<=y)
						{
							y-=sum[x][i];
							x=fa[x][i];
							ans+=(1ll<<i);
						}
					}
				}
				lst=ans;opl(lst);edl;
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