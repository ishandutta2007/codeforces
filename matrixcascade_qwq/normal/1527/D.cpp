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
const int maxn=2e5+10;
int head[maxn],to[maxn*2],nxt[maxn*2],tot;
void add(int a,int b)
{
    to[++tot]=b;
    nxt[tot]=head[a];
    head[a]=tot;
}
int f[maxn];
int vis[maxn],siz[maxn];
void dfs(int x,int fa)
{
	f[x]=fa;
	siz[x]=1;
	ft(x)
	{
		int v=to[i];if(v==fa)continue;
		dfs(v,x);
		siz[x]+=siz[v];
	}
}
int c[maxn];
signed main()
{
	int T=read();
	while(T--)
	{
		rdn;
		up(i,0,n+1)c[i]=siz[i]=vis[i]=head[i]=0;
		up_(n-1)
		{
			int x,y;
			rd(x);rd(y);++x;++y;
			add(x,y);add(y,x);
		}
		dfs(1,0);
		vis[1]=1;
		int p=1,q=2;
		c[0]=n*(n-1)/2;
		int tt=0;
		ft(1)
		{
			int v=to[i];
			tt+=siz[v]*(siz[v]-1)/2;
		}
		upn
		{
			if(i==1)
			{
				c[i]=c[0]-tt;
			}
			else if(i<=2)
			{
				int nw=i;
				while(1)
				{vis[nw]=1;
					if(f[nw]==1)break;
				//	cout<<nw<<" ";
					
					nw=f[nw];
				}
				siz[1]-=siz[nw];
			//	cout<<nw<<" "<<siz[1]<<'\n';
				c[i]=siz[p]*siz[q];
			}
			else
			{
				if(vis[i])
				{
					c[i]=siz[p]*siz[q]; 
				}
				else
				{
					int nw=i;
					while(1)
					{
					//	cout<<nw<<' ';
						if(vis[nw])break;
						vis[nw]=1;
						nw=f[nw];
					}
					if(nw!=p&&nw!=q)break; 
					if(nw==p)p=i;
					else if(nw==q)q=i;
				//	cout<<nw<<'\n';
				//	cout<<i<<" "<<p<<" "<<q<<'\n';
					c[i]=siz[p]*siz[q];
				}
			}
			
		}
		assert(c[1]>=c[2]);
		up(i,0,n)cout<<c[i]-c[i+1]<<" ";edl;
	}
}
/*
1
3
1 0
2 1
*/
/*
  When you are coding,remember to:
	   - clear the arrays if a problem has many tasks.
	   - pay attention to some special cases(n=0,1).
	   - Don't code before think completely.
	   - ...
*/