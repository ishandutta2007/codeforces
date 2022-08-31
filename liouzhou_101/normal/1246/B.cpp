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
//const int MAXM = 4010;
const int MAXK = 20;
const int INF = 1000000000;
//const i64 INF = 2000000000000000000LL;
//const int MOD = 998244353;
//const int INV2 = (MOD+1)/2;
//const int INV6 = power(6, MOD-2, MOD);

using namespace io;

//mt19937 rd(chrono::steady_clock::now().time_since_epoch().count());

#define rep(i,a,b) for (int i = (a), I = (b); i <= I; ++ i)

int dx[] = {0, 1, 0, -1};
int dy[] = {1, 0, -1, 0};

int n, m;
int a[MAXN], c[MAXN];

int b[MAXN];
int tot, p[MAXN];

void init(int MAXP)
{
	for (int i = 2; i <= MAXP; ++ i)
	{
		if (!b[i])
		{
			p[++ tot] = i;
			b[i] = i;
		}
		for (int j = 1, t; (t = i*p[j]) <= MAXP; ++ j)
		{
			b[t] = b[i];
			if (i%p[j] == 0) break;
		}
	}
}

int f[MAXN];

void solve()
{
	//init(100000);
	n = inp();
	int k = inp();
	for (int i = 1; i <= n; ++ i)
	{
		a[i] = inp();
		c[a[i]] ++;
	}
	
	ll ans = 0;
	
	if (k == 2)
	{
		/*
		ll tmp = 0;
		for (int i = 1; i <= n; ++ i)
			for (int j = i+1; j <= n; ++ j)
			{
				ll x = a[i]*a[j];
				ll y = sqrt(x);
				if ((y+1)*(y+1) <= x) ++ y;
				if (y*y == x) ++ tmp;
			}
		cout << tmp << endl;
		*/
		for (int i = 1; i <= 100000; ++ i)
		{
			f[i] = 0;
			for (int j = 1; (ll)i*j*j <= 100000; ++ j)
				f[i] += c[i*j*j];
		}
		for (int i = 1; i <= 100000; ++ i)
		{
			int tmp = i;
			int cur = 1;
			for (int j = 2; j*j <= tmp; ++ j)
			{
				if (tmp%j == 0)
				{
					int cnt = 0;
					while (tmp%j == 0)
					{
						tmp /= j;
						cnt ++;
					}
					if (cnt&1) cur *= j;
				}
			}
			if (tmp > 1) cur *= tmp;
			ans += (ll)c[i]*f[cur];
		}
		ans -= n;
		ans /= 2;
		writeln(ans);
		return;
	}
	
	for (int i = 1; i <= 100000; ++ i)
	{
		ll cur = 1;
		for (int j = 1; j <= k; ++ j)
		{
			cur *= i;
			if (cur > 10000000000LL) break;
		}
		if (cur > 10000000000LL) continue;
		//v.push_back(cur);
		//ans += calc(cur);
		for (int j = max<ll>(cur/100000, 1); j <= 100000; ++ j) if (c[j])
		{
			if (cur%j == 0)
			{
				if ((ll)j*j == cur) ans += (ll)c[j]*(c[j]-1);
				else ans += (ll)c[j]*c[cur/j];
			}
		}
	}
	ans /= 2;
	
	writeln(ans);
}

int main()
{
	
	//for (int T = inp(); T --; )
		solve();
	
	return 0;
}