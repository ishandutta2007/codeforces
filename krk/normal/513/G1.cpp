#include <cstdio>
#include <algorithm>
using namespace std;

const int Maxn = 31;
const int Maxk = 201;

int n, k;
int p[Maxn];
double dp[Maxn][Maxn][Maxk];
double res;

int Modify(int a, int i, int j)
{
	if (a < i || a > j) return a;
	return i + j - a;
}

double getRes(int a, int b, int k)
{
	if (a == b) return 0.0;
	if (a > b) return 1.0 - getRes(b, a, k);
	if (dp[a][b][k] < -0.1) {
		double res = 0.0;
		for (int i = 0; i < n; i++)
			for (int j = i; j < n; j++) {
				int ga = Modify(a, i, j);
				int gb = Modify(b, i, j);
				res += getRes(ga, gb, k - 1);
			}
		dp[a][b][k] = res / double(n * (n + 1) / 2);
	}
	return dp[a][b][k];
}

int main()
{
	scanf("%d %d", &n, &k);
	fill((double*)dp, (double*)dp + Maxn * Maxn * Maxk, -1.0);
	for (int i = 0; i < n; i++)
		scanf("%d", &p[i]);
	for (int i = 0; i < n; i++)
		for (int j = i + 1; j < n; j++)
			dp[i][j][0] = p[i] > p[j]? 1.0: 0.0;
	for (int i = 0; i < n; i++)
		for (int j = i + 1; j < n; j++)
			res += getRes(i, j, k);
	printf("%.15lf\n", res);
	return 0;
}