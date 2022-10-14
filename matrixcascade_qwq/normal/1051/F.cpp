/*
qwq
*/


//#pragma GCC optimize("Ofast", "unroll-loops")
//#pragma GCC target("sse", "sse2", "sse3", "ssse3", "sse4", "avx")
#include <bits/stdc++.h>
#define ll long long
#define ull unsigned long long
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
const int maxn=404040;
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
int head[maxn*1],to[maxn*2],nxt[maxn*2],w[maxn*2],tot;
void add(int a,int b,int c)
{
    to[++tot]=b;
    nxt[tot]=head[a];
    head[a]=tot;
    w[tot]=c;
}
struct node
{
    ll dis,nw;
    node(int diss,int nww)
    {
        dis=diss,nw=nww;
    }
    bool operator <(const node &q)const
    {
        return dis>q.dis;
    }
};
priority_queue<node>q;
ll dis[44][maxn];int id[maxn];
void dij(int s)
{
	upn dis[id[s]][i]=1e17;
    dis[id[s]][s]=0;
    q.push(node(0,s));
    while(!q.empty())
    {
        node ze=q.top();
        q.pop();
        ll nw=ze.nw,val=ze.dis;
        if(val>dis[id[s]][nw])continue;
        for(int i=head[nw];i;i=nxt[i])
        {
            int v=to[i];
            if(dis[id[s]][nw]+w[i]<dis[id[s]][v])
            {
                dis[id[s]][v]=dis[id[s]][nw]+w[i];

                q.push(node(dis[id[s]][v],v));
            }
        }
    }   
}
int b[maxn];
vector<pii>v[maxn];
ll val[maxn];
int f[maxn][20],dep[maxn];

void dfs(int x,int fa,ll vv)
{

	f[x][0]=fa;dep[x]=dep[fa]+1;
	up(i,1,19)f[x][i]=f[f[x][i-1]][i-1];
	val[x]=vv;
	fp v[x] pf
	{
		if(to.fi==fa)continue;
		dfs(to.fi,x,vv+to.se);
	}
}
int lca(int x,int y)
{
	if(dep[x]<dep[y])swap(x,y);
	pu(i,19,0)if(dep[f[x][i]]>=dep[y])x=f[x][i];
	if(x==y)return x;
	pu(i,19,0)if(f[x][i]!=f[y][i])x=f[x][i],y=f[y][i];
	return f[x][0];
}
ll getdis(int x,int y)
{
	return val[x]+val[y]-2*val[lca(x,y)];
}
signed main()
{
	int T=1;
	while(T--)
	{
		rd(n);rd(m);
		S(n);
		upm
		{
			int x,y,z;rd(x);rd(y);rd(z);
			add(x,y,z);add(y,x,z);
			if(find(x)==find(y))
			{
				b[x]=b[y]=1;
			}
			else
			{
				
				v[x].ep(mkp(y,z));v[y].ep(mkp(x,z));
				merge(x,y);
			}
		}
		vector<int>g;
		int tt=0;
		upn
		{
			if(b[i])id[i]=++tt,dij(i),g.ep(i);
		}
		dfs(1,0,0);
		int q;rd(q);
		up_(q)
		{
			int x,y;rd(x);rd(y);
			ll ans=getdis(x,y);
			fp g pf ans=min(ans,dis[id[to]][x]+dis[id[to]][y]);
		//	cout<<x<<" "<<y<<" ";
			opl(ans);edl;
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