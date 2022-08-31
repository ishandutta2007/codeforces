#include <bits/stdc++.h>

using namespace std;

typedef unsigned long long ll;
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

const int MAXN = 100010;
const int MAXK = 17;

struct node
{
	node *son[2];
	int /*cnt, */minv;
};

node *nil = new node();

node *new_node()
{
	node *it = new node();
	it->son[0] = it->son[1] = nil;
	it->minv = MAXN;
	//it->cnt = 0;
	return it;
}

node *v[MAXN];

void add(int i, int u)
{
	if (v[i] == nil)
		v[i] = new_node();
	node *r = v[i];
	for (int k = MAXK-1; k >= 0; -- k)
	{
		int x = (u>>k)&1;
		//r->cnt ++;
		r->minv = min(r->minv, u);
		if (r->son[x] == nil)
			r->son[x] = new_node();
		r = r->son[x];
	}
	//r->cnt ++;
	r->minv = u;
}

void add(int u)
{
	for (int i = 1; i*i <= u; ++ i)
		if (u%i == 0)
		{
			add(i, u);
			if (i*i != u) add(u/i, u);
		}
}

void solve(int x, int kk, int s)
{
	if (x%kk != 0)
	{
		puts("-1");
		return;
	}
	if (s-x <= 0)
	{
		puts("-1");
		return;
	}
	s -= x;
	
	node *r = v[kk];
	int cur = 0;
	for (int k = MAXK-1; k >= 0; -- k)
	{
		int c = ((x>>k)&1)^1;
		if (cur+(c<<k) <= s /*&& r->son[c]->cnt >= 1*/ && r->son[c]->minv <= s)
		{
			cur += c<<k;
			r = r->son[c];
		}
		else if (cur+((c^1)<<k) <= s /*&& r->son[c^1]->cnt >= 1*/ && r->son[c^1]->minv <= s)
		{
			cur += (c^1)<<k;
			r = r->son[c^1];
		}
		else
		{
			puts("-1");
			return;
		}
	}
	/*
	if (r->cnt == 0)
		puts("-1");
	else*/
		printf("%d\n", cur);
}

int main()
{
	
	nil->son[0] = nil->son[1] = nil;
	//nil->cnt = 0;
	nil->minv = MAXN;
	
	for (int i = 1; i <= 100000; ++ i)
		v[i] = nil;
	
	int q = inp();
	while (q --)
	{
		int t = inp();
		if (t == 1)
		{
			int u = inp();
			add(u);
		}
		else
		{
			int x = inp();
			int k = inp();
			int s = inp();
			solve(x, k, s);
		}
	}
	
	return 0;
}