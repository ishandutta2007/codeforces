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

const int MAXN = 400010;

int n, d, k;
vector<int> v[MAXN];
vector<pii> ans;
int deg[MAXN], relax[MAXN];

void addedge(int x, int y)
{
	ans.emplace_back(x, y);
	v[x].push_back(y);
	v[y].push_back(x);
	deg[x] ++;
	deg[y] ++;
}

int m;

void dfs(int x, int deep)
{
	if (deep == 0) return;
	while (deg[x] < k && m < n)
	{
		int y = ++ m;
		addedge(x, y);
		dfs(y, deep-1);
	}
}

void solve()
{
	if (d > n)
	{
		puts("NO");
		return;
	}
	for (int i = 1; i <= d; ++ i)
		addedge(i, i+1);
	for (int i = 2; i <= d; ++ i)
		relax[i] = min(i-1, d-i+1);
	m = d+1;
	for (int i = 2; i <= d; ++ i)
	{
		dfs(i, relax[i]);
	}
	if (m != n)
	{
		puts("NO");
		return;
	}
	int flag = 0;
	for (int i = 1; i <= n; ++ i)
		if (deg[i] > k) flag = 1;
	if (flag)
	{
		puts("NO");
		return;
	}
	puts("YES");
	for (auto p : ans)
		printf("%d %d\n", p.X, p.Y);
}

int main()
{
	
	cin >> n >> d >> k;
	solve();
	
	return 0;
}