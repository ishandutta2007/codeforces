#include <cstdio>
using namespace std;

typedef long long ll;

const int Maxn = 1005;
const int Maxk = 105;

int n, k, m;
int dp[Maxn][Maxk][2][2];
int res;

int main()
{
	scanf("%d %d %d", &n, &k, &m);
	if (m == 1) { printf("0\n"); return 0; }
	dp[0][0][0][0] = 1;
	int cur = 1 % k;
	for (int i = 0; i <= n; i++) {
		for (int j = 0; j < k; j++)
			for (int l = 0; l < 2; l++)
				for (int w = 0; w < 2; w++) {
					int nj = j;
					int nl = 0;
					int nw = w;
					dp[i + 1][nj][nl][nw] = (dp[i + 1][nj][nl][nw] + dp[i][j][l][w]) % m;
					for (int g = 1; g < 10; g++) {
						nj = (g * cur + j) % k;
						nl = 1;
						nw = w || nj == 0;
						dp[i + 1][nj][nl][nw] = (dp[i + 1][nj][nl][nw] + dp[i][j][l][w]) % m;
					}
				}
		cur = cur * 10 % k;
	}
	for (int j = 0; j < k; j++)
		res = (res + dp[n][j][1][1]) % m;
	printf("%d\n", res);
	return 0;
}