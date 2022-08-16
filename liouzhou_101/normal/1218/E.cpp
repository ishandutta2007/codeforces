#pragma GCC optimize("Ofast,unroll-loops,no-stack-protector,fast-math")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")
//#pragma comment(linker, "/stack:200000000")
 
#include <bits/stdc++.h>
 
using namespace std;
 
typedef long long ll;
typedef unsigned long long ull;
typedef double ld;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;
typedef pair<ld,ld> pdd;
 
#define X first
#define Y second
 
//#include <boost/unordered_map.hpp>
//using namespace boost;
 
/*
#include <ext/pb_ds/tree_policy.hpp>
#include <ext/pb_ds/assoc_container.hpp>
using namespace __gnu_pbds;
typedef tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update> rbtree;
rbtree T;
*/
 
using i32 = int;
using i64 = long long;
using u8 = unsigned char;
using u32 = unsigned;
using u64 = unsigned long long;
using f64 = double;
using f80 = long double;
//using i128 = __int128_t;
//using u128 = __uint128_t;
//using i128 = i64;
//using u128 = u64;
 
ll power(ll a, ll b, ll p)
{
	if (!b) return 1;
	ll t = power(a, b/2, p);
	t = t*t%p;
	if (b&1) t = t*a%p;
	return t;
}
 
ll exgcd(ll a, ll b, ll &x, ll &y)
{
	if (b == 0)
	{
		x = 1;
		y = 0;
		return a;
	}
	ll px, py;
	ll d = exgcd(b, a%b, px, py);
	x = py;
	y = px-a/b*py;
	return d;
}
 
template<class T>
inline void freshmin(T &a, const T &b)
{
	if (a > b) a = b;
}
 
template<class T>
inline void freshmax(T &a, const T &b)
{
	if (a < b) a = b;
}
 
//#define getchar getchar_unlocked
//#define putchar putchar_unlocked

#define FWRITE

namespace io
{

#ifndef FWRITE
#include <unistd.h>
#endif
const int BUFSIZE = 1<<20;

int isize, osize;
char ibuf[BUFSIZE+10], obuf[BUFSIZE+10];
char *is, *it, *os = obuf, *ot = obuf+BUFSIZE;

char getchar()
{
	if (is == it)
	{
		is = ibuf;
		#ifdef FWRITE
		it = ibuf+fread(ibuf, 1, BUFSIZE, stdin);
		#else
		it = ibuf+read(STDIN_FILENO, ibuf, BUFSIZE);
		#endif
		if (is == it) return EOF;
	}
	return *is ++;
}

char getalpha()
{
	char c = getchar();
	while (!isalpha(c)) c = getchar();
	return c;
}

void putchar(char c)
{
	*os ++ = c;
	if (os == ot)
	{
		#ifdef FWRITE
		fwrite(obuf, 1, BUFSIZE, stdout);
		#else
		write(STDOUT_FILENO, obuf, BUFSIZE);
		#endif
		os = obuf;
	}
}

int inp() {
	int x = 0, f = 0; char ch;
	for(ch = getchar(); !isdigit(ch); ch = getchar())
		if(ch == '-') f = 1;
	for(; isdigit(ch); x = x * 10 + ch - '0', ch = getchar());
	return f ? -x : x;
}

ll inp_ll() {
	ll x = 0; int f = 0; char ch;
	for(ch = getchar(); !isdigit(ch); ch = getchar())
		if(ch == '-') f = 1;
	for(; isdigit(ch); x = x * 10 + ch - '0', ch = getchar());
	return f ? -x : x;
}

template<class T>
bool read(T &x)
{
	x = 0;
	char ch = getchar();
	if (ch == EOF) return 0;
	for(; !isdigit(ch); )
	{
		ch = getchar();
		if (ch == EOF) return 0;
	}
	for(; isdigit(ch); x = x * 10 + ch - '0', ch = getchar());
	return 1;
}

template<class T>
void write(T x)
{
	static char s[22];
	static char *it = s+20;
	static char *end = s+20;
	
	if (x < 0)
	{
		putchar('-');
		x = -x;
	}
	
	do
	{
		*-- it = x%10+'0';
		x /= 10;
	}
	while (x);
	/*
	if (!x)
		*-- it = '0';
	while (x)
	{
		*-- it = x%10+'0';
		x /= 10;
	}
	*/
	for (; it < end; ++ it)
		putchar(*it);
}

template<>
void write(const char *s)
{
	for (; *s; ++ s) putchar(*s);
}

template<>
void write(char c)
{
	putchar(c);
}

template<class T, class V>
void write(T x, V y)
{
	write(x);
	write(y);
}

template<class T>
void writeln(T x)
{
	write(x);
	putchar('\n');
}

struct ender
{
	~ender()
	{
		if (os != obuf)
			#ifdef FWRITE
			fwrite(obuf, 1, os-obuf, stdout);
			#else
			write(STDOUT_FILENO, obuf, os-obuf);
			#endif
	}
}__ender;

}

