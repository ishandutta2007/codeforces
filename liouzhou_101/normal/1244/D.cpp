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
//const int MAXM = 4010;
const int MAXK = 18;
//const int INF = 1000000000;
const i64 INF = 2000000000000000000LL;
const int MOD = 1000000007;
const int INV2 = (MOD+1)/2;
//const int INV6 = power(6, MOD-2, MOD);

using namespace io;

//mt19937 rd(chrono::steady_clock::now().time_since_epoch().count());

#define rep(i,a,b) for (int i = (a), I = (b); i <= I; ++ i)

int n;
int w[MAXN][4];
vector<int> v[MAXN];
ll F[MAXN][4][4];
int to[MAXN];
int go[MAXN][4][4];
ll ans[MAXN];

void dfs(int x, int p)
{
	int y = 0;
	for (auto z : v[x])
	{
		if (z == p) continue;
		y = z;
		dfs(z, x);
	}
	to[x] = y;
	for (int a = 0; a <= 3; ++ a)
		for (int b = 0; b <= 3; ++ b)
			F[x][a][b] = INF;
	if (y == 0)
	{
		for (int a = 1; a <= 3; ++ a)
			F[x][a][0] = w[x][a];
	}
	else
	{
		for (int a = 1; a <= 3; ++ a)
			for (int b = 1; b <= 3; ++ b) if (a != b)
				for (int c = 0; c <= 3; ++ c) if (c != a && c != b)
				{
					freshmin(F[x][a][b], F[y][b][c]+w[x][a]);
					if (F[x][a][b] == F[y][b][c]+w[x][a])
						go[x][a][b] = c;
				}
	}
}

void solve()
{
	
	n = inp();
	for (int c = 1; c <= 3; ++ c)
		for (int i = 1; i <= n; ++ i)
			w[i][c] = inp();
	
	for (int i = 1; i < n; ++ i)
	{
		int x = inp(), y = inp();
		v[x].push_back(y);
		v[y].push_back(x);
	}
	
	for (int i = 1; i <= n; ++ i)
	{
		if (v[i].size() >= 3)
		{
			puts("-1");
			return;
		}
	}
	
	int root = 0;
	for (int i = 1; i <= n; ++ i)
		if (v[i].size() == 1)
		{
			root = i;
			break;
		}
	dfs(root, 0);
	ll ret = INF;
	for (int a = 0; a <= 3; ++ a)
		for (int b = 0; b <= 3; ++ b)
			freshmin(ret, F[root][a][b]);
	writeln(ret);
	for (int a = 0; a <= 3; ++ a)
		for (int b = 0; b <= 3; ++ b)
			if (ret == F[root][a][b])
			{
				int cur = root;
				for (int i = 1; i <= n; ++ i)
				{
					ans[cur] = a;
					int c = go[cur][a][b];
					a = b;
					b = c;
					cur = to[cur];
				}
				
				for (int i = 1; i <= n; ++ i)
				{
					write(ans[i], ' ');
				}
				
				return;
			}
}

int main()
{
	
	//for (int T = inp(); T --; )
		solve();
	
	return 0;
}