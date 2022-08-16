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

const int MAXN = 300010;
const int MOD = 1000000007;
const int MAXK = 20;

int node_cnt;
struct node
{
	node *son[2];
	int sum;
}tree[MAXN*MAXK];

node *nil = tree, *root;

node *new_node()
{
	node *it = &tree[++ node_cnt];
	it->son[0] = it->son[1] = nil;
	it->sum = 0;
	return it;
}

void add(int x)
{
	node *it = root;
	it->sum ++;
	for (int k = MAXK-1; k >= 0; -- k)
	{
		int s = x>>k&1;
		if (it->son[s] == nil)
			it->son[s] = new_node();
		it = it->son[s];
		it->sum ++;
	}
}

void solve(int tag)
{
	node *it = root;
	int ans = 0;
	for (int k = MAXK-1; k >= 0; -- k)
	{
		int s = tag>>k&1;
		if (it->son[s]->sum < (1<<k))
			it = it->son[s];
		else
		{
			it = it->son[s^1];
			ans |= 1<<k;
		}
	}
	printf("%d\n", ans);
}

int main()
{
	
	nil->son[0] = nil->son[1] = nil;
	nil->sum = 0;
	
	int n = inp();
	int m = inp();
	root = new_node();
	set<int> H;
	for (int i = 1; i <= n; ++ i)
	{
		int x = inp();
		H.insert(x);
	}
	for (auto x : H)
		add(x);
	int tag = 0;
	while (m --)
	{
		int x = inp();
		tag ^= x;
		solve(tag);
	}
	
	return 0;
}