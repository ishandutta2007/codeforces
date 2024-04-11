#include <cstdio>
#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

const int Maxk = 505;

int n, k;
bool dp[2][Maxk][Maxk];
int cur;
vector <int> res;

int main()
{
	scanf("%d %d", &n, &k);
	fill((bool*)dp[cur], (bool*)dp[cur] + Maxk * Maxk, false); dp[cur][0][0] = true;
	for (int i = 0; i < n; i++) {
		int a; scanf("%d", &a);
		fill((bool*)dp[!cur], (bool*)dp[!cur] + Maxk * Maxk, false);
		for (int j = 0; j <= k; j++)
			for (int l = j; l <= k; l++) if (dp[cur][j][l]) {
				dp[!cur][j][l] = true;
				if (l + a <= k) {
					dp[!cur][j][l + a] = true;
					dp[!cur][j + a][l + a] = true;
				}
			}
		cur = !cur;
	}
	for (int i = 0; i <= k; i++)
		if (dp[cur][i][k]) res.push_back(i);
	printf("%d\n", res.size());
	for (int i = 0; i < res.size(); i++)
		printf("%d%c", res[i], i + 1 < res.size()? ' ': '\n');
	return 0;
}