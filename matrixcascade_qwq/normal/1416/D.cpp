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

int q;
const int maxn=6e5+10;
int p[maxn];
int x[maxn],y[maxn],id[maxn],vv[maxn];
int fa[maxn];
int ft[maxn];
int val[maxn];
int cnt;
vector<int>v[maxn];
int find(int x)
{
    return fa[x]==x?fa[x]:fa[x]=find(fa[x]);
}
void merge(int x,int y,int w)
{
    int fx=find(x),fy=find(y);
    if(fx==fy)return;
    ++cnt;
    fa[fx]=fa[fy]=fa[cnt]=cnt;
    ft[fx]=ft[fy]=cnt;
    val[cnt]=w;
    v[cnt].ep(fx);
    v[cnt].ep(fy);
}
void S(int x)
{
    up(i,1,x)fa[i]=i;
}
int opt[maxn],vl[maxn];
int cmp(int a,int b)
{
	return vv[a]>vv[b];
}
int idfn[maxn];
int f[maxn][21],dep[maxn],dfn[maxn],tim,siz[maxn];
int gw[maxn];
void dfs(int x)
{
//	cout<<x<<" qwq\n";
//	assert(!dfn[x]);
	dfn[x]=++tim;
	idfn[tim]=x;
	siz[x]=1;
	fp v[x] pf
	{
		f[to][0]=x;
		up(i,1,20)f[to][i]=f[f[to][i-1]][i-1];
		dfs(to);
		siz[x]+=siz[to];
	}
}

int ans[maxn<<2];
#define ls ((x<<1))
#define rs ((x<<1)|1)
#define mid ((l+r)>>1)
void pushup(int x)
{
	//do sth
	ans[x]=max(ans[ls],ans[rs]);
}
void build(int x,int l,int r)
{
	if(l==r)
	{
		ans[x]=p[idfn[l]];
		//do sth
		return;
	}
	build(ls,l,mid);build(rs,mid+1,r);
	pushup(x);
}
void update(int x,int l,int r,int p)
{
//	mc;
	if(l==r)
	{
//		mc;
//assert(l==p);
//		cout<<ans[x]<<" "<<p<<" qwq\n";
		ans[x]=0;
		//do sth
		return;
	}
	if(p<=mid)update(ls,l,mid,p);
	else update(rs,mid+1,r,p);
	pushup(x);
}
int query(int x,int l,int r,int ql,int qr)
{
//	cout<<l<<" "<<r<<" "<<ql<<" "<<qr,edl;
	if(ql<=l&&r<=qr)
	{
		//do sth
		return ans[x];
	}
	int anss=-1e9;
	if(ql<=mid)
	{
		chkmax(anss,query(ls,l,mid,ql,qr));
	}
	if(mid<qr)
	{
		chkmax(anss,query(rs,mid+1,r,ql,qr));
	}
	return anss;
}


signed main()
{
	int T=1;
	while(T--)
	{
		rdn;rdm;rd(q);cnt=n;
		upn rd(p[i]),gw[p[i]]=i;
		S(n);
		up_(m)
		{
			rd(x[i]);rd(y[i]);id[i]=i;
		}
		memset(vv,0x3f,sizeof(vv));
		up_(q)
		{
			rd(opt[i]);rd(vl[i]);
			if(opt[i]==2)
			{
				vv[vl[i]]=i;
			}
		}
		sort(id+1,id+m+1,cmp);
		val[0]=-100;
		up(I,1,m)
		{
			int i=id[I];
			merge(x[i],y[i],vv[i]);
		}
//		up(i,1,cnt)cout<<fa[i]<<" ";edl;
		up(i,1,cnt)
		{
			if(fa[i]==i)
			{
				dfs(i);
			}
		}
//		cout<<cnt<<" "<<tim,edl;
		build(1,1,cnt);
		up_(q)
		{
//			cout<<i;edl;
			if(opt[i]==1)
			{
//				cout<<i;edl;
				int x=vl[i];
//				cout<<x;edl;
				pu(j,20,0)if(val[f[x][j]]>=i)x=f[x][j];
//				mc;
//				cout<<x;edl;
				int w=query(1,1,cnt,dfn[x],dfn[x]+siz[x]-1);
//				cout<<x<<" "<<dfn[x]<<" "<<dfn[x]+siz[x]-1,edl;
				opl(w);edl;
				int rw=gw[w];
//				mc;
//				cout<<rw<<" "<<dfn[rw];edl;
				if(w!=0)
				{
					update(1,1,cnt,dfn[rw]);
				}
			}
		}
	}
}
/*

*/
/*
  When you are coding,remember to:
	   - clear the arrays if a problem has many tasks.
	   - pay attention to some special cases(n=0,1).
	   - Don't code before think completely.
	   - ...
*/