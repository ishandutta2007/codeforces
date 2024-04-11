#pragma GCC optimize("Ofast", "unroll-loops")
#pragma GCC target("sse", "sse2", "sse3", "ssse3", "sse4", "avx")
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
int stp=0;
const int maxn=606060;
int num[maxn];
int x[maxn],y[maxn];
int fa[maxn],dis[maxn],siz[maxn],is[maxn];
int find(int x,int &y)
{
	stp++;
	y^=dis[x];//dis to fa
	if(fa[x]==x)return x;
	return find(fa[x],y);
}
stack<int>s;
int merge(int x,int y,int opt)
{
	int d1,d2;
	d1=d2=0;
	int fx=find(x,d1),fy=find(y,d2);
	int dist=1^d1^d2;
	if(fx==fy)
	{
		if(dist&1)
		{
			return 0;
		}
		else return 1;
	}
	if(siz[fx]>siz[fy])swap(fx,fy);
	fa[fx]=fy;
	siz[fy]+=siz[fx];
	dis[fx]=dist;
	if(opt)s.push(fx);
	return 1;
}
void del(int x,int sz)
{
	x=fa[x];
	while(true)
	{
		siz[x]-=sz;
		if(x==fa[x])return;
		x=fa[x];
	}
}
map<pii,vector<pii> >mp;
signed main()
{
	int T=1;
	while(T--)
	{
		rdn;rdm;rdk;
		upn rd(num[i]);
		up_(m)
		{
			rd(x[i]);rd(y[i]);
		}
		int nn=k;
		upn
		{
			fa[i]=i;siz[i]=1;
		}
		up_(m)
		{
			if(num[x[i]]==num[y[i]])
			{
				int fl=merge(x[i],y[i],0);
				if(fl==0&&is[num[x[i]]]==0)is[num[x[i]]]=1,nn--;
//				if(stp>=100000000)return 0;
			}
		}int ans=1ll*nn*(nn-1)/2; 
		//if(n==500000&&m==499999&&k==100000)return 0;
		up_(m)
		{
			if(is[num[x[i]]]||is[num[y[i]]])continue;
			if(num[x[i]]!=num[y[i]])
			{
				pii p=mkp(num[x[i]],num[y[i]]);
				if(p.fi<p.se)swap(p.fi,p.se);
				mp[p].ep(mkp(x[i],y[i]));
			}
		}
		
		fp mp pf
		{
			auto ve=to.se;
			for(auto too:ve)
			{
				
				int p=too.fi,q=too.se;
//				cout<<p<<" qwq "<<q;edl;
				int fl=merge(p,q,1);
				if(!fl)
				{
//					cout<<to.fi.fi<<" "<<to.fi.se;edl;
					--ans;break;
				}
			}
			while(s.size())
			{
				auto w=s.top();s.pop();
				del(w,siz[w]);
				dis[w]=0;fa[w]=w;
			}
		}
		cout<<ans;edl;
	}
}
/*
  When you are coding,remember to:
	   - clear the arrays if a problem has many tasks.
	   - pay attention to some special cases(n=0,1).
	   - Don't code before think completely.
	   - ...
*/