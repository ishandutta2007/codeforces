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
using i128 = i64;
using u128 = u64;
 
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
	if (!x)
		*-- it = '0';
	while (x)
	{
		*-- it = x%10+'0';
		x /= 10;
	}
	for (; it < end; ++ it)
		putchar(*it);
}
 
template<class T>
void writeln(T x)
{
	write(x);
	putchar('\n');
}
 
const int MAXN = 200010;
const int INF = 1000000000;
const int MOD = 1000000007;

int n;
vector<pair<int, i64>> v[MAXN];
pii e[MAXN];

i64 dis[MAXN], pre[MAXN], weight[MAXN];
int times, r[MAXN], X[MAXN], Y[MAXN];

void dfs(int x)
{
	r[X[x] = ++ times] = x;
	for (auto p : v[x])
	{
		int y = p.X;
		i64 z = p.Y;
		if (y == pre[x]) continue;
		dis[y] = dis[x]+z;
		pre[y] = x;
		weight[y] = z;
		dfs(y);
		r[++ times] = x;
	}
	Y[x] = times;
}

struct node
{
	i64 tag, val, M, LM, MR, LMR;
}tree[MAXN*4];

void add(int k, i64 d)
{
	tree[k].tag += d;
	tree[k].val += d;
	tree[k].M -= 2*d;
	tree[k].LM -= d;
	tree[k].MR -= d;
}

void clear(int k)
{
	if (tree[k].tag)
	{
		add(k<<1, tree[k].tag);
		add(k<<1|1, tree[k].tag);
		tree[k].tag = 0;
	}
}

void update(int k)
{
	tree[k].val = max(tree[k<<1].val, tree[k<<1|1].val);
	tree[k].M = max(tree[k<<1].M, tree[k<<1|1].M);
	tree[k].LM = max(max(tree[k<<1].LM, tree[k<<1|1].LM), tree[k<<1].val+tree[k<<1|1].M);
	tree[k].MR = max(max(tree[k<<1].MR, tree[k<<1|1].MR), tree[k<<1].M+tree[k<<1|1].val);
	tree[k].LMR = max(max(tree[k<<1].LMR, tree[k<<1|1].LMR), max(tree[k<<1].val+tree[k<<1|1].MR, tree[k<<1].LM+tree[k<<1|1].val));
}

void build(int k, int L, int R)
{
	if (L == R)
	{
		int x = r[L];
		tree[k].tag = 0;
		tree[k].val = dis[x];
		tree[k].M = -2*dis[x];
		tree[k].LM = tree[k].MR = -dis[x];
		tree[k].LMR = 0;
		return;
	}
	int m = (L+R)>>1;
	build(k<<1, L, m);
	build(k<<1|1, m+1, R);
	update(k);
}

void add(int k, int L, int R, int x, int y, i64 d)
{
	if (L == x && R == y)
	{
		add(k, d);
		return;
	}
	clear(k);
	int m = (L+R)>>1;
	if (y <= m)
		add(k<<1, L, m, x, y, d);
	else if (x > m)
		add(k<<1|1, m+1, R, x, y, d);
	else
	{
		add(k<<1, L, m, x, m, d);
		add(k<<1|1, m+1, R, m+1, y, d);
	}
	update(k);
}

int main()
{
	
	n = inp();
	int q = inp();
	i64 W = inp_ll();
	for (int i = 1; i < n; ++ i)
	{
		int x = inp();
		int y = inp();
		i64 z = inp_ll();
		v[x].push_back({y, z});
		v[y].push_back({x, z});
		e[i] = {x, y};
	}
	dfs(1);
	build(1, 1, times);
	i64 ans = 0;
	while (q --)
	{
		int k = (inp()+ans)%(n-1)+1;
		i64 w = (inp_ll()+ans)%W;
		int x = pre[e[k].X] == e[k].Y ? e[k].X : e[k].Y;
		add(1, 1, times, X[x], Y[x], w-weight[x]);
		weight[x] = w;
		writeln(ans = tree[1].LMR);
	}
	
	return 0;
}