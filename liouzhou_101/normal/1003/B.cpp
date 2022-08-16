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

string solve(int a, int b, int x) // a > b
{
	string s = "0";
	a --;
	for (int i = 0; i < x; ++ i)
	{
		if (i%2 == 0)
		{
			s += '1';
			b --;
		}
		else
		{
			s += '0';
			a --;
		}
	}
	string t;
	for (auto c : s)
	{
		t += c;
		if (c == '0' && a > 0)
		{
			for (int i = 0; i < a; ++ i)
				t += c;
			a = 0;
		}
		if (c == '1' && b > 0)
		{
			for (int i = 0; i < b; ++ i)
				t += c;
			b = 0;
		}
	}
	return t;
}

int main()
{
	
	int a, b, x;
	cin >> a >> b >> x;
	string s;
	if (a > b)
		s = solve(a, b, x);
	else
	{
		s = solve(b, a, x);
		for (auto &c : s)
			if (c == '0') c = '1'; else c = '0';
	}
	cout << s << endl;
	
	return 0;
}