#include<iostream>
#include<cmath>
#include<fstream>
#include<vector>
#include<set>
#include<map>
using namespace std;
int main()
{
	string s;
	cin >> s;
	int dp[10][10][10][10];
	for(int x = 0; x < 10; x++)
	{
		for(int y = 0; y < 10; y++)
		{
			for(int a = 0; a < 10; a++)
			{
				for(int b = 0; b < 10; b++)
				{
					dp[x][y][a][b] = 1e9;
					for(int t = 0; t < 10; t++)
					{
						for(int t1 = 0; t1 < 10; t1++)
						{
							if(t + t1 != 0 && (a + t * x + t1 * y) % 10 == b)
							{
								dp[x][y][a][b] = min(t + t1, dp[x][y][a][b]);
								break;
							}
						}
					}
				}
			}
		}
	}
	for(int x = 0; x < 10; x++)
	{
		for(int y = 0; y < 10; y++)
		{
			int ans = 0;
			for(int i = 1; i < s.size(); i++)
			{
				int a = s[i - 1] - '0';
				int b = s[i] - '0';
				if(dp[x][y][a][b] == 1e9)
				{
					ans = -1;
					break;
				}
				else
				{
					ans += dp[x][y][a][b];
				}
			}
			if(ans != -1)
			{
				ans -= int(s.size()) - 1;
			}
			cout << ans << " ";
		}
		cout << "\n";
	}
	return 0;
}