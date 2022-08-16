//#pragma GCC optimize("Ofast,unroll-loops,no-stack-protector,fast-math")
//#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")
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

	char B[25], *outs=B+20, *outr=B+20;
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

const int MAXN = 2010;
const int MOD = 998244353;
const f80 MI = f80(1)/MOD;
const int INF = 1000000000;

int n, m;
char s[MAXN][MAXN];

int F[MAXN];

int father(int x)
{
	return F[x] == x ? x : F[x] = father(F[x]);
}

vector<int> v[MAXN];
int d[MAXN];

void addedge(int x, int y)
{
	v[x].push_back(y);
	++ d[y];
}

int ans[MAXN], ok[MAXN];

int main()
{
	
	scanf("%d%d", &n, &m);
	for (int i = 1; i <= n; ++ i)
		scanf("%s", s[i]+1);
	for (int i = 1; i <= n+m; ++ i)
		F[i] = i;
	for (int i = 1; i <= n; ++ i)
		for (int j = 1; j <= m; ++ j)
		{
			if (s[i][j] == '=')
				F[father(i)] = father(n+j);
		}
	for (int i = 1; i <= n; ++ i)
		for (int j = 1; j <= m; ++ j)
		{
			if (s[i][j] == '>')
				addedge(father(n+j), father(i));
			if (s[i][j] == '<')
				addedge(father(i), father(n+j));
		}
	
	queue<int> Q;
	for (int i = 1; i <= n+m; ++ i)
		if (i == father(i) && d[i] == 0)
		{
			Q.push(i);
		}
	while (!Q.empty())
	{
		int x = Q.front();
		ans[x] ++;
		ok[x] = 1;
		Q.pop();
		for (auto y : v[x])
		{
			ans[y] = max(ans[y], ans[x]);
			-- d[y];
			if (d[y] == 0)
			{
				Q.push(y);
			}
		}
	}
	for (int i = 1; i <= n+m; ++ i)
		if (i == father(i) && ok[i] == 0)
		{
			puts("No");
			return 0;
		}
	
	puts("Yes");
	for (int i = 1; i <= n; ++ i)
	{
		int x = ans[father(i)];
		printf("%d ", x);
	}
	puts("");
	for (int i = 1; i <= m; ++ i)
	{
		int x = ans[father(n+i)];
		printf("%d ", x);
	}
	puts("");
	
	return 0;
}