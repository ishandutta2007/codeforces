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

struct edge_type
{
	int X, Y;
	ll Z;
	bool operator < (const edge_type &a) const
	{
		return Z < a.Z;
	}
};

struct undirected_graph
{
	int n;
	vector<edge_type> edge;
	undirected_graph (int n)
	{
		init(n);
	}
	void init(int n)
	{
		assert(n >= 0);
		this->n = n;
	}
	void addedge(int x, int y, ll z)
	{
		assert(1 <= x && x <= n);
		assert(1 <= y && y <= n);
		edge.push_back({x, y, z});
	}
};

struct tree
{
	const static int K = 17; // for LCA
	int n;
	vector<vector<pll>> v;
	tree (const undirected_graph &G)
	{
		n = G.n;
		v = vector<vector<pll>>(n+1);
		for (auto e : G.edge)
		{
			int x = e.X, y = e.Y;
			ll z = e.Z;
			v[x].push_back({y, z});
			v[y].push_back({x, z});
		}
	}
	
	vector<int> r;
	int times;
	vector<int> X, Y;
	vector<int> dis;
	vector<array<ll, K>> pre, val;
	void dfs(int x, int p)
	{
		X[x] = ++ times;
		for (auto e : v[x])
		{
			int y = e.X;
			ll z = e.Y;
			if (y == p) continue;
			dis[y] = dis[x]+1;
			pre[y][0] = x;
			val[y][0] = z;
			dfs(y, x);
		}
		Y[x] = times;
	}
	void build_dfs_order(int root)
	{
		assert(1 <= root && root <= n);
		r = vector<int>(n+1);
		X = vector<int>(n+1);
		Y = vector<int>(n+1);
		dis = vector<int>(n+1);
		pre = vector<array<ll, K>>(n+1);
		val = vector<array<ll, K>>(n+1);
		times = 0;
		dfs(root, 0);
		for (int k = 1; k < K; ++ k)
			for (int i = 1; i <= n; ++ i)
			{
				pre[i][k] = pre[pre[i][k-1]][k-1];
				val[i][k] = val[i][k-1];
				if (pre[i][k-1]) freshmax(val[i][k], val[pre[i][k-1]][k-1]);
			}
	}
	
	ll getLCA(int x, int y)
	{
		ll ret = 0;
		assert(n <= 1<<K);
		if (dis[x] < dis[y]) swap(x, y);
		for (int k = K-1; k >= 0; -- k)
			if (dis[x]-dis[y] >= 1<<k)
			{
				freshmax(ret, val[x][k]);
				x = pre[x][k];
			}
		if (x == y) return ret;
		for (int k = K-1; k >= 0; -- k)
			if (pre[x][k] != pre[y][k])
			{
				freshmax(ret, val[x][k]);
				freshmax(ret, val[y][k]);
				x = pre[x][k];
				y = pre[y][k];
			}
		
		freshmax(ret, val[x][0]);
		freshmax(ret, val[y][0]);
		return ret;
	}
};

int n, m;
vector<pii> v[MAXN];
ll dis[MAXN];
int from[MAXN];

void solve()
{
	n = inp();
	m = inp();
	int k = inp();
	int tests = inp();
	for (int i = 1; i <= m; ++ i)
	{
		int x = inp();
		int y = inp();
		int z = inp();
		v[x].push_back({y, z});
		v[y].push_back({x, z});
	}
	
	priority_queue<pll, vector<pll>, greater<pll> > q;
	for (int i = 1; i <= n; ++ i)
		dis[i] = INF;
	for (int i = 1; i <= k; ++ i)
	{
		from[i] = i;
		q.push({dis[i] = 0, i});
	}
	while (!q.empty())
	{
		ll d;
		int x;
		d = q.top().X;
		x = q.top().Y;
		q.pop();
		if (dis[x] != d) continue;
		for (auto e : v[x])
		{
			int y = e.X, z = e.Y;
			if (dis[y] > d+z)
			{
				dis[y] = d+z;
				from[y] = from[x];
				q.push({dis[y], y});
			}
		}
	}
	
	vector<edge_type> edge;
	for (int x = 1; x <= n; ++ x)
		for (auto e : v[x])
		{
			int y = e.X;
			ll z = e.Y;
			if (from[x] != from[y])
			{
				edge.push_back({from[x], from[y], dis[x]+dis[y]+z});
			}
		}
	sort(edge.begin(), edge.end());
	/*
	for (auto e : edge)
		printf("%d %d %lld\n", e.X, e.Y, e.Z);
	*/
	undirected_graph G(k); 
	for (int i = 1; i <= k; ++ i) F[i] = i;
	for (auto e : edge)
	{
		int x = e.X, y = e.Y;
		ll z = e.Z;
		if (father(x) == father(y)) continue;
		F[father(x)] = father(y);
		G.addedge(x, y, z);
	}
	tree T(G);
	T.build_dfs_order(1);
	
	while (tests --)
	{
		int x = inp(), y = inp();
		ll ans = T.getLCA(x, y);
		writeln(ans);
	}
}

int32_t main()
{
	
	//for (int T = inp(); T --; )
		solve();
	
	return 0;
}