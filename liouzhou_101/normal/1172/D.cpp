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

namespace io{
	const int L = (1 << 20) + 1;

	char buf[L], *S , *T, c;

	char getchar() {
		if(__builtin_expect(S == T, 0)) {
			T = (S = buf) + fread(buf, 1, L, stdin);
			return (S == T ? EOF : *S++);
		}
		return *S++;
	}

	int inp() {
		int x = 0, f = 1; char ch;
		for(ch = getchar(); !isdigit(ch); ch = getchar())
			if(ch == '-') f = -1;
		for(; isdigit(ch); x = x * 10 + ch - '0', ch = getchar());
		return x * f;
	}

	unsigned inpu()
	{
		unsigned x = 0; char ch;
		for(ch = getchar(); !isdigit(ch); ch = getchar());
		for(; isdigit(ch); x = x * 10 + ch - '0', ch = getchar());
		return x;
	}

	ll inp_ll() {
		ll x = 0; int f = 1; char ch;
		for(ch = getchar(); !isdigit(ch); ch = getchar())
			if(ch == '-') f = -1;
		for(; isdigit(ch); x = x * 10 + ch - '0', ch = getchar());
		return x * f;
	}

	char B[45], *outs=B+40, *outr=B+40;
	template<class T>
	inline void print(register T a,register char x=0){
		if(x) *--outs = x, x = 0;

		if(!a)*--outs = '0';
		else
			while(a)
				*--outs = (a % 10) + 48, a /= 10;

		if(x)
			*--outs = x;

		fwrite(outs, outr - outs , 1, stdout);
		outs = outr;
	}
};

using io :: print;
using io :: inp;
using io :: inpu;
using io :: inp_ll;

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

const int MOD = 998244353;
const int INF = 1000000010;
const int MAXN = 1010;

int n;
int a[MAXN], b[MAXN];

int u[MAXN];
vector<pii> solve(int *a)
{
	for (int i = 1; i <= n; ++ i)
		u[i] = 0;
	vector<pii> ret;
	for (int i = 1; i <= n; ++ i)
	{
		if (u[i]) continue;
		vector<int> v;
		for (int x = i; !u[x]; x = a[x])
		{
			u[x] = 1;
			v.push_back(x);
		}
		for (int k = v.size()-1; k >= 1; -- k)
			ret.emplace_back(v[k-1], v[k]);
	}
	reverse(ret.begin(), ret.end());
	return ret;
}

vector<pair<pii, pii> > ans;

int g[MAXN][MAXN];

void add(int x1, int y1, int x2, int y2)
{
	g[x1][y1] = g[x2][y2] = 1;
	ans.push_back(make_pair(pii(x1, y1), pii(x2, y2)));
}

int main()
{
	
	scanf("%d", &n);
	for (int i = 1; i <= n; ++ i)
		scanf("%d", &a[i]);
	for (int i = 1; i <= n; ++ i)
		scanf("%d", &b[i]);
	auto pa = solve(a);
	auto pb = solve(b);
	for (int i = 0; i < max(pa.size(), pb.size()); ++ i)
	{
		if (i < min(pa.size(), pb.size()))
		{
			int x1 = pa[i].X, x2 = pa[i].Y;
			int y1 = pb[i].X, y2 = pb[i].Y;
			add(x1, y1, x2, y2);
		}
		else if (pa.size() < pb.size())
		{
			for (int xx = 1; xx <= n; ++ xx)
			{
				int y1 = pb[i].X, y2 = pb[i].Y;
				if (!g[xx][y1] && !g[xx][y2])
				{
					add(xx, y1, xx, y2);
					break;
				}
			}
		}
		else
		{
			for (int yy = 1; yy <= n; ++ yy)
			{
				int x1 = pa[i].X, x2 = pa[i].Y;
				if (!g[x1][yy] && !g[x2][yy])
				{
					add(x1, yy, x2, yy);
					break;
				}
			}
		}
	}
	cout << ans.size() << endl;
	for (auto p : ans)
	{
		printf("%d %d %d %d\n", p.X.X, p.X.Y, p.Y.X, p.Y.Y);
	}
	
	return 0;
}