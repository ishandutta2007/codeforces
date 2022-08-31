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

const int MAXN = 310;

int n;
int len[MAXN], a[MAXN];
char tmp[100010];

int tot;
map<string, int> F;

int fail[MAXN];

void kmp(int *a, int m)
{
	fail[0] = 0;
	for (int i = 2; i <= m; ++ i)
	{
		int j = fail[i-1];
		while (j && a[j+1] != a[i])
			j = fail[j];
		if (a[j+1] == a[i])
			fail[i] = j+1;
		else
			fail[i] = 0;
	}
}

void kmpdeal(int *a, int m, int &p, int ch)
{
	if (p == m) p = fail[p];
	while (p && a[p+1] != ch)
		p = fail[p];
	if (a[p+1] == ch) p ++; else p = 0;
}

int main()
{
	
	scanf("%d", &n);
	for (int i = 1; i <= n; ++ i)
	{
		scanf("%s", tmp);
		len[i] = len[i-1]+strlen(tmp);
		int &c = F[tmp];
		if (c == 0)
			c = ++ tot;
		a[i] = c;
	}
	
	int ans = len[n]+n-1;
	
	for (int i = 1; i <= n; ++ i)
		for (int j = i; j <= n; ++ j)
		{
			kmp(a+i-1, j-i+1);
			int p = 0;
			int cnt = 0;
			for (int k = 1; k <= n; ++ k)
			{
				kmpdeal(a+i-1, j-i+1, p, a[k]);
				if (p == j-i+1)
				{
					++ cnt;
					p = 0;
				}
			}
			if (cnt < 2) continue;
			int cur = n-cnt*(j-i+1)+cnt-1;
			cur += len[n]-cnt*(len[j]-len[i-1])+cnt*(j-i+1);
			ans = min(ans, cur);
		}
	
	cout << ans << endl;
	
	return 0;
}