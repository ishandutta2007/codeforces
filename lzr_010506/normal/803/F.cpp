#include <bits/stdc++.h>
using namespace std;
const int MOD = 1000000007;
int N, a[100010], p[100010], m[100010], pr[100010], v, u[100010], O;
int main()
{
	scanf("%d", &N);
	for (int i = 1, x; i <= N; i ++)
	{
		scanf("%d", &x);
		a[x] ++;
	}
	u[1] = 1;
	for (int i = 2; i <= 100000; i ++)
	{
		if (!m[i])
		{
			pr[++ v] = m[i] = i;
			u[i] = -1;
		}
		for (int j = 1; j <= v && pr[j] * i <= 100000 && pr[j] <= m[i]; j++)
		{
			m[pr[j] * i] = pr[j];
			u[pr[j] * i] = pr[j] == m[i] ? 0 : -u[i];
		}
	}
	for (int i = 1; i <= 100000; i ++)
		if ((p[i] = p[i - 1] << 1 | 1) >= MOD)
			p[i] -= MOD;
	for (int i = 1; i <= 100000; i++)
	{
		int s = 0;
		for (int j = i; j <= 100000; j += i)
			s += a[j];
		O += p[s] * u[i];
		if (O >= MOD) O -= MOD;
		if (O < 0) O += MOD;
	}
	printf("%d\n", O);
	return 0;
}