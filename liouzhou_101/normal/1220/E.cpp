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

const int MAXN = 200010;
const int MAXM = 30*30*16*16+10;
const int MAXK = 62;
//const i64 INF = 1000000000000000000LL;
const int INF = 1000000000;
//const int MOD = 998244353;
//const int MOD = 1000000007;
//const int INV2 = (MOD+1)/2;
const ld pi = 3.1415926535897932384626433;

int dx[] = {-1, 1, 0, 0};
int dy[] = {0, 0, -1, 1};

int n, m;
vector<int> v[MAXN];
vector<pii> e;
int w[MAXN];

int F[MAXN];

int father(int x)
{
	return F[x] == x ? x : F[x] = father(F[x]);
}

int dis[MAXN];
int pre[MAXN];

void dfs(int x)
{
	for (auto y : v[x])
	{
		if (y == pre[x]) continue;
		dis[y] = dis[x]+1;
		pre[y] = x;
		dfs(y);
	}
}

int tot[MAXN];
ll sum[MAXN], dp[MAXN];

vector<int> vv[MAXN];

void dfs2(int x)
{
	dp[x] = 0;
	for (auto y : vv[x])
	{
		dfs2(y);
		dp[x] = max(dp[x], dp[y]);
	}
	dp[x] += sum[x];
}

void solve()
{
	scanf("%d%d", &n, &m);
	for (int i = 1; i <= n; ++ i) scanf("%d", &w[i]);
	for (int i = 1; i <= n; ++ i) F[i] = i;
	for (int i = 1; i <= m; ++ i)
	{
		int x, y;
		scanf("%d%d", &x, &y);
		int fx = father(x), fy = father(y);
		if (fx == fy)
		{
			e.push_back({x, y});
		}
		else
		{
			F[fx] = fy;
			v[x].push_back(y);
			v[y].push_back(x);
		}
	}
	int r;
	scanf("%d", &r);
	dfs(r);
	for (int i = 1; i <= n; ++ i) F[i] = i;
	for (auto p : e)
	{
		int x = father(p.X), y = father(p.Y);
		while (x != y)
		{
			if (dis[x] < dis[y]) swap(x, y);
			int px = father(pre[x]);
			F[x] = px;
			x = px;
		}
	}
	for (int i = 1; i <= n; ++ i)
	{
		tot[father(i)] ++;
		//sum[father(i)] += w[i];
	}
	vector<int> q;
	for (int i = 1; i <= n; ++ i)
		if (tot[i] >= 2)
		{
			q.push_back(i);
		}
	if (!q.empty())
	{
		int x = r;
		for (int i = 0; i < q.size(); ++ i)
		{
			int y = father(q[i]);
			while (x != y)
			{
				if (dis[x] < dis[y]) swap(x, y);
				int px = father(pre[x]);
				F[x] = px;
				x = px;
			}
		}
		r = x;
	}
	
	for (int i = 1; i <= n; ++ i)
	{
		sum[father(i)] += w[i];
	}
	
	for (int i = 1; i <= n; ++ i)
	{
		if (pre[i] == 0) continue;
		int x = father(i), y = father(pre[i]);
		if (x != y)
		{
			vv[y].push_back(x);
		}
	}
	r = father(r);
	dfs2(r);
	
	cout << dp[r] << endl;
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