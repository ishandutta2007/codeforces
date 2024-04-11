#include <bits/stdc++.h>
using namespace std;

bool dp[6][6][201][201];
pair<int, int> pre[6][6][201][201];

void out(int i, int j, int a, int b) {
	if (i == 0)
		return ;
	auto x = pre[i][j][a][b];

	if (x.first < x.second)
		out(i - 1, j, a - x.first, b - x.second);
	else
		out(i - 1, j - 1, a - x.first, b - x.second);
	printf("%d:%d", x.first, x.second);
	// if (i == 5)
	// 	printf("\n");
	// else
	printf(" ");
}

int main() {
	dp[0][0][0][0] = true;
	for (int i = 1; i <= 5; i++) {
		for (int j = 0; j < i; j++)
			for (int a = 0; a <= 200; a++)
				for (int b = 0; b <= 200; b++)
					if (dp[i - 1][j][a][b] && j < 3 && i - 1 - j < 3) {

						int T = 25;
						if (i == 5)
							T = 15;
						for (int k = 0; k <= T - 2; k++) {
							if (a + T <= 200 && b + k <= 200) {
								// if (i - 1 == 3 && j == 2 && a == 65 && b == 69 && k == 21)
								// 	printf("xxx %d %d %d %d\n", i, j + 1, a + T, b + k);
								dp[i][j + 1][a + T][b + k] = true;
								pre[i][j + 1][a + T][b + k] = make_pair(T, k);
							}
						}
						for (int k = T + 1; a + k <= 200 && b + k - 2 <= 200; k++) {
							dp[i][j + 1][a + k][b + k - 2] = true;
							pre[i][j + 1][a + k][b + k - 2] = make_pair(k, k - 2);
						}

						for (int k = 0; k <= T - 2; k++) {
							if (b + T <= 200 && a + k <= 200) {
								dp[i][j][a + k][b + T] = true;
								pre[i][j][a + k][b + T] = make_pair(k, T);
							}
						}
						for (int k = T + 1; a + k - 2 <= 200 && b + k <= 200; k++) {
							dp[i][j][a + k - 2][b + k] = true;
							pre[i][j][a + k - 2][b + k] = make_pair(k - 2, k);
						}
					}
	}
	// printf("%d\n", dp[4][3][90][90]);
	int T;
	scanf("%d", &T);
	while (T--) {
		int a, b;
		scanf("%d%d", &a, &b);
		bool ok = false;
		for (int diff = 3; diff >= -3 && !ok; diff--) {
			for (int i = 0; i <= 3; i++) {
				// if (i - diff >= 0 && 2 * i - diff <= 5 && (i >= 3 || i - diff >= 3))
				// 	printf("%d %d\n", i, i - diff);
				if (i - diff >= 0 && 2 * i - diff <= 5 && (i >= 3 || i - diff >= 3) && dp[2 * i - diff][i][a][b]) {
					printf("%d:%d\n", i, i - diff);
					out(2 * i - diff, i, a, b);
					ok = true;
					printf("\n");
					break;
				}
			}
		}
		if (!ok)
			printf("Impossible\n");
	}
}