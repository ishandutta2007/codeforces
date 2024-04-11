#include <iostream>
#include <cstdio>
#include <cstring>
#define MN 4010

int f[MN][MN];
int l[MN], s[MN], c[MN];
int n, m;
int b[MN];

int main()
{
	scanf("%d%d", &n, &m);
	for(int i = 1; i <= n; i++) scanf("%d", &l[i]);
	for(int i = 1; i <= n; i++) scanf("%d", &s[i]);
	for(int i = 1; i <= n + m; i++) scanf("%d", &c[i]), c[i] += c[i - 1];
	b[0] = 0; for(int i = 1; i <= n; i++) b[i] = b[i >> 1] + 1;
	memset(f, -0x3f, sizeof(f));
	for(int i = 1; i <= m; i++) f[i][0] = 0;
	for(int i = n; i >= 1; i--)
	{
		for(int j = n - i; j >= 0; j--)
		{
			if(f[l[i]][j] < -1e9) continue;
			int len = b[(j + 1) & -(j + 1)];
			f[l[i]][j + 1] = std::max(f[l[i]][j + 1], f[l[i]][j] + c[l[i] + len - 1] - c[l[i] - 1] - s[i]);
		}
		int N = (n - i + 1) >> 1;
		for(int k = l[i] + 1; k <= m; k++, N >>= 1)
			for(int j = 0; j <= N; j++)
				f[k][j] = std::max(f[k][j], std::max(f[k - 1][j << 1], f[k - 1][j << 1 | 1]));
	}
	int ans = 0;
	for(int i = 1; i <= m; i++)
		for(int j = 0; j <= n; j++) ans = std::max(ans, f[i][j]);
	printf("%d\n", ans);
}