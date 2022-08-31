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

const int MAXN = 200010;
const int MAXM = 2010;
const int MAXK = 20;
//const i64 INF = 1000000000000000000LL;
const int INF = 1000000000;
//const int MOD = 998244353;
const int MOD = 1000000007;
const int INV2 = (MOD+1)/2;
const ld pi = 3.1415926535897932384626433;

int n;
string s, t;

vector<pii> ans;

void add(int x, int y)
{
	swap(s[x], t[y]);
	ans.push_back({x, y});
}

void solve()
{
	cin >> n;
	cin >> s >> t;
	vector<int> a, b;
	for (int i = 0; i < n; ++ i)
	{
		if (s[i] == t[i]) continue;
		if (s[i] == 'a')
			a.push_back(i);
		else
			b.push_back(i);
	}
	if (a.size()%2 != b.size()%2)
	{
		puts("-1");
		return;
	}
	if (a.size()%2 == 0)
	{
		for (int i = 0; i < a.size(); i += 2)
			add(a[i], a[i+1]);
		for (int i = 0; i < b.size(); i += 2)
			add(b[i], b[i+1]);
	}
	else
	{
		for (int i = 0; i < a.size()-1; i += 2)
			add(a[i], a[i+1]);
		for (int i = 0; i < b.size()-1; i += 2)
			add(b[i], b[i+1]);
		add(a.back(), a.back());
		add(a.back(), b.back());
	}
	if (s == t)
	{
		printf("%d\n", ans.size());
		for (auto e : ans)
			printf("%d %d\n", e.X+1, e.Y+1);
	}
	else
		puts("-1");
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