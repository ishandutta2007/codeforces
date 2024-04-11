#include <iostream>
#include <vector>
using namespace std;


int dp[2005][2005];

vector <int> g[2005];
const int mod = (int)1e9 + 7;

void add(int &a, int b)
{
	a += b;
	if (a >= mod)
		a -= mod;
}


int main()
{
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
	int n, k;
	scanf("%d%d", &n, &k);

	for (int i = 1; i <= n; i++)
		for (int j = i; j <= n; j += i)
		{
			g[i].push_back(j);
		}
	dp[0][1] = 1;
	for (int i = 0; i < k; i++)
	{
		for (int x = 1; x <= n; x++)
			for (int j = 0; j < g[x].size(); j++)
			{
				int nx = g[x][j];
				add(dp[i + 1][nx], dp[i][x] );
			}
	}
	int ans = 0;
	for (int x = 1; x <= n; x++)
		add(ans, dp[k][x] );
	printf("%d\n", ans);


	return 0;	                      
}