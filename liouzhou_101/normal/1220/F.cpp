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

ll gcd(ll a, ll b)
{
	return b ? gcd(b, a%b) : a;
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

template<class T>
void print(const T &a)
{
	for (auto x : a) printf("%d ", x); puts("");
}

const int MAXN = 400010;
const int MAXM = 30*30*16*16+10;
const int MAXK = 19;
//const i64 INF = 1000000000000000000LL;
const int INF = 1000000000;
//const int MOD = 998244353;
//const int MOD = 1000000007;
//const int INV2 = (MOD+1)/2;
const ld pi = 3.1415926535897932384626433;

int dx[] = {-1, 1, 0, 0};
int dy[] = {0, 0, -1, 1};

int n, m;
int a[MAXN];

int f[MAXN][MAXK];

int get_min(int x, int y)
{
	return a[x] < a[y] ? x : y;
}

int getmin(int L, int R)
{
	int k = __lg(R-L+1);
	return get_min(f[L][k], f[R-(1<<k)+1][k]);
}

int L[MAXN], R[MAXN];

int build(int L, int R)
{
	if (L > R) return 0;
	int mid = getmin(L, R);
	::L[mid] = build(L, mid-1);
	::R[mid] = build(mid+1, R);
	return mid;
}

vector<int> v[MAXN];

int dis[MAXN];
int pre[MAXN];

int times;
int X[MAXN], Y[MAXN];

void dfs(int x)
{
	if (!x) return;
	X[x] = Y[x] = ++ times;
	dfs(L[x]);
	dfs(R[x]);
	Y[x] = times;
}

struct node
{
	int minv;
	int tag;
}tree[MAXN*4];


void clear(int k)
{
	if (tree[k].tag)
	{
		tree[k<<1].tag += tree[k].tag;
		tree[k<<1].minv += tree[k].tag;
		tree[k<<1|1].tag += tree[k].tag;
		tree[k<<1|1].minv += tree[k].tag;
		tree[k].tag = 0;
	}
}

void update(int k)
{
	tree[k].minv = max(tree[k<<1].minv, tree[k<<1|1].minv);
}

void add(int k, int L, int R, int x, int y, int d)
{
	if (L == x && R == y)
	{
		tree[k].tag += d;
		tree[k].minv += d;
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

void solve()
{
	scanf("%d", &n);
	for (int i = 1; i <= n; ++ i)
		scanf("%d", &a[i]);
	for (int i = 1; i <= n; ++ i)
	{
		a[i] = a[i]*2-1;
		a[i+n] = a[i]+1;
	}
	for (int i = 1; i <= 2*n; ++ i)
		f[i][0] = i;
	for (int k = 1; k < MAXK; ++ k)
		for (int i = 1; i <= 2*n; ++ i)
		{
			f[i][k] = f[i][k-1];
			if (i+(1<<(k-1)) <= 2*n) f[i][k] = get_min(f[i][k], f[i+(1<<(k-1))][k-1]);
		}
	int root = build(1, 2*n);
	dfs(root);
	for (int i = 1; i <= n; ++ i)
	{
		add(1, 1, times, X[i], Y[i], 1);
	}
	pii ans(n+1, -1);
	freshmin(ans, pii(tree[1].minv, 0));
	for (int i = 1; i < n; ++ i)
	{
		add(1, 1, times, X[i], Y[i], -1);
		add(1, 1, times, X[i+n], Y[i+n], 1);
		freshmin(ans, pii(tree[1].minv, i));
	}
	printf("%d %d\n", ans.X, ans.Y);
}

int main()
{
	
	int T;
	T = 1;
	//scanf("%d", &T);
	while (T --)
	solve();
	
	return 0;
}