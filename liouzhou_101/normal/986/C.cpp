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

const int MAXN = 2<<22|10;

int n, m;
bool b[MAXN];

int u[MAXN];
int head, tail, Q[MAXN];

#define go(to) \
{ \
	int y = to; \
	if (!u[y]) \
	{ \
		u[y] = 1; \
		Q[++ tail] = y; \
	} \
}
				

int main()
{
	
	n = inp();
	m = inp();
	for (int i = 1; i <= m; ++ i)
	{
		int x = inp();
		b[x] = 1;
	}
	int ans = 0;
	for (int i = 0; i < 1<<n; ++ i)
	{
		if (!b[i]) continue;
		if (u[i]) continue;
		ans ++;
		head = tail = 1;
		Q[1] = i;
		while (head <= tail)
		{
			int x = Q[head ++];
			if (x < 1<<n)
			{
				go((~x&((1<<n)-1))^(1<<n));
			}
			else
			{
				int s = x^(1<<n);
				if (b[s]) go(s);
				for (int c = s; c; )
				{
					int k = __builtin_ffs(c)-1;
					
					go(s^(1<<k)^(1<<n));
					
					c ^= 1<<k;
				}
			}
		}
	}
	printf("%d\n", ans);
	
	return 0;
}