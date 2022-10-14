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
#define up(i,x,y) for(int i=x,i##end=y;i<=i##end;++i)//
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
const int maxn = 5e5 + 10, maxc = 11;
int val[maxn], w[maxn];
struct link_cut_tree
{
    int fa[maxn], sum[maxn], tag[maxn], sta[maxn], ch[maxn][2], siz[maxn];
    int get(int x)
    {
        return ch[fa[x]][0] == x || ch[fa[x]][1] == x;
    }
    void pushup(int x)
    {
        sum[x] = sum[ch[x][0]] + sum[ch[x][1]] + siz[x] + 1;
    }
    void flip(int x)
    {
        swap(ch[x][0], ch[x][1]);
        tag[x] ^= 1;
    }
    void pushdown(int x)
    {
        if (!tag[x])
            return;
        if (ch[x][0])
            flip(ch[x][0]);
        if (ch[x][1])
            flip(ch[x][1]);
        tag[x] = 0;
        return;
    }
    void rotate(int x)
    {
        int y = fa[x], z = fa[y];
        int k1 = (ch[y][1] == x);
        int v = ch[x][!k1];
        if (get(y))
        {
            ch[z][ch[z][1] == y] = x;
        }
        ch[x][!k1] = y;
        ch[y][k1] = v;
        if (v)
        {
            fa[v] = y;
        }
        fa[y] = x;
        fa[x] = z;
        pushup(y);
        pushup(x);
    }
    void splay(int x)
    {
        int top = 0;
        int y = x, z;
        sta[++top] = y;
        while (get(y))
            sta[++top] = y = fa[y];
        while (top)
            pushdown(sta[top--]);
        while (get(x))
        {
            y = fa[x], z = fa[y];
            if (get(y))
            {
                rotate((ch[y][0] == x) ^ (ch[z][0] == y) ? x : y);
            }
            rotate(x);
        }
        pushup(x);
        return;
    }
    void access(int x)
    {
        for (int y = 0; x; x = fa[y = x])
        {
            splay(x);
            siz[x] += sum[ch[x][1]] - sum[ch[x][1] = y];
            pushup(x);
        }
    }
    int findroot(int x)
    {
        access(x);
        splay(x);
        while (ch[x][0])
        {
            pushdown(x);
            x = ch[x][0];
        }
        return x;
    }
    void makeroot(int x)
    {
        access(x);
        splay(x);
        flip(x);
    }
    void split(int x, int y)
    {
        makeroot(x);
        access(y);
        splay(y);
    }
    void cut(int x,int y)
	{
		split(x,y);
		ch[y][0]=fa[x]=0;
		pushup(y);
		pushup(x);
	}
    void link(int x, int y)
    {
        split(x, y);
        siz[fa[x] = y] += sum[x];
        pushup(y);
    }
    int qry(int x)
    {
    	makeroot(x);
    	return sum[x];
	}

} Tree;
vector<pii>v[505050];
signed main()
{
	int T=1;
	while(T--)
	{
		rdn;
		upn Tree.sum[i]=1;
		up_(n-1)
		{
			int x,y,z;rd(x);rd(y);rd(z);
			Tree.link(x,y);
			v[z].ep(mkp(x,y));
		}
		int ans=0;
		up(i,1,n)
		{
			if(!v[i].size())continue;
			fp v[i] pf Tree.cut(to.fi,to.se);
			fp v[i] pf ans+=Tree.qry(to.fi)*Tree.qry(to.se);
			fp v[i] pf Tree.link(to.fi,to.se);
		}cout<<ans;
	}
}
/*
  When you are coding,remember to:
	   - clear the arrays if a problem has many tasks.
	   - pay attention to some special cases(n=0,1).
	   - Don't code before think completely.
	   - ...
*/