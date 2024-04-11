#include <bits/stdc++.h>
using namespace std;
typedef double db;
typedef long long ll;
const ll mod=1000000007;
const db eps=1e-9;
const db pi=acos(-1);
ll powmod(ll a,ll b)
{
	ll res = 1; a %= mod;
	for(;b;b>>=1)
	{
		if(b & 1) res = res * a % mod;
		a = a * a % mod;
	}
	return res;
}

const int N = 100;
const int M = 1000;

db dp[N + 1][N * M + 5];
int n, m;
int a[N + 5];
inline int read()
{
	int x = 0, f = 1; char ch = getchar();
	while (ch < '0' || ch > '9') { if (ch == '-') f = -1; ch = getchar(); }
	while (ch >= '0' && ch <= '9') { x = x * 10 + ch - '0'; ch = getchar(); }
	return x * f;
}

int main()
{
	n = read();
	m = read();
	if(m == 1)
	{
		puts("1.000000000000000");
		return 0;
	}
	for(int i = 1; i <= n; i ++) a[i] = read();
	memset(dp, 0, sizeof dp);
	dp[0][0] = m - 1;
	for(int i = 1; i <= n; i ++)
	{
		db sum = 0;
		for(int j = 0; j <= n * m; j ++)
		{
			if(j - a[i] >= 0) dp[i][j] = (sum - dp[i - 1][j - a[i]]) / (m - 1);
			else dp[i][j] = sum / (m - 1);
			if(j - m >= 0) sum -= dp[i - 1][j - m];
			sum += dp[i - 1][j];
		}
	}
	db ans = 1;
	int tot = 0;
	for(int i = 1; i <= n; i ++) tot += a[i];
	for(int i = 0; i < tot; i ++) ans += dp[n][i];
	printf("%.15lf\n", ans);
	return 0;
}