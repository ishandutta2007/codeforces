#include <cstdio>
#include <iostream>
#include <cstring>

int f[1010000][3][6];
int cnt[1010000];

int main()
{
	int n, m; scanf("%d%d", &n, &m);
	for(int i = 1; i <= n; i++)
	{
		int x; scanf("%d", &x);
		cnt[x]++;
	}
	memset(f, -0x3f, sizeof(f));
	f[0][0][0] = 0;
	for(int i = 1; i <= m; i++)
	{
		for(int j = 0; j < 5; j++)
			for(int k = 0; k < 3; k++)
			{
				for(int l = 0; l < 3; l++)
				{
					if(l > j || l > k) break;
					for(int o = 0; o < 3; o++)
					{
						if(l > cnt[i]) break;
						int lst = cnt[i] - l;
						if(o * 3 > lst) break;
						int A = j - l, B = lst % 3 + 3 * o;
						int add = l + (lst - B) / 3;
						A = std::min(A, 2); B = std::min(B, 4);
						f[i][A][B] = std::max(f[i][A][B], f[i - 1][k][j] + add); 
					}
				}
			}
	}
	int ans = 0;
	for(int j = 0; j < 5; j++)
		for(int k = 0; k < 3; k++) ans = std::max(ans, f[m][k][j]);
	printf("%d\n", ans);
}
//f[i][j][k]1~ii-1jik/