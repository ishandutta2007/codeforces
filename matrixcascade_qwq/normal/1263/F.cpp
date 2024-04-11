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
int s,t;
const int maxn=2003030;
int head[maxn],to[maxn],nxt[maxn],w[maxn],tot=1;
int dep[maxn];
int cur[maxn];
const int inf=1<<30;
void addd(int a,int b,int c)
{
    to[++tot]=b;
    w[tot]=c;
    nxt[tot]=head[a];
    head[a]=tot;
}
void add(int a,int b,int c)
{
    addd(a,b,c);
    addd(b,a,0);
}
bool bfs()
{
    memset(dep,0,sizeof(dep));
    queue<int>q;
    cur[s]=head[s];
    q.push(s);
    dep[s]=1;
    while(!q.empty())
    {
        int x=q.front();q.pop();
        for(int i=head[x];i;i=nxt[i])
        {
            int v=to[i];
            if(w[i]&&!dep[v])
            {
                q.push(v);
                dep[v]=dep[x]+1;
                cur[v]=head[v];
                if(v==t)return 1;
            }
        }
    }
    return 0;
}
int dinic(int x,int flow)
{
    if(x==t)return flow;
    int rst=flow;
    int fl;
    for(int i=cur[x];i&&rst;i=nxt[i])
    {
        cur[x]=i;
        int v=to[i];
        if(w[i]&&dep[v]==dep[x]+1)
        {
            fl=dinic(v,min(rst,w[i]));
            if(!fl)dep[v]=0;
            w[i]-=fl;w[i^1]+=fl;
            rst-=fl;
        }
    }
    return flow-rst;
}
int solve()
{
    int flow=0,maxflow=0;
    while(bfs())
    {
        while(flow=dinic(s,inf))maxflow+=flow;
    }
    return maxflow;
}
int w1[2020],w2[2020];
signed main()
{
	int T=1;
	while(T--)
	{
		s=0;t=100000;
		rd(n);
		rd(m);
		up_(m-1)
		{
			int fa;rd(fa);
			add(fa,i+1,inf);
		}
		up(i,2,m)add(s,i,1);
		upn rd(w1[i]);
		rd(k);
		up_(k-1)
		{
			int fa;rd(fa);
			add(i+m+1,fa+m,inf);
		}
		up(i,2,k)add(i+m,t,1);
		upn
		{
			add(w1[i],m+read(),inf);
		}
		int ans=solve();
		cout<<(k+m-2)-ans;
	}
}
/*
  When you are coding,remember to:
	   - clear the arrays if a problem has many tasks.
	   - pay attention to some special cases(n=0,1).
	   - Don't code before think completely.
	   - ...
*/