template<class T>
void print(const T &a)
{
	for (auto x : a) printf("%d ", x); puts("");
}

const int MAXN = 200010;
const int MAXK = 17;
//const int INF = 1000000010;
const i64 INF = 1000000000000000000LL;
const int MOD = 998244353;
const int INV2 = (MOD+1)/2;
const int INV6 = power(6, MOD-2, MOD);

using namespace io;

//mt19937 rd(chrono::steady_clock::now().time_since_epoch().count());

namespace ntt
{

using word_t = u32;
using dword_t = u64;

template<word_t mod, word_t root>
class Mod
{
public:
    //static constexpr int level = __builtin_ctzll(mod-1);
    static constexpr int level = 16;
    static constexpr int all = (1<<level)-1;

    word_t x;

    Mod () {}
    Mod (word_t n) : x(n) {}

    static word_t modulus()
    {
        return mod;
    }

    static bool isntt()
    {
        return root != 1;
    }

    static Mod omega()
    {
        return Mod(root).pow((mod - 1) >> level);
    }

    bool operator == (const Mod &rhs) const
    {
        return x == rhs.x;
    }

    Mod& operator += (const Mod &rhs)
    {
        this->x += rhs.x;
        if (this->x >= mod) this->x -= mod;
        return *this;
    }
    Mod& operator -= (const Mod &rhs)
    {
        this->x += mod-rhs.x;
        if (this->x >= mod) this->x -= mod;
        return *this;
    }
    Mod& operator *= (const Mod &rhs)
    {
        this->x = dword_t(this->x)*rhs.x%mod;
        return *this;
    }

    Mod operator + (const Mod &rhs) const
    {
        return Mod(*this) += rhs;
    }
    Mod operator - (const Mod &rhs) const
    {
        return Mod(*this) -= rhs;
    }
    Mod operator - () const
    {
        return Mod(x ? mod-x : 0);
    }
    Mod operator * (const Mod &rhs) const
    {
        return Mod(*this) *= rhs;
    }

    word_t get() const
    {
        return this->x;
    }
    void set(word_t n) const
    {
        this->x = n;
    }

    Mod pow(word_t exp) const
    {
        Mod ret = Mod(1);
        for (Mod base = *this; exp; exp >>= 1, base *= base)
            if (exp & 1) ret *= base;
        return ret;
    }
    Mod inverse() const
    {
        return pow(mod - 2);
    }

