#include <cstdio>
#include <iostream>
#include <vector>
#include <set>
#include <map>
#include <cmath>
#include <string>
#include <cstring>
#include <sstream>
#include <algorithm>
using namespace std;

const int Maxn = 77;
const int Inf = 1000000000;

int n;
char str[Maxn];
vector <int> V[3];
int dp[Maxn][Maxn][Maxn][2];

int main()
{
	scanf("%d", &n); scanf("%s", str);
	for (int i = 0; i < n; i++)
		if (str[i] == 'V') V[0].push_back(i);
		else if (str[i] == 'K') V[1].push_back(i);
		else V[2].push_back(i);
	fill((int*)dp, (int*)dp + Maxn * Maxn * Maxn * 2, Inf);
	dp[0][0][0][0] = 0;
	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++)
			for (int k = 0; k < n; k++)
				for (int f = 0; f < 2; f++) if (dp[i][j][k][f] < Inf) {
					int a = j, b = k, c = i - j - k;
					if (a < V[0].size()) {
						int add = (upper_bound(V[1].begin() + b, V[1].end(), V[0][a]) - V[1].begin() - b) +
								  (upper_bound(V[2].begin() + c, V[2].end(), V[0][a]) - V[2].begin() - c);
						dp[i + 1][j + 1][k][1] = min(dp[i + 1][j + 1][k][1], dp[i][j][k][f] + add); 
					}
					if (b < V[1].size() && f != 1) {
						int add = (upper_bound(V[0].begin() + a, V[0].end(), V[1][b]) - V[0].begin() - a) +
								  (upper_bound(V[2].begin() + c, V[2].end(), V[1][b]) - V[2].begin() - c);
						dp[i + 1][j][k + 1][0] = min(dp[i + 1][j][k + 1][0], dp[i][j][k][f] + add);
					}
					if (c < V[2].size()) {
						int add = (upper_bound(V[0].begin() + a, V[0].end(), V[2][c]) - V[0].begin() - a) +
								  (upper_bound(V[1].begin() + b, V[1].end(), V[2][c]) - V[1].begin() - b);
						dp[i + 1][j][k][0] = min(dp[i + 1][j][k][0], dp[i][j][k][f] + add);
					}
				}
	printf("%d\n", min(dp[n][V[0].size()][V[1].size()][0], dp[n][V[0].size()][V[1].size()][1]));
	return 0;
}