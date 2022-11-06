#include <cstdio>
#include <iostream>
#include <algorithm>

int q[101000], h = 0, t = 0;
int a[101000], cnt[101000];
int ans[101000][2], tot = 0;

int main()
{
	int n; scanf("%d", &n);
	for(int i = 1; i < n; i++)
	{
		int b, c; scanf("%d%d", &b, &c);
		if(b == n) cnt[c]++;
		else if(c == n) cnt[b]++;
		else return 0 * puts("NO");
		if(b == n && c == n) return 0 * puts("NO");
	}
	std::sort(a + 1, a + n + 1);
	for(int i = 1; i < n; i++)
	{
		if(cnt[i] == 0) q[t++] = i;
		else
		{
			int lst = n;
			for(int j = 1; j < cnt[i]; j++)
			{
				if(h < t)
				{
					++tot; ans[tot][0] = lst; ans[tot][1] = q[h];
					lst = q[h]; h++;
				}
				else return 0 * puts("NO");
			}
			++tot; ans[tot][0] = lst; ans[tot][1] = i;
		}
	}
	puts("YES");
	for(int i = 1; i <= tot; i++) printf("%d %d\n", ans[i][0], ans[i][1]);
	return 0;
}