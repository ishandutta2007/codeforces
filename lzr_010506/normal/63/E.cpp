#include <bits/stdc++.h>
using namespace std;
int dp[1 << 20];
char ch;
int sz[15] = {3,4,5,4,3,3,4,5,4,3,3,4,5,4,3};
int d[15][5] =
{
    {0, 1, 2},
    {3, 4, 5, 6},
    {7, 8, 9, 10, 11},
    {12, 13, 14, 15},
    {16, 17, 18},
    {0, 3, 7},
    {1, 4, 8, 12},
    {2, 5, 9, 13, 16},
    {6, 10, 14, 17},
    {11, 15, 18},
    {7, 12, 16},
    {3, 8, 13, 17},
    {0, 4, 9, 14, 18},
    {1, 5, 10, 15},
    {2, 6, 11},
};

bool dfs(int m)
{
	if(dp[m] != -1) return dp[m];
	for(int i = 0; i < 15; i ++)
		for(int j = 0; j < sz[i]; j ++)
			for(int k = j; k < sz[i]; k ++)
			{
				bool flag = 1;
				int pm = m;
				for(int f = j; f <= k; f ++)
					if(pm & (1 << d[i][f])) pm -= (1 << d[i][f]);
					else {flag = 0; break;}
				if(flag) if(dfs(pm) == 0) return dp[m] = 1;
			}
	return dp[m] = 0;
}
int main()
{
	int mask = 0;
	for(int i = 0; i < 19; i ++)
	{
		cin >> ch;
		if(ch == 'O') mask |= (1 << i);
	}
	memset(dp, -1, sizeof(dp));
	if(dfs(mask)) cout << "Karlsson";
	else cout << "Lillebror";
    return 0;
}