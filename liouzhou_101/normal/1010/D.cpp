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
		if(S == T) {
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
using io :: inp_ll;

const int MAXN = 1000010;
const int INF = 1000000000;
const int MOD = 1000000007;

ll power(ll a, ll b, ll p)
{
	if (!b) return 1;
	ll t = power(a, b/2, p);
	t = t*t%p;
	if (b&1) t = t*a%p;
	return t;
}

const ld eps = 1e-10;

int n;
char op[MAXN][5];
int s[MAXN][2];
int w[MAXN];
int rev[MAXN];

void dfs(int x)
{
	if (op[x][0] == 'I')
		return;
	if (op[x][0] == 'N')
		dfs(s[x][0]);
	else
	{
		dfs(s[x][0]);
		dfs(s[x][1]);
	}
	if (op[x][0] == 'N')
		w[x] = !w[s[x][0]];
	else if (op[x][0] == 'A')
		w[x] = w[s[x][0]] && w[s[x][1]];
	else if (op[x][0] == 'O')
		w[x] = w[s[x][0]] || w[s[x][1]];
	else if (op[x][0] == 'X')
		w[x] = w[s[x][0]] ^ w[s[x][1]];
}

void work(int x)
{
	if (op[x][0] == 'I')
	{
		rev[x] = 1;
		return;
	}
	if (op[x][0] == 'N')
		work(s[x][0]);
	else if (op[x][0] == 'A')
	{
		if (w[s[x][0]] == 0 && w[s[x][1]] == 1)
			work(s[x][0]);
		if (w[s[x][0]] == 1 && w[s[x][1]] == 0)
			work(s[x][1]);
		if (w[s[x][0]] == 1 && w[s[x][1]] == 1)
		{
			work(s[x][0]);
			work(s[x][1]);
		}
	}
	else if (op[x][0] == 'O')
	{
		if (w[s[x][0]] == 0 && w[s[x][1]] == 1)
			work(s[x][1]);
		if (w[s[x][0]] == 1 && w[s[x][1]] == 0)
			work(s[x][0]);
		if (w[s[x][0]] == 0 && w[s[x][1]] == 0)
		{
			work(s[x][0]);
			work(s[x][1]);
		}
	}
	else if (op[x][0] == 'X')
	{
		work(s[x][0]);
		work(s[x][1]);
	}
}

int main()
{
	
	scanf("%d", &n);
	for (int i = 1; i <= n; ++ i)
	{
		scanf("%s", op[i]);
		if (op[i][0] == 'I')
			scanf("%d", &w[i]);
		else if (op[i][0] == 'N')
			scanf("%d", &s[i][0]);
		else
			scanf("%d%d", &s[i][0], &s[i][1]);
	}
	dfs(1);
	work(1);
	for (int i = 1; i <= n; ++ i)
		if (op[i][0] == 'I') printf("%d", w[1]^rev[i]);
	
	return 0;
}