    friend ostream& operator << (ostream& os, const Mod& m)
    {
        return os << m.get();
    }
};

template <typename mod_t>
void rev_permute(mod_t* A, int n)
{
    int r = 0, nh = n >> 1;
    for (int i = 1; i < n; ++ i)
    {
        for (int h = nh; !((r ^= h) & h); h >>= 1);
        if (r > i) swap(A[i], A[r]);
    }
}

template <typename mod_t>
void ntt_dit4(mod_t* A, int n, int sign, mod_t* roots) {
    rev_permute(A, n);
    int logn = __builtin_ctz(n);
    assert(logn <= mod_t::level);

    if (logn & 1)
        for (int i = 0; i < n; i += 2)
        {
            mod_t a = A[i], b = A[i + 1];
            A[i] = a + b;
            A[i + 1] = a - b;
        }

    mod_t imag = roots[1<<(mod_t::level - 2)];
    if (sign < 0) imag = imag.inverse();

    for (int e = 2 + (logn & 1); e <= logn; e += 2)
    {
        const int m = 1 << e;
        const int m4 = m >> 2;
        int dw = 1<<(mod_t::level - e);
        if (sign < 0) dw = mod_t::all+1-dw;

        const int block_size = min(n, max(m, (1 << 15) / int(sizeof(A[0]))));
        for (int k = 0; k < n; k += block_size)
        {
            int w = 0, w2 = 0, w3 = 0;
            for (int j = 0; j < m4; ++ j)
            {
                for (int i = k + j; i < k + block_size; i += m)
                {
                    mod_t a0 = A[i + m4 * 0], a2 = A[i + m4 * 1] * roots[w2];
                    mod_t a1 = A[i + m4 * 2] * roots[w],   a3 = A[i + m4 * 3] * roots[w3];
                    mod_t t02 = a0 + a2, t13 = a1 + a3;
                    A[i + m4 * 0] = t02 + t13; A[i + m4 * 2] = t02 - t13;
                    t02 = a0 - a2, t13 = (a1 - a3) * imag;
                    A[i + m4 * 1] = t02 + t13; A[i + m4 * 3] = t02 - t13;
                }
                w = (w+dw)&mod_t::all; w2 = (w+w)&mod_t::all; w3 = (w2+w)&mod_t::all;
            }
        }
    }
}

template<class mod_t>
mod_t* get_roots()
{
    static int flag = 0;
    static mod_t roots[1<<mod_t::level];
    if (!flag)
    {
        flag = 1;
        roots[0] = 1;
        roots[1] = mod_t::omega();
        for (int i = 2; i < 1<<mod_t::level; ++ i)
            roots[i] = roots[i-1]*roots[1];
    }
    return roots;
}

template <typename mod_t>
void convolve(mod_t* A, int s1, mod_t* B, int s2, bool cyclic = false)
{
    int s = (cyclic ? max(s1, s2) : s1 + s2 - 1);
    int size = 1;
    while (size < s) size <<= 1;

    mod_t *roots = get_roots<mod_t>();
    fill(A + s1, A + size, 0);
    ntt_dit4(A, size, 1, roots);
    if (A == B && s1 == s2)
    {
        for (int i = 0; i < size; ++ i)
            A[i] *= A[i];
    }
    else
    {
        fill(B + s2, B + size, 0);
        ntt_dit4(B, size, 1, roots);
        for (int i = 0; i < size; ++ i)
            A[i] *= B[i];
    }
    ntt_dit4(A, size, -1, roots);
    mod_t inv = mod_t(size).inverse();
    for (int i = 0; i < (cyclic ? size : s); ++ i)
        A[i] *= inv;
}

}

namespace fft
{

using float_t = f64;

constexpr int LEVEL = 16;
constexpr int FFT_MAXN = 1<<LEVEL;
constexpr float_t PI = 3.1415926535897932384626433;

struct complex
{
    float_t x, y;
    complex (float_t x = 0, float_t y = 0) : x(x), y(y) {}

    complex& operator += (const complex& rhs)
    {
        x += rhs.x;
        y += rhs.y;
        return *this;
    }
    complex& operator -= (const complex& rhs)
    {
        x -= rhs.x;
        y -= rhs.y;
        return *this;
    }
    complex& operator *= (const complex& rhs)
    {
        *this = complex(x*rhs.x-y*rhs.y, x*rhs.y+y*rhs.x);
        return *this;
    }
    complex& operator /= (const float_t& rhs)
    {
        x /= rhs;
        y /= rhs;
        return *this;
    }

