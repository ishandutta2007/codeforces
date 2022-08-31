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
	const int L = (1 << 18) + 1;
	
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

const int MAXN = 111111;

inline ull gcd(ull a, ull b)
{
	if (a == 0 || b == 0) return a|b;
	unsigned shift = __builtin_ctzll(a|b);
	a >>= __builtin_ctzll(a);
	while (b)
	{
		b >>= __builtin_ctzll(b);
		if (a > b) swap(a, b);
		b -= a;
	}
	return a << shift;
}

int main()
{
	
	int T;
	scanf("%d", &T);
	while (T --)
	{
		ll p, q, b;
		scanf("%lld%lld%lld", &p, &q, &b);
		ll d = gcd(p, q);
		p /= d;
		q /= d;
		d = gcd(q, b);
		while (1)
		{
			// ll d = gcd(q, b);
			d = gcd(q, d);
			if (d == 1) break;
			q /= d;
		}
		if (q == 1)
			puts("Finite");
		else
			puts("Infinite");
	}
	
	
	return 0;
}