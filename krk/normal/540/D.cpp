#include <cstdio>
#include <iostream>
#include <iomanip>
using namespace std;

typedef long double ld;

const int Maxn = 105;

int r, s, p;
ld dp[3][Maxn][Maxn][Maxn];

void Calc(int r, int s, int p)
{
	if (dp[0][r][s][p] >= -0.5) return;
	if (r == 0 && s == 0) {
		dp[2][r][s][p] = 1.0; 
		dp[0][r][s][p] = dp[1][r][s][p] = 0.0;
	} else if (r == 0 && p == 0) {
		dp[1][r][s][p] = 1.0;
		dp[0][r][s][p] = dp[2][r][s][p] = 0.0;
	} else if (s == 0 && p == 0) {
		dp[0][r][s][p] = 1.0;
		dp[1][r][s][p] = dp[2][r][s][p] = 0.0;
	} else {
		if (r) Calc(r - 1, s, p);
		if (s) Calc(r, s - 1, p);
		if (p) Calc(r, s, p - 1);
		int tot = r * s + r * p + s * p;
		for (int i = 0; i < 3; i++) {
			ld res = 0.0;
			if (s) res += ld(r * s) / tot * dp[i][r][s - 1][p];
			if (r) res += ld(r * p) / tot * dp[i][r - 1][s][p];
			if (p) res += ld(s * p) / tot * dp[i][r][s][p - 1];
			dp[i][r][s][p] = res;
		}
	}
}

int main()
{
	fill((ld*)dp, (ld*)dp + 3 * Maxn * Maxn * Maxn, -1.0l);
	scanf("%d %d %d", &r, &s, &p);
	Calc(r, s, p);
	for (int i = 0; i < 3; i++)
		cout << fixed << setprecision(12) << dp[i][r][s][p] << (i + 1 < 3? ' ': '\n');
	return 0;
}