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

const int MAXN = 600010;
const int MAXM = 31;
const int MAXK = 20;
//const i64 INF = 1000000000000000000LL;
const int INF = 1000000000;
//const int MOD = 998244353;
const int MOD = 1000000007;
const int INV2 = (MOD+1)/2;
const ld pi = 3.1415926535897932384626433;

int m, n;
ll a[MAXN], b[MAXN], ta[MAXN], tb[MAXN];
pii e[MAXN];
int to[MAXN];
int ua[MAXN], ub[MAXN];
int f[MAXN], pa[MAXN], pb[MAXN];

void solve()
{
	scanf("%d%d", &m, &n);
	for (int i = 1; i <= n; ++ i)
	{
		scanf("%lld", &a[i]);
		a[i] --;
		ta[i] = a[i];
		pa[i] = i;
	}
	sort(a+1, a+n+1);
	sort(pa+1, pa+n+1, [&](int i, int j)
	{
		return ta[i] < ta[j];
	});
	for (int i = 1; i <= n; ++ i)
	{
		scanf("%lld", &b[i]);
		b[i] --;
		tb[i] = b[i];
		pb[i] = i;
	}
	sort(b+1, b+n+1);
	sort(pb+1, pb+n+1, [&](int i, int j)
	{
		return tb[i] < tb[j];
	});
	for (int i = 1; i <= n; ++ i)
	{
		b[i+n] = b[i]+m;
		b[i+n+n] = b[i]+m+m;
	}
	
	
	ll ans = 0;
	for (int i = 1; i <= n; ++ i) ans += abs(a[i]-b[i]);
	
	int type = 1;
	int where = 1;
	
	{
		for (int i = 1; i <= n; ++ i)
		{
			int j = lower_bound(b+1, b+3*n+1, a[i])-b;
			to[i] = j;
			e[i] = {j-i+1, i};
		}
		sort(e+1, e+n+1);
		int j = 1;
		
		for (int i = 1; i <= 3*n; ++ i)
		{
			ua[i] = 1;
			ub[i] = -1;
		}
		
		ll suma = 0;
		for (int i = 1; i <= n; ++ i)
		{
			ua[i] = a[i] >= b[i] ? 1 : -1;
			suma += ua[i]*a[i];
		}
		ll sumb = 0;
		for (int i = 1; i <= n; ++ i)
		{
			ub[i] = a[i] >= b[i] ? -1 : 1;
			sumb += ub[i]*b[i];
		}
		
		for (int i = 1; i <= 2*n; ++ i)
		{
			while (j <= n && e[j].X <= i)
			{
				if (ua[e[j].Y] == 1)
				{
					suma -= ua[e[j].Y]*a[e[j].Y];
					ua[e[j].Y] *= -1;
					suma += ua[e[j].Y]*a[e[j].Y];
				}
				if (ub[to[e[j].Y]] == -1 && to[e[j].Y] < i+n)
				{
					sumb -= ub[to[e[j].Y]]*b[to[e[j].Y]];
					ub[to[e[j].Y]] *= -1;
					sumb += ub[to[e[j].Y]]*b[to[e[j].Y]];
				}
				++ j;
			}
			if (ans > suma+sumb)
			{
				freshmin(ans, suma+sumb);
				type = 1;
				where = i;
			}
			sumb -= ub[i]*b[i];
			ub[i+n] = a[n] >= b[i+n] ? -1 : 1;
			sumb += ub[i+n]*b[i+n];
		}
	}
	
	{
		for (int i = 1; i <= n; ++ i)
		{
			a[i] += m;
			int j = lower_bound(b+1, b+3*n+1, a[i])-b;
			to[i] = j;
			e[i] = {j-i+1, i};
		}
		sort(e+1, e+n+1);
		int j = 1;
		
		for (int i = 1; i <= 3*n; ++ i)
		{
			ua[i] = 1;
			ub[i] = -1;
		}
		
		ll suma = 0;
		for (int i = 1; i <= n; ++ i)
		{
			ua[i] = a[i] >= b[i] ? 1 : -1;
			suma += ua[i]*a[i];
		}
		ll sumb = 0;
		for (int i = 1; i <= n; ++ i)
		{
			ub[i] = a[i] >= b[i] ? -1 : 1;
			sumb += ub[i]*b[i];
		}
		
		for (int i = 1; i <= 2*n; ++ i)
		{
			while (j <= n && e[j].X <= i)
			{
				if (ua[e[j].Y] == 1)
				{
					suma -= ua[e[j].Y]*a[e[j].Y];
					ua[e[j].Y] *= -1;
					suma += ua[e[j].Y]*a[e[j].Y];
				}
				if (ub[to[e[j].Y]] == -1 && to[e[j].Y] < i+n)
				{
					sumb -= ub[to[e[j].Y]]*b[to[e[j].Y]];
					ub[to[e[j].Y]] *= -1;
					sumb += ub[to[e[j].Y]]*b[to[e[j].Y]];
				}
				++ j;
			}
			if (ans > suma+sumb)
			{
				freshmin(ans, suma+sumb);
				type = 2;
				where = i;
			}
			sumb -= ub[i]*b[i];
			ub[i+n] = a[n] >= b[i+n] ? -1 : 1;
			sumb += ub[i+n]*b[i+n];
		}
	}
	
	cout << ans << endl;
	for (int i = 1; i <= n; ++ i)
	{
		int x = where+i-1;
		if (x > n) x -= n;
		if (x > n) x -= n;
		if (x > n) x -= n;
		f[pa[i]] = pb[x];
	}
	for (int i = 1; i <= n; ++ i)
		printf("%d ", f[i]);
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