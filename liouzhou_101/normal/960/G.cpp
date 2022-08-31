//#pragma GCC optimize("Ofast,unroll-loops,no-stack-protector,fast-math")
//#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")
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

namespace io{
    const int L = (1 << 20) + 1;

    char buf[L], *S , *T, c;

    char getchar() {
        if(__builtin_expect(S == T, 0)) {
            T = (S = buf) + fread(buf, 1, L, stdin);
            return (S == T ? EOF : *S++);
        }
        return *S++;
    }

    int inp() {
        int x = 0, f = 1; char ch;
        for(ch = getchar(); !isdigit(ch); ch = getchar())
            if(ch == '-') f = -1;
        for(; isdigit(ch); x = x * 10 + ch - '0', ch = getchar());
        return x * f;
    }

    unsigned inpu()
    {
        unsigned x = 0; char ch;
        for(ch = getchar(); !isdigit(ch); ch = getchar());
        for(; isdigit(ch); x = x * 10 + ch - '0', ch = getchar());
        return x;
    }

    ll inp_ll() {
        ll x = 0; int f = 1; char ch;
        for(ch = getchar(); !isdigit(ch); ch = getchar())
            if(ch == '-') f = -1;
        for(; isdigit(ch); x = x * 10 + ch - '0', ch = getchar());
        return x * f;
    }

    char B[25], *outs=B+20, *outr=B+20;
    template<class T>
    inline void print(register T a,register char x=0){
        if(x) *--outs = x, x = 0;

        if(!a)*--outs = '0';
        else
            while(a)
                *--outs = (a % 10) + 48, a /= 10;

        if(x)
            *--outs = x;

        fwrite(outs, outr - outs , 1, stdout);
        outs = outr;
    }
};

using io :: print;
using io :: inp;
using io :: inpu;
using io :: inp_ll;

using i32 = int;
using i64 = long long;
using u8 = unsigned char;
using u32 = unsigned;
using u64 = unsigned long long;
using f64 = double;
using f80 = long double;

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

namespace ntt
{

using word_t = u32;
using dword_t = u64;

template<word_t mod, word_t root>
class Mod
{
public:
    //static constexpr int level = __builtin_ctzll(mod-1);
    static constexpr int level = 17;
    static constexpr int all = (1<<level)-1;

    word_t x;

    Mod () {}
    Mod (word_t n) : x(n) {}

    static word_t modulus()
    {
        return mod;
    }

    static Mod omega()
    {
        return Mod(root).pow((mod - 1) >> level);
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
void convolve(mod_t* A, int s1, mod_t* B, int s2, bool cyclic = false)
{
    int s = (cyclic ? max(s1, s2) : s1 + s2 - 1);
    int size = 1;
    while (size < s) size <<= 1;

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


}

namespace fft
{

using float_t = f64;

constexpr int LEVEL = 17;
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

void convolve(word_t *a, int n1, word_t *b, int n2, word_t mod)
{
    static complex f[FFT_MAXN], g[FFT_MAXN], p[FFT_MAXN], q[FFT_MAXN];
    int n = n1+n2-1;
    if (n < 48)
    {
        static word_t c[48];
        for (int i = 0; i < n; ++ i)
        {
            c[i] = a[i];
            a[i] = 0;
        }
        for (int i = 0; i < n1; ++ i)
            for (int j = 0; j < n2; ++ j)
                a[i+j] = (a[i+j]+dword_t(c[i])*b[j])%mod;
        return;
    }
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

const int MAXN = 1<<17;
const int MOD = 998244353;
const int G = 3;
const f80 MI = f80(1)/MOD;
const int INF = 100001;

typedef ntt::Mod<MOD, G> mint;
//typedef ntt::Mod<138412033, 5> mint;

mint fact[MAXN], rfact[MAXN];

void init(int n)
{
    fact[0] = 1;
    for (int i = 1; i <= n; ++ i)
        fact[i] = fact[i-1]*i;
    rfact[n] = fact[n].inverse();
    for (int i = n-1; i >= 0; -- i)
        rfact[i] = rfact[i+1]*(i+1);
}

void stirling(mint *s, int n)
{
    if (n == 1)
    {
        s[0] = 0;
        s[1] = 1;
        return;
    }
    int m = n>>1;
    stirling(s, m);

    static mint a[MAXN], b[MAXN];

    // a[i] = m^i / i!
    // b[i] = (m-i)! * s[m-i]
    mint tmp = 1;
    for (int i = 0; i <= m; ++ i, tmp *= m)
    {
        a[m-i] = s[i]*fact[i];
        b[i] = rfact[i]*tmp;
    }
    fft::convolve((u32*)a, m+1, (u32*)b, m+1, MOD);

    for (int i = 0; i <= m; ++ i)
        b[i] = a[m-i]*rfact[i];
    fft::convolve((u32*)s, m+1, (u32*)b, m+1, MOD);
    if (n&1)
    {
        s[n] = 0;
        for (int i = n; i >= 1; -- i)
            s[i] = s[i]*(n-1)+s[i-1];
    }
}

mint stirling_first_type(int n, int k)
{
    if (n == 0) return k == 0;
    if (n <= 1) return k;
    static mint s[MAXN];
    stirling(s, n);
    return s[k];
}

mint binomial(int n, int m)
{
    return fact[n]*rfact[m]*rfact[n-m];
}

int main()
{

    int N, A, B;
    cin >> N >> A >> B;
    if (A < 1 || B < 1 || A+B > N+1)
    {
        puts("0");
        return 0;
    }
    init(N-1);
    mint ans = mint(stirling_first_type(N-1, A+B-2))*mint(binomial(A+B-2, A-1));
    cout << ans << endl;

    return 0;
}