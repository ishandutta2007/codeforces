//#pragma GCC optimize("Ofast,unroll-loops,no-stack-protector,fast-math")
//#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")
//#pragma comment(linker, "/stack:200000000")

#include <bits/stdc++.h>

using namespace std;

//typedef long long ll;
typedef unsigned long long ull;
typedef double ld;
typedef pair<int,int> pii;
//typedef pair<ll,ll> pll;
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

/*
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
*/
using i32 = int;
using i64 = long long;
using u8 = unsigned char;
using u32 = unsigned;
using u64 = unsigned long long;
using f64 = double;
using f80 = long double;
/*
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
*/
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

const int MAXN = 100010;
const int MAXM = 30;
const int MOD = 998244353;
const f80 MI = f80(1)/MOD;
const int INF = 1000000000;

int n;
string s[MAXN];

int A[MAXN][MAXM], L[MAXN][MAXM], R[MAXN][MAXM], M[MAXN][MAXM];
int l[MAXM], r[MAXM], a[MAXM], m[MAXM];
int ll[MAXM], rr[MAXM], aa[MAXM], mm[MAXM];

int main()
{
	
	scanf("%d", &n);
	for (int i = 1; i <= n; ++ i)
	{
		static char tmp[MAXN];
		scanf("%s", tmp);
		s[i] = tmp;
		
		for (int x = 0; x < 26; ++ x)
		{
			L[i][x] = 0;
			for (int k = 0; k < s[i].size(); ++ k)
			{
				if (s[i][k]-'a' != x) break;
				L[i][x] ++;
			}
			R[i][x] = 0;
			for (int k = s[i].size()-1; k >= 0; -- k)
			{
				if (s[i][k]-'a' != x) break;
				R[i][x] ++;
			}
			M[i][x] = 0;
			for (int k = 0; k < s[i].size(); ++ k)
			{
				if (s[i][k]-'a' == x)
				{
					int cur = 1;
					for (++ k; k < s[i].size(); ++ k)
					{
						if (s[i][k]-'a' != x) break;
						++ cur;
					}
					-- k;
					freshmax(M[i][x], cur);
				}
			}
			A[i][x] = L[i][x] == s[i].size();
		}
		
		
	}
	
	for (int i = 0; i < 26; ++ i)
	{
		l[i] = L[1][i];
		m[i] = M[1][i];
		r[i] = R[1][i];
		a[i] = A[1][i];
	}
	for (int i = 2; i <= n; ++ i)
	{
		for (int x = 0; x < 26; ++ x)
		{
			ll[x] = L[i][x];
			if (A[i][x]) ll[x] = l[x]+(l[x]+1)*L[i][x];
			rr[x] = R[i][x];
			if (A[i][x]) rr[x] = r[x]+(r[x]+1)*R[i][x];
			aa[x] = A[i][x];
			if (A[i][x]) aa[x] = a[x];
			mm[x] = M[i][x];
			if (m[x])
			{
				if (A[i][x])
					freshmax(mm[x], m[x]+(m[x]+1)*M[i][x]);
				else
					freshmax(mm[x], L[i][x]+R[i][x]+1);
			}
		}
		for (int x = 0; x < 26; ++ x)
		{
			l[x] = ll[x];
			r[x] = rr[x];
			m[x] = mm[x];
			a[x] = aa[x];
		}
	}
	
	int ans = 0;
	for (int x = 0; x < 26; ++ x)
		freshmax(ans, m[x]);
	cout << ans << endl;
	
	return 0;
}