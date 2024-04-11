#include <bits/stdc++.h>
using namespace std;
int n, u, v, cnt[1005], tot;
int main()
{
#ifdef _noname
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
	memset(cnt, 0, sizeof cnt);
	tot = 0;
	scanf("%d", &n);
	for (int i = 1; i < n; i++)
	{
		scanf("%d%d", &u, &v);
		cnt[u]++, cnt[v]++;
	}
	for (int i = 1; i <= n; i++) tot += (cnt[i] == 1);
	printf("%d\n", tot);
	return 0;
}