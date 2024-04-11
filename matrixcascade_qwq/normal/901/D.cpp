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
#define mss map<string,string>
#define mvi map<vector<int>,int>
#define miv map<int,vector<int>>
#define rdn rd(n)
#define rdm rd(m)
#define rdk rd(k)
#define pb push_back
#define clr(f, n) memset(f, 0, sizeof(int) * (n))
#define cpy(f, g, n) memcpy(f, g, sizeof(int) * (n))
#define rev(f, n) reverse(f, f + n)
#define edge1 int head[maxn],to[maxn],nxt[maxn],tot;\
void add(int a,int b)\
{\
	to[++tot]=b;nxt[tot]=head[a];head[a]=tot;\
}
#define edge2 int head[maxn],to[maxn],nxt[maxn],tot,w[maxn];\
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
int x[maxn],y[maxn],z[maxn],cnt;
edge2;
int val[maxn],C[maxn];
int ans[maxn];
int dep[maxn];
int f[maxn][20];
void dfs(int x,int fa)
{
	f[x][0]=fa;
	up(i,1,19)f[x][i]=f[f[x][i-1]][i-1];
	dep[x]=dep[fa]+1;
	ver(x)
	{
		int v=to[i];
		if(v==fa)continue;
		dfs(v,x);
		ans[w[i]]=val[v];
		val[x]-=val[v];
		val[v]=0;
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
signed main()
{
	int T=1;
	while(T--)
	{
		rdn;rdm;
		S(n);
		upn rd(C[i]),val[i]=C[i];
		
		up_(m)
		{
			int a,b,c;rd(a);rd(b);c=i;
			int fx=find(a),fy=find(b);
			if(fx==fy)
			{
				x[++cnt]=a;y[cnt]=b;z[cnt]=c;
				continue;
			}
			add(a,b,c);add(b,a,c);
		//	cout<<a<<" qwq "<<b;edl;
			fa[fx]=fy;
		}
		dfs(1,0);
		if(abs(val[1])%2==1)
		{
			NO;return 0;
		}
	//	upm opl(ans[j]),edl;
	//	upn opls(val[i]);edl;
		if(val[1]==0)
		{
			YES;
			up_(m)
			{
				opl(ans[i]);edl;
			}
			return 0;
		}
	//	upn cout<<dep[i]<<" ";edl;
		up_(cnt)
		{
			int p=x[i],q=y[i];
			int la=lca(p,q);
			int vl=dep[p]+dep[q]-2*dep[lca(p,q)]+1;
			if(vl%2==0)continue;
			int ww=val[1]/2;
			up(j,1,n) val[j]=C[j];
			memset(ans,0,sizeof(ans));
			val[p]-=ww,val[q]-=ww;
			ans[z[i]]=ww;
			dfs(1,0);
			int ggg=val[1];
			if(val[1]==0)
			{
			//	mc;
				;
			}
			else
			{
				up(j,1,n) val[j]=C[j];
				memset(ans,0,sizeof(ans));
				ans[z[i]]=-ww;
				val[p]+=ww,val[q]+=ww;
				dfs(1,0);
//				if(val[1]==ggg)
//				{
//					cout<<p<<" "<<q<<" "<<ww;edl;return 0;
//				}
			//	assert(val[1]!=ggg);
			}
			YES;
			upm
			{
				opl(ans[j]);edl;
			}
			return 0;
		}
		NO;
	}
}
/*
20 40
-9 -10 -9 15 -3 -5 -17 -10 -6 2 -13 19 10 -15 15 -14 17 0 7 -8
3 17
6 18
15 12
2 5
18 3
16 20
6 17
20 10
10 18
9 12
15 3
6 4
15 16
20 6
20 9
9 4
4 8
14 5
11 7
12 11
3 13
14 19
7 17
16 14
19 7
12 13
14 13
13 11
9 14
13 17
8 19
5 20
2 17
2 16
12 5
8 1
20 3
6 2
5 18
13 8
*/
/*
  When you are coding,remember to:
	   - clear the arrays if a problem has many tasks.
	   - pay attention to some special cases(n=0,1).
	   - Don't code before think completely.
	   - ...
*/