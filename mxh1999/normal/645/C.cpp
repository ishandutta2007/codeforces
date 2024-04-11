#include <bits/stdc++.h>
using namespace std;
int k, n, f[100005] = {0}, ans = 100000, x;
char c[100005] = {'\0'};
int main()
{
	scanf("%d%d", &n, &k);
	scanf("%s", c);
	for (int i = 0; c[i]; i++)
		if (c[i] == '0')
			f[++f[0]] = i;
	if (k == 1)
	{
		for (int i = 1; i < f[0]; i++) ans = min(ans, f[i + 1] - f[i]);
		printf("%d\n", ans);
		return 0;
	}
	int l = 1, r = k + 1;
	while (r <= f[0])
	{
		x = lower_bound(f + 1, f + f[0] + 1, (f[l] + f[r]) >> 1) - f;
		if (x == l) x++;
		if (x == r) x--;
		ans = min(ans, max(f[r] - f[x], f[x] - f[l]));
		x = upper_bound(f + 1, f + f[0] + 1, (f[l] + f[r]) >> 1) - f;
		if (x == l) x++;
		if (x == r) x--;
		ans = min(ans, max(f[r] - f[x], f[x] - f[l]));
		x = lower_bound(f + 1, f + f[0] + 1, (f[l] + f[r]) >> 1) - f;
		if (x!=1)	x--;
		if (x == l) x++;
		if (x == r) x--;
		ans = min(ans, max(f[r] - f[x], f[x] - f[l]));
		l++, r++;
	}
	printf("%d\n", ans);
	return 0;
}