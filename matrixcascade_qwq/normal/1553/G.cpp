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
const int maxn=1e6+10;
bool e[maxn];
int p[maxn],tot;
vector<int>v[maxn];
void sieve(int n)
{
    e[1]=1;
    up(i,2,n)
    {
        if(!e[i])
        {
            p[++tot]=i;
        }
        up(j,1,tot)
        {
            if(p[j]*i>n)break;
            e[p[j]*i]=1;
            if(i%p[j]==0)break;
        }
    }
    up(i,1,tot)
    {
    	for(int j=p[i];j<=n;j+=p[i])
    	{
    		v[j].ep(p[i]);
		}
	}
}
vector<int>is;
vector<int>g[maxn]; 
int fa[maxn];
int a[maxn];
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
signed main()
{
	int T=1;
	sieve(maxn-9);
	
	while(T--)
	{
		rdn;int q;rd(q);S(n);
		upn rd(a[i]),a[i+n]=a[i]+1;;
		upn
		{
			fp v[a[i]] pf is.ep(to),g[to].ep(i);
		}
		sort(is.begin(),is.end());is.erase(unique(is.begin(),is.end()),is.end());
		fp is pf
		{
			int w=g[to][0];
			for(auto gw:g[to])
			{
				merge(w,gw);
			}
		}
	//	upn cout<<find(i)<<" ";edl;
		map<pii,int> mp;
		up(i,n+1,n+n)
		{
		//	cout<<a[i]<<" "<<v[a[i]].size();edl;
			vector<int>y;
			fp v[a[i]] pf y.ep(to);
			fp v[a[i-n]] pf y.ep(to);
			fp y pf
			{
				for(auto to2:y)
				{
					if(to==to2)continue;
					if(!g[to].size()||!g[to2].size())continue;
					int fx=find(g[to][0]),fy=find(g[to2][0]);
					mp[mkp(fx,fy)]=1;
				}
			}
			
//			for(int j=0;j<v[a[i]].size();++j)
//			{
//				for(int t=j+1;t<v[a[i]].size();++t)
//				{
//			//		cout<<j<<" "<<t;edl;
//					if(!g[v[a[i]][j]].size()||!g[v[a[i]][t]].size())continue;
//					int fx=find(g[v[a[i]][j]][0]),fy=find(g[v[a[i]][t]][0]);
//				//	cout<<j<<" "<<t;edl;
//				//	cout<<fx<<" qwq "<<fy;edl;
//					mp[mkp(fx,fy)]=1;
//				}
//			}
		}
		up_(q)
		{
			int x,y;rd(x);rd(y);
			int fx=find(x),fy=find(y);
			if(fx==fy)
			{
				puts("0");continue;
			}
			if(__gcd(a[x]+1,a[y])!=1||__gcd(a[x],a[y]+1)!=1)
			{
				puts("1");continue;
			}
			if(mp.find(mkp(fx,fy))!=mp.end()||mp.find(mkp(fy,fx))!=mp.end())
			{
				puts("1");continue;
			}
			puts("2");
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