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

const int maxn=2e5+10;
edge2;
int f[maxn][4];//3
int g[maxn][4];//3
int ans1[maxn];
int up[maxn];//
int p[maxn][2],q[maxn][2],d[maxn];//
void dfs(int x,int fa)
{
	f[x][0]=0;
	ver(x)
	{
		int v=to[i];
		if(v==fa)continue;
		dfs(v,x);
		if(f[v][0]+w[i]>f[x][0])
		{
			g[x][0]=v;f[x][0]=f[v][0]+w[i];
		}
	}
	ver(x)
	{
		int v=to[i];
		if(v==fa)continue;
		if(f[v][0]+w[i]>f[x][1]&&v!=g[x][0])
		{
			g[x][1]=v;f[x][1]=f[v][0]+w[i];
		}
	}
	ver(x)
	{
		int v=to[i];
		if(v==fa)continue;
		if(f[v][0]+w[i]>f[x][2]&&v!=g[x][0]&&v!=g[x][1])
		{
			g[x][2]=v;f[x][2]=f[v][0]+w[i];
		}
	}
	ver(x)
	{
		int v=to[i];
		if(v==fa)continue;
		if(f[v][0]+w[i]>f[x][3]&&v!=g[x][0]&&v!=g[x][1]&&v!=g[x][2])
		{
			g[x][3]=v;f[x][3]=f[v][0]+w[i];
		}
	}
}
int dd[maxn];
void dfs2(int x,int fa)
{
	d[x]=f[x][0]+f[x][1];
	ver(x)
	{
		int v=to[i];if(v==fa)continue;
		if(v==g[x][0])
		{
			up[v]=f[x][1]+w[i];
		}
		else
		{
			up[v]=f[x][0]+w[i];
		}
		chkmax(up[v],up[x]+w[i]);
		dfs2(v,x);
		chkmax(d[x],d[v]);
		if(d[v]>p[x][0])
		{
			q[x][0]=v;p[x][0]=d[v];
		}
	}
	ver(x)
	{
		int v=to[i];
		if(v==fa)continue;
		if(d[v]>p[x][1]&&v!=q[x][0])
		{
			q[x][1]=v;p[x][1]=d[v];
		}
	}
}
void dfs4(int x,int fa)
{
	ver(x)
	{
		int v=to[i];
		if(v==fa)continue;
		
		int ww;
		if(v==q[x][0])ww=p[x][1];
		else ww=p[x][0];
		dd[v]=max(ww,dd[x]);
		dfs4(v,x);
	}
}
int ass;
void dfs3(int x,int fa,int pre)
{
	ver(x)
	{
		int v=to[i];if(v==fa)continue;
		int pp;
		//if(q[x][1])assert(q[x][0]!=q[x][1]);if(g[x][1])assert(g[x][0]!=g[x][1]);if(g[x][2])assert(g[x][1]!=g[x][2]);
		if(v==q[x][0])
		{
			int ans=pre;
			if(v==g[x][0])ans=f[x][1]+max(up[x],f[x][2]);
			else if(v==g[x][1])ans=f[x][0]+max(up[x],f[x][2]);
			else ans=f[x][0]+max(up[x],f[x][1]);
			chkmax(ans,pre);
			chkmax(ans,p[x][1]);
			chkmax(ass,ans+d[v]+2*w[i]);pp=ans;
		}
		else
		{
			int ans=pre;
			if(v==g[x][0])ans=f[x][1]+max(up[x],f[x][2]);
			else if(v==g[x][1])ans=f[x][0]+max(up[x],f[x][2]);
			else ans=f[x][0]+max(up[x],f[x][1]);
			chkmax(ans,pre);
			chkmax(ans,p[x][0]);
			chkmax(ass,ans+d[v]+2*w[i]);pp=ans;
		}
		
		
		dfs3(v,x,pp);
	}
}
signed main()
{
	int T=1;
	while(T--)
	{
		rdn;
		int sm=0;
		up_(n-1)
		{
			int a,b,c;rd(a);rd(b);rd(c);add(a,b,c);add(b,a,c);
			sm+=c;
		}
		sm*=2;
		dfs(1,0);dfs2(1,0);dfs4(1,0);dfs3(1,0,0);
//		cout<<ass;edl;
		upn
		{
			vector<int>v;
			up(j,0,3)v.ep(f[i][j]);
			v.ep(up[i]);
			sort(v.begin(),v.end());reverse(v.begin(),v.end());
			int w=0;
			up(j,0,3)w+=v[j];
			chkmax(ass,w);
		}
		cout<<sm-ass;
//		upn up(i,0,2)f[i][j]=-100000000;
	}
}
/*
  When you are coding,remember to:
	   - clear the arrays if a problem has many tasks.
	   - pay attention to some special cases(n=0,1).
	   - Don't code before think completely.
	   - ...
*/