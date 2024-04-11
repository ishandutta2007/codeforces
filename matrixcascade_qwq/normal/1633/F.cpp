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
const int maxn=4e5+10;
int cnt,dfn[maxn],id[maxn],fa[maxn],dep[maxn],siz[maxn],son[maxn],top[maxn];
int head[maxn],to[maxn],nxt[maxn],w[maxn],tot;
int val[maxn];
int ncnt;
void add(int a,int b,int c)
{
	to[++tot]=b;
	nxt[tot]=head[a];
	w[tot]=c;
	head[a]=tot;
}
void dfs1(int x,int ff)
{
    fa[x]=ff;dep[x]=dep[ff]+1;
    siz[x]=1;
    for(int i=head[x];i;i=nxt[i])
    {
        int v=to[i];
        if(v==ff)continue;
        dfs1(v,x);
        siz[x]+=siz[v];
        val[v]=w[i];
     //   cout<<x<<" "<<val[x];edl;
        if(siz[v]>siz[son[x]])son[x]=v;
    }
}
void dfs2(int x,int tp)
{
    dfn[x]=++cnt;
    id[cnt]=x;
    top[x]=tp;
    if(son[x])dfs2(son[x],tp);
    for(int i=head[x];i;i=nxt[i])
    {
        int v=to[i];
        if(v==fa[x]||v==son[x])continue;
        dfs2(v,v);
    }
}

#define ls (x<<1)
#define rs ((x<<1)|1)
#define mid ((l+r)>>1)

int sum1[maxn<<1],sum2[maxn<<1],sum3[maxn<<1],tag[maxn<<1];
//sum1 sum2 sum3 tag  lazytag

void pushup(int x)
{
	sum1[x]=sum1[ls]+sum1[rs];
	sum2[x]=sum2[ls]+sum2[rs];
	sum3[x]=sum3[ls]+sum3[rs];
}
void f(int x,int l,int r)
{
	sum2[x]=(r-l+1)-sum2[x];
	sum3[x]=sum1[x]-sum3[x];
	tag[x]^=1;
}
void pushdown(int x,int l,int r)
{
	if(tag[x]==0)return;
	f(ls,l,mid);f(rs,mid+1,r);
	tag[x]=0;
}
void build(int x,int l,int r)
{
	if(l==r)
	{
	//	
		sum1[x]=val[id[l]];
	//	opl(id[l]);edl;
		return;
	}
	build(ls,l,mid);build(rs,mid+1,r);
	pushup(x);
}
void update(int x,int l,int r,int ql,int qr)
{
	if(ql<=l&&r<=qr)
	{
		f(x,l,r);
		return;
	}
	pushdown(x,l,r);
	if(ql<=mid)update(ls,l,mid,ql,qr);
	if(mid<qr)update(rs,mid+1,r,ql,qr);
	pushup(x);
}
vector<int>g;
int ff[maxn],bl[maxn];
void add(int x)
{
	bl[x]=1;
	++ncnt;
	int y=1;
	while(top[x]!=top[y])
	{
	//	mc;
		if(dep[top[x]]<dep[top[y]])swap(x,y);
		update(1,1,n,dfn[top[x]],dfn[x]);
		x=fa[top[x]];
	}
	if(dep[x]>dep[y])swap(x,y);
	update(1,1,n,dfn[x],dfn[y]);
}


void solve(int x)
{
	ff[x]=1;
	for(int i=head[x];i;i=nxt[i])
	{
		int v=to[i];
		if(v==fa[x]||bl[v]==0)continue;
		solve(v);
		if(ff[x]==1&&ff[v]==1)
		{
			ff[x]=0;ff[v]=0;g.ep(w[i]);
		}
	}
}
signed main()
{
	int T=1;
	while(T--)
	{
		rdn;
		up_(n-1)
		{
			int x,y;rd(x);rd(y);add(x,y,i);add(y,x,i);
		}
		dfs1(1,0);dfs2(1,1);
//		upn cout<<val[i]<<" ";edl;
		int opt;
		build(1,1,n);
		add(1);
		while(opt=read())
		{
			if(opt==3)return 0;
			if(opt==1)
			{
				int x;rd(x);
				add(x);
		//		++ncnt;
		//		opl(sum2[1]);edl;opl(ncnt);edl;
				if(sum2[1]*2==ncnt)
				{
				//	mc;
					opl(sum3[1]);edl;
				}
				else
				{
					puts("0");
				}
				fflush(stdout);
			}
			else
			{
				if(sum2[1]*2==ncnt)
				{
					upn ff[i]=0;g.clear();
					solve(1);
					sort(g.begin(),g.end());
					opls((int)g.size());
					fp g pf opls(to);
					edl;fflush(stdout);
				}
				else
				{
					puts("0");
					fflush(stdout);
				}
			}
		}
	}
}
/*
6
1 4
6 1
3 2
1 2
5 1
1 4
1 2
1 3
*/
/*
  When you are coding,remember to:
	   - clear the arrays if a problem has many tasks.
	   - pay attention to some special cases(n=0,1).
	   - Don't code before think completely.
	   - ...
*/