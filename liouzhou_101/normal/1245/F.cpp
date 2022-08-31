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

const int MAXN = 500010;
//const int MAXM = 100010;
const int MAXK = 30;
//const i64 INF = 1000000000000000000LL;
const int INF = 1000000000;
//const int MOD = 998244353;
const int B = 31;
const int MOD = 1000000007;
//const int INV2 = (MOD+1)/2;
const ld pi = 3.1415926535897932384626433;

int dx[] = {-1, 1, 0, 0};
int dy[] = {0, 0, -1, 1};

#define rep(i,a,b) for (int i = (a), I = (b); i <= I; ++ i)

int days[] = {0, 31, 29, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

bool leap(int y)
{
	return y%4 == 0 && y%100 != 0 || y%400 == 0;
}

ll C[44][44];

ll calc(int n, int m)
{
	if (n > m) swap(n, m);
	if (n == 0) return 0;
	vector<int> vn, vm;
	for (int i = 0; i < 30; ++ i, n /= 2) vn.push_back(n%2);
	for (int i = 0; i < 30; ++ i, m /= 2) vm.push_back(m%2);
	
	ll ret = 0;
	
	int cn = 0;
	for (int i = 29; i >= 0; -- i)
	{
		if (vn[i] == 1)
		{
			int cm = 0;
			
			auto get = [&](int a, int b, int cn, int cm) -> ll
			{
				if (cn&cm) return 0;
				if (a > b) swap(a, b), swap(cn, cm);
				int cnt = 0;
				for (int i = a; i < b; ++ i)
					if (cn>>i&1) ++ cnt;
				ll ret = 0;
				for (int k = 0; k <= a; ++ k)
					ret += C[a][k]<<(b-cnt-k);
				return ret;
			};
			
			for (int j = 29; j >= 0; -- j)
			{
				if (vm[j] == 1)
				{
					ret += get(i, j, cn, cm);
					cm |= 1<<j;
				}
			}
			cn |= 1<<i;
		}
	}
	return ret;
}

void solve()
{
	int L, R;
	cin >> L >> R;
	L ++;
	R ++;
	ll ans = calc(R, R) - calc(R, L-1)*2 + calc(L-1, L-1);
	//ll ans = calc(R, R);
	cout << ans << endl;
}

int main()
{
	
	for (int i = 0; i <= 40; ++ i)
	{
		C[i][0] = 1;
		for (int j = 1; j <= i; ++ j)
			C[i][j] = C[i-1][j-1]+C[i-1][j];
	}
	/*
	cout <<calc(6,6)<<endl;
	cout <<calc(6,7)<<endl;
	cout <<calc(7,7)<<endl;
	return 0;*/
	int T;
	T = 1;
	scanf("%d", &T);
	while (T --)
	solve();
	
	return 0;
}