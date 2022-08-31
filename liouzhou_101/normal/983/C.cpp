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

const int MAXN = 2010;
const int INF = 1000000000;

int F[2][10][5][10][10][10][10];

void fresh(int &a, int b)
{
	if (a > b) a = b;
}

int main()
{
	
	int n;
	scanf("%d", &n);
	
	for (int f = 1; f <= 9; ++ f)
	{
		F[0][f][0][0][0][0][0] = INF;
		for (int a = 1; a <= 9; ++ a)
		{
			F[0][f][1][a][0][0][0] = INF;
			for (int b = 1; b <= 9; ++ b)
			{
				F[0][f][2][a][b][0][0] = INF;
				for (int c = 1; c <= 9; ++ c)
				{
					F[0][f][3][a][b][c][0] = INF;
					for (int d = 1; d <= 9; ++ d)
						F[0][f][4][a][b][c][d] = INF;
				}
			}
		}
	}
	F[0][1][0][0][0][0][0] = 0;
	
	for (int i = 1; i <= n; ++ i)
	{
		int from, to;
		scanf("%d%d", &from, &to);
		int cur = i&1;
		int pre = cur^1;
		
		for (int f = 1; f <= 9; ++ f)
		{
			F[cur][f][0][0][0][0][0] = INF;
			for (int a = 1; a <= 9; ++ a)
			{
				F[cur][f][1][a][0][0][0] = INF;
				for (int b = 1; b <= 9; ++ b)
				{
					F[cur][f][2][a][b][0][0] = INF;
					for (int c = 1; c <= 9; ++ c)
					{
						F[cur][f][3][a][b][c][0] = INF;
						for (int d = 1; d <= 9; ++ d)
							F[cur][f][4][a][b][c][d] = INF;
					}
				}
			}
		}
		
		for (int f = 1; f <= 9; ++ f)
		{
			fresh(F[cur][from][1][to][0][0][0], F[pre][f][0][0][0][0][0]+abs(f-from)+1);
			for (int a = 1; a <= 9; ++ a)
			{
				fresh(F[cur][from][2][a][to][0][0], F[pre][f][1][a][0][0][0]+abs(f-from)+1);
				for (int b = 1; b <= 9; ++ b)
				{
					fresh(F[cur][from][3][a][b][to][0], F[pre][f][2][a][b][0][0]+abs(f-from)+1);
					for (int c = 1; c <= 9; ++ c)
					{
						fresh(F[cur][from][4][a][b][c][to], F[pre][f][3][a][b][c][0]+abs(f-from)+1);
					}
				}
			}
		}
		
		for (int f = 1; f <= 9; ++ f)
			for (int a = 1; a <= 9; ++ a)
				for (int b = 1; b <= 9; ++ b)
					for (int c = 1; c <= 9; ++ c)
						for (int d = 1; d <= 9; ++ d)
						{
							fresh(F[cur][a][3][b][c][d][0], F[cur][f][4][a][b][c][d]+abs(a-f)+1);
							fresh(F[cur][b][3][a][c][d][0], F[cur][f][4][a][b][c][d]+abs(b-f)+1);
							fresh(F[cur][c][3][a][b][d][0], F[cur][f][4][a][b][c][d]+abs(c-f)+1);
							fresh(F[cur][d][3][a][b][c][0], F[cur][f][4][a][b][c][d]+abs(d-f)+1);
						}
							
		for (int f = 1; f <= 9; ++ f)
			for (int a = 1; a <= 9; ++ a)
				for (int b = 1; b <= 9; ++ b)
					for (int c = 1; c <= 9; ++ c)
					{
						fresh(F[cur][a][2][b][c][0][0], F[cur][f][3][a][b][c][0]+abs(a-f)+1);
						fresh(F[cur][b][2][a][c][0][0], F[cur][f][3][a][b][c][0]+abs(b-f)+1);
						fresh(F[cur][c][2][a][b][0][0], F[cur][f][3][a][b][c][0]+abs(c-f)+1);
					}
		
		for (int f = 1; f <= 9; ++ f)
			for (int a = 1; a <= 9; ++ a)
				for (int b = 1; b <= 9; ++ b)
				{
					fresh(F[cur][a][1][b][0][0][0], F[cur][f][2][a][b][0][0]+abs(a-f)+1);
					fresh(F[cur][b][1][a][0][0][0], F[cur][f][2][a][b][0][0]+abs(b-f)+1);
				}
		
		for (int f = 1; f <= 9; ++ f)
			for (int a = 1; a <= 9; ++ a)
				fresh(F[cur][a][0][0][0][0][0], F[cur][f][1][a][0][0][0]+abs(a-f)+1);
	}
	
	int ans = INF;
	for (int f = 1; f <= 9; ++ f)
		ans = min(ans, F[n&1][f][0][0][0][0][0]);
	printf("%d\n", ans);
	
	return 0;
}