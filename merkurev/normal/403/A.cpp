#include <iostream>
using namespace std;


bool g[105][105];

void solve()
{
	memset(g, false, sizeof g);
	int edges = 0;

        int n, p;
	scanf("%d%d", &n, &p);
	for (int i = 0; i < n; i++)
	{
		edges += 2;
		g[i][(i + 1) % n] = true;
		g[i][(i + 2) % n] = true;
	}

	

	for (int i = 0; i < n; i++)                     
		for (int j = i + 1; j < n && edges < 2 * n + p; j++)
			if (!g[i][j] && !g[j][i] )
			{
				edges++;
				g[i][j] = true;
			}
		
	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++)
			if (g[i][j] )
				printf("%d %d\n", i + 1, j + 1);

}


int main()
{
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
	int t;
	scanf("%d", &t);
	for (int i = 0; i < t; i++)
		solve();

	return 0;
}