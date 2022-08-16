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

const int MOD = 998244353;
const int INF = 1000000000;
const int MAXN = 510;

int n, m;
int c[MAXN];
int u[MAXN][MAXN];
ll F[MAXN][MAXN];

ll solve(int L, int R)
{
	if (L > R) return 1;
	if (u[L][R]) return F[L][R];
	u[L][R] = 1;
	ll &ret = F[L][R];
	
	int color = n+1;
	for (int i = L; i <= R; ++ i)
		freshmin(color, c[i]);
	int pos = L;
	for (int i = L; i <= R; ++ i)
		if (c[i] == color) pos = i;
	
	ll Ls = 0;
	for (int i = L; i <= pos; ++ i)
		(Ls += solve(L, i-1) * solve(i, pos-1)) %= MOD;
	
	ll Rs = 0;
	for (int i = pos; i <= R; ++ i)
		(Rs += solve(pos+1, i) * solve(i+1, R)) %= MOD;
	
	return ret = Ls*Rs%MOD;
}

int main()
{
	
	n = inp();
	m = inp();
	for (int i = 1; i <= m; ++ i)
		c[i] = inp();
	cout << solve(1, m) << endl;
	
	return 0;
}