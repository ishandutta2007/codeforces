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

const int MAXN = 100010;

int n;
vector<int> v[MAXN];
int d[MAXN];

int main()
{
	
	n = inp();
	for (int i = 1; i < n; ++ i)
	{
		int x = inp();
		int y = inp();
		v[x].push_back(y);
		v[y].push_back(x);
		d[x] ++;
		d[y] ++;
	}
	int c = 0;
	for (int i = 1; i <= n; ++ i)
	{
		if (d[i] >= 3) c ++;
	}
	if (c >= 2)
	{
		puts("No");
		return 0;
	}
	puts("Yes");
	int r = 1;
	for (int i = 1; i <= n; ++ i)
		if (d[i] > d[r]) r = i;
	vector<int> w;
	for (int i = 1; i <= n; ++ i)
		if (d[i] == 1 && i != r)
			w.push_back(i);
	printf("%d\n", (int)w.size());
	for (auto x : w)
		printf("%d %d\n", r, x);
	
	return 0;
}