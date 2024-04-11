#include <cstdio>
#include <algorithm>
#include <vector>
#define MN 1010000

char s[MN];
int n, m;
std::vector<int> sum[MN], c[MN];
std::vector<char> v[MN], ans[MN];

bool check(int t)
{
	for(int i = 1; i <= n; i++)
		for(int j = 1; j <= m; j++)
			c[i][j] = 0, ans[i][j] = '.';
			
	for(int i = t + 1; i <= n - t; i++)
		for(int j = t + 1; j <= m - t; j++)
		{
			if(sum[i + t][j + t] - sum[i - t - 1][j + t] - sum[i + t][j - t - 1] + sum[i - t - 1][j - t - 1] == (2 * t + 1) * (2 * t + 1))
			{
				c[i - t][j - t]++;
				if(i + t + 1 <= n) c[i + t + 1][j - t]--;
				if(j + t + 1 <= m) c[i - t][j + t + 1]--;
				if(i + t + 1 <= n && j + t + 1 <= m) c[i + t + 1][j + t + 1]++;
				ans[i][j] = 'X';
			}
		}
		
	for(int i = 1; i <= n; i++)
		for(int j = 1; j <= m; j++)
		{
			c[i][j] = c[i - 1][j] + c[i][j - 1] - c[i - 1][j - 1] + c[i][j];
			if(!c[i][j] && v[i][j] == 'X') return 0;
		}
	return 1;
}

int main()
{
	scanf("%d%d", &n, &m);
	for(int i = 0; i <= n; i++)
		for(int j = 0; j <= m; j++) sum[i].push_back(0);
	for(int i = 0; i <= n; i++)
		for(int j = 0; j <= m; j++) c[i].push_back(0);
	for(int i = 0; i <= n; i++)
		for(int j = 0; j <= m; j++) v[i].push_back('.');
	for(int i = 0; i <= n; i++)
		for(int j = 0; j <= m; j++) ans[i].push_back('.');
	for(int i = 1; i <= n; i++)
	{
		scanf("%s", s + 1);
		for(int j = 1; j <= m; j++) 
			v[i][j] = s[j];
	}
	
	for(int i = 1; i <= n; i++)
		for(int j = 1; j <= m; j++)
			sum[i][j] = sum[i - 1][j] + sum[i][j - 1] - sum[i - 1][j - 1] + (v[i][j] == 'X'); 
			
	int l = 1, r = 1e6;
	while(l < r)
	{
		int mid = l + r >> 1;
		if(check(mid)) l = mid + 1;
		else r = mid;
	}
	check(l - 1); printf("%d\n", l - 1);
	for(int i = 1; i <= n; i++, puts(""))
		for(int j = 1; j <= m; j++)
			printf("%c", ans[i][j]);
}