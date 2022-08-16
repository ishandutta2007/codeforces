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

const int MAXN = 2222;
const i64 INF = 100000000000000LL;
const int MOD = 998244353;
const int INV2 = (MOD+1)/2;

//using namespace io;

int n, k;
char s[MAXN][MAXN];
int f[MAXN][MAXN], L[MAXN][MAXN], R[MAXN][MAXN], U[MAXN][MAXN], D[MAXN][MAXN];
int a[MAXN], b[MAXN];

int main()
{
	
	scanf("%d%d", &n, &k);
	for (int i = 1; i <= n; ++ i)
		scanf("%s", s[i]+1);
	
	for (int i = 1; i <= n; ++ i)
	{
		L[i][0] = 1;
		for (int j = 1; j <= n; ++ j)
			L[i][j] = L[i][j-1] && s[i][j] == 'W';
		R[i][n+1] = 1;
		for (int j = n; j >= 1; -- j)
			R[i][j] = R[i][j+1] && s[i][j] == 'W';
	}
	
	for (int j = 1; j <= n; ++ j)
	{
		U[0][j] = 1;
		for (int i = 1; i <= n; ++ i)
			U[i][j] = U[i-1][j] && s[i][j] == 'W';
		D[n+1][j] = 1;
		for (int i = n; i >= 1; -- i)
			D[i][j] = D[i+1][j] && s[i][j] == 'W';
	}
	
	for (int i = 1; i <= n-k+1; ++ i)
	{
		for (int j = 1; j <= n; ++ j)
		{
			a[j] = a[j-1]+U[i-1][j]*D[i+k][j];
			b[j] = b[j-1]+U[n][j];
		}
		for (int j = 1; j <= n-k+1; ++ j)
			f[i][j] += a[j+k-1]-a[j-1] + b[j-1] + b[n]-b[j+k-1];
	}
	
	for (int j = 1; j <= n-k+1; ++ j)
	{
		for (int i = 1; i <= n; ++ i)
		{
			a[i] = a[i-1]+L[i][j-1]*R[i][j+k];
			b[i] = b[i-1]+L[i][n];
		}
		for (int i = 1; i <= n-k+1; ++ i)
			f[i][j] += a[i+k-1]-a[i-1] + b[i-1] + b[n]-b[i+k-1];
	}
	
	int ans = 0;
	for (int i = 1; i <= n-k+1; ++ i)
		for (int j = 1; j <= n-k+1; ++ j)
			freshmax(ans, f[i][j]);
	cout << ans << endl;
	
	return 0;
}