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

const int MAXN = 1000010;
//const int MAXM = 100010;
const int MAXK = 30;
//const i64 INF = 1000000000000000000LL;
const int INF = 1000000000;
//const int MOD = 998244353;
const int B = 31;
const int MOD = 1000000007;
//const int INV2 = (MOD+1)/2;
const ld pi = 3.1415926535897932384626433;

int dx[] = {-1, -1, -1, 0, 0, 1, 1, 1};
int dy[] = {-1, 0, 1, -1, 1, -1, 0, 1};

#define rep(i,a,b) for (int i = (a), I = (b); i <= I; ++ i)

int days[] = {0, 31, 29, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

bool leap(int y)
{
	return y%4 == 0 && y%100 != 0 || y%400 == 0;
}

int n, m;
char s[MAXN];

void solve()
{
	scanf("%d%d", &n, &m);
	vector<vector<char>> a(n+2, vector<char>(m+2, '.'));
	for (int i = 1; i <= n; ++ i)
	{
		scanf("%s", s);
		for (int j = 1; j <= m; ++ j)
			a[i][j] = s[j-1];
	}
	
	n += 2;
	m += 2;
	
	vector<vector<int>> d(n, vector<int>(m, INF));
	vector<vector<int>> u(n, vector<int>(m, 0));
	
	queue<pii> Q;
	for (int i = 0; i < n; ++ i)
		for (int j = 0; j < m; ++ j)
			if (a[i][j] == '.')
			{
				d[i][j] = 0;
				Q.push({i, j});
			}
	while (!Q.empty())
	{
		int x = Q.front().X, y = Q.front().Y;
		Q.pop();
		for (int k = 0; k < 8; ++ k)
		{
			int tx = x+dx[k], ty = y+dy[k];
			if (0 <= tx && tx < n && 0 <= ty && ty < m && a[tx][ty] == 'X' && d[tx][ty] == INF)
			{
				d[tx][ty] = d[x][y]+1;
				Q.push({tx, ty});
			}
		}
	}
	
	vector<vector<char>> b(n, vector<char>(m, '.'));
	vector<vector<int>> f(n, vector<int>(m, INF));
	
	auto check = [&](int T)
	{
		queue<pii> H;
		for (int i = 0; i < n; ++ i)
			for (int j = 0; j < m; ++ j)
			{
				f[i][j] = INF;
				if (a[i][j] == 'X' && d[i][j] >= T+1)
				{
					b[i][j] = 'X';
					H.push({i, j});
					f[i][j] = 0;
				}
				else
					b[i][j] = '.';
			}
		while (!H.empty())
		{
			int x = H.front().X, y = H.front().Y;
			H.pop();
			if (f[x][y] == T) break;
			for (int k = 0; k < 8; ++ k)
			{
				int tx = x+dx[k], ty = y+dy[k];
				if (0 <= tx && tx < n && 0 <= ty && ty < m && f[tx][ty] > f[x][y]+1)
				{
					f[tx][ty] = f[x][y]+1;
					b[tx][ty] = 'X';
					H.push({tx, ty});
				}
			}
		}
		return a == b;
	};
	
	int L = 1, R = min(n, m);
	int ans = 0;
	while (L <= R)
	{
		int mid = (L+R)/2;
		if (check(mid))
		{
			ans = mid;
			L = mid+1;
		}
		else
			R = mid-1;
	}
	
	check(ans);
	
	printf("%d\n", ans);
	
	n -= 2;
	m -= 2;
	
	for (int i = 1; i <= n; ++ i)
	{
		for (int j = 1; j <= m; ++ j)
			putchar(a[i][j] == 'X' && d[i][j] >= ans+1 ? 'X' : '.');
		puts("");
	}
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