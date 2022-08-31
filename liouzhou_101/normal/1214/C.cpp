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

const int MAXN = 200010;
const int MAXM = 31;
//const i64 INF = 1000000000000000000LL;
const int INF = 1000000000;
//const int MOD = 998244353;
const int MOD = 1000000007;
const int INV2 = (MOD+1)/2;
const ld pi = 3.1415926535897932384626433;

int n;
char s[MAXN];
int a[MAXN];

void solve()
{
	scanf("%d%s", &n, s+1);
	if (n%2)
	{
		puts("No");
		return;
	}
	int cnt = 0;
	for (int i = 1; i <= n; ++ i)
		cnt += s[i] == '(';
	if (cnt != n/2)
	{
		puts("No");
		return;
	}
	for (int i = 1; i <= n; ++ i)
	{
		a[i] = a[i-1]+(s[i] == '(' ? 1 : -1);
	}
	int flag = 0;
	for (int i = 1; i <= n; ++ i)
		if (a[i] < 0)
		{
			flag = i;
			break;
		}
	if (!flag)
	{
		puts("Yes");
		return;
	}
	for (int i = 1; i <= n; ++ i)
	{
		a[i] = a[i-1];
		if (i != flag) a[i] = a[i-1]+(s[i] == '(' ? 1 : -1);
	}
	for (int i = 1; i <= n; ++ i)
	{
		if (a[i] < 0)
		{
			puts("No");
			return;
		}
	}
	puts("Yes");
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