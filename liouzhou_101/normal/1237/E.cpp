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

//const int MAXN = 1<<20|10;
//const int MAXM = 4010;
const int MAXK = 20;
//const int INF = 1000000000;
const i64 INF = 2000000000000000000LL;
const int MOD = 1000000007;
const int INV2 = (MOD+1)/2;
//const int INV6 = power(6, MOD-2, MOD);

using namespace io;

//mt19937 rd(chrono::steady_clock::now().time_since_epoch().count());

#define rep(i,a,b) for (int i = (a), I = (b); i <= I; ++ i)

typedef long long LL;

struct comp{ 
	double r, i;
	comp() { }	
	comp(double a, double b) : r(a), i(b) { }
};
const int N = (1 << 20), MAXN = (N << 1) + 10;
const int K = 32767, L = 15;
int P; 
comp add(comp a, comp b) { return comp(a.r + b.r, a.i + b.i); }
comp sub(comp a, comp b) { return comp(a.r - b.r, a.i - b.i); }
comp mul(comp a, comp b) { return comp(a.r * b.r - a.i * b.i, a.r * b.i + a.i * b.r);}
comp div(comp a, double b){	return comp(a.r/b, a.i/b); }
comp conj(comp x) { return comp(x.r, -x.i); }
int add(int x, int y) { return x + y >= P ? x + y - P : x + y; }
int sub(int x, int y) {	return x - y < 0 ? x - y + P : x - y;  }
int mul(int x, int y) {	return (LL)x * y % P; }
int fexp(int x, LL n) {
	int res = 1;
	for(n = (n % (P - 1) + P - 1) % (P - 1); n; n >>= 1, x = mul(x, x)) 
		if(n & 1) res = mul(res, x);
	return res;
}
	
comp eps[MAXN]; 
void init() {
	double pi = acos(-1);
	for(int i = 0; i < N; i++)
		eps[i] = comp(cos(2 * pi * i /N), sin(2 * pi * i /N));
}

inline void trans(int n, comp x[], comp w[]) {
    for (int i = 0, j = 0; i != n; i++) {
        if (i < j) std::swap(x[i], x[j]);
        for (int l = n >> 1; (j ^= l) < l; l >>= 1);
    }
    for (int i = 2; i <= n; i <<= 1) {
        int l = i >> 1, d = N / i;
        for (int j = 0; j != n; j += i)
            for (int k = 0; k != l; k++) {
                comp t = mul(x[j + k + l], w[d * k]);
                x[j + k + l] = sub(x[j + k], t);
                x[j + k] = add(x[j + k], t);
            }
    }
}

inline void dft(int n, comp x[]) {
    trans(n, x, eps);
}
inline void idft(int n, comp x[]) {
    trans(n, x, eps);
    reverse(x + 1, x + n);
    for (int i = 0; i < n; i++) x[i] = div(x[i], n);
}
void conv(int na, int a[], int nb, int b[], int nc, int c[]) {
    int n, i;
    static comp x[MAXN], y[MAXN], z[MAXN], w[MAXN];
    for(n = 1; n < na + nb - 1; n <<= 1);
    for(i = 0; i < n; i++){
    	x[i] = i < na ? comp(a[i] & K, a[i] >> L): comp(0, 0);
    	y[i] = i < nb ? comp(b[i] & K, b[i] >> L): comp(0, 0);    	
	}
	dft(n, x); dft(n, y);
    comp r0(0.5, 0), r1(0, -0.5), r(0, 1);
	for(i = 0; i < n; i++){
		int j = (n - i) & (n - 1);
		comp x0, x1, y0, y1;
		x0 = mul(add(x[i], conj(x[j])), r0);
		x1 = mul(sub(x[i], conj(x[j])), r1);
		y0 = mul(add(y[i], conj(y[j])), r0);
		y1 = mul(sub(y[i], conj(y[j])), r1);
		z[i] = mul(x0, add(y0, mul(y1, r)));
		w[i] = mul(x1, add(y0, mul(y1, r)));
 	}
 	idft(n, z);
	idft(n, w); 
    for(i = 0; i < nc; i++) {
        int c00 = (LL)(z[i].r + 0.5) % P, c01 = (LL)(z[i].i + 0.5) % P;
        int c10 = (LL)(w[i].r + 0.5) % P, c11 = (LL)(w[i].i + 0.5) % P;
        c[i] = ((((LL)c11 << L) + c01 + c10 << L) + c00) % P;
    }
}

int ans[MAXN];
int f[2][MAXN], g[2][MAXN];

void calc()
{
	P = 998244353;
	
	init();
	// k = 1
	f[0][0] = 0, f[0][1] = 1, f[0][2] = 0;
	f[1][0] = 1, f[1][1] = 0, f[1][2] = 0;
	
	ans[1] = 1;
	ans[2] = 1;
	ans[3] = 0;
	
	int cur = 3;
	
	for (int k = 1; ; ++ k)
	{
		int m = 1<<k;
		conv(m+1, f[1], m+1, f[0], 2*m+1, g[0]);
		conv(m+1, f[0], m+1, f[0], 2*m+1, g[1]);
		
		for (int i = 1; i <= m+m; ++ i)
			if (cur+i <= 1000000) ans[cur+i] = (g[0][i]+g[1][i])%P;
			
		for (int i = 0; i <= 2*m; ++ i)
		{
		    f[0][i] = g[0][i];
		    f[1][i] = g[1][i];
		}
		
		cur += m+m;
		if (cur >= 1000000) break;
	}
}

void solve()
{
	calc();
	//for (int i = 1000; i <= 1100; ++ i) printf("%d ", ans[i]);
	int n = inp();
	writeln(ans[n]);
}

int main()
{
	
	//for (int T = inp(); T --; )
		solve();
	
	return 0;
}