    complex operator + (const complex& rhs) const
    {
        return complex(*this) += rhs;
    }
    complex operator - (const complex& rhs) const
    {
        return complex(*this) -= rhs;
    }
    complex operator * (const complex& rhs) const
    {
        return complex(*this) *= rhs;
    }
    complex operator ! () const
    {
        return complex(x, -y);
    }
};

int rev[FFT_MAXN];
complex roots[FFT_MAXN+1];

void dft(complex *a, int n, int sign = 1)
{
    static int init = 0;
    if (!init)
    {
        init = 1;
        rev[0] = 0;
        for (int i = 1; i < FFT_MAXN; ++ i)
            rev[i] = (rev[i>>1]>>1) | ((i&1)<<(LEVEL-1));
        roots[0] = roots[FFT_MAXN] = 1;
        for (int i = 1; i <= FFT_MAXN>>1; ++ i)
        {
            roots[i] = complex(cos(2*PI*i/FFT_MAXN), sin(2*PI*i/FFT_MAXN));
            roots[FFT_MAXN-i] = !roots[i];
        }
    }

    int d = 0;
    while (n<<d != FFT_MAXN) ++ d;
    for (int i = 0; i < n; ++ i)
        if (i < (rev[i]>>d)) swap(a[i], a[rev[i]>>d]);
    for (int l = 2; l <= n; l <<= 1)
    {
        int delta = FFT_MAXN/l*sign;
        for (int i = 0; i < n; i += l)
        {
            complex *x = a+i, *y = a+i+(l>>1), *w = sign == 1 ? roots : roots+FFT_MAXN;
            for (int k = 0; k < (l>>1); ++ k)
            {
                complex tmp = *y * *w;
                *y = *x-tmp;
                *x += tmp;
                ++ x;
                ++ y;
                w += delta;
            }
        }
    }

    if (sign != 1)
    {
        for (int i = 0; i < n; ++ i)
            a[i] /= n;
    }
}

using word_t = u32;
using dword_t = u64;

void convolve(word_t *a, int n1, const word_t *b, int n2, word_t mod)
{
    static complex f[FFT_MAXN], g[FFT_MAXN], p[FFT_MAXN], q[FFT_MAXN];
    int n = n1+n2-1;
    while (n != (n&-n)) n += n&-n;
    for (int i = 0; i < n1; ++ i)
        f[i] = complex(a[i]>>15, a[i]&32767);
    for (int i = n1; i < n; ++ i)
        f[i] = 0;
    for (int i = 0; i < n2; ++ i)
        g[i] = complex(b[i]>>15, b[i]&32767);
    for (int i = n2; i < n; ++ i)
        g[i] = 0;
    dft(f, n, 1);
    dft(g, n, 1);
    for (int i = 0; i < n; ++ i)
    {
        int j = i ? n-i : 0;
        p[i] = ( (f[i]+!f[j])*(!g[j]-g[i]) + (!f[j]-f[i])*(g[i]+!g[j]) )* complex(0, 0.25);
        q[i] = (!f[j]-f[i])*(!g[j]-g[i])*complex(-0.25, 0) + complex(0, 0.25)*(f[i]+!f[j])*(g[i]+!g[j]);
    }
    dft(p, n, -1);
    dft(q, n, -1);
    for (int i = 0; i < n; ++ i)
    {
        a[i]=( (dword_t(p[i].x+0.1)%mod<<15) + dword_t(q[i].x+0.1) + (dword_t(q[i].y+0.1)%mod<<30) )%mod;
    }
}

}

namespace ntt
{

template<class mod_t>
void polynomial_inverse(const mod_t *a, mod_t *b, int n)
{
    if (n == 1)
    {
        b[0] = a[0].inverse();
        return;
    }
    polynomial_inverse(a, b, (n+1)/2);
    int m = 1;
    for (; m < n*2-1; m <<= 1);

    static mod_t c[1<<mod_t::level];
    if (mod_t::isntt())
    {
        for (int i = 0; i < n; ++ i)
            c[i] = a[i];
        for (int i = n; i < m; ++ i)
            c[i] = 0;
        for (int i = (n+1)/2; i < m; ++ i)
            b[i] = 0;
        mod_t *roots = get_roots<mod_t>();
        ntt_dit4(c, m, 1, roots);
        ntt_dit4(b, m, 1, roots);
        for (int i = 0; i < m; ++ i)
            b[i] = b[i]*(mod_t(2)-c[i]*b[i]);
        ntt_dit4(b, m, -1, roots);
        mod_t inv = mod_t(m).inverse();
        for (int i = 0; i < n; ++ i)
            b[i] *= inv;
        for (int i = n; i < m; ++ i)
            b[i] = 0;

        /*
        static mod_t a0[1<<mod_t::level];
        for (int i = (n+1)/2; i < n; ++ i)
            b[i] = 0;
        for (int i = 0; i < n; ++ i)
        {
            c[i] = b[i];
            a0[i] = a[i];
        }
        ntt::convolve(c, (n+1)/2, c, (n+1)/2);
        ntt::convolve(c, n, a0, n);
        for (int i = 0; i < n; ++ i)
            b[i] = mod_t(2)*b[i]-c[i];
        */
    }
    else
    {
        int mod = mod_t::modulus();
        for (int i = (n+1)/2; i < n; ++ i)
            b[i] = 0;
        for (int i = 0; i < n; ++ i)
            c[i] = b[i];
        fft::convolve((fft::word_t*)c, (n+1)/2, (fft::word_t*)c, (n+1)/2, mod);
        fft::convolve((fft::word_t*)c, n, (fft::word_t*)a, n, mod);
        for (int i = 0; i < n; ++ i)
            b[i] = mod_t(2)*b[i]-c[i];
    }
}

}

