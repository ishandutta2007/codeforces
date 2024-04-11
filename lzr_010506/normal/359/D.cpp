#include <bits/stdc++.h>
using namespace std;
const int N = 300010;
int a[N], dp[N][21], Dp[N][21], l[N], ans, n;
bool ok[N];
inline int read()
{
	int x = 0, f = 1; char ch = getchar();
	while (ch < '0' || ch > '9') { if (ch == '-') f = -1; ch = getchar(); }
	while (ch >= '0' && ch <= '9') { x = x * 10 + ch - '0'; ch = getchar(); }
	return x * f;
}

int gcd(int a, int b)
{
	while(a)
	{
		int c = a;
		a = b % a;
		b = c;
	}
	return b;
}

int Query(int a,int b)
{
	if(a == b) return Dp[a][0];
	int k = l[b - a + 1];
	return min(Dp[a][k], Dp[b - (1 << k) + 1][k]);
}

int Query2(int a, int b)
{
	if(a == b) return dp[a][0];
	int k = l[b - a + 1];
	return gcd(dp[a][k], dp[b - (1 << k) + 1][k]);
}

bool check(int x)
{
	bool flag = 0;
	ans = 0;
	for(int i = 1; i + x - 1 <= n; i ++)
	{
		int j = i + x - 1;
		if(Query(i, j) == Query2(i, j)) flag = 1, ok[i] = 1, ans ++;
		else ok[i] = 0;
	}
	return flag;
}
int main()
{
	n = read();
	for(int i = 1; i <= n; i ++)
		a[i] = read();
	for(int i = 1; i <= n; i ++)
		dp[i][0] = a[i], Dp[i][0] = a[i];

	for(int j = 1; j <= 20; j ++)
		for(int i = 1; i <= n; i ++)
		{
			int a = i + (1 << j - 1);
			if(a > n)
			{
				dp[i][j] = dp[i - 1][j];
				Dp[i][j] = Dp[i - 1][j];
			}
			else
			{
				dp[i][j] = gcd(dp[i][j - 1], dp[a][j - 1]);
				Dp[i][j] = min(Dp[i][j - 1], Dp[a][j - 1]);
			}
		}
	int k = 0;
	for(int i = 1; i <= n; i ++)
	{
		if((1 << k) < i) k ++;
		l[i] = k - 1;
	}
	memset(ok, 0, sizeof(ok));
	int l = 1, r = n;
	while(l != r)
	{
		int mid = (l + r) >> 1;
		mid ++;
		if(check(mid)) l = mid;
		else r = mid - 1;
	}
	check(l);
	cout << ans << " " << l - 1 << endl;
	for(int i = 1; i + l - 1 <= n; i ++)
		if(ok[i])printf("%d ",i);
	return 0;
}