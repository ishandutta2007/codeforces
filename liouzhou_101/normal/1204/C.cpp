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

const int MAXN = 111;
const int MAXM = 1000010;
//const i64 INF = 1000000000000000000LL;
const int INF = 1000000000;
//const int MOD = 998244353;
const int MOD = 1000000007;
const int INV2 = (MOD+1)/2;
const ld pi = 3.1415926535897932384626433;

int n;
int f[MAXN][MAXN];
int m;
int a[MAXM];
int F[MAXM], G[MAXM];
int head, tail, Q[MAXM];

int main()
{
	
	scanf("%d", &n);
	for (int i = 1; i <= n; ++ i)
	{
		char s[MAXN];
		scanf("%s", s+1);
		for (int j = 1; j <= n; ++ j)
			f[i][j] = s[j] == '0' ? INF : 1;
	}
	for (int i = 1; i <= n; ++ i)
		f[i][i] = 0;
	
	for (int k = 1; k <= n; ++ k)
		for (int i = 1; i <= n; ++ i)
			for (int j = 1; j <= n; ++ j)
				freshmin(f[i][j], f[i][k]+f[k][j]);
	
	scanf("%d", &m);
	for (int i = 1; i <= m; ++ i)
		scanf("%d", &a[i]);
	
	head = tail = 1;
	Q[1] = 1;
	F[1] = 1;
	
	for (int i = 2; i <= m; ++ i)
	{
		while (head <= tail)
		{
			if (f[a[Q[head]]][a[i]] == i-Q[head]) break;
			++ head;
		}
		F[i] = F[Q[head]]+1;
		G[i] = Q[head];
		
		while (head <= tail)
		{
			if (F[Q[tail]] < F[i]) break;
			-- tail;
		}
		Q[++ tail] = i;
	}
	
	vector<int> ret;
	for (int i = m; i >= 1; i = G[i])
		ret.push_back(a[i]);
	
	printf("%d\n", ret.size());
	reverse(ret.begin(), ret.end());
	for (auto x : ret)
		printf("%d ", x);
	
	return 0;
}