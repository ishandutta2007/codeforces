#pragma GCC optimize("Ofast", "unroll-loops")
#pragma GCC target("sse", "sse2", "sse3", "ssse3", "sse4", "avx")
#include <bits/stdc++.h>
#define ll long long
#define int long long
#define ull unsigned long long
#define clr(f, n) memset(f, 0, sizeof(int) * (n))
#define cpy(f, g, n) memcpy(f, g, sizeof(int) * (n))
#define rev(f, n) reverse(f, f + n)
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
//Mod998;

#define ls (x<<1)
#define rs ((x<<1)|1)
const int N=(1<<16)+10;
int dp[17][202020];
const int mod = 998244353;
const int G = 3;
const int maxn = 3020200;
int read2()
{
    int x = 0;
    char ch = getchar();
    while (!isdigit(ch))
        ch = getchar();
    while (isdigit(ch))
        x = (1ll * x * 10 + ch - '0') % mod, ch = getchar();
    return x;
}
inline void print(int *f, int len)
{
    for (int i = 0; i < len; i++)
        printf("%lld ", f[i]);
    puts("");
}

int qpow(int a, int b = mod - 2)
{
    int ans = 1;
    while (b)
    {
        if (b & 1)
            ans = ans * a % mod;
        a = a * a % mod;
        b >>= 1;
    }
    return ans;
}
const int invG = qpow(G);
int tr[maxn], f[maxn], g[maxn], invn, trs;
int inv[maxn];
void poly_pre(int n)
{
    if (trs == n)
        return;
    trs = n;
    for (int i = 0; i < n; ++i)
        tr[i] = (tr[i >> 1] >> 1) | ((i & 1) ? n >> 1 : 0);
}
void ntt(int *f, int n, bool op)
{
    poly_pre(n);
    for (int i = 0; i < n; ++i)
    {
        if (i < tr[i])
            swap(f[i], f[tr[i]]);
    }
    for (int p = 2; p <= n; p <<= 1)
    {
        int len = (p >> 1);
        int bas = qpow(op == 1 ? G : invG, (mod - 1) / p);
        for (int k = 0; k < n; k += p)
        {
            int buf = 1;
            for (int l = k; l < k + len; ++l)
            {
                int kk = buf * f[l + len] % mod;
                f[l + len] = f[l] - kk;
                if (f[len + l] < 0)
                    f[len + l] += mod;
                f[l] = f[l] + kk;
                f[l] %= mod;
                buf *= bas, buf %= mod;
            }
        }
    }
    if (!op)
    {
        int invn = qpow(n);
        for (int i = 0; i < n; ++i)
            f[i] = (f[i] * invn) % mod;
    }
}

