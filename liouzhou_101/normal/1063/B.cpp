#pragma GCC optimize("Ofast")

#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;
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

const int MAXN = 2010;
const u64 MOD = 1000000007;
const f80 MI = f80(1)/MOD;
const int INF = 1000000010;

int n, m;
int sx, sy;
int L, R;
char s[MAXN][MAXN];
int F[MAXN][MAXN];

queue<pii> ql, qr, tmpql;

void add(int sx, int sy, int flag = 1)
{
	int x = sx, y = sy;
	qr.emplace(x, y);
	if (s[x][y-1] == '.' && F[x][y-1] > F[x][y])
		if (flag) ql.emplace(x, y); else tmpql.emplace(x, y);
	while (s[x+1][y] == '.' && F[x+1][y] > F[sx][sy])
	{
		++ x;
		F[x][y] = F[sx][sy];
		qr.emplace(x, y);
		if (s[x][y-1] == '.' && F[x][y-1] > F[x][y])
			if (flag) ql.emplace(x, y); else tmpql.emplace(x, y);
	}
	x = sx, y = sy;
	while (s[x-1][y] == '.' && F[x-1][y] > F[sx][sy])
	{
		-- x;
		F[x][y] = F[sx][sy];
		qr.emplace(x, y);
		if (s[x][y-1] == '.' && F[x][y-1] > F[x][y])
			if (flag) ql.emplace(x, y); else tmpql.emplace(x, y);
	}
}

int main()
{
	
	scanf("%d%d%d%d%d%d", &n, &m, &sx, &sy, &L, &R);
	for (int i = 1; i <= n; ++ i)
		scanf("%s", s[i]+1);
	for (int i = 1; i <= n; ++ i)
		for (int j = 1; j <= m; ++ j)
			F[i][j] = INF;
	
	{
		int x, y;
		F[sx][sy] = 0;
		add(sx, sy);
	}
	
	for (int l = 0; l <= L; ++ l)
	{
		while (!qr.empty())
		{
			int x, y;
			tie(x, y) = qr.front();
			qr.pop();
			// if (F[x][y] == R) continue;
			if (s[x][y+1] == '.' && F[x][y+1] > F[x][y]+1)
			{
				F[x][y+1] = F[x][y]+1;
				add(x, y+1);
			}
		}
		if (l == L || ql.empty()) break;
		while (!tmpql.empty()) tmpql.pop();
		while (!ql.empty())
		{
			int x, y;
			tie(x, y) = ql.front();
			ql.pop();
			if (s[x][y-1] == '.' && F[x][y-1] > F[x][y])
			{
				F[x][y-1] = F[x][y];
				add(x, y-1, 0);
			}
		}
		ql = tmpql;
	}
	

	
	int ans = 0;
	for (int i = 1; i <= n; ++ i)
		for (int j = 1; j <= m; ++ j)
			ans += (F[i][j] <= R);
	cout << ans << endl;
	
	return 0;
}