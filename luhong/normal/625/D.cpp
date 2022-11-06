#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
#define MN 101000

char s[MN];
bool f[MN][2][2];
int g[MN][2][2], ga[MN][2][2], gb[MN][2][2];
char ans[MN];

bool solve(int n)
{
	for(int i = 1; i <= n / 2; i++)
	{
		for(int j = 0; j <= 18; j++)
		{
			if(i == 1 && j == 0) continue;
			for(int A = 0; A <= 1; A++)
				for(int B = 0; B <= 1; B++)
				{
					if(!f[i - 1][A][B]) continue;
					int a = A * 10 + s[n - i + 1] - '0' - j;
					int b = (j + B) / 10;
					if(a < 0 || a > 1 || s[i] - '0' + b * 10 != j + B) continue;
					f[i][a][b] = 1;	g[i][a][b] = j; ga[i][a][b] = A; gb[i][a][b] = B;
				}
		}
	}
	for(int A = 0; A <= 1; A++)
		for(int B = 0; B <= 1; B++)
		{
			if(f[n / 2][A][B])
			{
				bool ok = 0;
				if(n & 1)
				{
					if(!((s[n / 2 + 1] - '0' - B) & 1))
					{
						ans[n / 2 + 1] = (s[n / 2 + 1] - '0' - B + A * 10) / 2 + '0';
						ok = 1;
					}
				}
				else
				{
					if(A == B) ok = 1;
				}
				if(ok)
				{
					int a = A, b = B;
					for(int i = n / 2; i >= 1; i--)
					{
						int j = g[i][a][b];
						ans[i] = j / 2 + '0'; ans[n - i + 1] = j - j / 2 + '0';
						int aa = a, bb = b;
						a = ga[i][aa][bb], b = gb[i][aa][bb];
					}
					std::reverse(ans + 1, ans + n + 1);
					return 1;
				}
			}
		}
	return 0;
}

int main()
{
	scanf("%s", s + 1); int n = strlen(s + 1);
	std::reverse(s + 1, s + n + 1);
	f[0][0][0] = 1;
	if(solve(n)) return 0 * printf("%s", ans + 1);
	memset(f, 0, sizeof(f));
	if(s[n] - '0' == 1)
	{
		f[0][1][0] = 1;
		if(solve(n - 1)) return 0 * printf("%s", ans + 1);
	}
	puts("0");
}