#include <bits/stdc++.h>
using namespace std;
int n, dp[1100][1 << 8], f[1100][1100 / 8][8], a[1100];
int func(int Mid)
{
	int ans = -1;
	for (int i = 0; i <= n; i ++)
		for (int j = 1; j < 1 << 8; j ++)
			dp[i][j] = 0x80000000;
	for (int i = 1; i <= n; i ++)
    {
		for (int j = 1; j < 1 << 8; j ++)
			for (int k = 0; k < 8; k ++)
				if ((1 << k) & j)
				{
					int N1 = f[i][Mid][k];
					int N2 = f[i][Mid + 1][k];
					if (~N1) dp[i][j] = max(dp[i][j], dp[N1 - 1][j ^ (1 << k)] + Mid);
					if (~N2) dp[i][j] = max(dp[i][j], dp[N2 - 1][j ^ (1 << k)] + Mid + 1);
				}
		if (dp[i][(1 << 8) - 1] >= 0)
			ans = max(ans, dp[i][(1 << 8) - 1]);
	}
	return ans;
}

bool Pd(int Mid)
{
	return func(Mid) >= 0;
}

int main()
{
	cin >> n;
	for (int i = 1; i <= n; i ++)
	{
		cin >> a[i];
		a[i] --;
	}

	memset(f, -1, sizeof f);

	for (int i = 1; i <= n; i ++)
		for (int j = 0; j < 8; j ++)
        {
			int now = 0;
			f[i][0][j] = i + 1;
			for (int k = i; k >= 1; k --)
				if (a[k] == j && now < (1100 / 8) - 1)
                {
					now += 1;
					f[i][now][j] = k;
				}
		}

	int L = 0, R = n / 8;
	while (L != R)
    {
		int mid = (L + R + 1) >> 1;
		if(Pd(mid)) L = mid;
        else R = mid - 1;
	}
	cout << func( (L + R) >> 1 );
	return 0;
}