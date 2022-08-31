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
#include<ext/pb_ds/priority_queue.hpp>
using namespace __gnu_pbds;
//typedef tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update> rbtree;
//rbtree T;
template<class T>
using rbtree = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;
//rbtree<int> T;
//template<class T, class cmp = less<T>, class tag = pairing_heap_tag>
//using pqueue = __gnu_pbds::priority_queue<T, cmp, tag>;
template<class T, class cmp = less<T>>
using pqueue = __gnu_pbds::priority_queue<T, cmp>;
//pqueue<int> T;
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

//#define FWRITE

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
	{
		//if (ch == EOF) return -1;
		if(ch == '-') f = 1;
	}
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

const int MAXN = 500010;
//const int MAXM = 3000010;
const int MAXK = 20;
//const int INF = 1000000000;
const i64 INF = 2000000000000000000LL;
const int MOD = 998244353;
//const int INV2 = (MOD+1)/2;
//const int INV6 = power(6, MOD-2, MOD);

using namespace io;

//mt19937 rd(chrono::steady_clock::now().time_since_epoch().count());

#define rep(i,a,b) for (int i = (a), I = (b); i <= I; ++ i)

int dx[] = {0, 1, 0, -1};
int dy[] = {1, 0, -1, 0};

int F[MAXN];

int father(int x)
{
	return F[x] == x ? x : F[x] = father(F[x]);
}

struct mod_int {
    int val;
 
    mod_int(long long v = 0) {
        if (v < 0)
            v = v % MOD + MOD;
 
        if (v >= MOD)
            v %= MOD;
 
        val = v;
    }
 
    static int mod_inv(int a, int m = MOD) {
        // https://en.wikipedia.org/wiki/Extended_Euclidean_algorithm#Example
        int g = m, r = a, x = 0, y = 1;
 
        while (r != 0) {
            int q = g / r;
            g %= r; swap(g, r);
            x -= q * y; swap(x, y);
        }
 
        return x < 0 ? x + m : x;
    }
 
    explicit operator int() const {
        return val;
    }
 
    mod_int& operator+=(const mod_int &other) {
        val += other.val;
        if (val >= MOD) val -= MOD;
        return *this;
    }
 
    mod_int& operator-=(const mod_int &other) {
        val -= other.val;
        if (val < 0) val += MOD;
        return *this;
    }
 
    static unsigned fast_mod(uint64_t x, unsigned m = MOD) {
#if !defined(_WIN32) || defined(_WIN64)
        return x % m;
#endif
        // Optimized mod for Codeforces 32-bit machines.
        // x must be less than 2^32 * m for this to work, so that x / m fits in a 32-bit integer.
        unsigned x_high = x >> 32, x_low = (unsigned) x;
        unsigned quot, rem;
        asm("divl %4\n"
            : "=a" (quot), "=d" (rem)
            : "d" (x_high), "a" (x_low), "r" (m));
        return rem;
    }
 
    mod_int& operator*=(const mod_int &other) {
        val = fast_mod((uint64_t) val * other.val);
        return *this;
    }
 
    mod_int& operator/=(const mod_int &other) {
        return *this *= other.inv();
    }
 
    friend mod_int operator+(const mod_int &a, const mod_int &b) { return mod_int(a) += b; }
    friend mod_int operator-(const mod_int &a, const mod_int &b) { return mod_int(a) -= b; }
    friend mod_int operator*(const mod_int &a, const mod_int &b) { return mod_int(a) *= b; }
    friend mod_int operator/(const mod_int &a, const mod_int &b) { return mod_int(a) /= b; }
 
    mod_int& operator++() {
        val = val == MOD - 1 ? 0 : val + 1;
        return *this;
    }
 
    mod_int& operator--() {
        val = val == 0 ? MOD - 1 : val - 1;
        return *this;
    }
 
    mod_int operator++(int) { mod_int before = *this; ++*this; return before; }
    mod_int operator--(int) { mod_int before = *this; --*this; return before; }
 
    mod_int operator-() const {
        return val == 0 ? 0 : MOD - val;
    }
 
    bool operator==(const mod_int &other) const { return val == other.val; }
    bool operator!=(const mod_int &other) const { return val != other.val; }
 
    mod_int inv() const {
        return mod_inv(val);
    }
 
    mod_int pow(long long p) const {
        assert(p >= 0);
        mod_int a = *this, result = 1;
 
        while (p > 0) {
            if (p & 1)
                result *= a;
 
            a *= a;
            p >>= 1;
        }
 
        return result;
    }
 
    friend ostream& operator<<(ostream &stream, const mod_int &m) {
        return stream << m.val;
    }
};
 
namespace NTT {
    vector<mod_int> roots = {0, 1};
    vector<int> bit_reverse;
    int max_size = -1;
    mod_int root;
 
    bool is_power_of_two(int n) {
        return (n & (n - 1)) == 0;
    }
 
    int round_up_power_two(int n) {
        assert(n > 0);
 
        while (n & (n - 1))
            n = (n | (n - 1)) + 1;
 
        return n;
    }
 
    // Given n (a power of two), finds k such that n == 1 << k.
    int get_length(int n) {
        assert(is_power_of_two(n));
        return __builtin_ctz(n);
    }
 
