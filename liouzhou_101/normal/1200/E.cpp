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

const int MAXN = 1111111;
const i64 INF = 100000000000000LL;
const int MOD = 998244353;
const int INV2 = (MOD+1)/2;

const i64 A[3] = {31, 37, 41};
const i64 P[3] = {1000000007, 1000000009, 998244353};

using namespace io;

i64 PA[MAXN][3];

int len;
char t[MAXN];
i64 G[MAXN][3];

int main()
{
	
	PA[0][0] = PA[0][1] = PA[0][2] = 1;
	for (int i = 1; i <= 1000000; ++ i)
	{
		for (int k = 0; k < 3; ++ k)
		{
			PA[i][k] = PA[i-1][k]*A[k]%P[k];
		}
	}
	
	int T;
	scanf("%d", &T);
	len = 0;
	while (T --)
	{
		static char s[MAXN];
		scanf("%s", s+1);
		int n = strlen(s+1);
		
		static i64 F[MAXN][3];
		for (int i = 1; i <= n; ++ i)
		{
			for (int k = 0; k < 3; ++ k)
			{
				F[i][k] = (F[i-1][k]*A[k]+s[i])%P[k];
			}
		}
		
		int flag = 0;
		for (int i = min(n, len); i >= 1; -- i)
		{
			// t[len-i+1 .. len] == s[1 .. i]
			int eq = 1;
			for (int k = 0; k < 3; ++ k)
			{
				i64 ht = (G[len][k]+P[k]-G[len-i][k]*PA[i][k]%P[k])%P[k];
				i64 hs = F[i][k];
				if (ht != hs)
				{
					eq = 0;
					break;
				}
			}
			if (eq)
			{
				flag = i;
				break;
			}
		}
		
		for (int j = flag+1; j <= n; ++ j)
		{
			t[++ len] = s[j];
			for (int k = 0; k < 3; ++ k)
			{
				G[len][k] = (G[len-1][k]*A[k]+t[len])%P[k];
			}
		}
	}
	
	puts(t+1);
	
	return 0;
}