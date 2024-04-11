#include <bits/stdc++.h>
using namespace std;

const int mod = 1e9 + 7;
const int P = 1e5 + 7;

long long a[100010], w[100010], p[100010];
int s[100010];

int get(int l, int r)
{
	return ((w[r] - w[l - 1] * p[r - l + 1]) % mod + mod) % mod;
}

int n;

int LCP(int x, int y)
{
	int l = 0, r = y - x;
	while (l < r)
	{
		int mid = l + r + 1 >> 1;
		if (get(x - mid + 1, x) == get(y - mid + 1, y))
			l = mid;
		else
			r = mid - 1;
	}
	return l;
}

int LCS(int x, int y)
{
	int l = 0, r = n - y + 1;
	while (l < r)
	{
		int mid = l + r + 1 >> 1;
		if (get(x, x + mid - 1) == get(y, y + mid - 1))
			l = mid;
		else
			r = mid - 1;
	}
	return l;
}

int main()
{
	scanf("%d", &n);
	for (int i = 1; i <= n; i++)
		scanf("%d", s + i);
	p[0] = 1;
	for (int i = 1; i <= n; i++)
	{
		p[i] = p[i - 1] * P % mod;
		w[i] = (w[i - 1] * P + s[i]) % mod;
	}
	int first = 1;
	for (int l = 1; 2 * l + first - 1 <= n; l++)
	{
		int j = l + first - 1, k = 2 * l + first - 1;
		while (k <= n)
		{
			int lcp = LCP(j, k);
			if (lcp + LCS(j, k) > l)
				first = max(first, k - lcp + 1);
			j += l, k += l;
		}
	}
	printf("%d\n", n - first + 1);
	for (int i = first; i <= n; i++)
		printf("%d ", s[i]);
	puts("");
	return 0;
}