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

const int MAXN = 15;
const int MAXM = 2010;
const int MAXK = 20;
//const i64 INF = 1000000000000000000LL;
const int INF = 1000000000;
//const int MOD = 998244353;
const int MOD = 1000000007;
const int INV2 = (MOD+1)/2;
const ld pi = 3.1415926535897932384626433;

int n, m;
int a[MAXN][MAXM];
int maxv[MAXM];

int p[MAXM];
int F[15][1<<12];
int tmp[1<<12];

void solve()
{
	scanf("%d%d", &n, &m);
	for (int i = 0; i < n; ++ i)
	{
		for (int j = 1; j <= m; ++ j)
			scanf("%d", &a[i][j]);
	}
	for (int j = 1; j <= m; ++ j)
	{
		maxv[j] = 0;
		for (int i = 0; i < n; ++ i) freshmax(maxv[j], a[i][j]);
	}
	for (int j = 1; j <= m; ++ j) p[j] = j;
	sort(p+1, p+m+1, [&](int x, int y)
	{
		return maxv[x] > maxv[y];
	});
	
	for (int i = 0; i <= min(n, m); ++ i)
		for (int j = 0; j < 1<<n; ++ j)
			F[i][j] = 0;
	
	for (int k = 1; k <= min(n, m); ++ k)
	{
		int j = p[k];
		
		for (int s = 0; s < 1<<n; ++ s)
		{
			tmp[s] = 0;
			for (int d = 0; d < n; ++ d)
			{
				int sum = 0;
				for (int i = 0; i < n; ++ i) if (s>>i&1) sum += a[(i+d)%n][j];
				freshmax(tmp[s], sum);
			}
		}
		
		for (int s = 0; s < 1<<n; ++ s)
		{
			F[k][s] = F[k-1][s];
			for (int t = s; t; t = (t-1)&s)
			{
				freshmax(F[k][s], F[k-1][s^t]+tmp[t]);
			}
		}
	}
	
	cout << F[min(n, m)][(1<<n)-1] << endl;
}

int main()
{
	
	int T;
	scanf("%d", &T);
	while (T --)
	solve();
	
	return 0;
}