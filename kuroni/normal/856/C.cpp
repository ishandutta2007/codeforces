#include <iostream>
#include <cstdio>
#include <cstring>
#include <vector>
using namespace std;

const int mod = 998244353;
int t, n, i, j, k, x, y, tmp;
vector <int> a[2];
long long f[2][2005][11], ans;

bool dgc(int x)
{
	bool ev = 0;
	do
	{
		x /= 10;
		ev ^= 1;
	}	while (x != 0);
	return ev;
}

int main()
{
	scanf("%d", &t);
	while (t--)
	{
		memset(f, 0, sizeof(f)); f[0][0][0] = 1; ans = 0;
		scanf("%d", &n);
		for (i = 1; i <= n; i++)
		{
			scanf("%d", &x);
			a[dgc(x)].push_back(x % 11);
		}
		if (a[1].empty())
		{
			ans = 1; x = 0;
			for (i = 1; i <= n; i++)
			{
				ans = ans * i % mod;
				x += a[0].back();
				a[0].pop_back();
			}
			printf("%I64d\n", ans * (x % 11 == 0));
			continue;
		}
		x = a[1].size(); y = k = 0;
		while (!a[1].empty())
		{
			++y; k ^= 1; tmp = a[1].back(); a[1].pop_back();
			for (i = max(0, y - (x + 1) / 2); i <= min(x / 2, y); i++)
				for (j = 0; j < 11; j++)
					f[k][i][j] = (((i == 0) ? 0LL : f[k ^ 1][i - 1][(j + tmp) % 11] * (x / 2 - i + 1))
								+ f[k ^ 1][i][(11 + j - tmp) % 11] * ((x + 1) / 2 - y + 1 + i)) % mod;
		}
		while (!a[0].empty())
		{
			++y; k ^= 1; tmp = a[0].back(); a[0].pop_back();
			for (i = x / 2; i <= y - (x + 1) / 2; i++)
				for (j = 0; j < 11; j++)
					f[k][i][j] = (((i == x / 2) ? 0LL : f[k ^ 1][i - 1][(j + tmp) % 11] * (i - 1 - x / 2 + (x + 1) / 2))
								+ f[k ^ 1][i][(11 + j - tmp) % 11] * (y - i + x / 2 - (x + 1) / 2)) % mod;
		}
		for (i = x / 2; i <= y - (x + 1) / 2; i++)
			ans += f[k][i][0];
		printf("%I64d\n", ans % mod );
	}
}