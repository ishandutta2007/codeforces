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

template<class T>
void print(const T &a)
{
	for (auto x : a) printf("%d ", x); puts("");
}

const int MAXN = 4010;
const int MAXM = 8010;
const int MAXK = 20;
//const i64 INF = 1000000000000000000LL;
const int INF = 1000000000;
//const int MOD = 998244353;
const int MOD = 1000000007;
const int INV2 = (MOD+1)/2;
const ld pi = 3.1415926535897932384626433;

int n;
char s[MAXN];
bool a[MAXN][MAXN];
int p[MAXN];

bool g[MAXM][MAXM];

void add(int x, int y)
{
	//printf("%d %d\n", x, y);
	g[x][y] = 1;
}

int times, dfn[MAXM], low[MAXM];
vector<int> st;
int in[MAXM];
int scc, belong[MAXM];

void tarjan(int x)
{
	dfn[x] = low[x] = ++ times;
	st.push_back(x);
	in[x] = 1;
	for (int y = 1; y <= n+n+n+n; ++ y)
	{
		if (!g[x][y]) continue;
		if (!dfn[y])
		{
			tarjan(y);
			freshmin(low[x], low[y]);
		}
		else if (in[y])
			freshmin(low[x], dfn[y]);
	}
	if (low[x] == dfn[x])
	{
		scc ++;
		while (1)
		{
			int y = st.back();
			st.pop_back();
			in[y] = 0;
			belong[y] = scc;
			if (x == y) break;
		}
	}
}

bool f[MAXM][MAXM];
int deg[MAXM];
int rev[MAXM], color[MAXM];

void solve()
{
	scanf("%d", &n);
	for (int i = 1; i <= n; ++ i)
	{
		scanf("%s", s+1);
		for (int j = 1; j <= n; ++ j)
			a[i][j] ^= s[j]-'0';
	}
	for (int i = 1; i <= n; ++ i)
	{
		scanf("%s", s+1);
		for (int j = 1; j <= n; ++ j)
			a[i][j] ^= s[j]-'0';
	}
	scanf("%s", s+1);
	for (int i = 1; i <= n; ++ i)
	{
		p[i] = s[i]-'0';
	}
	for (int i = 1; i <= n; ++ i)
		for (int j = 1; j <= n; ++ j)
		{
			if (a[i][j])
			{
				if (p[i] && p[j])
				{
					add(i, n+n+j+n);
					add(n+n+j, i+n);
					add(i+n, n+n+j);
					add(n+n+j+n, i);
				}
				else if (p[j])
				{
					add(i+n, i);
				}
				else if (p[i])
				{
					add(n+n+j+n, n+n+j);
				}
				else
				{
					puts("-1");
					return;
				}
			}
			else
			{
				if (p[i] && p[j])
				{
					add(i, n+n+j);
					add(n+n+j, i);
					add(i+n, n+n+j+n);
					add(n+n+j+n, i+n);
				}
				else if (p[j])
				{
					add(i, i+n);
				}
				else if (p[i])
				{
					add(n+n+j, n+n+j+n);
				}
				else
				{
					
				}
			}
		}
	
	for (int i = 1; i <= n+n+n+n; ++ i)
		if (!dfn[i]) tarjan(i);
	
	for (int i = 1; i <= n; ++ i)
	{
		if (belong[i] == belong[i+n])
		{
			puts("-1");
			return;
		}
		rev[belong[i]] = belong[i+n];
		rev[belong[i+n]] = belong[i];
	}
	
	for (int j = 1; j <= n; ++ j)
	{
		if (belong[n+n+j] == belong[n+n+j+n])
		{
			puts("-1");
			return;
		}
		rev[belong[n+n+j]] = belong[n+n+j+n];
		rev[belong[n+n+j+n]] = belong[n+n+j];
	}
	
	for (int i = 1; i <= n+n+n+n; ++ i)
		for (int j = 1; j <= n+n+n+n; ++ j)
			if (g[i][j] && belong[i] != belong[j])
			{
				f[belong[j]][belong[i]] = 1;
				deg[belong[i]] ++;
			}
	
	queue<int> Q;
	for (int i = 1; i <= scc; ++ i)
		if (deg[i] == 0)
			Q.push(i);
	while (!Q.empty())
	{
		int x = Q.front();
		Q.pop();
		if (!color[x])
		{
			color[x] = 1;
			color[rev[x]] = 2;
		}
		for (int y = 1; y <= scc; ++ y)
			if (f[x][y])
			{
				if (!-- deg[y]) Q.push(y);
			}
	}
	
	vector<pii> ans;
	for (int i = 1; i <= n; ++ i)
		if (color[belong[i]] == 1)
			ans.push_back({0, i});
	
	for (int j = 1; j <= n; ++ j)
		if (color[belong[n+n+j]] == 1)
			ans.push_back({1, j});
	
	printf("%d\n", ans.size());
	for (auto e : ans)
	{
		if (e.X == 0)
			printf("row %d\n", e.Y-1);
		else
			printf("col %d\n", e.Y-1);
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