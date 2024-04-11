#include <bits/stdc++.h>
#define ll long long
using namespace std;
const int N = 105;
const int M = 25;
const ll mod = 1000000007;
ll a[N], b[N], times;
int y[N], n;

namespace Matrix
{
	ll c[M][M];
	void mul(ll a[M][M], ll b[M][M])
	{
		for(int i = 0; i <= 15; i ++)
			for(int j = 0; j <= 15; j ++)
				c[i][j] = 0;
		for(int i = 0; i <= 15; i ++)
			for(int j = 0; j <= 15; j ++)
				for(int k = 0; k <= 15; k ++)
					c[i][j] = (c[i][j] + a[i][k] * b[k][j]) % mod;
		for(int i = 0; i <= 15; i ++)
			for(int j = 0; j <= 15; j ++)
				a[i][j] = c[i][j];

	}
	void fff(ll a[M][M], ll b[M][M], ll times)
	{
		while (times)
		{
			if (times & 1) mul(a,b);
			times >>= 1;
			mul(b,b);
		}
	}
};

ll ans[M][M], zy[M][M];
int main()
{
	scanf("%d %lld", &n, &times);
	ans[0][0] = 1;
	for (int i = 1; i <= n; i ++)
		scanf("%lld %lld %d", &a[i], &b[i], &y[i]);
	for (int i = 1; i <= n; i ++)
	{
		for (int j = 0; j <= 15; j ++)
			for (int k = 0; k <= 15; k ++)
				zy[j][k] = 0;
		for (int j = 0; j <= y[i]; j ++) zy[j][j] ++;
		for (int j = 1; j <= y[i]; j ++) zy[j][j - 1] ++;
		for (int j = 0; j < y[i]; j ++) zy[j][j + 1] ++;
		if (times <= b[i])
		{
			Matrix::fff(ans, zy, times - a[i]);
			printf("%lld", ans[0][0]);
			return 0;
		}
		else Matrix::fff(ans, zy, b[i] - a[i]);
	}
	return 0;
}