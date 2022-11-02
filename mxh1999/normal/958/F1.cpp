#include <bits/stdc++.h>
using namespace std;
int n, m, k[105], to[105], cnt[105], tot;
bool chk()
{
	for (int i = 1; i <= m; i++)
		if (cnt[i] != to[i])
			return false;
	return true;
}
int main()
{
#ifdef _noname
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
	memset(cnt, 0, sizeof cnt);
	tot = 0;
	scanf("%d%d", &n, &m);
	for (int i = 1; i <= n; i++) scanf("%d", k + i);
	for (int i = 1; i <= m; i++)
	{
		scanf("%d", to + i);
		tot += to[i];
	}
	for (int i = 1; i <= tot; i++) cnt[k[i]]++;
	if (chk()) {puts("YES"); return 0;}
	for (int i = 1, j = i + tot; j <= n; i++, j++)
	{
		cnt[k[i]]--, cnt[k[j]]++;
		if (chk())
		{
			puts("YES");
			return 0;
		}
	}
	puts("NO");
	return 0;
}