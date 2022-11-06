#include <cstdio>
#include <iostream>
#include <algorithm>

int a[555], b[555];
int f[555][555];
long long sa = 0, sb = 0;
int s[555];

int main()
{
	int n, k; scanf("%d%d", &n, &k);
	for(int i = 1; i <= n; i++)
		scanf("%d%d", &a[i], &b[i]), sa += a[i], sb += b[i];
	if((sa + sb) / k == sa / k + sb / k) return 0 * printf("%lld\n", (sa + sb) / k);
	f[0][0] = 1;
	for(int i = 1; i <= n; i++)
	{
		s[0] = 1;
		for(int j = 1; j < k; j++) s[j] = s[j - 1] + f[i - 1][j];
		for(int j = 0; j < k; j++)
		{
			int l = std::max(0, k - b[i]), r = std::min(a[i], k - 1);
			f[i][j] = f[i - 1][j];
			if(l > r || f[i][j]) continue;
			int ll = (j - r + k) % k, rr = (j - l + k) % k;
			l = ll, r = rr;
			if(l > r) f[i][j] = std::min(1, s[k - 1] - s[l - 1] + s[r]);
			else f[i][j] = std::min(1, s[r] - (l == 0 ? 0 : s[l - 1]));
		}
	}
	for(int j = 0; j < k; j++)
	{
		if(f[n][j] && j <= sa % k && k - j <= sb % k) return 0 * printf("%lld\n", (sa + sb) / k);
	}
	return 0 * printf("%lld\n", sa / k + sb / k);
}