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

const int MAXN = 1000010;
const int MAXK = 4;
const int INF = 2000000000;
//const i64 INF = 2000000000000000000LL;
//const int MOD = 1000000007;
//const int INV2 = (MOD+1)/2;
//const int INV6 = power(6, MOD-2, MOD);

using namespace io;

//mt19937 rd(chrono::steady_clock::now().time_since_epoch().count());

int n;
struct node
{
	int x, y, c;
}e[MAXN];

vector<pii> v[MAXN];

pll a[MAXN*4];
ll tag[MAXN*4];

void clear(int k)
{
	a[k<<1].X += tag[k];
	tag[k<<1] += tag[k];
	a[k<<1|1].X += tag[k];
	tag[k<<1|1] += tag[k];
	tag[k] = 0;
}

void update(int k)
{
	a[k] = max(a[k<<1], a[k<<1|1]);
}

void build(int k, int L, int R)
{
	if (L == R)
	{
		a[k] = {0, L};
		return;
	}
	int m = (L+R)/2;
	build(k<<1, L, m);
	build(k<<1|1, m+1, R);
	update(k);
}

void add(int k, int L, int R, int x, int y, int p)
{
	if (L == x && R == y)
	{
		tag[k] += p;
		a[k].X += p;
		return;
	}
	clear(k);
	int m = (L+R)/2;
	if (y <= m)
		add(k<<1, L, m, x, y, p);
	else if (x > m)
		add(k<<1|1, m+1, R, x, y, p);
	else
	{
		add(k<<1, L, m, x, m, p);
		add(k<<1|1, m+1, R, m+1, y, p);
	}
	update(k);
}

pll get(int k, int L, int R, int x, int y)
{
	if (L == x && R == y) return a[k];
	clear(k);
	int m = (L+R)/2;
	if (y <= m)
		return get(k<<1, L, m, x, y);
	if (x > m)
		return get(k<<1|1, m+1, R, x, y);
	return max(get(k<<1, L, m, x, m), get(k<<1|1, m+1, R, m+1, y));
}

void solve()
{
	int n = inp();
	vector<int> p;
	for (int i = 1; i <= n; ++ i)
	{
		int x, y, c;
		x = inp();
		y = inp();
		if (x > y) swap(x, y);
		p.push_back(x);
		p.push_back(y);
		c = inp();
		e[i] = {x, y, c};
	}
	sort(p.begin(), p.end());
	p.erase(unique(p.begin(), p.end()), p.end());
	int m = p.size();
	for (int i = 1; i <= n; ++ i)
	{
		e[i].x = lower_bound(p.begin(), p.end(), e[i].x)-p.begin()+1;
		e[i].y = lower_bound(p.begin(), p.end(), e[i].y)-p.begin()+1;
		v[e[i].x].push_back({e[i].y, e[i].c});
	}
	pair<ll, pii> ans(0, pii(INF, INF));
	build(1, 1, m);
	for (int i = 1; i <= m; ++ i)
		add(1, 1, m, i, i, -p[i-1]);
	for (int x = m; x >= 1; -- x)
	{
		for (auto z : v[x])
		{
			int y = z.X, c = z.Y;
			add(1, 1, m, y, m, c);
		}
		pll ret = get(1, 1, m, x, m);
		freshmax(ans, pair<ll,pii>{ret.X+p[x-1], pii(p[x-1], p[ret.Y-1])});
	}
	printf("%lld\n%d %d %d %d\n", ans.X, ans.Y.X, ans.Y.X, ans.Y.Y, ans.Y.Y);
}

int main()
{
	
	//for (int T = inp(); T --; )
		solve();
	
	return 0;
}