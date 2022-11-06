#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
#define MN 2010000

int n, m1, m2, t;
int f[MN][2], g[MN][2], a[MN][2], used[MN][2];
int b[MN], Ans[MN], Ansx[MN], Ansy[MN], o1 = 0, o2 = 0;

int main()
{
	scanf("%d%d%d%d", &n, &m1, &m2, &t);
	int N = 0;
	for(int i = 1; i <= m1; i++)
	{
		scanf("%d", &a[i][0]);
		b[++N] = a[i][0]; b[++N] = a[i][0] + 1;
	}
	for(int i = 1; i <= m2; i++)
	{
		scanf("%d", &a[i][1]);
		b[++N] = a[i][1]; b[++N] = a[i][1] + 1;
	}
	std::sort(b + 1, b + N + 1); N = std::unique(b + 1, b + N + 1) - b - 1;
	for(int i = 1; i <= m1; i++)
	{
		a[i][0] = std::lower_bound(b + 1, b + N + 1, a[i][0]) - b;
		used[a[i][0]][0] = 1;
	}
	for(int i = 1; i <= m2; i++)
	{
		a[i][1] = std::lower_bound(b + 1, b + N + 1, a[i][1]) - b;
		used[a[i][1]][1] = 1;
	}
	memset(f, -0x3f, sizeof(f)); f[0][0] = 0; 
	for(int i = 1; i <= N; i++)
	{
		for(int j = 0; j <= 1; j++)
		{
			int v = f[i - 1][j] + b[i] - b[i - 1] - 1 - used[i][j] * t;
			if(v >= 0) f[i][j] = v + 1;
			
			v = std::min(t, f[i - 1][j ^ 1]) + b[i] - b[i - 1] - 1 - used[i][j] * t;
			if(!used[i - 1][j] && v >= 0)
			{
				if(v + 1 >= f[i][j]) f[i][j] = v + 1, g[i][j] = 1;
			}
		}
	}
	if(f[N][0] >= 0 || f[N][1] >= 0) puts("Yes");
	else return 0 * puts("No");
	int j = f[N][0] >= 0 ? 0 : 1;
	int lst = N;
	for(int i = N; i >= 1; i--)
	{
		if(g[i][j])
		{
			Ans[++o1] = b[i - 1];
			int cnt = 0;
			for(int k = i - 1; k <= lst; k++) if(used[k][j]) cnt++;
			for(int k = cnt; k >= 1; k--) ++o2, Ansx[o2] = t - std::min(t, f[i - 1][j ^ 1]) + (k - 1) * t + b[i - 1], Ansy[o2] = j;
			j ^= 1; lst = i - 1;
		}
	}
	int cnt = 0;
	for(int k = 1; k <= lst; k++) if(used[k][j]) cnt++;
	for(int k = cnt; k >= 1; k--) ++o2, Ansx[o2] = k * t, Ansy[o2] = j;
	printf("%d\n", o1);
	for(int i = o1; i >= 1; i--) printf("%d ", Ans[i]); puts("");
	printf("%d\n", o2);
	for(int i = o2; i >= 1; i--) printf("%d %d\n", Ansx[i], Ansy[i] + 1);
}