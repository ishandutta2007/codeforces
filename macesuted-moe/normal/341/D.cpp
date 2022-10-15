#include <bits/stdc++.h>
using namespace std;

const int maxn = 1005;

long long tree[maxn][maxn][2][2];
int n;

void add(int x, int y, long long val)
{
	for (int i = x; i <= n; i += i & -i)
		for (int j = y; j <= n; j += j & -j)
			tree[i][j][x & 1][y & 1] ^= val;
}

long long sum(int x, int y)
{
	long long sum = 0;
	for (int i = x; i; i -= i & -i)
		for (int j = y; j; j -= j & -j)
			sum ^= tree[i][j][x & 1][y & 1];
	return sum;
}

int main()
{
	int m;
	scanf("%d%d", &n, &m);
	while (m--)
	{
		int cmd, x1, y1, x2, y2, w;
		scanf("%d%d%d%d%d", &cmd, &x1, &y1, &x2, &y2);
		if (cmd == 1)
			printf("%lld\n", sum(x2, y2) ^ sum(x2, y1 - 1) ^ sum(x1 - 1, y2) ^ sum(x1 - 1, y1 - 1));
		else
		{
			scanf("%d", &w);
			add(x1, y1, w);
			add(x1, y2 + 1, w);
			add(x2 + 1, y1, w);
			add(x2 + 1, y2 + 1, w);
		}
	}
	return 0;
}