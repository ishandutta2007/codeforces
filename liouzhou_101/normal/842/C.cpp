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
	
	ull inp_ull() {
		ull x = 0; char ch;
		for(ch = getchar(); !isdigit(ch); ch = getchar());
		for(; isdigit(ch); x = x * 10 + ch - '0', ch = getchar());
		return x;
	}
	
	void inp_str(char *s)
	{
		int len = 0;
		char ch;
		for (ch = getchar(); !isdigit(ch); ch = getchar());
		for (; isdigit(ch); ch = getchar())
			s[len ++] = ch;
		s[len] = 0;
	}
	
	char B[25], *outs=B+20, *outr=B+20;
	template<class T>
	inline void print(register T a,register char x=0){
		if(x) *--outs = x, x = 0;
		
		if(!a)*--outs = '0';
		else 
			while(a)
				*--outs = (a % 10) + 48, a /= 10;
		
		fwrite(outs, outr - outs , 1, stdout);
		outs = outr;
	}
};

using io :: print;
using io :: inp;
using io :: inp_ull;

const int MAXN = 200010;
const int MOD = 1000000007;

int n;
int a[MAXN];
vector<int> v[MAXN], divisor[MAXN];
int d[MAXN], cnt[MAXN], ans[MAXN];
int dis[MAXN];

void dfs(int x, int p)
{
	for (auto y : v[x])
	{
		if (y == p) continue;
		dis[y] = dis[x]+1;
		d[y] = __gcd(d[x], a[y]);
		ans[y] = d[x];
		
		for (auto z : divisor[a[y]])
			cnt[z] ++;
		
		for (auto z : divisor[a[y]])
			if (cnt[z] >= dis[y]) ans[y] = max(ans[y], z);
		
		dfs(y, x);
		
		for (auto z : divisor[a[y]])
			cnt[z] --;
	}
}

int main()
{
	
	for (int i = 1; i <= 200000; ++ i)
		for (int j = i; j <= 200000; j += i)
			divisor[j].push_back(i);
	
	n = inp();
	for (int i = 1; i <= n; ++ i)
		a[i] = inp();
	for (int i = 1; i < n; ++ i)
	{
		int x, y;
		x = inp();
		y = inp();
		v[x].push_back(y);
		v[y].push_back(x);
	}
	d[1] = a[1];
	ans[1] = a[1];
	for (auto z : divisor[a[1]])
		cnt[z] ++;
	dfs(1, 0);
	for (int i = 1; i <= n; ++ i)
		printf("%d\n", ans[i]);
	
	return 0;
}