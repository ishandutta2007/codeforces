#include <bits/stdc++.h>
#define rep(i,  x,  y) for(int i = x; i <= y; i ++)
#define rrep(i, x,  y) for(int i = x; i >= y; i --)
#define ll long long
//#define X fisrt
#define Y second
#define pb push_back
//#define mp make_pair
#define ls rt << 1
#define rs rt << 1 | 1
#define INF 0x3f3f3f3f
#define pll pair<ll, ll>
#define db double
using namespace std;
inline int read()
{
	int x = 0, f = 1; char ch = getchar();
	while (ch < '0' || ch > '9') { if (ch == '-') f = -1; ch = getchar(); }
	while (ch >= '0' && ch <= '9') { x = x * 10 + ch - '0'; ch = getchar(); }
	return x * f;
}
using namespace std;
const int N = 200010;
const int M = 60;
const int P = 110;
const int inf = 1000000000;

int n,p,ans,m;
int dp[M][N],a[N],b[P],c[P];

int main()
{
	n = read();
	m = read();
	p = read();
	rep(i, 1, n) a[i] = read(), a[i] %= p;
	rep(i, 1, m)
		rep(j, 1, n)
			dp[i][j] = -inf;
	rep(i, 1, n) dp[1][i] = (dp[1][i - 1] + a[i]) % p;
	rep(i, 2, m)
	{
		b[0] = 0;
		rep(j, 1, p - 1) b[j] = -inf;
		rep(j, 1, n)
		{
			rep(k, 0, p - 1) c[k] = -inf;
			rep(k, 0, p - 1) c[(k + a[j]) % p] = max(c[(k + a[j]) % p], b[k]);
			rep(k, 0, p - 1) b[k] = c[k];
			rep(k, 0, p - 1)
				if (b[k] != -inf)
					dp[i][j] = max(dp[i][j], b[k] + k);
			if (dp[i][j] != inf) b[0] = max(b[0], dp[i - 1][j]);
		}
	}
	printf("%d",dp[m][n]);
	return 0;
}