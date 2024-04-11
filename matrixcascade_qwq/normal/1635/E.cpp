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
const int maxn=2e5+10;
int x[maxn],y[maxn],z[maxn];
int head[maxn],to[maxn*2],nxt[maxn*2],w[maxn*2],vis[maxn];
int tot,cc[maxn];
vector<int>g;
vector<pii>h;map<pii,int>b;
void add(int a,int b,int c)
{
	to[++tot]=b;w[tot]=c;nxt[tot]=head[a];
	head[a]=tot;
}
void dfs(int x,int col)
{
	vis[x]=1;
	cc[x]=col;
	g.ep(x);
	for(int i=head[x];i;i=nxt[i])
	{
		int v=to[i];
		if(!b.count(mkp(x,v)))
		{
			h.ep(mkp(x,v));
			b[mkp(x,v)]=b[mkp(v,x)]=w[i];
		}
		if(cc[v])
		{
			if(cc[v]+cc[x]!=3)
			{
				NO;
				exit(0);
			}
			continue;
		}
		dfs(v,3-col);
	}
}
vector<int>v[maxn];int in[maxn];
int a1[maxn],a2[maxn];
int nw=0;
signed main()
{
	int T=1;
	while(T--)
	{
		rdn;rdm;
		set<int>s;
		up(i,1,500000)s.insert(i);
		up_(m)
		{
			rd(z[i]);rd(x[i]);rd(y[i]);
			add(x[i],y[i],z[i]);add(y[i],x[i],z[i]);
		}
		upn
		{
			if(vis[i])continue;
			dfs(i,1);
		}
		up_(m)
		{
			int xx=x[i],yy=y[i];
			if(cc[xx]==1&&cc[yy]==2)
			{
				if(b[mkp(xx,yy)]==2)
				{
					v[yy].ep(xx);++in[xx];
				}
				else
				{
			//		cout<<xx<<" "<<yy;edl;
					v[xx].ep(yy);++in[yy];
				}
			}
			else
			{
				if(b[mkp(xx,yy)]==1)
				{
					v[yy].ep(xx);++in[xx];
				}
				else
				{
					v[xx].ep(yy);++in[yy];
				}
			}
		}
		queue<int>q;
		fp g pf
		{
			if(in[to]==0)
			{
				a2[to]=*s.begin();q.push(to);
				s.erase(a2[to]);
			}
		}
		while(!q.empty())
		{
			int nw=q.front();q.pop();
			fp v[nw] pf
			{
				--in[to];
				a2[to]=*s.lower_bound(a2[nw]+1);
				s.erase(a2[to]);
				if(in[to]==0)q.push(to);
			}
		}
		int fl=0;
		fp g pf
		{
			if(in[to]!=0)
			{
				fl=1;
			}
		}
		if(fl==0)
		{
			fp g pf a1[to]=cc[to];
		}
		else
		{
			NO;
			return 0;
		}
		YES;
		upn
		{
			if(a1[i]==1)putchar('L');
			else putchar('R');
			putchar(' ');
			opl(a2[i]);edl;
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