template<class mod_t>
class polynomial
{
public:
    static constexpr int LIMIT = 1<<16;

    vector<mod_t> v;
    polynomial (int len = 0) : v(len) {}
    polynomial (const vector<mod_t> &v) : v(v) {}
    void set_degree(int d)
    {
        resize(d+1);
    }
    void resize(int d)
    {
        int n = this->size();
        v.resize(d);
        for (int i = n; i < d; ++ i)
            v[i] = 0;
    }

    int size() const
    {
        return v.size();
    }

    mod_t& operator [] (int index)
    {
        return v[index];
    }
    mod_t operator [] (int index) const
    {
        return v[index];
    }

    polynomial& operator -= (const polynomial &rhs)
    {
        if (this->size() < rhs.size())
            this->resize(rhs.size());
        for (int i = 0; i < rhs.size(); ++ i)
            v[i] -= rhs[i];
        for (; !v.empty() && v.back() == 0; v.pop_back());
        if (v.empty()) v.push_back(0);
        return *this;
    }
    polynomial operator - (const polynomial &rhs) const
    {
        return polynomial(*this) -= rhs;
    }
    polynomial& operator *= (const polynomial &rhs)
    {
        int n1 = this->size();
        int n2 = rhs.size();
        int n = n1+n2-1;
        while (n != (n&-n)) n += n&-n;
        this->resize(n);
        if (mod_t::isntt())
        {
            static mod_t tmp[LIMIT];
            for (int i = 0; i < n2; ++ i)
                tmp[i] = rhs[i];
            ntt::convolve(v.data(), n1, tmp, n2);
        }
        else
        {
            int mod = mod_t::modulus();
            fft::convolve((fft::word_t*)v.data(), n1, (fft::word_t*)rhs.v.data(), n2, mod);
        }
        this->resize(n1+n2-1);
        return *this;
    }
    polynomial operator * (const polynomial &rhs) const
    {
        return polynomial(*this) *= rhs;
    }
    polynomial reverse() const
    {
        return vector<mod_t>(v.rbegin(), v.rend());
    }
    polynomial inverse() const
    {
        static mod_t ret[LIMIT];
        ntt::polynomial_inverse(v.data(), ret, v.size());
        return vector<mod_t>(ret, ret+v.size());
    }
    polynomial operator / (const polynomial &rhs) const
    {
        int n = this->size();
        int m = rhs.size();
        if (n < m) return vector<mod_t>(1, 0);
        polynomial ar = this->reverse();
        polynomial br = rhs.reverse().inverse();
        ar *= br;
        ar.resize(n-m+1);
        return ar.reverse();
    }
    pair<polynomial, polynomial> divmod(const polynomial &rhs) const
    {
        int n = this->size();
        int m = rhs.size();
        if (n < m) return pair<polynomial, polynomial>(vector<mod_t>(1, 0), *this);
        polynomial q = *this/rhs;
        polynomial r = *this-rhs*q;
        return pair<polynomial, polynomial>(q, r);
    }
    polynomial operator % (const polynomial &rhs) const
    {
        int n = this->size();
        int m = rhs.size();
        if (n < m) return *this;
        return this->divmod(rhs).second;
    }
    polynomial& operator %= (const polynomial &rhs)
    {
        *this = *this%rhs;
        return *this;
    }
    
