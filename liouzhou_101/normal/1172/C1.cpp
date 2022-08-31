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
const int MAXN = 55;

int n, m;
ll a[MAXN], w[MAXN];
ll F[MAXN][MAXN][MAXN];

int main()
{
	
	cin >> n >> m;
	for (int i = 1; i <= n; ++ i)
		cin >> a[i];
	ll sum = 0, sumx = 0, sumy = 0;
	for (int i = 1; i <= n; ++ i)
	{
		cin >> w[i];
		sum += w[i];
		if (a[i]) sumx += w[i];
		if (!a[i]) sumy += w[i];
	}
	for (int i = 1; i <= n; ++ i)
	{
		//F[x][y][k] x good times, y bad times, k hits
		for (int s = 0; s <= m; ++ s)
			for (int x = 0; x <= s; ++ x)
			{
				int y = s-x;
				int up = a[i] ? x : y;
				for (int k = 0; k <= up; ++ k)
					F[x][y][k] = 0;
			}
		
		F[0][0][0] = 1;
		
		for (int s = 0; s <= m; ++ s)
			for (int x = 0; x <= s; ++ x)
			{
				int y = s-x;
				ll up = a[i] ? x : y;
				if (!a[i]) up = min(up, w[i]);
				ll rev = power(sum+x-y, MOD-2, MOD);
				for (int k = 0; k <= up; ++ k)
				{
					if (a[i])
					{
						F[x+1][y][k] += F[x][y][k]*((sumx+x)-(w[i]+k))%MOD*rev%MOD;
						F[x+1][y][k+1] += F[x][y][k]*(w[i]+k)%MOD*rev%MOD;
						F[x][y+1][k] += F[x][y][k]*(sumy-y)%MOD*rev%MOD;
					}
					else
					{
						F[x+1][y][k] += F[x][y][k]*(sumx+x)%MOD*rev%MOD;
						F[x][y+1][k] += F[x][y][k]*((sumy-y)-(w[i]-k))%MOD*rev%MOD;
						F[x][y+1][k+1] += F[x][y][k]*(w[i]-k)%MOD*rev%MOD;
					}
				}
				
			}
		
		ll ret = 0;
		for (int x = 0; x <= m; ++ x)
		{
			int y = m-x;
			ll up = a[i] ? x : y;
			if (!a[i]) up = min(up, w[i]);
			for (int k = 0; k <= up; ++ k)
			{
				if (a[i])
					ret = (ret+k*F[x][y][k])%MOD;
				else
					ret = (ret-k*F[x][y][k])%MOD;
			}
		}
		
		ret = ((w[i]+ret)%MOD+MOD)%MOD;
		printf("%lld\n", ret);
	}
	
	
	return 0;
}