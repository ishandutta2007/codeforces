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

const int MAXN = 55;

int n, k;
ll a[MAXN];
int to[MAXN][MAXN], F[MAXN][MAXN];

bool check(ll m)
{
	for (int i = 1; i <= n; ++ i)
		for (int j = i; j <= n; ++ j)
		{
			if (((a[j]-a[i-1])&m) == m)
				to[i][j] = 1;
			else
				to[i][j] = 0;
		}
	F[0][0] = 1;
	for (int k = 1; k <= n; ++ k)
		for (int i = 1; i <= n; ++ i)
		{
			F[k][i] = 0;
			for (int j = 1; j <= i; ++ j)
				if (F[k-1][j-1] && to[j][i]) F[k][i] = 1;
		}
	return F[k][n];
}

int main()
{
	
	scanf("%d%d", &n, &k);
	for (int i = 1; i <= n; ++ i)
	{
		scanf("%lld", &a[i]);
		a[i] += a[i-1];
	}
	ll ans = 0;
	for (int k = 56; k >= 0; -- k)
	{
		if (check(ans|(1LL<<k)))
			ans |= 1LL<<k;
	}
	cout << ans << endl;
	
	return 0;
}