    polynomial& operator <<= (int k)
    {
        int n = this->size();
        v.resize(n+k);
        for (int i = n-1; i >= 0; -- i)
            v[i+k] = v[i];
        for (int i = 0; i < k; ++ i)
            v[i] = 0;
        return *this;
    }
    polynomial operator << (int k)
    {
        return polynomial(*this) <<= k;
    }

    friend void get_polys(const mod_t *x, int k, int L, int R, polynomial *poly)
    {
        if (L == R)
        {
            poly[k] = vector<mod_t>{-x[L], 1};
            return;
        }
        int m = (L+R)/2;
        get_polys(x, k<<1, L, m, poly);
        get_polys(x, k<<1|1, m+1, R, poly);
        poly[k] = poly[k<<1]*poly[k<<1|1];
    }

    void get_values(polynomial *poly, int k, int L, int R, vector<mod_t> &y)
    {
        if (L == R)
        {
            y[L] = this->v[0];
            return;
        }
        int m = (L+R)/2;
        (*this%poly[k<<1]).get_values(poly, k<<1, L, m, y);
        (*this%poly[k<<1|1]).get_values(poly, k<<1|1, m+1, R, y);
    }
    
    void get_values(polynomial *poly, int k, int L, int R, vector<mod_t> &y, const vector<mod_t> &x)
    {
        int n = this->size();
        if (n <= 200)
        {
            for (int i = L; i <= R; ++ i)
                y[i] = this->get_value(x[i]);
            return;
        }
        int m = (L+R)/2;
        (*this%poly[k<<1]).get_values(poly, k<<1, L, m, y, x);
        (*this%poly[k<<1|1]).get_values(poly, k<<1|1, m+1, R, y, x);
    }
    
    mod_t get_value(mod_t x)
    {
        int n = this->size();
        mod_t ret = 0;
        for (int i = n-1; i >= 0; -- i)
            (ret *= x) += v[i];
        return ret;
    }

    void get_values(const vector<mod_t> &x, vector<mod_t> &y)
    {
        if (x.empty()) return;
        static polynomial poly[LIMIT];
        int n = x.size();
        get_polys(x.data(), 1, 0, n-1, poly);
        (*this%poly[1]).get_values(poly, 1, 0, n-1, y, x);
    }
    
    void print() const
    {
        for (auto x : v)
            printf("%d ", x.get());
        puts("");
    }
};

using mint = ntt::Mod<MOD, 1>;
using poly = polynomial<mint>;

polynomial<mint> f;

int n, k;
int a[MAXN], b[MAXN];

poly calc(int L, int R)
{
	if (L == R)
	{
		poly ret;
		ret.set_degree(1);
		ret[1] = 1;
		ret[0] = a[L];
		return ret;
	}
	int m = (L+R)>>1;
	return calc(L, m)*calc(m+1, R);
}

void calc()
{
	poly ret = calc(1, n);
	printf("%d\n", ret[n-k].get());
}

void solve()
{
	n = inp();
	k = inp();
	for (int i = 1; i <= n; ++ i)
	{
		b[i] = inp();
	}
	int T = inp();
	while (T --)
	{
		int t = inp();
		if (t == 1)
		{
			int q = inp();
			int x = inp();
			int d = inp();
			for (int i = 1; i <= n; ++ i)
				a[i] = b[i];
			a[x] = d;
			for (int i = 1; i <= n; ++ i)
				a[i] %= MOD;
			for (int i = 1; i <= n; ++ i)
				a[i] = (q-a[i]+MOD)%MOD;
			calc();
		}
		else
		{
			int q = inp();
			int L = inp();
			int R = inp();
			int d = inp();
			for (int i = 1; i <= n; ++ i)
				a[i] = b[i];
			for (int i = L; i <= R; ++ i)
				a[i] += d;
			for (int i = 1; i <= n; ++ i)
				a[i] %= MOD;
			for (int i = 1; i <= n; ++ i)
				a[i] = (q-a[i]+MOD)%MOD;
			calc();
		}
	}
}

int main()
{
	
	//for (int T = inp(); T --; )
		solve();
	
	return 0;
}