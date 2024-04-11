#include <bits/stdc++.h>
using namespace std;

int main()
{
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	int t, k;
	scanf("%d%d", &t, &k);
	while (t--)
	{
		int n, m;
		scanf("%d%d", &n, &m);
		if (k == 1)
		{
			puts((n & 1) & (m & 1) ? "-" : "+");
			continue;
		}
		if (n < m)
			swap(n, m);
		int div = m / (k + 1);
		n -= (k + 1) * div, m -= (k + 1) * div;
		if (m == 0)
			puts("+");
		else
			puts((n & 1) ^ (m & 1) ^ (div & 1) ? "+" : "-");
	}
	return 0;
}