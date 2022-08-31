#pragma GCC optimize("Ofast,unroll-loops,no-stack-protector,fast-math")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")
//#pragma comment(linker, "/stack:200000000")
 
#include <bits/stdc++.h>
#include<fcntl.h>
 
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

template<class T>
void print(const T &a)
{
	for (auto x : a) printf("%d ", x); puts("");
}

const int MAXN = 1000010;
const int MAXM = 31;
const int MAXK = 20;
//const i64 INF = 1000000000000000000LL;
const int INF = 1000000000;
//const int MOD = 998244353;
const int MOD = 1000000007;
const int INV2 = (MOD+1)/2;
const ld pi = 3.1415926535897932384626433;

int n, m;
char s[MAXN];
int pre[MAXN][MAXK];
int dis[MAXN];

int getLCA(int x, int y)
{
	if (dis[x] < dis[y]) swap(x, y);
	for (int k = MAXK-1; k >= 0; -- k)
		if (dis[x]-dis[y] >= 1<<k)
		{
			x = pre[x][k];
		}
	if (x == y) return x;
	for (int k = MAXK-1; k >= 0; -- k)
		if (pre[x][k] != pre[y][k])
		{
			x = pre[x][k];
			y = pre[y][k];
		}
	return pre[x][0];
}

int place(int x, int y)
{
	return (x-1)*m+y;
}

void solve()
{
	scanf("%d%d", &n, &m);
	vector<vector<int>> g(n+1, vector<int>(m+1));
	for (int i = 1; i <= n; ++ i)
	{
		scanf("%s", s+1);
		for (int j = 1; j <= m; ++ j)
			g[i][j] = s[j] == '#';
	}
	vector<vector<int>> f(n+1, vector<int>(m+1));
	f[1][1] = 1;
	for (int i = 1; i <= n; ++ i)
	{
		for (int j = 1; j <= m; ++ j)
		{
			if (i == 1 && j == 1) continue;
			f[i][j] = !g[i][j] && (f[i-1][j] || f[i][j-1]);
			if (f[i][j])
			{
				int x = place(i, j);
				if (f[i-1][j] && !f[i][j-1])
					pre[x][0] = place(i-1, j);
				else if (!f[i-1][j] && f[i][j-1])
					pre[x][0] = place(i, j-1);
				else
					pre[x][0] = getLCA(place(i-1, j), place(i, j-1));
				dis[x] = dis[pre[x][0]]+1;
				for (int k = 1; k < MAXK; ++ k)
					pre[x][k] = pre[pre[x][k-1]][k-1];
			}
		}
	}
	if (!f[n][m])
	{
		puts("0");
		return;
	}
	int x = place(n, m);
	if (pre[x][0] == 1)
	{
		puts("2");
	}
	else
	{
		puts("1");
	}
}

int main()
{
	/*
	int T;
	scanf("%d", &T);
	while (T --)*/
	solve();
	
	return 0;
}