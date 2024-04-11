#include <cstdio>
#include <iostream>
#include <vector>

int n, a[1010000], c;
int f[1010000], g[1010000];
std::vector<int> v[501000];

int main()
{
	scanf("%d%d", &n, &c);
	for(int i = 1; i <= n; i++)
	{
		scanf("%d", &a[i]);
		v[a[i]].push_back(i);
	}
	for(int i = 1; i <= n; i++)
	{
		f[i] = f[i - 1] + (a[i] == c);
	}
	for(int i = n; i >= 1; i--)
	{
		g[i] = g[i + 1] + (a[i] == c);
	}
	int ans = 0;
	for(int i = 1; i <= 500000; i++)
	{
		int S = v[i].size();
		int Max = -1e9;
		for(int j = 0; j < S; j++)
		{
			Max = std::max(Max, f[v[i][j] - 1] - j);
			ans = std::max(ans, Max + j + 1 + g[v[i][j] + 1]); 
		}
	}
	printf("%d\n", ans);
	return 0;
}