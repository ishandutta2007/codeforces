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
Mod998;
const int maxn=1010101;
int pw[maxn];
int c[maxn][2],d[maxn][2];
map<pii,int>mp;
int e[maxn],f[maxn];
int fn=0,fm=0;
int rn,rm;
int b[101010];
int wl=2;
int ff=0;
void add1(int a,int b)
{
	assert(b==0||b==1);
	++c[a][b];
	if(c[a][b]==1)
	{
		e[a]++;
		if(e[a]==1)--rm;
		if(e[a]==2)++fm;
	}
}
void add2(int a,int b)
{
	assert(b==0||b==1);
	++d[a][b];
	if(d[a][b]==1)
	{
		f[a]++;
		if(f[a]==1)--rn;
		if(f[a]==2)++fn;
		
//		if(f[a]==3)
//		{
//			cout<<d[a][0]<<d[a][1];exit(0);
//		}
	}
}
void del1(int a,int b)
{
	assert(b==0||b==1);
	--c[a][b];
	if(c[a][b]==0)
	{
		e[a]--;
		if(e[a]==1)--fm;
	//	if(c[a][b^1])--fm;
		if(e[a]==0)++rm;
	}
}
void del2(int a,int b)
{
	assert(b==0||b==1);
	--d[a][b];
	if(d[a][b]==0)
	{
		f[a]--;
		if(f[a]==1)--fn;
	//	if(d[a][b^1])--fm;
		if(f[a]==0)++rn;
	}
}
void change(int x,int y,int opt)
{
	auto t=mkp(x,y);
	if(opt==-1)
	{
		if(mp.find(t)==mp.end()||mp[t]==-1)
		{
		}
		else
		{
			
			//c[y][(x&1)^mp[t]]--;
			
			//d[x][(y&1)^mp[t]]--;
			int a=((x+y)&1)^mp[t];
//			assert(mp[t]!=-1);
			b[a]--;
			if(b[a]==0)++wl;
			
			del1(y,(x&1)^mp[t]);
			del2(x,(y&1)^mp[t]);
			mp.erase(t);
			
		}
	}
	if(opt!=-1)
	{
		if(mp.find(t)==mp.end()||mp[t]==-1)
		{
			int bb=((x+y)&1)^opt;
			b[bb]++;
			assert(bb>=0&&bb<=10);
			if(b[bb]==1)--wl;
			
			add1(y,(x&1)^opt);
			add2(x,(y&1)^opt);
//			c[y][(x&1)^opt]++;
//			d[x][(y&1)^opt]++;
		}
		else
		{
			int a=((x+y)&1)^opt;
			b[a]++;
			if(b[a]==1)--wl;
			
			int bb=((x+y)&1)^mp[t];
			b[bb]--;
			if(b[bb]==0)++wl;
			
			del1(y,(x&1)^mp[t]);
			add1(y,(x&1)^opt);
			
//			c[y][(x&1)^mp[t]]--;
//			c[y][(x&1)^opt]++;
			
			del2(x,(y&1)^mp[t]);
			add2(x,(y&1)^opt);
//			
//			d[x][(y&1)^mp[t]]--;
//			d[x][(y&1)^opt]++;
		}
	}
	mp[t]=opt;
}
signed main()
{
	int T=1;
	pw[0]=1;
	up(i,1,maxn-10)pw[i]=pw[i-1]*2ll%mod;
	while(T--)
	{
		rdn;rdm;rdk;
		rn=n,rm=m;
		fn=fm=0;
		while(k--)
		{
			int x,y,opt;rd(x);rd(y);rd(opt);
			change(x,y,opt);
			int ans=0;
			if(!fn)ans+=pw[rn];
			if(!fm)ans+=pw[rm];
			ans%=mod;
			ans-=wl;ans+=mod;ans%=mod;
			cout<<ans;edl;
		}
	}
}
/*
2 2 7
1 1 1
*/
/*
  When you are coding,remember to:
	   - clear the arrays if a problem has many tasks.
	   - pay attention to some special cases(n=0,1).
	   - Don't code before think completely.
	   - ...
*/




///