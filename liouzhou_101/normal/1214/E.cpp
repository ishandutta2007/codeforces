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
const int MAXK = 20;
//const i64 INF = 1000000000000000000LL;
const int INF = 1000000000;
//const int MOD = 998244353;
const int MOD = 1000000007;
const int INV2 = (MOD+1)/2;
const ld pi = 3.1415926535897932384626433;

int n;
pii e[MAXN];
int u[MAXN];
vector<int> v[MAXN];

void solve()
{
	scanf("%d", &n);
	for (int i = 1; i <= n; ++ i)
	{
		int x;
		scanf("%d", &x);
		e[i] = {x, i};
	}
	sort(e+1, e+n+1);
	int len = e[n].X+1;
	u[1] = 2*e[n].Y-1;
	u[len] = 2*e[n].Y;
	int cur = 1;
	for (int i = n-1; i >= 1; -- i)
	{
		while (u[cur]) cur ++;
		if (cur <= len)
		{
			u[cur] = 2*e[i].Y-1;
			int pos = cur+e[i].X;
			if (pos == len+1) len = pos;
			if (pos <= len)
			{
				if (u[pos])
					v[pos-1].push_back(2*e[i].Y);
				else
					u[pos] = 2*e[i].Y;
			}
			else
			{
				pos = cur-e[i].X;
				v[pos+1].push_back(2*e[i].Y);
			}
		}
		else if (e[i].X == 1)
		{
			u[len+1] = 2*e[i].Y-1;
			u[len+2] = 2*e[i].Y;
			len += 2;
		}
		else
		{
			v[1].push_back(2*e[i].Y-1);
			v[e[i].X-1].push_back(2*e[i].Y);
		}
	}
	for (int i = 1; i < len; ++ i)
		printf("%d %d\n", u[i], u[i+1]);
	for (int i = 1; i <= len; ++ i)
		for (auto j : v[i])
			printf("%d %d\n", u[i], j);
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