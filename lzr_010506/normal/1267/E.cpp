#include <bits/stdc++.h>
#define ull unsigned long long
#define ll long long
#define il inline
#define db double
#define ls rt << 1
#define rs rt << 1 | 1
#define pb push_back
#define mp make_pair
#define pii pair<int, int>
#define X first
#define Y second
#define pcc pair<char, char>
#define vi vector<int>
#define vl vector<ll>
#define rep(i, x, y) for(int i = x; i <= y; i ++)
#define rrep(i, x, y) for(int i = x; i >= y; i --)
#define rep0(i, n) for(int i = 0; i < (n); i ++)
#define per0(i, n) for(int i = (n) - 1; i >= 0; i --)
#define ept 1e-9
#define INF 0x3f3f3f3f
#define sz(x) (x).size()
#define All(x) (x).begin(), (x).end()
using namespace std;
inline int read()
{
	int x = 0, f = 1; char ch = getchar();
	while (ch < '0' || ch > '9') { if (ch == '-') f = -1; ch = getchar(); }
	while (ch >= '0' && ch <= '9') { x = x * 10 + ch - '0'; ch = getchar(); }
	return x * f;
}
inline ll read1()
{
	ll x = 0, f = 1; char ch = getchar();
	while (ch < '0' || ch > '9') { if (ch == '-') f = -1; ch = getchar(); }
	while (ch >= '0' && ch <= '9') { x = x * 10 + ch - '0'; ch = getchar(); }
	return x * f;
}
const int N = 110;
int a[N][N];
pii c[N];
vector<int> A;
int main()
{
	int n = read();
	int m = read();
	rep(i, 1, m)
		rep(j, 1, n)
			a[j][i] = read();
	int Ans = 110;
	rep(i, 1, n - 1)
	{
		rep(j, 1, m)
			c[j].X = a[i][j] - a[n][j], c[j].Y = j;
		
		sort(c + 1, c + m + 1);
		reverse(c + 1, c + m + 1);
		//rep(j, 1, m) printf("%d %d\n", c[j].X, c[j].Y);
		int sum = 0, ans = -1;
		rep(j, 1, m)
		{
			sum += c[j].X;
			if(sum < 0) {ans = j; break;}
		}
		if(ans == -1) {printf("0"); return 0;}
		//printf("ans : %d\n", ans);
		if((m - ans + 1) < Ans) {Ans = m - ans + 1;A.clear(); rep(k, ans, m) A.pb(c[k].Y);}
	}
	if(Ans == 110) 
	{
		printf("%d\n", m);
		rep(i, 1, m) printf("%d ", i);
		return 0; 
	}
	printf("%d\n", Ans);
	rep0(i, sz(A)) printf("%d ", A[i]);

	return 0; 	
}