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
ll a[MAXN];

int get_p2(ll x)
{
	int ret = 0;
	while (x%2 == 0)
	{
		ret ++;
		x /= 2;
	}
	return ret;
}

ll b[MAXN];
int p2[MAXN];
int F[MAXN][MAXK];

void solve()
{
	scanf("%d", &n);
	for (int i = 1; i <= n; ++ i)
	{
		scanf("%lld", &a[i]);
	}
	sort(a+1, a+n+1);
	for (int i = n; i >= 1; -- i)
	{
		b[i] = gcd(b[i+1], a[i]);
		p2[i] = get_p2(a[i]);
		for (int k = 0; k < MAXK; ++ k)
			F[i][k] = F[i+1][k];
		F[i][p2[i]] ++;
	}
	int ans = 0;
	for (int i = 1; i <= n; ++ i)
	{
		int s = get_p2(b[i]);
		ans = max(ans, F[i][p2[i]]);
	}
	for (int i = 1; i <= n; ++ i)
	{
		if (ans == F[i][p2[i]])
		{
			int ret = n-ans;
			printf("%d\n", ret);
			for (int j = 1; j <= i-1; ++ j)
				printf("%lld\n", a[j]);
			for (int j = i; j <= n; ++ j)
				if (p2[j] != p2[i])
					printf("%lld\n", a[j]);
			return;
		}
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