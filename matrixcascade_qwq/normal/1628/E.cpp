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



const int maxn=6e5+10;
edge1;
struct node
{
	int x,y,w;
}q[maxn];
int cmp(node a,node b)
{
	return a.w<b.w;
}
int val[maxn<<1];
int fa[maxn],ft[maxn];
int cnt=n;
int find(int x)
{
    return fa[x]==x?fa[x]:fa[x]=find(fa[x]);
}
void merge(int x,int y,int w)
{
    int fx=find(x),fy=find(y);
    if(fx==fy)return;
    ++cnt;
    val[cnt]=w;
    add(cnt,fx);add(cnt,fy);
	fa[cnt]=fa[fx]=fa[fy]=cnt;
}
void S(int x)
{
    up(i,1,x)fa[i]=i;
}
int dfn[maxn<<1];
int tim=0;
int f[maxn<<1][21],dep[maxn<<1];
int id[maxn<<1];
void dfs(int x)
{
//	cout<<x<<" qwq";edl;
	dfn[x]=++tim;
	id[dfn[x]]=x;
	ver(x)
	{
		int v=to[i];
		dep[v]=dep[x]+1;
		f[v][0]=x;
		
		dfs(v);
	}
}
int lca(int x,int y)
{
	
	if(dep[x]<dep[y])swap(x,y);
	pu(i,20,0)if(dep[f[x][i]]>=dep[y])x=f[x][i];
	if(x==y)return x;
	pu(i,20,0)if(f[x][i]!=f[y][i])x=f[x][i],y=f[y][i];
	return f[x][0];
}

int mx[maxn<<2],tag[maxn<<2],mn[maxn<<2];
int pmx[maxn<<2],pmn[maxn<<2];
#define ls ((x<<1))
#define rs ((x<<1)|1)
#define mid ((l+r)>>1)

void pushup(int x)
{
	mx[x]=max(mx[ls],mx[rs]);mn[x]=min(mn[ls],mn[rs]);
	
}
void build(int x,int l,int r)
{
	tag[x]=0;
	if(l==r)
	{
		pmx[x]=pmn[x]=dfn[l];
		mx[x]=-1e9;mn[x]=1e9;
		//do sth
		return;
	}
	build(ls,l,mid);build(rs,mid+1,r);
	pushup(x);
	pmx[x]=max(pmx[ls],pmx[rs]);
	pmn[x]=min(pmn[ls],pmn[rs]);
}
void pushdown(int x)
{
	if(!tag[x])return;
	if(tag[x]==1)
	{
		tag[ls]=tag[rs]=1;
		mx[ls]=pmx[ls];mn[ls]=pmn[ls];
		mx[rs]=pmx[rs];mn[rs]=pmn[rs];
	}
	else
	{
		tag[ls]=tag[rs]=2;
		mx[ls]=-1e9;mn[ls]=1e9;
		mx[rs]=-1e9;mn[rs]=1e9;
	}
	tag[x]=0;
}
void update1(int x,int l,int r,int ql,int qr)
{
	if(ql<=l&&r<=qr)
	{
		tag[x]=1;
		mx[x]=pmx[x];mn[x]=pmn[x];
		//do sth
		return;
	}
	pushdown(x);
	if(ql<=mid)update1(ls,l,mid,ql,qr);
	if(mid<qr)update1(rs,mid+1,r,ql,qr);
	pushup(x);
}
void update2(int x,int l,int r,int ql,int qr)
{
	if(ql<=l&&r<=qr)
	{
		tag[x]=2;
		mx[x]=-1e9;
		mn[x]=1e9;
		//do sth
		return;
	}
	pushdown(x);
	if(ql<=mid)update2(ls,l,mid,ql,qr);
	if(mid<qr)update2(rs,mid+1,r,ql,qr);
	pushup(x);
}
pii query(int x,int l,int r,int ql,int qr)
{
	if(ql<=l&&r<=qr)
	{
		//do sth
		return mkp(mx[x],mn[x]);
	}
	pushdown(x);
	pii ans=mkp(-1e9,1e9);
	if(ql<=mid)
	{
		auto w=query(ls,l,mid,ql,qr);
		chkmax(ans.fi,w.fi);chkmin(ans.se,w.se);
	}
	if(mid<qr)
	{
		auto w=query(rs,mid+1,r,ql,qr);
		chkmax(ans.fi,w.fi);chkmin(ans.se,w.se);
	}
	return ans;
}

signed main()
{
	int T=1;
	while(T--)
	{
		rdn;int qq;rd(qq);
		S(n);
		up_(n-1)
		{
			rd(q[i].x);
			rd(q[i].y);
			rd(q[i].w);
		}
		sort(q+1,q+n,cmp);
		cnt=n;
		up_(n-1)
		{
			merge(q[i].x,q[i].y,q[i].w);
		}dep[0]=-1;
		dfs(cnt);
//		cout<<lca(1,5);ed0l;
//assert(tim==n+cnt);
		build(1,1,n);
		
		up(j,1,20)up(v,1,cnt)f[v][j]=f[f[v][j-1]][j-1];
		while(qq--)
		{
			int opt,l,r,x;;
			rd(opt);
			if(opt==1)
			{
				rd(l);rd(r);
				update1(1,1,n,l,r);
			}
			else if(opt==2)
			{
				rd(l);rd(r);
				update2(1,1,n,l,r);
			}
			else
			{
				rd(x);
				int mxx=mx[1],mnn=mn[1];
				
				if(mxx==-1e9)
				{
					puts("-1");continue;
				}
				if(mxx==mnn&&mxx==dfn[x])
				{
					puts("-1");continue;
				}
				int p=id[mxx],q=id[mnn];
				int lq=lca(p,q);
//				cout<<lq<<" "<<x;edl;
				int la=lca(lq,x);
//				assert(p!=0&&q!=0);
				assert(la!=0);
//				cout<<p<<" "<<q<<" "<<x;edl;
				opd(val[la]);edl;
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