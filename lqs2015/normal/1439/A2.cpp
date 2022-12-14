#include <bits/stdc++.h>
#define Accepted 0
using namespace std;
int test, n, m, msk, cnt;
char s[111];
int mp[111][111];
struct tp
{
	int a, b, c, d, e, f;
};
vector<tp> ans;
void proc(int a, int b, int c, int d, int e, int f)
{
	mp[a][b] ^= 1;
	mp[c][d] ^= 1;
	mp[e][f] ^= 1;
	ans.push_back((tp){a, b, c, d, e, f});
}
void proc2(int a, int b, int c, int d, int e, int f)
{
	ans.push_back((tp){a, b, c, d, e, f});
}
int main()
{
	scanf("%d", &test);
	while(test--)
	{
		scanf("%d%d", &n, &m);
		for (int i = 1; i <= n; i++)
		{
			scanf("%s", s);
			for (int j = 1; j <= m; j++)
			{
				mp[i][j] = s[j-1] - '0';
			}
		}
		ans.clear();
		for (int i = 1; i <= n - 2; i++)
		{
			for (int j = 1; j <= m; j++)
			{
				if (mp[i][j])
				{
					if (j == 1)
					{
						proc(i, j, i + 1, j, i + 1, j + 1);
					}
					else
					{
						proc(i, j, i + 1, j - 1, i + 1, j);
					}
				}
			}
		}
		for (int j = 1; j <= m - 2; j++)
		{
			if (mp[n - 1][j]) proc(n - 1, j, n - 1, j + 1, n, j + 1);
			if (mp[n][j]) proc(n, j, n - 1, j + 1, n, j + 1);
		}
		cnt = mp[n - 1][m - 1] + mp[n - 1][m] + mp[n][m - 1] + mp[n][m];
		if (cnt & 1)
		{
			if (!mp[n - 1][m - 1]) proc2(n - 1, m, n, m - 1, n, m);
			if (!mp[n - 1][m]) proc2(n - 1, m - 1, n, m - 1, n, m);
			if (!mp[n][m - 1]) proc2(n - 1, m, n - 1, m - 1, n, m);
			if (!mp[n][m]) proc2(n - 1, m, n - 1, m - 1, n, m - 1);
		}
		else
		{
			if (mp[n - 1][m - 1]) proc2(n - 1, m, n, m - 1, n, m);
			if (mp[n - 1][m]) proc2(n - 1, m - 1, n, m - 1, n, m);
			if (mp[n][m - 1]) proc2(n - 1, m, n - 1, m - 1, n, m);
			if (mp[n][m]) proc2(n - 1, m, n - 1, m - 1, n, m - 1);
		}
		printf("%d\n", (int)ans.size());
		for (int i = 0; i < ans.size(); i++)
		{
			printf("%d %d %d %d %d %d\n", ans[i].a, ans[i].b, ans[i].c, ans[i].d, ans[i].e, ans[i].f);
		}
	}
	return Accepted;
}