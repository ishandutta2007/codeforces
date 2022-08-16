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

const int MAXN = 100010;
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
ld m;
ld a[MAXN], b[MAXN];

bool check(ld cost)
{
	cost += m;
	for (int i = 1; i <= n; ++ i)
	{
		cost -= cost/a[i];
		cost -= cost/b[i+1];
	}
	return cost >= m;
}

int main()
{
	
	cin >> n >> m;
	for (int i = 1; i <= n; ++ i)
		cin >> a[i];
	a[n+1] = a[1];
	for (int i = 1; i <= n; ++ i)
		cin >> b[i];
	b[n+1] = b[1];
	ld L = 0, R = 1e9;
	
	ld cost = m;
	for (int i = n; i >= 1; -- i)
	{
		if (b[i+1] == 1)
		{
			puts("-1");
			return 0;
		}
		cost = cost*b[i+1]/(b[i+1]-1);
		if (a[i] == 1)
		{
			puts("-1");
			return 0;
		}
		cost = cost*a[i]/(a[i]-1);
	}
	
	cost -= m;
	printf("%.12f\n", (double)cost);
	
	return 0;
}