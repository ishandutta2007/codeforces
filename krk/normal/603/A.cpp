#include <cstdio>
#include <cstring>
#include <vector>
using namespace std;

const int Maxn = 100005;

int n;
char s[Maxn];
int dp[Maxn][2][3];

int main()
{
	scanf("%d", &n);
	scanf("%s", s);
	for (int i = 0; i < n; i++)
		for (int j = 0; j < 2; j++)
			for (int l = 0; l < 3; l++) {
				if (l + 1 < 3) dp[i][j][l + 1] = max(dp[i][j][l + 1], dp[i][j][l]);
				int has = ((s[i] == '0') ^ (l % 2 == 1))? 1: 0;
				if (has == j) dp[i + 1][1 - j][l] = max(dp[i + 1][1 - j][l], dp[i][j][l] + 1);
				else dp[i + 1][j][l] = max(dp[i + 1][j][l], dp[i][j][l]); 
			}
	int res = 0;
	for (int j = 0; j < 2; j++)
		for (int l = 0; l < 3; l++)
			res = max(res, dp[n][j][l]);
	printf("%d\n", res);
	return 0;
}