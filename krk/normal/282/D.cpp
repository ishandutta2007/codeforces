#include <cstdio>
#include <algorithm>
using namespace std;

const int Maxn = 3;
const int Maxm = 301;
const int Inf = 1000000000;

int n;
int a[Maxn];
bool dp[Maxm][Maxm];
int rc[Maxm][Maxm];
bool diag[Maxm][Maxm];
bool win;

bool Win1() { return a[0]; }

bool Win2()
{
	for (int i = 0; i <= a[0]; i++)
		for (int j = 0; j <= a[1]; j++) {
			int mn = min(i, j);
			for (int l = 1; l <= mn && !dp[i][j]; l++)
				dp[i][j] = !dp[i - l][j - l];
			for (int l = 1; l <= i && !dp[i][j]; l++)
				dp[i][j] = !dp[i - l][j];
			for (int l = 1; l <= j && !dp[i][j]; l++)
				dp[i][j] = !dp[i][j - l];
		}
	return dp[a[0]][a[1]];
}

bool Win3()
{
	fill((int*)rc, (int*)rc + Maxm * Maxm, Inf);
	bool win;
	for (int i = 0; i <= a[0]; i++)
		for (int j = 0; j <= a[1]; j++)
			for (int k = 0; k <= a[2]; k++) {
				int i2 = i, j2 = j, k2 = k;
				if (i2 > j2) swap(i2, j2);
				if (j2 > k2) swap(j2, k2);
				if (i2 > j2) swap(i2, j2);
				win = rc[i2][j2] < k2 || rc[i2][k2] < j2 || rc[j2][k2] < i2 || diag[j2 - i2][k2 - j2];
				if (!win) {
					rc[i2][j2] = min(rc[i2][j2], k2); rc[i2][k2] = min(rc[i2][k2], j2); rc[j2][k2] = min(rc[j2][k2], i2);
					diag[j2 - i2][k2 - j2] = true;
				}
			}
	return win;
}

int main()
{
	scanf("%d", &n);
	for (int i = 0; i < n; i++)
		scanf("%d", &a[i]);
	sort(a, a + n);
	if (n == 1) win = Win1();
	else if (n == 2) win = Win2();
	else win = Win3();
	printf("%s\n", win? "BitLGM": "BitAryo");
	return 0;
}