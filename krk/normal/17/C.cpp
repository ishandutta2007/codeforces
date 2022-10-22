#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

const int mod = 51123987;
const int Maxn = 155;
const int Maxm = 52;

char s[Maxn];
int slen;
int nxt[Maxn][3];
int dp[2][Maxn][Maxm][Maxm];
bool cur;
int res;

int main()
{
	scanf("%d", &slen);
	scanf("%s", s);
	nxt[slen][0] = nxt[slen][1] = nxt[slen][2] = slen;
	for (int i = slen - 1; i >= 0; i--) {
		for (int j = 0; j < 3; j++) nxt[i][j] = nxt[i + 1][j];
		nxt[i][s[i] - 'a'] = i;
	}
	dp[cur][0][0][0] = 1;
	for (int i = 0; i < slen; i++) {
		fill((int*)dp[!cur], (int*)dp[!cur] + Maxn * Maxm * Maxm, 0);
		for (int j = 0; j < slen; j++)
			for (int a = 0; a < Maxm && a <= i; a++)
				for (int b = 0; b < Maxm && a + b <= i; b++) {
					if (a + 1 < Maxm && nxt[j][0] < slen)
						dp[!cur][nxt[j][0]][a + 1][b] = (dp[!cur][nxt[j][0]][a + 1][b] + dp[cur][j][a][b]) % mod;
					if (b + 1 < Maxm && nxt[j][1] < slen)
						dp[!cur][nxt[j][1]][a][b + 1] = (dp[!cur][nxt[j][1]][a][b + 1] + dp[cur][j][a][b]) % mod;
					if (nxt[j][2] < slen)
						dp[!cur][nxt[j][2]][a][b] = (dp[!cur][nxt[j][2]][a][b] + dp[cur][j][a][b]) % mod;
				}
		cur = !cur;
	}
	for (int i = 0; i < slen; i++)
		for (int a = 0; a <= slen; a++)
			for (int b = 0; a + b <= slen; b++) {
				int c = slen - a - b;
				if (abs(a - b) <= 1 && abs(a - c) <= 1 && abs(b - c) <= 1)
					res = (res + dp[cur][i][a][b]) % mod;
			}
	printf("%d\n", res);
	return 0;
}