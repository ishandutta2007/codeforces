//#pragma GCC optimize("Ofast", "unroll-loops")
//#pragma GCC target("sse", "sse2", "sse3", "ssse3", "sse4", "avx")
#include <bits/stdc++.h>
#define ll long long
#define int long long
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
#define pb push_back
#define edge1 int head[maxn],to[maxn<<1],nxt[maxn<<1],tot;\
void add(int a,int b)\
{\
	to[++tot]=b;nxt[tot]=head[a];head[a]=tot;\
}
#define edge2 int head[maxn],to[maxn<<1],nxt[maxn<<1],tot,w[maxn<<1];\
void add(int a,int b,int c)\
{\
	to[++tot]=b;nxt[tot]=head[a];head[a]=tot;w[tot]=c;\
}
#define Mod998 const int mod=998244353;\
int qpow(int a,int b=mod-2)\
{\
	int ans=1;\
	while(b)\
	{\
		if(b&1)ans=1ll*ans*a%mod;\
		a=1ll*a*a%mod;\
		b>>=1;\
	}\
	return ans;\
}\
void Add(int &a,int b)\
{\
	a+=b;if(a>=mod)a-=mod;\
}\
void Sub(int &a,int b)\
{\
	a-=b;if(a<0)a+=mod;\
}\
int Mul(int a,int b)\
{\
	return 1ll*a*b%mod;\
}\
int Frac(int a,int b)\
{\
	return 1ll*a*qpow(b)%mod;\
}

#define Mod1e9 const int mod=1e9+7;\
int qpow(int a,int b=mod-2)\
{\
	int ans=1;\
	while(b)\
	{\
		if(b&1)ans=1ll*ans*a%mod;\
		a=1ll*a*a%mod;\
		b>>=1;\
	}\
	return ans;\
}\
void Add(int &a,int b)\
{\
	a+=b;if(a>=mod)a-=mod;\
}\
void Sub(int &a,int b)\
{\
	a-=b;if(a<0)a+=mod;\
}\
int Mul(int a,int b)\
{\
	return 1ll*a*b%mod;\
}\
int Frac(int a,int b)\
{\
	return 1ll*a*qpow(b)%mod;\
}

#define DSU int fa[maxn];\
int find(int x)\
{\
    return fa[x]==x?fa[x]:fa[x]=find(fa[x]);\
}\
void merge(int x,int y)\
{\
    int fx=find(x),fy=find(y);\
    if(fx==fy)return;\
    fa[fx]=fy;\
}\
void S(int x)\
{\
    up(i,1,x)fa[i]=i;\
}
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
void print(int x)
{
	if(x<0)putchar('-'),x=-x;
	if(x>9)print(x/10);
	putchar(x%10+'0');
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
/*
#define ls ((x<<1))
#define rs ((x<<1)|1)
#define mid ((l+r)>>1)
void pushup(int x)
{
	//do sth
}
void build(int x,int l,int r)
{
	if(l==r)
	{
		//do sth
		return;
	}
	build(ls,l,mid);build(rs,mid+1,r);
	pushup(x);
}
void update(int x,int l,int r,int ql,int qr)
{
	if(ql<=l&&r<=qr)
	{
		//do sth
		return;
	}
	if(ql<=mid)update(ls,l,mid,ql,qr);
	if(mid<qr)update(rs,mid+1,r,ql,qr);
	pushup(x);
}
void query(int x,int l,int r,int ql,int qr)
{
	if(ql<=l&&r<=qr)
	{
		//do sth
		return;
	}
	if(ql<=mid)
	{
		query(ls,l,mid,ql,qr);
	}
	if(mid<qr)
	{
		query(rs,mid+1,r,ql,qr);
	}
	return;
}
*/
Mod1e9;
int s,t;
const int maxn=1505050;
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
int a[maxn],b[maxn];
int p[maxn],q[maxn],c[maxn],d[maxn];
int pp[maxn],qq[maxn];
int e[maxn];
int cr[maxn];
int h1[maxn],h2[maxn];
signed main()
{
	int T=1;
	while(T--)
	{
		rdn;rdm;
		upn rd(a[i]);upn rd(b[i]);
		int cc=0;
		up_(m)
		{
			rd(p[i]);rd(q[i]);pp[i]=p[i];qq[i]=q[i];
			if(!a[p[i]]&&!a[q[i]])
			{
				c[i]=1;continue;
			}
			cc++;
			if(!a[p[i]])
			{
				++e[q[i]];
				++e[n+1];
				p[i]=n+1;
			}
			else if(!a[q[i]])
			{
				++e[p[i]];
				++e[n+1];
				q[i]=n+1;
			}
			else
			{
				++e[p[i]];++e[q[i]];
			}
		}
		s=0,t=n*10+m*10+2;
		up_(m)
		{
			if(!c[i])add(s,i,1);
			if(!c[i])
			{
				add(i,q[i]+m,1);
				cr[i]=tot-1;
				add(i,p[i]+m,1);
			}
		}
		a[n+1]=1;
		upn
		{
			if(a[i])b[n+1]-=b[i];
		}
//		e[n+1]=
		int sm=0;
		up(i,1,n+1)
		{
			if(a[i])
			{
				int w=e[i]+b[i];
				
//				cout<<i<<" "<<w;edl;
				if(w<0||w%2!=0)
				{
					NO;return 0;
				}
				w/=2;
				sm+=w;
				add(i+m,t,w);
//				cout<<i<<" "<<w;edl;
			}
		}
		if(sm!=cc)
		{
			NO;return 0;
		}
		int as=solve();
		if(as>m)
		{
//			assert(0);
		}
		if(as!=cc)
		{
			NO;return 0;
		}
		up_(m)
		{
			if(c[i])--h1[pp[i]],++h1[qq[i]];
			else
			{
//				cout<<cr[i]<<" w "<<w[cr[i]];edl;
				if(w[cr[i]])swap(pp[i],qq[i]);
				--h1[pp[i]];++h1[qq[i]];
			}
		}
		upn if(a[i])assert(h1[i]==b[i]);
		YES;
		
		up_(m)
		{
			if(c[i])opls(pp[i]),opls(qq[i]),--h1[pp[i]],++h1[qq[i]];
			else
			{
//				cout<<cr[i]<<" w "<<w[cr[i]];edl;
				opls(pp[i]);opls(qq[i]);
				--h1[pp[i]];++h1[qq[i]];
			}
			edl;
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