void poly_mul(int *f, int *g, int n)
{
    for (int i = 0; i <= n; ++i)
        f[i] = f[i] * g[i] % mod;
}
void times(int *f, int *g, int len, int lim)
{
    static int sav[maxn << 1];
    int n;
    for (n = 1; n < len + len; n <<= 1)
        ;
    clr(sav, n), cpy(sav, g, n);
    ntt(f, n, 1), ntt(sav, n, 1);
    poly_mul(f, sav, n);
    ntt(f, n, 0);
    clr(f + lim, n - lim), clr(sav, n);
}
int w[maxn], r[maxn], sav[maxn];
void poly_inv(int *f, int m)
{
    int n;
    for (n = 1; n < m; n <<= 1)
        ;

    w[0] = qpow(f[0]);
    for (int len = 2; len <= n; len <<= 1)
    {
        for (int i = 0; i < (len >> 1); ++i)
        {
            r[i] = (w[i] << 1) % mod;
        }
        cpy(sav, f, len);
        ntt(w, len << 1, 1);
        ntt(sav, len << 1, 1);
        poly_mul(w, w, len << 1), poly_mul(w, sav, len << 1);
        ntt(w, len << 1, 0);
        for (int i = 0; i < len; i++)
            w[i] = (r[i] - w[i] + mod) % mod;

        clr(w + len, len);
    }
    cpy(f, w, m);
    clr(sav, n << 1), clr(w, n << 1), clr(r, n << 1);
    return;
}
int b1[maxn << 1], b2[maxn << 1];
void poly_sqrt(int *f, int m)
{
    int n;
    for (n = 1; n <= m; n <<= 1)
        ;
    b1[0] = 1;
    for (int len = 2; len <= n; len <<= 1)
    {
        for (int i = 0; i < (len >> 1); ++i)
        {
            b2[i] = (b1[i] << 1) % mod;
        }
        poly_inv(b2, len);
        ntt(b1, len, 1);
        poly_mul(b1, b1, len);
        ntt(b1, len, 0);
        for (int i = 0; i < len; ++i)
        {
            b1[i] = (b1[i] + f[i]) % mod;
        }
        times(b1, b2, len, len);
    }
    cpy(f, b1, m);
    clr(b1, n << 1), clr(b2, n << 1);
}
void poly_dao(int *f, int m)
{
    for (int i = 1; i < m; ++i)
    {
        f[i - 1] = f[i] * 1ll * i % mod;
    }
    f[m - 1] = 0;
}
void initmath(int lim)
{
    inv[1] = 1;
    for (int i = 2; i <= lim; i++)
        inv[i] = 1ll * inv[mod % i] * (mod - mod / i) % mod;
}
void poly_jifen(int *f, int m)
{
    for (int i = m; i; --i)
    {
        f[i] = 1ll * f[i - 1] * inv[i] % mod;
    }
    f[0] = 0;
}
void poly_ln(int *f, int m)
{
    static int g[maxn << 1];
    cpy(g, f, m);
    poly_inv(g, m);
    poly_dao(f, m);
    times(f, g, m, m);
    poly_jifen(f, m - 1);
    clr(g, m);
}
void poly_exp(int *f, int m)
{
    static int s1[maxn], s2[maxn];
    int n = 1;
    for (n = 1; n <= m; n <<= 1)
        ;
    s2[0] = 1;
    for (int len = 2; len <= n; len <<= 1)
    {
        cpy(s1, s2, len >> 1);
        poly_ln(s1, len);
        for (int i = 0; i < len; ++i)
        {
            s1[i] = (f[i] - s1[i] + mod) % mod;
        }
        s1[0]++;
        s1[0] %= mod;
        times(s2, s1, len, len);
    }
    cpy(f, s2, m);
    clr(s1, n), clr(s2, n);
}

void poly_pow(int *f, int m, int k)
{
    poly_ln(f, m);
    for (int i = 0; i < m; ++i)
        f[i] = (f[i] * k) % mod;
    poly_exp(f, m);
}
void poly_div(int *f, int *g, int n, int m)
{
    static int q[maxn], t[maxn];
    int len = n - m + 1;
    rev(g, m);
    cpy(q, g, len);
    rev(g, m);
    rev(f, n);
    cpy(t, f, len);
    rev(f, n);
    poly_inv(q, len);
    times(q, t, len, len);
    rev(q, len);
    times(g, q, n, n);
    for (int i = 0; i < m - 1; ++i)
        g[i] = (f[i] - g[i] + mod) % mod;
    clr(g + m + 1, len);
    cpy(f, q, len);

    clr(f + len, n - len);
}
signed main()
{
	int T=1;
	while(T--)
	{
		int kk;
		rdn;rd(kk);int ff;rd(ff);
		up(i,0,kk)dp[n][i]=1;
		pu(i,n-1,1)
		{
			up(j,0,kk*4)f[j]=g[j]=0;
			up(j,0,kk)f[j]=g[j]=dp[i+1][j];
//			up(j,0,k)cout<<f[j]<<" "<<g[j],edl;
			times(f,g,kk+1,(kk+1)*2);
			int w=0;
//			up(j,0,kk*2)cout<<f[j]<<" ";edl;
			pu(j,(kk+1)*2,0)
			{
//				cout<<f[j]<<" ";
				w+=f[j];w%=mod;
				if(j<=kk)
				{
					dp[i][j]=w;
					dp[i][j]+=f[j]*(kk-j)%mod;dp[i][j]%=mod;
					
				}
			}
//			up(j,0,kk)cout<<dp[i][j]<<" ";edl;
//			edl;
//			cout<<i;edl;
		}
		int ans=0;
//		cout<<dp[1][1];edl;
		up(i,0,ff)ans+=dp[1][i]*dp[1][ff-i]%mod,ans%=mod;
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


///