    // Rearranges the indices to be sorted by lowest bit first, then second lowest, etc., rather than highest bit first.
    // This makes even-odd div-conquer much easier.
    void bit_reorder(int n, vector<mod_int> &values) {
        if ((int) bit_reverse.size() != n) {
            bit_reverse.assign(n, 0);
            int length = get_length(n);
 
            for (int i = 0; i < n; i++)
                bit_reverse[i] = (bit_reverse[i >> 1] >> 1) + ((i & 1) << (length - 1));
        }
 
        for (int i = 0; i < n; i++)
            if (i < bit_reverse[i])
                swap(values[i], values[bit_reverse[i]]);
    }
 
    void find_root() {
        int order = MOD - 1;
        max_size = 1;
 
        while (order % 2 == 0) {
            order /= 2;
            max_size *= 2;
        }
 
        root = 2;
 
        // Find a max_size-th primitive root of MOD.
        while (!(root.pow(max_size) == 1 && root.pow(max_size / 2) != 1))
            root++;
    }
 
    void prepare_roots(int n) {
        if (max_size < 0)
            find_root();
 
        assert(n <= max_size);
 
        if ((int) roots.size() >= n)
            return;
 
        int length = get_length(roots.size());
        roots.resize(n);
 
        // The roots array is set up such that for a given power of two n >= 2, roots[n / 2] through roots[n - 1] are
        // the first half of the n-th primitive roots of MOD.
        while (1 << length < n) {
            // z is a 2^(length + 1)-th primitive root of MOD.
            mod_int z = root.pow(max_size >> (length + 1));
 
            for (int i = 1 << (length - 1); i < 1 << length; i++) {
                roots[2 * i] = roots[i];
                roots[2 * i + 1] = roots[i] * z;
            }
 
            length++;
        }
    }
 
    void fft_iterative(int N, vector<mod_int> &values) {
        assert(is_power_of_two(N));
        prepare_roots(N);
        bit_reorder(N, values);
 
        for (int n = 1; n < N; n *= 2)
            for (int start = 0; start < N; start += 2 * n)
                for (int i = 0; i < n; i++) {
                    mod_int even = values[start + i];
                    mod_int odd = values[start + n + i] * roots[n + i];
                    values[start + n + i] = even - odd;
                    values[start + i] = even + odd;
                }
    }
 
    const int FFT_CUTOFF = 150;
 
    vector<mod_int> mod_multiply(vector<mod_int> left, vector<mod_int> right) {
        int n = left.size();
        int m = right.size();
 
        // Brute force when either n or m is small enough.
        if (min(n, m) < FFT_CUTOFF) {
            const uint64_t ULL_BOUND = numeric_limits<uint64_t>::max() - (uint64_t) MOD * MOD;
            vector<uint64_t> result(n + m - 1);
 
            for (int i = 0; i < n; i++)
                for (int j = 0; j < m; j++) {
                    result[i + j] += (uint64_t) ((int) left[i]) * ((int) right[j]);
 
                    if (result[i + j] > ULL_BOUND)
                        result[i + j] %= MOD;
                }
 
            for (uint64_t &x : result)
                if (x >= MOD)
                    x %= MOD;
 
            return vector<mod_int>(result.begin(), result.end());
        }
 
        int N = round_up_power_two(n + m - 1);
        left.resize(N);
        right.resize(N);
 
        bool equal = left == right;
        fft_iterative(N, left);
 
        if (equal)
            right = left;
        else
            fft_iterative(N, right);
 
        mod_int inv_N = mod_int(N).inv();
 
        for (int i = 0; i < N; i++)
            left[i] *= right[i] * inv_N;
 
        reverse(left.begin() + 1, left.end());
        fft_iterative(N, left);
        left.resize(n + m - 1);
        return left;
    }
 
    vector<mod_int> mod_power(const vector<mod_int> &v, int exponent) {
        assert(exponent >= 0);
        vector<mod_int> result = {1};
 
        if (exponent == 0)
            return result;
 
        for (int k = 31 - __builtin_clz(exponent); k >= 0; k--) {
            result = mod_multiply(result, result);
 
            if (exponent >> k & 1)
                result = mod_multiply(result, v);
        }
 
        return result;
    }
}

using mint = mod_int;
using poly = vector<mint>;

int n, k;
int a[MAXN], b[MAXN];

void solve()
{
	using namespace NTT;
	n = inp();
	k = inp();
	for (int i = 1; i <= n; ++ i)
		a[i] = inp();
	if (k == 1)
	{
		writeln(0);
		return;
	}
	int x = 0, y = 0;
	for (int i = 1; i <= n; ++ i)
	{
		int j = i+1;
		if (j > n) j = 1;
		if (a[i] == a[j]) x ++;
		else y ++;
	}
	poly p = {0, k};
	poly q = {1, k-2, 1};
	poly px = mod_power(p, x);
	poly qy = mod_power(q, y);
	poly f = mod_multiply(px, qy);
	mint ans = 0;
	/*
	for (int i = 0; i < f.size(); ++ i)
		write(int(f[i]), i == f.size()-1 ? '\n' : ' ');
	*/
	for (int i = n+1; i < f.size(); ++ i)
		//if (i+n-1 < f.size())
		{
			//writeln(int(f[i+n-1]));
			ans = ans+f[i];
		}
	writeln(int(ans));
}

int32_t main()
{
	
	//for (int T = inp(); T --; )
		solve();
	
	return 0;
}