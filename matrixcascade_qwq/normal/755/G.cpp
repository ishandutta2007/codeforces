#include <bits/stdc++.h>
#define ll long long
#define ull unsigned long long
#define clr(f, n) memset(f, 0, sizeof(int) * (n))
#define cpy(f, g, n) memcpy(f, g, sizeof(int) * (n))
#define rev(f, n) reverse(f, f + n)
#define pir pair<int, int>
#define mkp make_pair
#define up(i,x,y) for(int i=x,i##end=y;i<=i##end;++i)
#define down(i,x,y) for(int i=x,i##end=y;i>=i##end;--i)
#define fst it->first
#define sec it->second
#define int long long
using namespace std;
int n, m, k;
const int mod = 998244353;
const int G = 3;
const int maxn = 300001;
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
int tr[maxn], f[7][maxn], g[7][maxn], invn, trs;
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
void solve(int nw)
{
	int cnt=1,lim=0;
	while(cnt<=nw*2)
	{
		cnt<<=1;
		lim++;
	}
	lim--;
	up(i,0,cnt-1)
	{
		//tr[i] = (tr[i >> 1] >> 1) | ((i & 1) ? cnt >> 1 : 0);
		g[0][i]=g[1][i]=g[2][i]=g[3][i]=g[4][i]=0;
	}
	ntt(f[0],cnt,1);
	ntt(f[1],cnt,1);
	ntt(f[2],cnt,1);
	up(i,0,cnt-1)
	{
		g[0][i]=f[0][i]*f[0][i]%mod;
		g[1][i]=f[1][i]*f[1][i]%mod;
		g[2][i]=f[2][i]*f[2][i]%mod;
		g[3][i]=f[0][i]*f[1][i]%mod;
		g[4][i]=f[1][i]*f[2][i]%mod;
		f[0][i]=0;
		f[1][i]=0;
		f[2][i]=0;
	}
	
	up(i,0,4)ntt(g[i],cnt,0);
	up(i,0,cnt-1)
	{
		f[0][i]=g[0][i];
		if(i)f[0][i]+=g[1][i-1];
		f[1][i]=g[3][i];
		if(i)f[1][i]+=g[4][i-1];
		f[2][i]=g[1][i];
		if(i)f[2][i]+=g[2][i-1];
		f[0][i]%=mod;
		f[1][i]%=mod;
		f[2][i]%=mod;
	}
	up(i,0,cnt-1)
	{
		g[0][i]=g[1][i]=g[2][i]=g[3][4]=g[4][i]=0;
	}
	up(i,nw,cnt-1)f[0][i]=f[1][i]=f[2][i]=0;
	return;
}
void change(int nw)
{
	up(i,0,nw-1)
	{
		f[2][i]=f[1][i];
		f[1][i]=f[0][i];
		f[0][i]=0;
	}
	f[0][0]=1;
	up(i,1,nw-1)
	{
		f[0][i]=(f[1][i-1]+f[2][i-1]+f[1][i])%mod;
	}
	return;
}
signed main()
{
	n=read(),k=read();
	f[0][0]=1;
	f[1][0]=f[0][1]=1;
	int lim=log2(n);
	down(i,lim-1,0)
	{
		solve(k+10);
		if(n&(1<<i))
		{
			change(k+10);
		}
	}
	up(i,1,k)printf("%lld ",f[0][i]);
}