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
#define ALL(x) (x).begin(), (x).end()
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
const int N = 333;
int n,a[N][N],d[N][N],b[5],e[5];
char c[N];
string s=".XO";
int main()
{
	int T = read();
	while (T --) 
	{
		scanf("%d", &n);
		rep(i, 1, n)
		{
			scanf("%s", c + 1);
			rep(j, 1, n)
			{
				a[i][j] = c[j] == 'X';
				d[i][j] = c[j] == 'O';
			}
		}
		rep0(i, 3) b[i] = 0, e[i] = 0;
		rep(i, 1, n)
			rep(j, 1, n)
				b[(i + j) % 3] += a[i][j], e[(i + j) % 3] += d[i][j];
		int o = 0;
		rep0(i, 3)
			if (b[i] + e[(i + 1) % 3] < b[o] + e[(o + 1) % 3])
				o = i;
		rep(i, 1, n)
			rep(j, 1, n)
			{
				if (a[i][j] && (i + j) % 3 == o) a[i][j] = 2;
				if (d[i][j] && (i + j) % 3 == (o + 1) % 3) d[i][j] = 2;
			}
		rep(i, 1, n)
		{
			rep(j, 1, n)
				printf("%c", s[(a[i][j] - d[i][j] + 3) % 3]);
			puts("");
		}
	}

	return 0;
}